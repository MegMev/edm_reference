// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RecoParticleVertexAssociationObj.h"
#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/Vertex.h"
#include "podio/ObjectID.h"

namespace edm4hep {

RecoParticleVertexAssociationObj::RecoParticleVertexAssociationObj() : id(), data(), m_rec(nullptr), m_vertex(nullptr) {
}

RecoParticleVertexAssociationObj::RecoParticleVertexAssociationObj(const podio::ObjectID id_,
                                                                   RecoParticleVertexAssociationData data_) :
    id(id_), data(data_) {
}

RecoParticleVertexAssociationObj::RecoParticleVertexAssociationObj(const RecoParticleVertexAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_vertex(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::ReconstructedParticle(*(other.m_rec));
  }
  if (other.m_vertex) {
    m_vertex = new edm4hep::Vertex(*(other.m_vertex));
  }
}

RecoParticleVertexAssociationObj::~RecoParticleVertexAssociationObj() {

  delete m_rec;
  delete m_vertex;
}
} // namespace edm4hep
