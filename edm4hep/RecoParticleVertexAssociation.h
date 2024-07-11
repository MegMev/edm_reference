// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecoParticleVertexAssociation_H
#define EDM4HEP_RecoParticleVertexAssociation_H

#include "edm4hep/RecoParticleVertexAssociationObj.h"

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

class MutableRecoParticleVertexAssociation;
class RecoParticleVertexAssociationCollection;
class RecoParticleVertexAssociationCollectionData;

/** @class RecoParticleVertexAssociation
 *  Association between a ReconstructedParticle and a Vertex
 *  @author: EDM4hep authors
 */
class RecoParticleVertexAssociation {

  friend class MutableRecoParticleVertexAssociation;
  friend class RecoParticleVertexAssociationCollection;
  friend class edm4hep::RecoParticleVertexAssociationCollectionData;
  friend class RecoParticleVertexAssociationCollectionIterator;

public:
  using mutable_type = MutableRecoParticleVertexAssociation;
  using collection_type = RecoParticleVertexAssociationCollection;

  /// default constructor
  RecoParticleVertexAssociation();

  /// Constructor initializing all members
  RecoParticleVertexAssociation(float weight);

  /// copy constructor
  RecoParticleVertexAssociation(const RecoParticleVertexAssociation& other) = default;

  /// copy-assignment operator
  RecoParticleVertexAssociation& operator=(RecoParticleVertexAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRecoParticleVertexAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~RecoParticleVertexAssociation() = default;

  /// converting constructor from mutable object
  RecoParticleVertexAssociation(const MutableRecoParticleVertexAssociation& other);

  static RecoParticleVertexAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed particle
  const edm4hep::ReconstructedParticle getRec() const;
  /// Access the reference to the vertex
  const edm4hep::Vertex getVertex() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecoParticleVertexAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj>{nullptr};
  }

  bool operator==(const RecoParticleVertexAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableRecoParticleVertexAssociation& other) const;

  bool operator!=(const RecoParticleVertexAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableRecoParticleVertexAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RecoParticleVertexAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(RecoParticleVertexAssociation& a, RecoParticleVertexAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RecoParticleVertexAssociationObj
  explicit RecoParticleVertexAssociation(podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj> obj);
  RecoParticleVertexAssociation(RecoParticleVertexAssociationObj* obj);

  podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const RecoParticleVertexAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecoParticleVertexAssociation& value);
#endif

} // namespace edm4hep

#endif
