// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableSimCalorimeterHit_H
#define EDM4HEP_MutableSimCalorimeterHit_H

#include "edm4hep/SimCalorimeterHitObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/SimCalorimeterHit.h"

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

/** @class MutableSimCalorimeterHit
 *  Simulated calorimeter hit
 *  @author: EDM4hep authors
 */
class MutableSimCalorimeterHit {

  friend class SimCalorimeterHitCollection;
  friend class SimCalorimeterHitMutableCollectionIterator;
  friend class SimCalorimeterHit;

public:
  using object_type = SimCalorimeterHit;
  using collection_type = SimCalorimeterHitCollection;

  /// default constructor
  MutableSimCalorimeterHit();

  /// Constructor initializing all members
  MutableSimCalorimeterHit(std::uint64_t cellID, float energy, edm4hep::Vector3f position);

  /// copy constructor
  MutableSimCalorimeterHit(const MutableSimCalorimeterHit& other) = default;

  /// copy-assignment operator
  MutableSimCalorimeterHit& operator=(MutableSimCalorimeterHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableSimCalorimeterHit clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableSimCalorimeterHit() = default;

public:
  /// Access the ID of the sensor that created this hit
  std::uint64_t getCellID() const;

  /// Access the energy of the hit [GeV]
  float getEnergy() const;

  /// Access the position of the hit in world coordinates [mm]
  const edm4hep::Vector3f& getPosition() const;

  /// Set the ID of the sensor that created this hit
  void setCellID(std::uint64_t value);
  /// Get mutable reference to ID of the sensor that created this hit
  std::uint64_t& getCellID();
  /// Get reference to ID of the sensor that created this hit
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the energy of the hit [GeV]
  void setEnergy(float value);
  /// Get mutable reference to energy of the hit [GeV]
  float& getEnergy();
  /// Get reference to energy of the hit [GeV]
  [[deprecated("use getEnergy instead")]] float& energy();

  /// Set the position of the hit in world coordinates [mm]
  void setPosition(edm4hep::Vector3f value);
  /// Get mutable reference to position of the hit in world coordinates [mm]
  edm4hep::Vector3f& getPosition();
  /// Get reference to position of the hit in world coordinates [mm]
  [[deprecated("use getPosition instead")]] edm4hep::Vector3f& position();

  void addToContributions(const edm4hep::CaloHitContribution&);
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

  bool operator==(const MutableSimCalorimeterHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const SimCalorimeterHit& other) const;

  bool operator!=(const MutableSimCalorimeterHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const SimCalorimeterHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableSimCalorimeterHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableSimCalorimeterHit& a, MutableSimCalorimeterHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing SimCalorimeterHitObj
  explicit MutableSimCalorimeterHit(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj> obj);

  podio::utils::MaybeSharedPtr<SimCalorimeterHitObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableSimCalorimeterHit& value);
#endif

} // namespace edm4hep

#endif
