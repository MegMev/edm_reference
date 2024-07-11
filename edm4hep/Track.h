// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Track_H
#define EDM4HEP_Track_H

#include "edm4hep/TrackObj.h"

#include "edm4hep/Quantity.h"
#include "edm4hep/TrackState.h"
#include "edm4hep/TrackerHit.h"
#include "podio/RelationRange.h"
#include <cstdint>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableTrack;
class TrackCollection;
class TrackCollectionData;

/** @class Track
 *  Reconstructed track
 *  @author: EDM4hep authors
 */
class Track {

  friend class MutableTrack;
  friend class TrackCollection;
  friend class edm4hep::TrackCollectionData;
  friend class TrackCollectionIterator;

public:
  using mutable_type = MutableTrack;
  using collection_type = TrackCollection;

  /// default constructor
  Track();

  /// Constructor initializing all members
  Track(std::int32_t type, float chi2, std::int32_t ndf, float dEdx, float dEdxError, float radiusOfInnermostHit);

  /// copy constructor
  Track(const Track& other) = default;

  /// copy-assignment operator
  Track& operator=(Track other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrack clone(bool cloneRelations = true) const;

  /// destructor
  ~Track() = default;

  /// converting constructor from mutable object
  Track(const MutableTrack& other);

  static Track makeEmpty();

public:
  /// Access the flagword that defines the type of track
  std::int32_t getType() const;

  /// Access the Chi^2 of the track fit
  float getChi2() const;

  /// Access the number of degrees of freedom of the track fit
  std::int32_t getNdf() const;

  /// Access the dEdx of the track
  float getDEdx() const;

  /// Access the error of dEdx
  float getDEdxError() const;

  /// Access the radius of the innermost hit that has been used in the track fit
  float getRadiusOfInnermostHit() const;

  std::size_t trackerHits_size() const;
  edm4hep::TrackerHit getTrackerHits(std::size_t) const;
  std::vector<edm4hep::TrackerHit>::const_iterator trackerHits_begin() const;
  std::vector<edm4hep::TrackerHit>::const_iterator trackerHits_end() const;
  podio::RelationRange<edm4hep::TrackerHit> getTrackerHits() const;
  std::size_t tracks_size() const;
  edm4hep::Track getTracks(std::size_t) const;
  std::vector<edm4hep::Track>::const_iterator tracks_begin() const;
  std::vector<edm4hep::Track>::const_iterator tracks_end() const;
  podio::RelationRange<edm4hep::Track> getTracks() const;
  std::size_t subdetectorHitNumbers_size() const;
  std::int32_t getSubdetectorHitNumbers(std::size_t) const;
  std::vector<std::int32_t>::const_iterator subdetectorHitNumbers_begin() const;
  std::vector<std::int32_t>::const_iterator subdetectorHitNumbers_end() const;
  podio::RelationRange<std::int32_t> getSubdetectorHitNumbers() const;
  std::size_t trackStates_size() const;
  edm4hep::TrackState getTrackStates(std::size_t) const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_begin() const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_end() const;
  podio::RelationRange<edm4hep::TrackState> getTrackStates() const;
  std::size_t dxQuantities_size() const;
  edm4hep::Quantity getDxQuantities(std::size_t) const;
  std::vector<edm4hep::Quantity>::const_iterator dxQuantities_begin() const;
  std::vector<edm4hep::Quantity>::const_iterator dxQuantities_end() const;
  podio::RelationRange<edm4hep::Quantity> getDxQuantities() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackObj>{nullptr};
  }

  bool operator==(const Track& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableTrack& other) const;

  bool operator!=(const Track& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableTrack& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const Track& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(Track& a, Track& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackObj
  explicit Track(podio::utils::MaybeSharedPtr<TrackObj> obj);
  Track(TrackObj* obj);

  podio::utils::MaybeSharedPtr<TrackObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const Track& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Track& value);
#endif

} // namespace edm4hep

#endif
