// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/VertexObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

VertexObj::VertexObj() : id(), data(), m_associatedParticle(nullptr), m_parameters(new std::vector<float>()) {
}

VertexObj::VertexObj(const podio::ObjectID id_, VertexData data_) : id(id_), data(data_) {
}

VertexObj::VertexObj(const VertexObj& other) :
    id(), data(other.data), m_associatedParticle(nullptr), m_parameters(new std::vector<float>(*(other.m_parameters))) {
  if (other.m_associatedParticle) {
    m_associatedParticle = new edm4hep::ReconstructedParticle(*(other.m_associatedParticle));
  }
}

VertexObj::~VertexObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_parameters;
  }

  delete m_associatedParticle;
}
} // namespace edm4hep
