// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TimeSeries_H
#define EDM4HEP_TimeSeries_H

#include "edm4hep/TimeSeriesObj.h"

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

class MutableTimeSeries;
class TimeSeriesCollection;
class TimeSeriesCollectionData;

/** @class TimeSeries
 *  Calibrated Detector Data
 *  @author: EDM4hep authors
 */
class TimeSeries {

  friend class MutableTimeSeries;
  friend class TimeSeriesCollection;
  friend class edm4hep::TimeSeriesCollectionData;
  friend class TimeSeriesCollectionIterator;

public:
  using mutable_type = MutableTimeSeries;
  using collection_type = TimeSeriesCollection;

  /// default constructor
  TimeSeries();

  /// Constructor initializing all members
  TimeSeries(std::uint64_t cellID, float time, float interval);

  /// copy constructor
  TimeSeries(const TimeSeries& other) = default;

  /// copy-assignment operator
  TimeSeries& operator=(TimeSeries other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTimeSeries clone(bool cloneRelations = true) const;

  /// destructor
  ~TimeSeries() = default;

  /// converting constructor from mutable object
  TimeSeries(const MutableTimeSeries& other);

  static TimeSeries makeEmpty();

public:
  /// Access the cell id
  std::uint64_t getCellID() const;

  /// Access the begin time [ns]
  float getTime() const;

  /// Access the interval of each sampling [ns]
  float getInterval() const;

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

  bool operator==(const TimeSeries& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableTimeSeries& other) const;

  bool operator!=(const TimeSeries& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableTimeSeries& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const TimeSeries& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(TimeSeries& a, TimeSeries& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TimeSeriesObj
  explicit TimeSeries(podio::utils::MaybeSharedPtr<TimeSeriesObj> obj);
  TimeSeries(TimeSeriesObj* obj);

  podio::utils::MaybeSharedPtr<TimeSeriesObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const TimeSeries& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TimeSeries& value);
#endif

} // namespace edm4hep

#endif
