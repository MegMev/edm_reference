// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableTimeSeries_H
#define EDM4HEP_MutableTimeSeries_H

#include "edm4hep/TimeSeriesObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/TimeSeries.h"

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

/** @class MutableTimeSeries
 *  Calibrated Detector Data
 *  @author: EDM4hep authors
 */
class MutableTimeSeries {

  friend class TimeSeriesCollection;
  friend class TimeSeriesMutableCollectionIterator;
  friend class TimeSeries;

public:
  using object_type = TimeSeries;
  using collection_type = TimeSeriesCollection;

  /// default constructor
  MutableTimeSeries();

  /// Constructor initializing all members
  MutableTimeSeries(std::uint64_t cellID, float time, float interval);

  /// copy constructor
  MutableTimeSeries(const MutableTimeSeries& other) = default;

  /// copy-assignment operator
  MutableTimeSeries& operator=(MutableTimeSeries other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTimeSeries clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableTimeSeries() = default;

public:
  /// Access the cell id
  std::uint64_t getCellID() const;

  /// Access the begin time [ns]
  float getTime() const;

  /// Access the interval of each sampling [ns]
  float getInterval() const;

  /// Set the cell id
  void setCellID(std::uint64_t value);
  /// Get mutable reference to cell id
  std::uint64_t& getCellID();
  /// Get reference to cell id
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the begin time [ns]
  void setTime(float value);
  /// Get mutable reference to begin time [ns]
  float& getTime();
  /// Get reference to begin time [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the interval of each sampling [ns]
  void setInterval(float value);
  /// Get mutable reference to interval of each sampling [ns]
  float& getInterval();
  /// Get reference to interval of each sampling [ns]
  [[deprecated("use getInterval instead")]] float& interval();

  void addToAmplitude(const float&);
  std::size_t amplitude_size() const;
  float getAmplitude(std::size_t) const;
  std::vector<float>::const_iterator amplitude_begin() const;
  std::vector<float>::const_iterator amplitude_end() const;
  podio::RelationRange<float> getAmplitude() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TimeSeriesObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TimeSeriesObj>{nullptr};
  }

  bool operator==(const MutableTimeSeries& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const TimeSeries& other) const;

  bool operator!=(const MutableTimeSeries& other) const {
    return !(*this == other);
  }
  bool operator!=(const TimeSeries& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableTimeSeries& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableTimeSeries& a, MutableTimeSeries& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TimeSeriesObj
  explicit MutableTimeSeries(podio::utils::MaybeSharedPtr<TimeSeriesObj> obj);

  podio::utils::MaybeSharedPtr<TimeSeriesObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTimeSeries& value);
#endif

} // namespace edm4hep

#endif
