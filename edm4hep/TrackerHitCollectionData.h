// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit_CollectionData_H
#define EDM4HEP_TrackerHit_CollectionData_H

// datamodel specific includes
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/TrackerHitObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TrackerHitObjPointerContainer = std::deque<TrackerHitObj*>;
using TrackerHitDataContainer = std::vector<TrackerHitData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TrackerHitCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TrackerHitObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TrackerHitCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TrackerHitCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TrackerHitCollectionData(const TrackerHitCollectionData&) = delete;
  TrackerHitCollectionData& operator=(const TrackerHitCollectionData&) = delete;
  TrackerHitCollectionData(TrackerHitCollectionData&& other) = default;
  TrackerHitCollectionData& operator=(TrackerHitCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~TrackerHitCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(TrackerHitObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations

  // members to handle vector members
  podio::UVecPtr<edm4hep::ObjectID> m_vec_rawHits{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<edm4hep::ObjectID>> m_vecs_rawHits{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<TrackerHitDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
