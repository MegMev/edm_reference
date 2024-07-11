// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCParticleObj::MCParticleObj() :
    id(),
    data(),
    m_parents(new std::vector<edm4hep::MCParticle>()),
    m_daughters(new std::vector<edm4hep::MCParticle>()) {
}

MCParticleObj::MCParticleObj(const podio::ObjectID id_, MCParticleData data_) : id(id_), data(data_) {
}

MCParticleObj::MCParticleObj(const MCParticleObj& other) :
    id(),
    data(other.data),
    m_parents(new std::vector<edm4hep::MCParticle>(*(other.m_parents))),
    m_daughters(new std::vector<edm4hep::MCParticle>(*(other.m_daughters))) {
}

MCParticleObj::~MCParticleObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_parents;
    delete m_daughters;
  }
}
} // namespace edm4hep
