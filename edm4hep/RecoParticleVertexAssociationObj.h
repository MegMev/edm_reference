// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecoParticleVertexAssociationOBJ_H
#define EDM4HEP_RecoParticleVertexAssociationOBJ_H

// data model specific includes
#include "edm4hep/RecoParticleVertexAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class Vertex;
} // namespace edm4hep

namespace edm4hep {

class RecoParticleVertexAssociation;

class RecoParticleVertexAssociationObj {
public:
  /// constructor
  RecoParticleVertexAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  RecoParticleVertexAssociationObj(const RecoParticleVertexAssociationObj&);
  /// constructor from ObjectID and RecoParticleVertexAssociationData
  /// does not initialize the internal relation containers
  RecoParticleVertexAssociationObj(const podio::ObjectID id, RecoParticleVertexAssociationData data);
  /// No assignment operator
  RecoParticleVertexAssociationObj& operator=(const RecoParticleVertexAssociationObj&) = delete;
  virtual ~RecoParticleVertexAssociationObj();

public:
  podio::ObjectID id;
  RecoParticleVertexAssociationData data;
  edm4hep::ReconstructedParticle* m_rec{nullptr};
  edm4hep::Vertex* m_vertex{nullptr};
};

} // namespace edm4hep

#endif
