// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloParticleAssociation_H
#define EDM4HEP_MCRecoCaloParticleAssociation_H

#include "edm4hep/MCRecoCaloParticleAssociationObj.h"

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

class MutableMCRecoCaloParticleAssociation;
class MCRecoCaloParticleAssociationCollection;
class MCRecoCaloParticleAssociationCollectionData;

/** @class MCRecoCaloParticleAssociation
 *  Association between a CalorimeterHit and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MCRecoCaloParticleAssociation {

  friend class MutableMCRecoCaloParticleAssociation;
  friend class MCRecoCaloParticleAssociationCollection;
  friend class edm4hep::MCRecoCaloParticleAssociationCollectionData;
  friend class MCRecoCaloParticleAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoCaloParticleAssociation;
  using collection_type = MCRecoCaloParticleAssociationCollection;

  /// default constructor
  MCRecoCaloParticleAssociation();

  /// Constructor initializing all members
  MCRecoCaloParticleAssociation(float weight);

  /// copy constructor
  MCRecoCaloParticleAssociation(const MCRecoCaloParticleAssociation& other) = default;

  /// copy-assignment operator
  MCRecoCaloParticleAssociation& operator=(MCRecoCaloParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoCaloParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoCaloParticleAssociation() = default;

  /// converting constructor from mutable object
  MCRecoCaloParticleAssociation(const MutableMCRecoCaloParticleAssociation& other);

  static MCRecoCaloParticleAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::CalorimeterHit getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoCaloParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoCaloParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoCaloParticleAssociation& other) const;

  bool operator!=(const MCRecoCaloParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoCaloParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoCaloParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoCaloParticleAssociation& a, MCRecoCaloParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoCaloParticleAssociationObj
  explicit MCRecoCaloParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj> obj);
  MCRecoCaloParticleAssociation(MCRecoCaloParticleAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoCaloParticleAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoCaloParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
