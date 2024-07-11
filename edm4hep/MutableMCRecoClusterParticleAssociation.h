// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoClusterParticleAssociation_H
#define EDM4HEP_MutableMCRecoClusterParticleAssociation_H

#include "edm4hep/MCRecoClusterParticleAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoClusterParticleAssociation.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class Cluster;
class MutableCluster;
class MCParticle;
class MutableMCParticle;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableMCRecoClusterParticleAssociation
 *  Association between a Cluster and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MutableMCRecoClusterParticleAssociation {

  friend class MCRecoClusterParticleAssociationCollection;
  friend class MCRecoClusterParticleAssociationMutableCollectionIterator;
  friend class MCRecoClusterParticleAssociation;

public:
  using object_type = MCRecoClusterParticleAssociation;
  using collection_type = MCRecoClusterParticleAssociationCollection;

  /// default constructor
  MutableMCRecoClusterParticleAssociation();

  /// Constructor initializing all members
  MutableMCRecoClusterParticleAssociation(float weight);

  /// copy constructor
  MutableMCRecoClusterParticleAssociation(const MutableMCRecoClusterParticleAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoClusterParticleAssociation& operator=(MutableMCRecoClusterParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoClusterParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoClusterParticleAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the cluster
  const edm4hep::Cluster getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the cluster
  void setRec(const edm4hep::Cluster& value);
  /// Set the reference to the Monte-Carlo particle
  void setSim(const edm4hep::MCParticle& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoClusterParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoClusterParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoClusterParticleAssociation& other) const;

  bool operator!=(const MutableMCRecoClusterParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoClusterParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoClusterParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoClusterParticleAssociation& a, MutableMCRecoClusterParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoClusterParticleAssociationObj
  explicit MutableMCRecoClusterParticleAssociation(
      podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoClusterParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
