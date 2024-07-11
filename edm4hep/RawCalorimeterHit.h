// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawCalorimeterHit_H
#define EDM4HEP_RawCalorimeterHit_H

#include "edm4hep/RawCalorimeterHitObj.h"

#include <cstdint>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableRawCalorimeterHit;
class RawCalorimeterHitCollection;
class RawCalorimeterHitCollectionData;

/** @class RawCalorimeterHit
 *  Raw calorimeter hit
 *  @author: EDM4hep authors
 */
class RawCalorimeterHit {

  friend class MutableRawCalorimeterHit;
  friend class RawCalorimeterHitCollection;
  friend class edm4hep::RawCalorimeterHitCollectionData;
  friend class RawCalorimeterHitCollectionIterator;

public:
  using mutable_type = MutableRawCalorimeterHit;
  using collection_type = RawCalorimeterHitCollection;

  /// default constructor
  RawCalorimeterHit();

  /// Constructor initializing all members
  RawCalorimeterHit(std::uint64_t cellID, std::int32_t amplitude, std::int32_t timeStamp);

  /// copy constructor
  RawCalorimeterHit(const RawCalorimeterHit& other) = default;

  /// copy-assignment operator
  RawCalorimeterHit& operator=(RawCalorimeterHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRawCalorimeterHit clone(bool cloneRelations = true) const;

  /// destructor
  ~RawCalorimeterHit() = default;

  /// converting constructor from mutable object
  RawCalorimeterHit(const MutableRawCalorimeterHit& other);

  static RawCalorimeterHit makeEmpty();

public:
  /// Access the detector specific (geometrical) cell id
  std::uint64_t getCellID() const;

  /// Access the amplitude of the hit in ADC counts
  std::int32_t getAmplitude() const;

  /// Access the time stamp for the hit
  std::int32_t getTimeStamp() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RawCalorimeterHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>{nullptr};
  }

  bool operator==(const RawCalorimeterHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableRawCalorimeterHit& other) const;

  bool operator!=(const RawCalorimeterHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableRawCalorimeterHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RawCalorimeterHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(RawCalorimeterHit& a, RawCalorimeterHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RawCalorimeterHitObj
  explicit RawCalorimeterHit(podio::utils::MaybeSharedPtr<RawCalorimeterHitObj> obj);
  RawCalorimeterHit(RawCalorimeterHitObj* obj);

  podio::utils::MaybeSharedPtr<RawCalorimeterHitObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const RawCalorimeterHit& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RawCalorimeterHit& value);
#endif

} // namespace edm4hep

#endif
