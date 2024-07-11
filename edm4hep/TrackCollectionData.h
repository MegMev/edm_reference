// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Track_CollectionData_H
#define EDM4HEP_Track_CollectionData_H

// datamodel specific includes
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackObj.h"
#include "edm4hep/TrackerHit.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using TrackObjPointerContainer = std::deque<TrackObj*>;
using TrackDataContainer = std::vector<TrackData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class TrackCollectionData {
public:
  /**
   * The Objs of this collection
   */
  TrackObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  TrackCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  TrackCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  TrackCollectionData(const TrackCollectionData&) = delete;
  TrackCollectionData& operator=(const TrackCollectionData&) = delete;
  TrackCollectionData(TrackCollectionData&& other) = default;
  TrackCollectionData& operator=(TrackCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~TrackCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(TrackObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::TrackerHit> m_rel_trackerHits;                    ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::TrackerHit>> m_rel_trackerHits_tmp{}; ///< Relation buffer for internal
                                                                            ///< book-keeping
  podio::UVecPtr<edm4hep::Track> m_rel_tracks;                              ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::Track>> m_rel_tracks_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members
  podio::UVecPtr<std::int32_t> m_vec_subdetectorHitNumbers{nullptr}; /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<std::int32_t>> m_vecs_subdetectorHitNumbers{}; /// pointers to individual member vectors
  podio::UVecPtr<edm4hep::TrackState> m_vec_trackStates{nullptr}; /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<edm4hep::TrackState>> m_vecs_trackStates{}; /// pointers to individual member vectors
  podio::UVecPtr<edm4hep::Quantity> m_vec_dxQuantities{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<edm4hep::Quantity>> m_vecs_dxQuantities{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<TrackDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
