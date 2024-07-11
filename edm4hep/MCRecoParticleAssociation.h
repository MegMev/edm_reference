// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoParticleAssociation_H
#define EDM4HEP_MCRecoParticleAssociation_H

#include "edm4hep/MCRecoParticleAssociationObj.h"

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

class MutableMCRecoParticleAssociation;
class MCRecoParticleAssociationCollection;
class MCRecoParticleAssociationCollectionData;

/** @class MCRecoParticleAssociation
 *  Association between a ReconstructedParticle and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MCRecoParticleAssociation {

  friend class MutableMCRecoParticleAssociation;
  friend class MCRecoParticleAssociationCollection;
  friend class edm4hep::MCRecoParticleAssociationCollectionData;
  friend class MCRecoParticleAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoParticleAssociation;
  using collection_type = MCRecoParticleAssociationCollection;

  /// default constructor
  MCRecoParticleAssociation();

  /// Constructor initializing all members
  MCRecoParticleAssociation(float weight);

  /// copy constructor
  MCRecoParticleAssociation(const MCRecoParticleAssociation& other) = default;

  /// copy-assignment operator
  MCRecoParticleAssociation& operator=(MCRecoParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoParticleAssociation() = default;

  /// converting constructor from mutable object
  MCRecoParticleAssociation(const MutableMCRecoParticleAssociation& other);

  static MCRecoParticleAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed particle
  const edm4hep::ReconstructedParticle getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoParticleAssociation& other) const;

  bool operator!=(const MCRecoParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoParticleAssociation& a, MCRecoParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoParticleAssociationObj
  explicit MCRecoParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj> obj);
  MCRecoParticleAssociation(MCRecoParticleAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoParticleAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
