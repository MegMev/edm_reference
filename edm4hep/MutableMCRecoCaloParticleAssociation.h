// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoCaloParticleAssociation_H
#define EDM4HEP_MutableMCRecoCaloParticleAssociation_H

#include "edm4hep/MCRecoCaloParticleAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoCaloParticleAssociation.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class CalorimeterHit;
class MutableCalorimeterHit;
class MCParticle;
class MutableMCParticle;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableMCRecoCaloParticleAssociation
 *  Association between a CalorimeterHit and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MutableMCRecoCaloParticleAssociation {

  friend class MCRecoCaloParticleAssociationCollection;
  friend class MCRecoCaloParticleAssociationMutableCollectionIterator;
  friend class MCRecoCaloParticleAssociation;

public:
  using object_type = MCRecoCaloParticleAssociation;
  using collection_type = MCRecoCaloParticleAssociationCollection;

  /// default constructor
  MutableMCRecoCaloParticleAssociation();

  /// Constructor initializing all members
  MutableMCRecoCaloParticleAssociation(float weight);

  /// copy constructor
  MutableMCRecoCaloParticleAssociation(const MutableMCRecoCaloParticleAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoCaloParticleAssociation& operator=(MutableMCRecoCaloParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoCaloParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoCaloParticleAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::CalorimeterHit getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the reconstructed hit
  void setRec(const edm4hep::CalorimeterHit& value);
  /// Set the reference to the Monte-Carlo particle
  void setSim(const edm4hep::MCParticle& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoCaloParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoCaloParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoCaloParticleAssociation& other) const;

  bool operator!=(const MutableMCRecoCaloParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoCaloParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoCaloParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoCaloParticleAssociation& a, MutableMCRecoCaloParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoCaloParticleAssociationObj
  explicit MutableMCRecoCaloParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoCaloParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
