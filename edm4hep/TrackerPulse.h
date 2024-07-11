// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerPulse_H
#define EDM4HEP_TrackerPulse_H

#include "edm4hep/TrackerPulseObj.h"

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

class MutableTrackerPulse;
class TrackerPulseCollection;
class TrackerPulseCollectionData;

/** @class TrackerPulse
 *  Reconstructed Tracker Pulse
 *  @author: Wenxing Fang, IHEP
 */
class TrackerPulse {

  friend class MutableTrackerPulse;
  friend class TrackerPulseCollection;
  friend class edm4hep::TrackerPulseCollectionData;
  friend class TrackerPulseCollectionIterator;

public:
  using mutable_type = MutableTrackerPulse;
  using collection_type = TrackerPulseCollection;

  /// default constructor
  TrackerPulse();

  /// Constructor initializing all members
  TrackerPulse(std::uint64_t cellID, float time, float charge, std::int16_t quality, std::array<float, 3> covMatrix);

  /// copy constructor
  TrackerPulse(const TrackerPulse& other) = default;

  /// copy-assignment operator
  TrackerPulse& operator=(TrackerPulse other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrackerPulse clone(bool cloneRelations = true) const;

  /// destructor
  ~TrackerPulse() = default;

  /// converting constructor from mutable object
  TrackerPulse(const MutableTrackerPulse& other);

  static TrackerPulse makeEmpty();

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

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerPulseObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackerPulseObj>{nullptr};
  }

  bool operator==(const TrackerPulse& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableTrackerPulse& other) const;

  bool operator!=(const TrackerPulse& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableTrackerPulse& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const TrackerPulse& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(TrackerPulse& a, TrackerPulse& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackerPulseObj
  explicit TrackerPulse(podio::utils::MaybeSharedPtr<TrackerPulseObj> obj);
  TrackerPulse(TrackerPulseObj* obj);

  podio::utils::MaybeSharedPtr<TrackerPulseObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const TrackerPulse& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerPulse& value);
#endif

} // namespace edm4hep

#endif
