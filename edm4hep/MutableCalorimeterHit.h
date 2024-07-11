// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableCalorimeterHit_H
#define EDM4HEP_MutableCalorimeterHit_H

#include "edm4hep/CalorimeterHitObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/CalorimeterHit.h"

#include "edm4hep/Vector3f.h"
#include <cstdint>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class MutableCalorimeterHit
 *  Calorimeter hit
 *  @author: EDM4hep authors
 */
class MutableCalorimeterHit {

  friend class CalorimeterHitCollection;
  friend class CalorimeterHitMutableCollectionIterator;
  friend class CalorimeterHit;

public:
  using object_type = CalorimeterHit;
  using collection_type = CalorimeterHitCollection;

  /// default constructor
  MutableCalorimeterHit();

  /// Constructor initializing all members
  MutableCalorimeterHit(std::uint64_t cellID, float energy, float energyError, float time, edm4hep::Vector3f position,
                        std::int32_t type);

  /// copy constructor
  MutableCalorimeterHit(const MutableCalorimeterHit& other) = default;

  /// copy-assignment operator
  MutableCalorimeterHit& operator=(MutableCalorimeterHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableCalorimeterHit clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableCalorimeterHit() = default;

public:
  /// Access the detector specific (geometrical) cell id
  std::uint64_t getCellID() const;

  /// Access the energy of the hit [GeV]
  float getEnergy() const;

  /// Access the error of the hit energy [GeV]
  float getEnergyError() const;

  /// Access the time of the hit [ns]
  float getTime() const;

  /// Access the position of the hit in world coordinates [mm]
  const edm4hep::Vector3f& getPosition() const;

  /// Access the type of hit
  std::int32_t getType() const;

  /// Set the detector specific (geometrical) cell id
  void setCellID(std::uint64_t value);
  /// Get mutable reference to detector specific (geometrical) cell id
  std::uint64_t& getCellID();
  /// Get reference to detector specific (geometrical) cell id
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the energy of the hit [GeV]
  void setEnergy(float value);
  /// Get mutable reference to energy of the hit [GeV]
  float& getEnergy();
  /// Get reference to energy of the hit [GeV]
  [[deprecated("use getEnergy instead")]] float& energy();

  /// Set the error of the hit energy [GeV]
  void setEnergyError(float value);
  /// Get mutable reference to error of the hit energy [GeV]
  float& getEnergyError();
  /// Get reference to error of the hit energy [GeV]
  [[deprecated("use getEnergyError instead")]] float& energyError();

  /// Set the time of the hit [ns]
  void setTime(float value);
  /// Get mutable reference to time of the hit [ns]
  float& getTime();
  /// Get reference to time of the hit [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the position of the hit in world coordinates [mm]
  void setPosition(edm4hep::Vector3f value);
  /// Get mutable reference to position of the hit in world coordinates [mm]
  edm4hep::Vector3f& getPosition();
  /// Get reference to position of the hit in world coordinates [mm]
  [[deprecated("use getPosition instead")]] edm4hep::Vector3f& position();

  /// Set the type of hit
  void setType(std::int32_t value);
  /// Get mutable reference to type of hit
  std::int32_t& getType();
  /// Get reference to type of hit
  [[deprecated("use getType instead")]] std::int32_t& type();

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CalorimeterHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<CalorimeterHitObj>{nullptr};
  }

  bool operator==(const MutableCalorimeterHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const CalorimeterHit& other) const;

  bool operator!=(const MutableCalorimeterHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const CalorimeterHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableCalorimeterHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableCalorimeterHit& a, MutableCalorimeterHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing CalorimeterHitObj
  explicit MutableCalorimeterHit(podio::utils::MaybeSharedPtr<CalorimeterHitObj> obj);

  podio::utils::MaybeSharedPtr<CalorimeterHitObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableCalorimeterHit& value);
#endif

} // namespace edm4hep

#endif
