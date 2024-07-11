// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloAssociation_CollectionData_H
#define EDM4HEP_MCRecoCaloAssociation_CollectionData_H

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/MCRecoCaloAssociationData.h"
#include "edm4hep/MCRecoCaloAssociationObj.h"
#include "edm4hep/SimCalorimeterHit.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using MCRecoCaloAssociationObjPointerContainer = std::deque<MCRecoCaloAssociationObj*>;
using MCRecoCaloAssociationDataContainer = std::vector<MCRecoCaloAssociationData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class MCRecoCaloAssociationCollectionData {
public:
  /**
   * The Objs of this collection
   */
  MCRecoCaloAssociationObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  MCRecoCaloAssociationCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  MCRecoCaloAssociationCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  MCRecoCaloAssociationCollectionData(const MCRecoCaloAssociationCollectionData&) = delete;
  MCRecoCaloAssociationCollectionData& operator=(const MCRecoCaloAssociationCollectionData&) = delete;
  MCRecoCaloAssociationCollectionData(MCRecoCaloAssociationCollectionData&& other) = default;
  MCRecoCaloAssociationCollectionData& operator=(MCRecoCaloAssociationCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~MCRecoCaloAssociationCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::CalorimeterHit> m_rel_rec{nullptr};    ///< Relation buffer for read / write
  podio::UVecPtr<edm4hep::SimCalorimeterHit> m_rel_sim{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<MCRecoCaloAssociationDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
