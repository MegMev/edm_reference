// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticle_CollectionData_H
#define EDM4HEP_MCParticle_CollectionData_H

// datamodel specific includes
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticleObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using MCParticleObjPointerContainer = std::deque<MCParticleObj*>;
using MCParticleDataContainer = std::vector<MCParticleData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class MCParticleCollectionData {
public:
  /**
   * The Objs of this collection
   */
  MCParticleObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  MCParticleCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  MCParticleCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  MCParticleCollectionData(const MCParticleCollectionData&) = delete;
  MCParticleCollectionData& operator=(const MCParticleCollectionData&) = delete;
  MCParticleCollectionData(MCParticleCollectionData&& other) = default;
  MCParticleCollectionData& operator=(MCParticleCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~MCParticleCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(MCParticleObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::MCParticle> m_rel_parents;                      ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::MCParticle>> m_rel_parents_tmp{};   ///< Relation buffer for internal book-keeping
  podio::UVecPtr<edm4hep::MCParticle> m_rel_daughters;                    ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::MCParticle>> m_rel_daughters_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<MCParticleDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
