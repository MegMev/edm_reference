// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoClusterParticleAssociation_H
#define EDM4HEP_MCRecoClusterParticleAssociation_H

#include "edm4hep/MCRecoClusterParticleAssociationObj.h"

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

class MutableMCRecoClusterParticleAssociation;
class MCRecoClusterParticleAssociationCollection;
class MCRecoClusterParticleAssociationCollectionData;

/** @class MCRecoClusterParticleAssociation
 *  Association between a Cluster and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MCRecoClusterParticleAssociation {

  friend class MutableMCRecoClusterParticleAssociation;
  friend class MCRecoClusterParticleAssociationCollection;
  friend class edm4hep::MCRecoClusterParticleAssociationCollectionData;
  friend class MCRecoClusterParticleAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoClusterParticleAssociation;
  using collection_type = MCRecoClusterParticleAssociationCollection;

  /// default constructor
  MCRecoClusterParticleAssociation();

  /// Constructor initializing all members
  MCRecoClusterParticleAssociation(float weight);

  /// copy constructor
  MCRecoClusterParticleAssociation(const MCRecoClusterParticleAssociation& other) = default;

  /// copy-assignment operator
  MCRecoClusterParticleAssociation& operator=(MCRecoClusterParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoClusterParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoClusterParticleAssociation() = default;

  /// converting constructor from mutable object
  MCRecoClusterParticleAssociation(const MutableMCRecoClusterParticleAssociation& other);

  static MCRecoClusterParticleAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the cluster
  const edm4hep::Cluster getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoClusterParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoClusterParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoClusterParticleAssociation& other) const;

  bool operator!=(const MCRecoClusterParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoClusterParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoClusterParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoClusterParticleAssociation& a, MCRecoClusterParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoClusterParticleAssociationObj
  explicit MCRecoClusterParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj> obj);
  MCRecoClusterParticleAssociation(MCRecoClusterParticleAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoClusterParticleAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoClusterParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
