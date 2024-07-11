// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ParticleIDObj.h"
#include "edm4hep/ReconstructedParticle.h"
#include "podio/ObjectID.h"

namespace edm4hep {

ParticleIDObj::ParticleIDObj() : id(), data(), m_particle(nullptr), m_parameters(new std::vector<float>()) {
}

ParticleIDObj::ParticleIDObj(const podio::ObjectID id_, ParticleIDData data_) : id(id_), data(data_) {
}

ParticleIDObj::ParticleIDObj(const ParticleIDObj& other) :
    id(), data(other.data), m_particle(nullptr), m_parameters(new std::vector<float>(*(other.m_parameters))) {
  if (other.m_particle) {
    m_particle = new edm4hep::ReconstructedParticle(*(other.m_particle));
  }
}

ParticleIDObj::~ParticleIDObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_parameters;
  }

  delete m_particle;
}
} // namespace edm4hep
