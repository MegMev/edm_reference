// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit3D_CollectionData_H
#define EDM4HEP_TrackerHit3D_CollectionData_H

// datamodel specific includes
#include "edm4hep/TrackerHit3DData.h"
#include "edm4hep/TrackerHit3DObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TrackerHit3DObjPointerContainer = std::deque<TrackerHit3DObj*>;
using TrackerHit3DDataContainer = std::vector<TrackerHit3DData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TrackerHit3DCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TrackerHit3DObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TrackerHit3DCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TrackerHit3DCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TrackerHit3DCollectionData(const TrackerHit3DCollectionData&) = delete;
  TrackerHit3DCollectionData& operator=(const TrackerHit3DCollectionData&) = delete;
  TrackerHit3DCollectionData(TrackerHit3DCollectionData&& other) = default;
  TrackerHit3DCollectionData& operator=(TrackerHit3DCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~TrackerHit3DCollectionData() = default;

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
  std::unique_ptr<TrackerHit3DDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
