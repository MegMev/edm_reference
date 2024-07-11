// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoTrackParticleAssociation_H
#define EDM4HEP_MutableMCRecoTrackParticleAssociation_H

#include "edm4hep/MCRecoTrackParticleAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoTrackParticleAssociation.h"

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

/** @class MutableMCRecoTrackParticleAssociation
 *  Association between a Track and the corresponding MCParticle
 *  @author: EDM4hep authors
 */
class MutableMCRecoTrackParticleAssociation {

  friend class MCRecoTrackParticleAssociationCollection;
  friend class MCRecoTrackParticleAssociationMutableCollectionIterator;
  friend class MCRecoTrackParticleAssociation;

public:
  using object_type = MCRecoTrackParticleAssociation;
  using collection_type = MCRecoTrackParticleAssociationCollection;

  /// default constructor
  MutableMCRecoTrackParticleAssociation();

  /// Constructor initializing all members
  MutableMCRecoTrackParticleAssociation(float weight);

  /// copy constructor
  MutableMCRecoTrackParticleAssociation(const MutableMCRecoTrackParticleAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoTrackParticleAssociation& operator=(MutableMCRecoTrackParticleAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoTrackParticleAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoTrackParticleAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the track
  const edm4hep::Track getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const edm4hep::MCParticle getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the track
  void setRec(const edm4hep::Track& value);
  /// Set the reference to the Monte-Carlo particle
  void setSim(const edm4hep::MCParticle& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackParticleAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoTrackParticleAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoTrackParticleAssociation& other) const;

  bool operator!=(const MutableMCRecoTrackParticleAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoTrackParticleAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoTrackParticleAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoTrackParticleAssociation& a, MutableMCRecoTrackParticleAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoTrackParticleAssociationObj
  explicit MutableMCRecoTrackParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoTrackParticleAssociation& value);
#endif

} // namespace edm4hep

#endif
