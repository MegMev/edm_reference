// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackParticleAssociation_CollectionData_H
#define EDM4HEP_MCRecoTrackParticleAssociation_CollectionData_H

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCRecoTrackParticleAssociationData.h"
#include "edm4hep/MCRecoTrackParticleAssociationObj.h"
#include "edm4hep/Track.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using MCRecoTrackParticleAssociationObjPointerContainer = std::deque<MCRecoTrackParticleAssociationObj*>;
using MCRecoTrackParticleAssociationDataContainer = std::vector<MCRecoTrackParticleAssociationData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class MCRecoTrackParticleAssociationCollectionData {
public:
  /**
   * The Objs of this collection
   */
  MCRecoTrackParticleAssociationObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  MCRecoTrackParticleAssociationCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  MCRecoTrackParticleAssociationCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  MCRecoTrackParticleAssociationCollectionData(const MCRecoTrackParticleAssociationCollectionData&) = delete;
  MCRecoTrackParticleAssociationCollectionData& operator=(const MCRecoTrackParticleAssociationCollectionData&) = delete;
  MCRecoTrackParticleAssociationCollectionData(MCRecoTrackParticleAssociationCollectionData&& other) = default;
  MCRecoTrackParticleAssociationCollectionData&
  operator=(MCRecoTrackParticleAssociationCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~MCRecoTrackParticleAssociationCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::Track> m_rel_rec{nullptr};      ///< Relation buffer for read / write
  podio::UVecPtr<edm4hep::MCParticle> m_rel_sim{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<MCRecoTrackParticleAssociationDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
