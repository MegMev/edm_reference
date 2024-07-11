// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCRecoCaloParticleAssociationObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoCaloParticleAssociationObj::MCRecoCaloParticleAssociationObj() : id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoCaloParticleAssociationObj::MCRecoCaloParticleAssociationObj(const podio::ObjectID id_,
                                                                   MCRecoCaloParticleAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoCaloParticleAssociationObj::MCRecoCaloParticleAssociationObj(const MCRecoCaloParticleAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::CalorimeterHit(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::MCParticle(*(other.m_sim));
  }
}

MCRecoCaloParticleAssociationObj::~MCRecoCaloParticleAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
