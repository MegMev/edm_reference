// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContribution_H
#define EDM4HEP_CaloHitContribution_H

#include "edm4hep/CaloHitContributionObj.h"

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

class MutableCaloHitContribution;
class CaloHitContributionCollection;
class CaloHitContributionCollectionData;

/** @class CaloHitContribution
 *  Monte Carlo contribution to SimCalorimeterHit
 *  @author: EDM4hep authors
 */
class CaloHitContribution {

  friend class MutableCaloHitContribution;
  friend class CaloHitContributionCollection;
  friend class edm4hep::CaloHitContributionCollectionData;
  friend class CaloHitContributionCollectionIterator;

public:
  using mutable_type = MutableCaloHitContribution;
  using collection_type = CaloHitContributionCollection;

  /// default constructor
  CaloHitContribution();

  /// Constructor initializing all members
  CaloHitContribution(std::int32_t PDG, float energy, float time, edm4hep::Vector3f stepPosition);

  /// copy constructor
  CaloHitContribution(const CaloHitContribution& other) = default;

  /// copy-assignment operator
  CaloHitContribution& operator=(CaloHitContribution other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableCaloHitContribution clone(bool cloneRelations = true) const;

  /// destructor
  ~CaloHitContribution() = default;

  /// converting constructor from mutable object
  CaloHitContribution(const MutableCaloHitContribution& other);

  static CaloHitContribution makeEmpty();

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

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CaloHitContributionObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<CaloHitContributionObj>{nullptr};
  }

  bool operator==(const CaloHitContribution& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableCaloHitContribution& other) const;

  bool operator!=(const CaloHitContribution& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableCaloHitContribution& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const CaloHitContribution& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(CaloHitContribution& a, CaloHitContribution& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing CaloHitContributionObj
  explicit CaloHitContribution(podio::utils::MaybeSharedPtr<CaloHitContributionObj> obj);
  CaloHitContribution(CaloHitContributionObj* obj);

  podio::utils::MaybeSharedPtr<CaloHitContributionObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const CaloHitContribution& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const CaloHitContribution& value);
#endif

} // namespace edm4hep

#endif
