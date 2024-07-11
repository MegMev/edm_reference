// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TimeSeries_CollectionData_H
#define EDM4HEP_TimeSeries_CollectionData_H

// datamodel specific includes
#include "edm4hep/TimeSeriesData.h"
#include "edm4hep/TimeSeriesObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TimeSeriesObjPointerContainer = std::deque<TimeSeriesObj*>;
using TimeSeriesDataContainer = std::vector<TimeSeriesData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TimeSeriesCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TimeSeriesObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TimeSeriesCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TimeSeriesCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TimeSeriesCollectionData(const TimeSeriesCollectionData&) = delete;
  TimeSeriesCollectionData& operator=(const TimeSeriesCollectionData&) = delete;
  TimeSeriesCollectionData(TimeSeriesCollectionData&& other) = default;
  TimeSeriesCollectionData& operator=(TimeSeriesCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~TimeSeriesCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(TimeSeriesObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations

  // members to handle vector members
  podio::UVecPtr<float> m_vec_amplitude{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<float>> m_vecs_amplitude{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<TimeSeriesDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
