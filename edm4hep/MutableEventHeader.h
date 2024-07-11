// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableEventHeader_H
#define EDM4HEP_MutableEventHeader_H

#include "edm4hep/EventHeaderObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/EventHeader.h"

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

/** @class MutableEventHeader
 *  Event Header. Additional parameters are assumed to go into the metadata tree.
 *  @author: EDM4hep authors
 */
class MutableEventHeader {

  friend class EventHeaderCollection;
  friend class EventHeaderMutableCollectionIterator;
  friend class EventHeader;

public:
  using object_type = EventHeader;
  using collection_type = EventHeaderCollection;

  /// default constructor
  MutableEventHeader();

  /// Constructor initializing all members
  MutableEventHeader(std::int32_t eventNumber, std::int32_t runNumber, std::uint64_t timeStamp, double weight);

  /// copy constructor
  MutableEventHeader(const MutableEventHeader& other) = default;

  /// copy-assignment operator
  MutableEventHeader& operator=(MutableEventHeader other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableEventHeader clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableEventHeader() = default;

public:
  /// Access the event number
  std::int32_t getEventNumber() const;

  /// Access the run number
  std::int32_t getRunNumber() const;

  /// Access the time stamp
  std::uint64_t getTimeStamp() const;

  /// Access the event weight
  double getWeight() const;

  /// Set the event number
  void setEventNumber(std::int32_t value);
  /// Get mutable reference to event number
  std::int32_t& getEventNumber();
  /// Get reference to event number
  [[deprecated("use getEventNumber instead")]] std::int32_t& eventNumber();

  /// Set the run number
  void setRunNumber(std::int32_t value);
  /// Get mutable reference to run number
  std::int32_t& getRunNumber();
  /// Get reference to run number
  [[deprecated("use getRunNumber instead")]] std::int32_t& runNumber();

  /// Set the time stamp
  void setTimeStamp(std::uint64_t value);
  /// Get mutable reference to time stamp
  std::uint64_t& getTimeStamp();
  /// Get reference to time stamp
  [[deprecated("use getTimeStamp instead")]] std::uint64_t& timeStamp();

  /// Set the event weight
  void setWeight(double value);
  /// Get mutable reference to event weight
  double& getWeight();
  /// Get reference to event weight
  [[deprecated("use getWeight instead")]] double& weight();

  void addToWeights(const double&);
  std::size_t weights_size() const;
  double getWeights(std::size_t) const;
  std::vector<double>::const_iterator weights_begin() const;
  std::vector<double>::const_iterator weights_end() const;
  podio::RelationRange<double> getWeights() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from EventHeaderObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<EventHeaderObj>{nullptr};
  }

  bool operator==(const MutableEventHeader& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const EventHeader& other) const;

  bool operator!=(const MutableEventHeader& other) const {
    return !(*this == other);
  }
  bool operator!=(const EventHeader& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableEventHeader& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableEventHeader& a, MutableEventHeader& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing EventHeaderObj
  explicit MutableEventHeader(podio::utils::MaybeSharedPtr<EventHeaderObj> obj);

  podio::utils::MaybeSharedPtr<EventHeaderObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableEventHeader& value);
#endif

} // namespace edm4hep

#endif
