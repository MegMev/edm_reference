// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticle_CollectionData_H
#define EDM4HEP_ReconstructedParticle_CollectionData_H

// datamodel specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/ReconstructedParticleObj.h"
#include "edm4hep/Track.h"
#include "edm4hep/Vertex.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using ReconstructedParticleObjPointerContainer = std::deque<ReconstructedParticleObj*>;
using ReconstructedParticleDataContainer = std::vector<ReconstructedParticleData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class ReconstructedParticleCollectionData {
public:
  /**
   * The Objs of this collection
   */
  ReconstructedParticleObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  ReconstructedParticleCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  ReconstructedParticleCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  ReconstructedParticleCollectionData(const ReconstructedParticleCollectionData&) = delete;
  ReconstructedParticleCollectionData& operator=(const ReconstructedParticleCollectionData&) = delete;
  ReconstructedParticleCollectionData(ReconstructedParticleCollectionData&& other) = default;
  ReconstructedParticleCollectionData& operator=(ReconstructedParticleCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~ReconstructedParticleCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(ReconstructedParticleObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::Cluster> m_rel_clusters;                    ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::Cluster>> m_rel_clusters_tmp{}; ///< Relation buffer for internal book-keeping
  podio::UVecPtr<edm4hep::Track> m_rel_tracks;                        ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::Track>> m_rel_tracks_tmp{};     ///< Relation buffer for internal book-keeping
  podio::UVecPtr<edm4hep::ReconstructedParticle> m_rel_particles;     ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::ReconstructedParticle>> m_rel_particles_tmp{}; ///< Relation buffer for internal
                                                                                     ///< book-keeping
  podio::UVecPtr<edm4hep::Vertex> m_rel_startVertex{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<ReconstructedParticleDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
