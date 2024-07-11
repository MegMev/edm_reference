// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimPrimaryIonizationCluster_CollectionData_H
#define EDM4HEP_SimPrimaryIonizationCluster_CollectionData_H

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/SimPrimaryIonizationClusterData.h"
#include "edm4hep/SimPrimaryIonizationClusterObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using SimPrimaryIonizationClusterObjPointerContainer = std::deque<SimPrimaryIonizationClusterObj*>;
using SimPrimaryIonizationClusterDataContainer = std::vector<SimPrimaryIonizationClusterData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class SimPrimaryIonizationClusterCollectionData {
public:
  /**
   * The Objs of this collection
   */
  SimPrimaryIonizationClusterObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  SimPrimaryIonizationClusterCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  SimPrimaryIonizationClusterCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  SimPrimaryIonizationClusterCollectionData(const SimPrimaryIonizationClusterCollectionData&) = delete;
  SimPrimaryIonizationClusterCollectionData& operator=(const SimPrimaryIonizationClusterCollectionData&) = delete;
  SimPrimaryIonizationClusterCollectionData(SimPrimaryIonizationClusterCollectionData&& other) = default;
  SimPrimaryIonizationClusterCollectionData& operator=(SimPrimaryIonizationClusterCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~SimPrimaryIonizationClusterCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(SimPrimaryIonizationClusterObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::MCParticle> m_rel_MCParticle{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members
  podio::UVecPtr<std::uint64_t> m_vec_electronCellID{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<std::uint64_t>> m_vecs_electronCellID{}; /// pointers to individual member vectors
  podio::UVecPtr<float> m_vec_electronTime{nullptr};                  /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<float>> m_vecs_electronTime{};           /// pointers to individual member vectors
  podio::UVecPtr<edm4hep::Vector3d> m_vec_electronPosition{nullptr};  /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<edm4hep::Vector3d>> m_vecs_electronPosition{}; /// pointers to individual member vectors
  podio::UVecPtr<float> m_vec_pulseTime{nullptr};             /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<float>> m_vecs_pulseTime{};      /// pointers to individual member vectors
  podio::UVecPtr<float> m_vec_pulseAmplitude{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<float>> m_vecs_pulseAmplitude{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<SimPrimaryIonizationClusterDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
