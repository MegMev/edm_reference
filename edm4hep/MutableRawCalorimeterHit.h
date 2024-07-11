// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableRawCalorimeterHit_H
#define EDM4HEP_MutableRawCalorimeterHit_H

#include "edm4hep/RawCalorimeterHitObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/RawCalorimeterHit.h"

#include <cstdint>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class MutableRawCalorimeterHit
 *  Raw calorimeter hit
 *  @author: EDM4hep authors
 */
class MutableRawCalorimeterHit {

  friend class RawCalorimeterHitCollection;
  friend class RawCalorimeterHitMutableCollectionIterator;
  friend class RawCalorimeterHit;

public:
  using object_type = RawCalorimeterHit;
  using collection_type = RawCalorimeterHitCollection;

  /// default constructor
  MutableRawCalorimeterHit();

  /// Constructor initializing all members
  MutableRawCalorimeterHit(std::uint64_t cellID, std::int32_t amplitude, std::int32_t timeStamp);

  /// copy constructor
  MutableRawCalorimeterHit(const MutableRawCalorimeterHit& other) = default;

  /// copy-assignment operator
  MutableRawCalorimeterHit& operator=(MutableRawCalorimeterHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRawCalorimeterHit clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableRawCalorimeterHit() = default;

public:
  /// Access the detector specific (geometrical) cell id
  std::uint64_t getCellID() const;

  /// Access the amplitude of the hit in ADC counts
  std::int32_t getAmplitude() const;

  /// Access the time stamp for the hit
  std::int32_t getTimeStamp() const;

  /// Set the detector specific (geometrical) cell id
  void setCellID(std::uint64_t value);
  /// Get mutable reference to detector specific (geometrical) cell id
  std::uint64_t& getCellID();
  /// Get reference to detector specific (geometrical) cell id
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the amplitude of the hit in ADC counts
  void setAmplitude(std::int32_t value);
  /// Get mutable reference to amplitude of the hit in ADC counts
  std::int32_t& getAmplitude();
  /// Get reference to amplitude of the hit in ADC counts
  [[deprecated("use getAmplitude instead")]] std::int32_t& amplitude();

  /// Set the time stamp for the hit
  void setTimeStamp(std::int32_t value);
  /// Get mutable reference to time stamp for the hit
  std::int32_t& getTimeStamp();
  /// Get reference to time stamp for the hit
  [[deprecated("use getTimeStamp instead")]] std::int32_t& timeStamp();

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RawCalorimeterHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>{nullptr};
  }

  bool operator==(const MutableRawCalorimeterHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const RawCalorimeterHit& other) const;

  bool operator!=(const MutableRawCalorimeterHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const RawCalorimeterHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableRawCalorimeterHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableRawCalorimeterHit& a, MutableRawCalorimeterHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RawCalorimeterHitObj
  explicit MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr<RawCalorimeterHitObj> obj);

  podio::utils::MaybeSharedPtr<RawCalorimeterHitObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRawCalorimeterHit& value);
#endif

} // namespace edm4hep

#endif
