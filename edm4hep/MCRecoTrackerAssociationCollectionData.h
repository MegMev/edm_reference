// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerAssociation_CollectionData_H
#define EDM4HEP_MCRecoTrackerAssociation_CollectionData_H

// datamodel specific includes
#include "edm4hep/MCRecoTrackerAssociationData.h"
#include "edm4hep/MCRecoTrackerAssociationObj.h"
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHit.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using MCRecoTrackerAssociationObjPointerContainer = std::deque<MCRecoTrackerAssociationObj*>;
using MCRecoTrackerAssociationDataContainer = std::vector<MCRecoTrackerAssociationData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class MCRecoTrackerAssociationCollectionData {
public:
  /**
   * The Objs of this collection
   */
  MCRecoTrackerAssociationObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  MCRecoTrackerAssociationCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  MCRecoTrackerAssociationCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  MCRecoTrackerAssociationCollectionData(const MCRecoTrackerAssociationCollectionData&) = delete;
  MCRecoTrackerAssociationCollectionData& operator=(const MCRecoTrackerAssociationCollectionData&) = delete;
  MCRecoTrackerAssociationCollectionData(MCRecoTrackerAssociationCollectionData&& other) = default;
  MCRecoTrackerAssociationCollectionData& operator=(MCRecoTrackerAssociationCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~MCRecoTrackerAssociationCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::TrackerHit> m_rel_rec{nullptr};    ///< Relation buffer for read / write
  podio::UVecPtr<edm4hep::SimTrackerHit> m_rel_sim{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<MCRecoTrackerAssociationDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
