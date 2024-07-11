// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawCalorimeterHit_CollectionData_H
#define EDM4HEP_RawCalorimeterHit_CollectionData_H

// datamodel specific includes
#include "edm4hep/RawCalorimeterHitData.h"
#include "edm4hep/RawCalorimeterHitObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using RawCalorimeterHitObjPointerContainer = std::deque<RawCalorimeterHitObj*>;
using RawCalorimeterHitDataContainer = std::vector<RawCalorimeterHitData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class RawCalorimeterHitCollectionData {
public:
  /**
   * The Objs of this collection
   */
  RawCalorimeterHitObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  RawCalorimeterHitCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  RawCalorimeterHitCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  RawCalorimeterHitCollectionData(const RawCalorimeterHitCollectionData&) = delete;
  RawCalorimeterHitCollectionData& operator=(const RawCalorimeterHitCollectionData&) = delete;
  RawCalorimeterHitCollectionData(RawCalorimeterHitCollectionData&& other) = default;
  RawCalorimeterHitCollectionData& operator=(RawCalorimeterHitCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~RawCalorimeterHitCollectionData() = default;

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
  std::unique_ptr<RawCalorimeterHitDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
