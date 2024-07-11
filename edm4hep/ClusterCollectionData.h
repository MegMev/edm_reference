// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Cluster_CollectionData_H
#define EDM4HEP_Cluster_CollectionData_H

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/ClusterData.h"
#include "edm4hep/ClusterObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using ClusterObjPointerContainer = std::deque<ClusterObj*>;
using ClusterDataContainer = std::vector<ClusterData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class ClusterCollectionData {
public:
  /**
   * The Objs of this collection
   */
  ClusterObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  ClusterCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  ClusterCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  ClusterCollectionData(const ClusterCollectionData&) = delete;
  ClusterCollectionData& operator=(const ClusterCollectionData&) = delete;
  ClusterCollectionData(ClusterCollectionData&& other) = default;
  ClusterCollectionData& operator=(ClusterCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~ClusterCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(ClusterObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::Cluster> m_rel_clusters;                       ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::Cluster>> m_rel_clusters_tmp{};    ///< Relation buffer for internal book-keeping
  podio::UVecPtr<edm4hep::CalorimeterHit> m_rel_hits;                    ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::CalorimeterHit>> m_rel_hits_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members
  podio::UVecPtr<float> m_vec_shapeParameters{nullptr};            /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<float>> m_vecs_shapeParameters{};     /// pointers to individual member vectors
  podio::UVecPtr<float> m_vec_subdetectorEnergies{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<float>> m_vecs_subdetectorEnergies{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<ClusterDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
