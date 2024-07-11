// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeader_H
#define EDM4HEP_EventHeader_H

#include "edm4hep/EventHeaderObj.h"

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

class MutableEventHeader;
class EventHeaderCollection;
class EventHeaderCollectionData;

/** @class EventHeader
 *  Event Header. Additional parameters are assumed to go into the metadata tree.
 *  @author: EDM4hep authors
 */
class EventHeader {

  friend class MutableEventHeader;
  friend class EventHeaderCollection;
  friend class edm4hep::EventHeaderCollectionData;
  friend class EventHeaderCollectionIterator;

public:
  using mutable_type = MutableEventHeader;
  using collection_type = EventHeaderCollection;

  /// default constructor
  EventHeader();

  /// Constructor initializing all members
  EventHeader(std::int32_t eventNumber, std::int32_t runNumber, std::uint64_t timeStamp, double weight);

  /// copy constructor
  EventHeader(const EventHeader& other) = default;

  /// copy-assignment operator
  EventHeader& operator=(EventHeader other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableEventHeader clone(bool cloneRelations = true) const;

  /// destructor
  ~EventHeader() = default;

  /// converting constructor from mutable object
  EventHeader(const MutableEventHeader& other);

  static EventHeader makeEmpty();

public:
  /// Access the event number
  std::int32_t getEventNumber() const;

  /// Access the run number
  std::int32_t getRunNumber() const;

  /// Access the time stamp
  std::uint64_t getTimeStamp() const;

  /// Access the event weight
  double getWeight() const;

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

  bool operator==(const EventHeader& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableEventHeader& other) const;

  bool operator!=(const EventHeader& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableEventHeader& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const EventHeader& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(EventHeader& a, EventHeader& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing EventHeaderObj
  explicit EventHeader(podio::utils::MaybeSharedPtr<EventHeaderObj> obj);
  EventHeader(EventHeaderObj* obj);

  podio::utils::MaybeSharedPtr<EventHeaderObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const EventHeader& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const EventHeader& value);
#endif

} // namespace edm4hep

#endif
