// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawTimeSeries_CollectionData_H
#define EDM4HEP_RawTimeSeries_CollectionData_H

// datamodel specific includes
#include "edm4hep/RawTimeSeriesData.h"
#include "edm4hep/RawTimeSeriesObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using RawTimeSeriesObjPointerContainer = std::deque<RawTimeSeriesObj*>;
using RawTimeSeriesDataContainer = std::vector<RawTimeSeriesData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class RawTimeSeriesCollectionData {
public:
  /**
   * The Objs of this collection
   */
  RawTimeSeriesObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  RawTimeSeriesCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  RawTimeSeriesCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  RawTimeSeriesCollectionData(const RawTimeSeriesCollectionData&) = delete;
  RawTimeSeriesCollectionData& operator=(const RawTimeSeriesCollectionData&) = delete;
  RawTimeSeriesCollectionData(RawTimeSeriesCollectionData&& other) = default;
  RawTimeSeriesCollectionData& operator=(RawTimeSeriesCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~RawTimeSeriesCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(RawTimeSeriesObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations

  // members to handle vector members
  podio::UVecPtr<std::int32_t> m_vec_adcCounts{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<std::int32_t>> m_vecs_adcCounts{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<RawTimeSeriesDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
