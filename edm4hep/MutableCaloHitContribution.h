// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableCaloHitContribution_H
#define EDM4HEP_MutableCaloHitContribution_H

#include "edm4hep/CaloHitContributionObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/CaloHitContribution.h"

#include "edm4hep/Vector3f.h"
#include <cstdint>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class MCParticle;
class MutableMCParticle;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableCaloHitContribution
 *  Monte Carlo contribution to SimCalorimeterHit
 *  @author: EDM4hep authors
 */
class MutableCaloHitContribution {

  friend class CaloHitContributionCollection;
  friend class CaloHitContributionMutableCollectionIterator;
  friend class CaloHitContribution;

public:
  using object_type = CaloHitContribution;
  using collection_type = CaloHitContributionCollection;

  /// default constructor
  MutableCaloHitContribution();

  /// Constructor initializing all members
  MutableCaloHitContribution(std::int32_t PDG, float energy, float time, edm4hep::Vector3f stepPosition);

  /// copy constructor
  MutableCaloHitContribution(const MutableCaloHitContribution& other) = default;

  /// copy-assignment operator
  MutableCaloHitContribution& operator=(MutableCaloHitContribution other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableCaloHitContribution clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableCaloHitContribution() = default;

public:
  /// Access the PDG code of the shower particle that caused this contribution
  std::int32_t getPDG() const;

  /// Access the energy of the this contribution [G]
  float getEnergy() const;

  /// Access the time of this contribution [ns]
  float getTime() const;

  /// Access the position of this energy deposition (step) [mm]
  const edm4hep::Vector3f& getStepPosition() const;

  /// Access the primary MCParticle that caused the shower responsible for this contribution to the hit
  const edm4hep::MCParticle getParticle() const;

  /// Set the PDG code of the shower particle that caused this contribution
  void setPDG(std::int32_t value);
  /// Get mutable reference to PDG code of the shower particle that caused this contribution
  std::int32_t& getPDG();
  /// Get reference to PDG code of the shower particle that caused this contribution
  [[deprecated("use getPDG instead")]] std::int32_t& PDG();

  /// Set the energy of the this contribution [G]
  void setEnergy(float value);
  /// Get mutable reference to energy of the this contribution [G]
  float& getEnergy();
  /// Get reference to energy of the this contribution [G]
  [[deprecated("use getEnergy instead")]] float& energy();

  /// Set the time of this contribution [ns]
  void setTime(float value);
  /// Get mutable reference to time of this contribution [ns]
  float& getTime();
  /// Get reference to time of this contribution [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the position of this energy deposition (step) [mm]
  void setStepPosition(edm4hep::Vector3f value);
  /// Get mutable reference to position of this energy deposition (step) [mm]
  edm4hep::Vector3f& getStepPosition();
  /// Get reference to position of this energy deposition (step) [mm]
  [[deprecated("use getStepPosition instead")]] edm4hep::Vector3f& stepPosition();

  /// Set the primary MCParticle that caused the shower responsible for this contribution to the hit
  void setParticle(const edm4hep::MCParticle& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CaloHitContributionObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<CaloHitContributionObj>{nullptr};
  }

  bool operator==(const MutableCaloHitContribution& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const CaloHitContribution& other) const;

  bool operator!=(const MutableCaloHitContribution& other) const {
    return !(*this == other);
  }
  bool operator!=(const CaloHitContribution& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableCaloHitContribution& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableCaloHitContribution& a, MutableCaloHitContribution& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing CaloHitContributionObj
  explicit MutableCaloHitContribution(podio::utils::MaybeSharedPtr<CaloHitContributionObj> obj);

  podio::utils::MaybeSharedPtr<CaloHitContributionObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableCaloHitContribution& value);
#endif

} // namespace edm4hep

#endif
