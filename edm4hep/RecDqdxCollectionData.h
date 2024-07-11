// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecDqdx_CollectionData_H
#define EDM4HEP_RecDqdx_CollectionData_H

// datamodel specific includes
#include "edm4hep/RecDqdxData.h"
#include "edm4hep/RecDqdxObj.h"
#include "edm4hep/Track.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using RecDqdxObjPointerContainer = std::deque<RecDqdxObj*>;
using RecDqdxDataContainer = std::vector<RecDqdxData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class RecDqdxCollectionData {
public:
  /**
   * The Objs of this collection
   */
  RecDqdxObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  RecDqdxCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  RecDqdxCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  RecDqdxCollectionData(const RecDqdxCollectionData&) = delete;
  RecDqdxCollectionData& operator=(const RecDqdxCollectionData&) = delete;
  RecDqdxCollectionData(RecDqdxCollectionData&& other) = default;
  RecDqdxCollectionData& operator=(RecDqdxCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~RecDqdxCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::Track> m_rel_track{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<RecDqdxDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
