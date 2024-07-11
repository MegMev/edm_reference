// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackParticleAssociation_H
#define EDM4HEP_MCRecoTrackParticleAssociation_H

#include "edm4hep/MCRecoTrackParticleAssociationObj.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class Track;
class MutableTrack;
class MCParticle;
class MutableMCParticle;
} // namespace edm4hep

namespace edm4hep {

class MutableMCRecoTrackParticleAssociation;
class MCRecoTrackParticleAssociationCollection;
class MCRecoTrackParticleAssociationCollectionData;

/** @class MCRecoTrackParticleAssociation
 *  Association between a Track and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MCRecoTrackParticleAssociation {

  friend class MutableMCRecoTrackParticleAssociation;
  friend class MCRecoTrackParticleAssociationCollection;
  friend class edm4hep::MCRecoTrackParticleAssociationCollectionData;
  friend class MCRecoTrackParticleAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoTrackParticleAssociation;
  using collection_type = MCRecoTrackParticleAssociationCollection;

  /// default constructor
  MCRecoTrackParticleAssociation();

  /// Constructor initializing all members
  MCRecoTrackParticleAssociation(float weight);

  /// copy constructor
  MCRecoTrackParticleAssociation(const MCRecoTrackParticleAssociation& other) = default;

  /// copy-assignment operator
  MCRecoTrackParticleAssociation& operator=(MCRecoTrackParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoTrackParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoTrackParticleAssociation() = default;

  /// converting constructor from mutable object
  MCRecoTrackParticleAssociation(const MutableMCRecoTrackParticleAssociation& other);

  static MCRecoTrackParticleAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the track
  const edm4hep::Track getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoTrackParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoTrackParticleAssociation& other) const;

  bool operator!=(const MCRecoTrackParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoTrackParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoTrackParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoTrackParticleAssociation& a, MCRecoTrackParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoTrackParticleAssociationObj
  explicit MCRecoTrackParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj> obj);
  MCRecoTrackParticleAssociation(MCRecoTrackParticleAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoTrackParticleAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoTrackParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
