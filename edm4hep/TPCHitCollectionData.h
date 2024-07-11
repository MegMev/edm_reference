// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHit_CollectionData_H
#define EDM4HEP_TPCHit_CollectionData_H

// datamodel specific includes
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHitObj.h"

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TPCHitObjPointerContainer = std::deque<TPCHitObj*>;
using TPCHitDataContainer = std::vector<TPCHitData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TPCHitCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TPCHitObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TPCHitCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TPCHitCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TPCHitCollectionData(const TPCHitCollectionData&) = delete;
  TPCHitCollectionData& operator=(const TPCHitCollectionData&) = delete;
  TPCHitCollectionData(TPCHitCollectionData&& other) = default;
  TPCHitCollectionData& operator=(TPCHitCollectionData&& other) = default;

  /**
   * Deconstructor
   */
  ~TPCHitCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(TPCHitObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations

  // members to handle vector members
  podio::UVecPtr<std::int32_t> m_vec_rawDataWords{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<std::int32_t>> m_vecs_rawDataWords{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<TPCHitDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
