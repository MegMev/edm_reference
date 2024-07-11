// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHit_H
#define EDM4HEP_CalorimeterHit_H

#include "edm4hep/CalorimeterHitObj.h"

#include "edm4hep/Vector3f.h"
#include <cstdint>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableCalorimeterHit;
class CalorimeterHitCollection;
class CalorimeterHitCollectionData;

/** @class CalorimeterHit
 *  Calorimeter hit
 *  @author: EDM4hep authors
 */
class CalorimeterHit {

  friend class MutableCalorimeterHit;
  friend class CalorimeterHitCollection;
  friend class edm4hep::CalorimeterHitCollectionData;
  friend class CalorimeterHitCollectionIterator;

public:
  using mutable_type = MutableCalorimeterHit;
  using collection_type = CalorimeterHitCollection;

  /// default constructor
  CalorimeterHit();

  /// Constructor initializing all members
  CalorimeterHit(std::uint64_t cellID, float energy, float energyError, float time, edm4hep::Vector3f position,
                 std::int32_t type);

  /// copy constructor
  CalorimeterHit(const CalorimeterHit& other) = default;

  /// copy-assignment operator
  CalorimeterHit& operator=(CalorimeterHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableCalorimeterHit clone(bool cloneRelations = true) const;

  /// destructor
  ~CalorimeterHit() = default;

  /// converting constructor from mutable object
  CalorimeterHit(const MutableCalorimeterHit& other);

  static CalorimeterHit makeEmpty();

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

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CalorimeterHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<CalorimeterHitObj>{nullptr};
  }

  bool operator==(const CalorimeterHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableCalorimeterHit& other) const;

  bool operator!=(const CalorimeterHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableCalorimeterHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const CalorimeterHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(CalorimeterHit& a, CalorimeterHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing CalorimeterHitObj
  explicit CalorimeterHit(podio::utils::MaybeSharedPtr<CalorimeterHitObj> obj);
  CalorimeterHit(CalorimeterHitObj* obj);

  podio::utils::MaybeSharedPtr<CalorimeterHitObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const CalorimeterHit& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const CalorimeterHit& value);
#endif

} // namespace edm4hep

#endif
