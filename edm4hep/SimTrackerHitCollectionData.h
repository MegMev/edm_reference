// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHit_CollectionData_H
#define EDM4HEP_SimTrackerHit_CollectionData_H

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/SimTrackerHitData.h"
#include "edm4hep/SimTrackerHitObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using SimTrackerHitObjPointerContainer = std::deque<SimTrackerHitObj*>;
using SimTrackerHitDataContainer = std::vector<SimTrackerHitData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class SimTrackerHitCollectionData {
public:
  /**
   * The Objs of this collection
   */
  SimTrackerHitObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  SimTrackerHitCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  SimTrackerHitCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  SimTrackerHitCollectionData(const SimTrackerHitCollectionData&) = delete;
  SimTrackerHitCollectionData& operator=(const SimTrackerHitCollectionData&) = delete;
  SimTrackerHitCollectionData(SimTrackerHitCollectionData&& other) = default;
  SimTrackerHitCollectionData& operator=(SimTrackerHitCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~SimTrackerHitCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::MCParticle> m_rel_particle{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<SimTrackerHitDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
