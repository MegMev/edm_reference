// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHit_H
#define EDM4HEP_SimCalorimeterHit_H

#include "edm4hep/SimCalorimeterHitObj.h"

#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/Vector3f.h"
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

class MutableSimCalorimeterHit;
class SimCalorimeterHitCollection;
class SimCalorimeterHitCollectionData;

/** @class SimCalorimeterHit
 *  Simulated calorimeter hit
 *  @author: EDM4hep authors
 */
class SimCalorimeterHit {

  friend class MutableSimCalorimeterHit;
  friend class SimCalorimeterHitCollection;
  friend class edm4hep::SimCalorimeterHitCollectionData;
  friend class SimCalorimeterHitCollectionIterator;

public:
  using mutable_type = MutableSimCalorimeterHit;
  using collection_type = SimCalorimeterHitCollection;

  /// default constructor
  SimCalorimeterHit();

  /// Constructor initializing all members
  SimCalorimeterHit(std::uint64_t cellID, float energy, edm4hep::Vector3f position);

  /// copy constructor
  SimCalorimeterHit(const SimCalorimeterHit& other) = default;

  /// copy-assignment operator
  SimCalorimeterHit& operator=(SimCalorimeterHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableSimCalorimeterHit clone(bool cloneRelations = true) const;

  /// destructor
  ~SimCalorimeterHit() = default;

  /// converting constructor from mutable object
  SimCalorimeterHit(const MutableSimCalorimeterHit& other);

  static SimCalorimeterHit makeEmpty();

public:
  /// Access the ID of the sensor that created this hit
  std::uint64_t getCellID() const;

  /// Access the energy of the hit [GeV]
  float getEnergy() const;

  /// Access the position of the hit in world coordinates [mm]
  const edm4hep::Vector3f& getPosition() const;

  std::size_t contributions_size() const;
  edm4hep::CaloHitContribution getContributions(std::size_t) const;
  std::vector<edm4hep::CaloHitContribution>::const_iterator contributions_begin() const;
  std::vector<edm4hep::CaloHitContribution>::const_iterator contributions_end() const;
  podio::RelationRange<edm4hep::CaloHitContribution> getContributions() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimCalorimeterHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<SimCalorimeterHitObj>{nullptr};
  }

  bool operator==(const SimCalorimeterHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableSimCalorimeterHit& other) const;

  bool operator!=(const SimCalorimeterHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableSimCalorimeterHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimCalorimeterHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(SimCalorimeterHit& a, SimCalorimeterHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing SimCalorimeterHitObj
  explicit SimCalorimeterHit(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj> obj);
  SimCalorimeterHit(SimCalorimeterHitObj* obj);

  podio::utils::MaybeSharedPtr<SimCalorimeterHitObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const SimCalorimeterHit& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimCalorimeterHit& value);
#endif

} // namespace edm4hep

#endif
