// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableRecoParticleVertexAssociation_H
#define EDM4HEP_MutableRecoParticleVertexAssociation_H

#include "edm4hep/RecoParticleVertexAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/RecoParticleVertexAssociation.h"

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
class Vertex;
class MutableVertex;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableRecoParticleVertexAssociation
 *  Association between a ReconstructedParticle and a Vertex
 *  @author: EDM4hep authors
 */
class MutableRecoParticleVertexAssociation {

  friend class RecoParticleVertexAssociationCollection;
  friend class RecoParticleVertexAssociationMutableCollectionIterator;
  friend class RecoParticleVertexAssociation;

public:
  using object_type = RecoParticleVertexAssociation;
  using collection_type = RecoParticleVertexAssociationCollection;

  /// default constructor
  MutableRecoParticleVertexAssociation();

  /// Constructor initializing all members
  MutableRecoParticleVertexAssociation(float weight);

  /// copy constructor
  MutableRecoParticleVertexAssociation(const MutableRecoParticleVertexAssociation& other) = default;

  /// copy-assignment operator
  MutableRecoParticleVertexAssociation& operator=(MutableRecoParticleVertexAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRecoParticleVertexAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableRecoParticleVertexAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed particle
  const edm4hep::ReconstructedParticle getRec() const;
  /// Access the reference to the vertex
  const edm4hep::Vertex getVertex() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the reconstructed particle
  void setRec(const edm4hep::ReconstructedParticle& value);
  /// Set the reference to the vertex
  void setVertex(const edm4hep::Vertex& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecoParticleVertexAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj>{nullptr};
  }

  bool operator==(const MutableRecoParticleVertexAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const RecoParticleVertexAssociation& other) const;

  bool operator!=(const MutableRecoParticleVertexAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const RecoParticleVertexAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableRecoParticleVertexAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableRecoParticleVertexAssociation& a, MutableRecoParticleVertexAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RecoParticleVertexAssociationObj
  explicit MutableRecoParticleVertexAssociation(podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj> obj);

  podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRecoParticleVertexAssociation& value);
#endif

} // namespace edm4hep

#endif
