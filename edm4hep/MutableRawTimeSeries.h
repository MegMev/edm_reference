// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableRawTimeSeries_H
#define EDM4HEP_MutableRawTimeSeries_H

#include "edm4hep/RawTimeSeriesObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/RawTimeSeries.h"

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

/** @class MutableRawTimeSeries
 *  Raw data of a detector readout
 *  @author: EDM4hep authors
 */
class MutableRawTimeSeries {

  friend class RawTimeSeriesCollection;
  friend class RawTimeSeriesMutableCollectionIterator;
  friend class RawTimeSeries;

public:
  using object_type = RawTimeSeries;
  using collection_type = RawTimeSeriesCollection;

  /// default constructor
  MutableRawTimeSeries();

  /// Constructor initializing all members
  MutableRawTimeSeries(std::uint64_t cellID, std::int32_t quality, float time, float charge, float interval);

  /// copy constructor
  MutableRawTimeSeries(const MutableRawTimeSeries& other) = default;

  /// copy-assignment operator
  MutableRawTimeSeries& operator=(MutableRawTimeSeries other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRawTimeSeries clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableRawTimeSeries() = default;

public:
  /// Access the detector specific cell id
  std::uint64_t getCellID() const;

  /// Access the quality flag for the hit
  std::int32_t getQuality() const;

  /// Access the time of the hit [ns]
  float getTime() const;

  /// Access the integrated charge of the hit [fC]
  float getCharge() const;

  /// Access the interval of each sampling [ns]
  float getInterval() const;

  /// Set the detector specific cell id
  void setCellID(std::uint64_t value);
  /// Get mutable reference to detector specific cell id
  std::uint64_t& getCellID();
  /// Get reference to detector specific cell id
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the quality flag for the hit
  void setQuality(std::int32_t value);
  /// Get mutable reference to quality flag for the hit
  std::int32_t& getQuality();
  /// Get reference to quality flag for the hit
  [[deprecated("use getQuality instead")]] std::int32_t& quality();

  /// Set the time of the hit [ns]
  void setTime(float value);
  /// Get mutable reference to time of the hit [ns]
  float& getTime();
  /// Get reference to time of the hit [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the integrated charge of the hit [fC]
  void setCharge(float value);
  /// Get mutable reference to integrated charge of the hit [fC]
  float& getCharge();
  /// Get reference to integrated charge of the hit [fC]
  [[deprecated("use getCharge instead")]] float& charge();

  /// Set the interval of each sampling [ns]
  void setInterval(float value);
  /// Get mutable reference to interval of each sampling [ns]
  float& getInterval();
  /// Get reference to interval of each sampling [ns]
  [[deprecated("use getInterval instead")]] float& interval();

  void addToAdcCounts(const std::int32_t&);
  std::size_t adcCounts_size() const;
  std::int32_t getAdcCounts(std::size_t) const;
  std::vector<std::int32_t>::const_iterator adcCounts_begin() const;
  std::vector<std::int32_t>::const_iterator adcCounts_end() const;
  podio::RelationRange<std::int32_t> getAdcCounts() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RawTimeSeriesObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RawTimeSeriesObj>{nullptr};
  }

  bool operator==(const MutableRawTimeSeries& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const RawTimeSeries& other) const;

  bool operator!=(const MutableRawTimeSeries& other) const {
    return !(*this == other);
  }
  bool operator!=(const RawTimeSeries& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableRawTimeSeries& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableRawTimeSeries& a, MutableRawTimeSeries& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RawTimeSeriesObj
  explicit MutableRawTimeSeries(podio::utils::MaybeSharedPtr<RawTimeSeriesObj> obj);

  podio::utils::MaybeSharedPtr<RawTimeSeriesObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRawTimeSeries& value);
#endif

} // namespace edm4hep

#endif
