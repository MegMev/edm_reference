// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoParticleAssociation_H
#define EDM4HEP_MutableMCRecoParticleAssociation_H

#include "edm4hep/MCRecoParticleAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoParticleAssociation.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class MutableReconstructedParticle;
class MCParticle;
class MutableMCParticle;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableMCRecoParticleAssociation
 *  Association between a ReconstructedParticle and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MutableMCRecoParticleAssociation {

  friend class MCRecoParticleAssociationCollection;
  friend class MCRecoParticleAssociationMutableCollectionIterator;
  friend class MCRecoParticleAssociation;

public:
  using object_type = MCRecoParticleAssociation;
  using collection_type = MCRecoParticleAssociationCollection;

  /// default constructor
  MutableMCRecoParticleAssociation();

  /// Constructor initializing all members
  MutableMCRecoParticleAssociation(float weight);

  /// copy constructor
  MutableMCRecoParticleAssociation(const MutableMCRecoParticleAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoParticleAssociation& operator=(MutableMCRecoParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoParticleAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed particle
  const edm4hep::ReconstructedParticle getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the reconstructed particle
  void setRec(const edm4hep::ReconstructedParticle& value);
  /// Set the reference to the Monte-Carlo particle
  void setSim(const edm4hep::MCParticle& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoParticleAssociation& other) const;

  bool operator!=(const MutableMCRecoParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoParticleAssociation& a, MutableMCRecoParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoParticleAssociationObj
  explicit MutableMCRecoParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
