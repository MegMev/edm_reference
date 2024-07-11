// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitPlane_CollectionData_H
#define EDM4HEP_TrackerHitPlane_CollectionData_H

// datamodel specific includes
#include "edm4hep/TrackerHitPlaneData.h"
#include "edm4hep/TrackerHitPlaneObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TrackerHitPlaneObjPointerContainer = std::deque<TrackerHitPlaneObj*>;
using TrackerHitPlaneDataContainer = std::vector<TrackerHitPlaneData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TrackerHitPlaneCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TrackerHitPlaneObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TrackerHitPlaneCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TrackerHitPlaneCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TrackerHitPlaneCollectionData(const TrackerHitPlaneCollectionData&) = delete;
  TrackerHitPlaneCollectionData& operator=(const TrackerHitPlaneCollectionData&) = delete;
  TrackerHitPlaneCollectionData(TrackerHitPlaneCollectionData&& other) = default;
  TrackerHitPlaneCollectionData& operator=(TrackerHitPlaneCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~TrackerHitPlaneCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<TrackerHitPlaneDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
