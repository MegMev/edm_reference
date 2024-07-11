// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableTrackerHit_H
#define EDM4HEP_MutableTrackerHit_H

#include "edm4hep/TrackerHitObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/TrackerHit.h"

#include "edm4hep/ObjectID.h"
#include "edm4hep/Vector3d.h"
#include "podio/RelationRange.h"
#include <array>
#include <cstdint>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class MutableTrackerHit
 *  Tracker hit
 *  @author: F.Gaede, DESY
 */
class MutableTrackerHit {

  friend class TrackerHitCollection;
  friend class TrackerHitMutableCollectionIterator;
  friend class TrackerHit;

public:
  using object_type = TrackerHit;
  using collection_type = TrackerHitCollection;

  /// default constructor
  MutableTrackerHit();

  /// Constructor initializing all members
  MutableTrackerHit(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep,
                    float eDepError, edm4hep::Vector3d position, std::array<float, 6> covMatrix);

  /// copy constructor
  MutableTrackerHit(const MutableTrackerHit& other) = default;

  /// copy-assignment operator
  MutableTrackerHit& operator=(MutableTrackerHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrackerHit clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableTrackerHit() = default;

public:
  /// Access the ID of the sensor that created this hit
  std::uint64_t getCellID() const;

  /// Access the type of raw data hit, either one of edm4hep::RawTimeSeries, edm4hep::SIMTRACKERHIT - see collection
  /// parameters "TrackerHitTypeNames" and "TrackerHitTypeValues".
  std::int32_t getType() const;

  /// Access the quality bit flag of the hit.
  std::int32_t getQuality() const;

  /// Access the time of the hit [ns].
  float getTime() const;

  /// Access the energy deposited on the hit [GeV].
  float getEDep() const;

  /// Access the error measured on EDep [GeV].
  float getEDepError() const;

  /// Access the hit position in [mm].
  const edm4hep::Vector3d& getPosition() const;

  /// Access the covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) , cov(y,x) ,
  /// cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)
  const std::array<float, 6>& getCovMatrix() const;
  /// Access item i of the covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) , cov(y,x)
  /// , cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)
  float getCovMatrix(size_t i) const;

  /// Set the ID of the sensor that created this hit
  void setCellID(std::uint64_t value);
  /// Get mutable reference to ID of the sensor that created this hit
  std::uint64_t& getCellID();
  /// Get reference to ID of the sensor that created this hit
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the type of raw data hit, either one of edm4hep::RawTimeSeries, edm4hep::SIMTRACKERHIT - see collection
  /// parameters "TrackerHitTypeNames" and "TrackerHitTypeValues".
  void setType(std::int32_t value);
  /// Get mutable reference to type of raw data hit, either one of edm4hep::RawTimeSeries, edm4hep::SIMTRACKERHIT - see
  /// collection parameters "TrackerHitTypeNames" and "TrackerHitTypeValues".
  std::int32_t& getType();
  /// Get reference to type of raw data hit, either one of edm4hep::RawTimeSeries, edm4hep::SIMTRACKERHIT - see
  /// collection parameters "TrackerHitTypeNames" and "TrackerHitTypeValues".
  [[deprecated("use getType instead")]] std::int32_t& type();

  /// Set the quality bit flag of the hit.
  void setQuality(std::int32_t value);
  /// Get mutable reference to quality bit flag of the hit.
  std::int32_t& getQuality();
  /// Get reference to quality bit flag of the hit.
  [[deprecated("use getQuality instead")]] std::int32_t& quality();

  /// Set the time of the hit [ns].
  void setTime(float value);
  /// Get mutable reference to time of the hit [ns].
  float& getTime();
  /// Get reference to time of the hit [ns].
  [[deprecated("use getTime instead")]] float& time();

  /// Set the energy deposited on the hit [GeV].
  void setEDep(float value);
  /// Get mutable reference to energy deposited on the hit [GeV].
  float& getEDep();
  /// Get reference to energy deposited on the hit [GeV].
  [[deprecated("use getEDep instead")]] float& eDep();

  /// Set the error measured on EDep [GeV].
  void setEDepError(float value);
  /// Get mutable reference to error measured on EDep [GeV].
  float& getEDepError();
  /// Get reference to error measured on EDep [GeV].
  [[deprecated("use getEDepError instead")]] float& eDepError();

  /// Set the hit position in [mm].
  void setPosition(edm4hep::Vector3d value);
  /// Get mutable reference to hit position in [mm].
  edm4hep::Vector3d& getPosition();
  /// Get reference to hit position in [mm].
  [[deprecated("use getPosition instead")]] edm4hep::Vector3d& position();

  /// Set the covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) , cov(y,x) , cov(y,y) ,
  /// cov(z,x) , cov(z,y) , cov(z,z)
  void setCovMatrix(std::array<float, 6> value);
  void setCovMatrix(size_t i, float value);
  /// Get mutable reference to covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) ,
  /// cov(y,x) , cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)
  std::array<float, 6>& getCovMatrix();
  /// Get reference to covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) , cov(y,x) ,
  /// cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)
  [[deprecated("use getCovMatrix instead")]] std::array<float, 6>& covMatrix();

  void addToRawHits(const edm4hep::ObjectID&);
  std::size_t rawHits_size() const;
  edm4hep::ObjectID getRawHits(std::size_t) const;
  std::vector<edm4hep::ObjectID>::const_iterator rawHits_begin() const;
  std::vector<edm4hep::ObjectID>::const_iterator rawHits_end() const;
  podio::RelationRange<edm4hep::ObjectID> getRawHits() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackerHitObj>{nullptr};
  }

  bool operator==(const MutableTrackerHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const TrackerHit& other) const;

  bool operator!=(const MutableTrackerHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const TrackerHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableTrackerHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableTrackerHit& a, MutableTrackerHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackerHitObj
  explicit MutableTrackerHit(podio::utils::MaybeSharedPtr<TrackerHitObj> obj);

  podio::utils::MaybeSharedPtr<TrackerHitObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerHit& value);
#endif

} // namespace edm4hep

#endif
