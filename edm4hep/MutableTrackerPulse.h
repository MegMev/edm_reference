// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableTrackerPulse_H
#define EDM4HEP_MutableTrackerPulse_H

#include "edm4hep/TrackerPulseObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/TrackerPulse.h"

#include <array>
#include <cstdint>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class TimeSeries;
class MutableTimeSeries;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableTrackerPulse
 *  Reconstructed Tracker Pulse
 *  @author: Wenxing Fang, IHEP
 */
class MutableTrackerPulse {

  friend class TrackerPulseCollection;
  friend class TrackerPulseMutableCollectionIterator;
  friend class TrackerPulse;

public:
  using object_type = TrackerPulse;
  using collection_type = TrackerPulseCollection;

  /// default constructor
  MutableTrackerPulse();

  /// Constructor initializing all members
  MutableTrackerPulse(std::uint64_t cellID, float time, float charge, std::int16_t quality,
                      std::array<float, 3> covMatrix);

  /// copy constructor
  MutableTrackerPulse(const MutableTrackerPulse& other) = default;

  /// copy-assignment operator
  MutableTrackerPulse& operator=(MutableTrackerPulse other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrackerPulse clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableTrackerPulse() = default;

public:
  /// Access the cell id.
  std::uint64_t getCellID() const;

  /// Access the time [ns].
  float getTime() const;

  /// Access the charge [fC].
  float getCharge() const;

  /// Access the quality.
  std::int16_t getQuality() const;

  /// Access the lower triangle covariance matrix of the charge(c) and time(t) measurements.
  const std::array<float, 3>& getCovMatrix() const;
  /// Access item i of the lower triangle covariance matrix of the charge(c) and time(t) measurements.
  float getCovMatrix(size_t i) const;

  /// Access the Optionally, the timeSeries that has been used to create the pulse can be stored with the pulse.
  const edm4hep::TimeSeries getTimeSeries() const;

  /// Set the cell id.
  void setCellID(std::uint64_t value);
  /// Get mutable reference to cell id.
  std::uint64_t& getCellID();
  /// Get reference to cell id.
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the time [ns].
  void setTime(float value);
  /// Get mutable reference to time [ns].
  float& getTime();
  /// Get reference to time [ns].
  [[deprecated("use getTime instead")]] float& time();

  /// Set the charge [fC].
  void setCharge(float value);
  /// Get mutable reference to charge [fC].
  float& getCharge();
  /// Get reference to charge [fC].
  [[deprecated("use getCharge instead")]] float& charge();

  /// Set the quality.
  void setQuality(std::int16_t value);
  /// Get mutable reference to quality.
  std::int16_t& getQuality();
  /// Get reference to quality.
  [[deprecated("use getQuality instead")]] std::int16_t& quality();

  /// Set the lower triangle covariance matrix of the charge(c) and time(t) measurements.
  void setCovMatrix(std::array<float, 3> value);
  void setCovMatrix(size_t i, float value);
  /// Get mutable reference to lower triangle covariance matrix of the charge(c) and time(t) measurements.
  std::array<float, 3>& getCovMatrix();
  /// Get reference to lower triangle covariance matrix of the charge(c) and time(t) measurements.
  [[deprecated("use getCovMatrix instead")]] std::array<float, 3>& covMatrix();

  /// Set the Optionally, the timeSeries that has been used to create the pulse can be stored with the pulse.
  void setTimeSeries(const edm4hep::TimeSeries& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerPulseObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackerPulseObj>{nullptr};
  }

  bool operator==(const MutableTrackerPulse& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const TrackerPulse& other) const;

  bool operator!=(const MutableTrackerPulse& other) const {
    return !(*this == other);
  }
  bool operator!=(const TrackerPulse& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableTrackerPulse& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableTrackerPulse& a, MutableTrackerPulse& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackerPulseObj
  explicit MutableTrackerPulse(podio::utils::MaybeSharedPtr<TrackerPulseObj> obj);

  podio::utils::MaybeSharedPtr<TrackerPulseObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerPulse& value);
#endif

} // namespace edm4hep

#endif
