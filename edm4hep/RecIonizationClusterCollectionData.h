// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecIonizationCluster_CollectionData_H
#define EDM4HEP_RecIonizationCluster_CollectionData_H

// datamodel specific includes
#include "edm4hep/RecIonizationClusterData.h"
#include "edm4hep/RecIonizationClusterObj.h"
#include "edm4hep/TrackerPulse.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using RecIonizationClusterObjPointerContainer = std::deque<RecIonizationClusterObj*>;
using RecIonizationClusterDataContainer = std::vector<RecIonizationClusterData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class RecIonizationClusterCollectionData {
public:
  /**
   * The Objs of this collection
   */
  RecIonizationClusterObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  RecIonizationClusterCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  RecIonizationClusterCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  RecIonizationClusterCollectionData(const RecIonizationClusterCollectionData&) = delete;
  RecIonizationClusterCollectionData& operator=(const RecIonizationClusterCollectionData&) = delete;
  RecIonizationClusterCollectionData(RecIonizationClusterCollectionData&& other) = default;
  RecIonizationClusterCollectionData& operator=(RecIonizationClusterCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~RecIonizationClusterCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(RecIonizationClusterObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::TrackerPulse> m_rel_trackerPulse;                    ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::TrackerPulse>> m_rel_trackerPulse_tmp{}; ///< Relation buffer for internal
                                                                               ///< book-keeping

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<RecIonizationClusterDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
