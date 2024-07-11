// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerHitPlaneAssociation_CollectionData_H
#define EDM4HEP_MCRecoTrackerHitPlaneAssociation_CollectionData_H

// datamodel specific includes
#include "edm4hep/MCRecoTrackerHitPlaneAssociationData.h"
#include "edm4hep/MCRecoTrackerHitPlaneAssociationObj.h"
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHitPlane.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using MCRecoTrackerHitPlaneAssociationObjPointerContainer = std::deque<MCRecoTrackerHitPlaneAssociationObj*>;
using MCRecoTrackerHitPlaneAssociationDataContainer = std::vector<MCRecoTrackerHitPlaneAssociationData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class MCRecoTrackerHitPlaneAssociationCollectionData {
public:
  /**
   * The Objs of this collection
   */
  MCRecoTrackerHitPlaneAssociationObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  MCRecoTrackerHitPlaneAssociationCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  MCRecoTrackerHitPlaneAssociationCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  MCRecoTrackerHitPlaneAssociationCollectionData(const MCRecoTrackerHitPlaneAssociationCollectionData&) = delete;
  MCRecoTrackerHitPlaneAssociationCollectionData&
  operator=(const MCRecoTrackerHitPlaneAssociationCollectionData&) = delete;
  MCRecoTrackerHitPlaneAssociationCollectionData(MCRecoTrackerHitPlaneAssociationCollectionData&& other) = default;
  MCRecoTrackerHitPlaneAssociationCollectionData&
  operator=(MCRecoTrackerHitPlaneAssociationCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~MCRecoTrackerHitPlaneAssociationCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::TrackerHitPlane> m_rel_rec{nullptr}; ///< Relation buffer for read / write
  podio::UVecPtr<edm4hep::SimTrackerHit> m_rel_sim{nullptr};   ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<MCRecoTrackerHitPlaneAssociationDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
