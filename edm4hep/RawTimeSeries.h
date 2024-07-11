// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawTimeSeries_H
#define EDM4HEP_RawTimeSeries_H

#include "edm4hep/RawTimeSeriesObj.h"

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

class MutableRawTimeSeries;
class RawTimeSeriesCollection;
class RawTimeSeriesCollectionData;

/** @class RawTimeSeries
 *  Raw data of a detector readout
 *  @author: EDM4hep authors
 */
class RawTimeSeries {

  friend class MutableRawTimeSeries;
  friend class RawTimeSeriesCollection;
  friend class edm4hep::RawTimeSeriesCollectionData;
  friend class RawTimeSeriesCollectionIterator;

public:
  using mutable_type = MutableRawTimeSeries;
  using collection_type = RawTimeSeriesCollection;

  /// default constructor
  RawTimeSeries();

  /// Constructor initializing all members
  RawTimeSeries(std::uint64_t cellID, std::int32_t quality, float time, float charge, float interval);

  /// copy constructor
  RawTimeSeries(const RawTimeSeries& other) = default;

  /// copy-assignment operator
  RawTimeSeries& operator=(RawTimeSeries other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRawTimeSeries clone(bool cloneRelations = true) const;

  /// destructor
  ~RawTimeSeries() = default;

  /// converting constructor from mutable object
  RawTimeSeries(const MutableRawTimeSeries& other);

  static RawTimeSeries makeEmpty();

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

  bool operator==(const RawTimeSeries& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableRawTimeSeries& other) const;

  bool operator!=(const RawTimeSeries& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableRawTimeSeries& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RawTimeSeries& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(RawTimeSeries& a, RawTimeSeries& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RawTimeSeriesObj
  explicit RawTimeSeries(podio::utils::MaybeSharedPtr<RawTimeSeriesObj> obj);
  RawTimeSeries(RawTimeSeriesObj* obj);

  podio::utils::MaybeSharedPtr<RawTimeSeriesObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const RawTimeSeries& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RawTimeSeries& value);
#endif

} // namespace edm4hep

#endif
