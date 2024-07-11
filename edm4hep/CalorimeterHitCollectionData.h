// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHit_CollectionData_H
#define EDM4HEP_CalorimeterHit_CollectionData_H

// datamodel specific includes
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHitObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using CalorimeterHitObjPointerContainer = std::deque<CalorimeterHitObj*>;
using CalorimeterHitDataContainer = std::vector<CalorimeterHitData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class CalorimeterHitCollectionData {
public:
  /**
   * The Objs of this collection
   */
  CalorimeterHitObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  CalorimeterHitCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  CalorimeterHitCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  CalorimeterHitCollectionData(const CalorimeterHitCollectionData&) = delete;
  CalorimeterHitCollectionData& operator=(const CalorimeterHitCollectionData&) = delete;
  CalorimeterHitCollectionData(CalorimeterHitCollectionData&& other) = default;
  CalorimeterHitCollectionData& operator=(CalorimeterHitCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~CalorimeterHitCollectionData() = default;

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
  std::unique_ptr<CalorimeterHitDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
