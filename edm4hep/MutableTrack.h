// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableTrack_H
#define EDM4HEP_MutableTrack_H

#include "edm4hep/TrackObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/Track.h"

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

/** @class MutableTrack
 *  Reconstructed track
 *  @author: EDM4hep authors
 */
class MutableTrack {

  friend class TrackCollection;
  friend class TrackMutableCollectionIterator;
  friend class Track;

public:
  using object_type = Track;
  using collection_type = TrackCollection;

  /// default constructor
  MutableTrack();

  /// Constructor initializing all members
  MutableTrack(std::int32_t type, float chi2, std::int32_t ndf, float dEdx, float dEdxError,
               float radiusOfInnermostHit);

  /// copy constructor
  MutableTrack(const MutableTrack& other) = default;

  /// copy-assignment operator
  MutableTrack& operator=(MutableTrack other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrack clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableTrack() = default;

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

  /// Set the flagword that defines the type of track
  void setType(std::int32_t value);
  /// Get mutable reference to flagword that defines the type of track
  std::int32_t& getType();
  /// Get reference to flagword that defines the type of track
  [[deprecated("use getType instead")]] std::int32_t& type();

  /// Set the Chi^2 of the track fit
  void setChi2(float value);
  /// Get mutable reference to Chi^2 of the track fit
  float& getChi2();
  /// Get reference to Chi^2 of the track fit
  [[deprecated("use getChi2 instead")]] float& chi2();

  /// Set the number of degrees of freedom of the track fit
  void setNdf(std::int32_t value);
  /// Get mutable reference to number of degrees of freedom of the track fit
  std::int32_t& getNdf();
  /// Get reference to number of degrees of freedom of the track fit
  [[deprecated("use getNdf instead")]] std::int32_t& ndf();

  /// Set the dEdx of the track
  void setDEdx(float value);
  /// Get mutable reference to dEdx of the track
  float& getDEdx();
  /// Get reference to dEdx of the track
  [[deprecated("use getDEdx instead")]] float& dEdx();

  /// Set the error of dEdx
  void setDEdxError(float value);
  /// Get mutable reference to error of dEdx
  float& getDEdxError();
  /// Get reference to error of dEdx
  [[deprecated("use getDEdxError instead")]] float& dEdxError();

  /// Set the radius of the innermost hit that has been used in the track fit
  void setRadiusOfInnermostHit(float value);
  /// Get mutable reference to radius of the innermost hit that has been used in the track fit
  float& getRadiusOfInnermostHit();
  /// Get reference to radius of the innermost hit that has been used in the track fit
  [[deprecated("use getRadiusOfInnermostHit instead")]] float& radiusOfInnermostHit();

  void addToTrackerHits(const edm4hep::TrackerHit&);
  std::size_t trackerHits_size() const;
  edm4hep::TrackerHit getTrackerHits(std::size_t) const;
  std::vector<edm4hep::TrackerHit>::const_iterator trackerHits_begin() const;
  std::vector<edm4hep::TrackerHit>::const_iterator trackerHits_end() const;
  podio::RelationRange<edm4hep::TrackerHit> getTrackerHits() const;
  void addToTracks(const edm4hep::Track&);
  std::size_t tracks_size() const;
  edm4hep::Track getTracks(std::size_t) const;
  std::vector<edm4hep::Track>::const_iterator tracks_begin() const;
  std::vector<edm4hep::Track>::const_iterator tracks_end() const;
  podio::RelationRange<edm4hep::Track> getTracks() const;
  void addToSubdetectorHitNumbers(const std::int32_t&);
  std::size_t subdetectorHitNumbers_size() const;
  std::int32_t getSubdetectorHitNumbers(std::size_t) const;
  std::vector<std::int32_t>::const_iterator subdetectorHitNumbers_begin() const;
  std::vector<std::int32_t>::const_iterator subdetectorHitNumbers_end() const;
  podio::RelationRange<std::int32_t> getSubdetectorHitNumbers() const;
  void addToTrackStates(const edm4hep::TrackState&);
  std::size_t trackStates_size() const;
  edm4hep::TrackState getTrackStates(std::size_t) const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_begin() const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_end() const;
  podio::RelationRange<edm4hep::TrackState> getTrackStates() const;
  void addToDxQuantities(const edm4hep::Quantity&);
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

  bool operator==(const MutableTrack& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const Track& other) const;

  bool operator!=(const MutableTrack& other) const {
    return !(*this == other);
  }
  bool operator!=(const Track& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableTrack& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableTrack& a, MutableTrack& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackObj
  explicit MutableTrack(podio::utils::MaybeSharedPtr<TrackObj> obj);

  podio::utils::MaybeSharedPtr<TrackObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrack& value);
#endif

} // namespace edm4hep

#endif
