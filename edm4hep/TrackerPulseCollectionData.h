// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerPulse_CollectionData_H
#define EDM4HEP_TrackerPulse_CollectionData_H

// datamodel specific includes
#include "edm4hep/TimeSeries.h"
#include "edm4hep/TrackerPulseData.h"
#include "edm4hep/TrackerPulseObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TrackerPulseObjPointerContainer = std::deque<TrackerPulseObj*>;
using TrackerPulseDataContainer = std::vector<TrackerPulseData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TrackerPulseCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TrackerPulseObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TrackerPulseCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TrackerPulseCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TrackerPulseCollectionData(const TrackerPulseCollectionData&) = delete;
  TrackerPulseCollectionData& operator=(const TrackerPulseCollectionData&) = delete;
  TrackerPulseCollectionData(TrackerPulseCollectionData&& other) = default;
  TrackerPulseCollectionData& operator=(TrackerPulseCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~TrackerPulseCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::TimeSeries> m_rel_timeSeries{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<TrackerPulseDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
