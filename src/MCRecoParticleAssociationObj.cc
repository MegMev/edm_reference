// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticle.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"
#include "edm4hep/ReconstructedParticle.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoParticleAssociationObj::MCRecoParticleAssociationObj() : id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoParticleAssociationObj::MCRecoParticleAssociationObj(const podio::ObjectID id_,
                                                           MCRecoParticleAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoParticleAssociationObj::MCRecoParticleAssociationObj(const MCRecoParticleAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::ReconstructedParticle(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::MCParticle(*(other.m_sim));
  }
}

MCRecoParticleAssociationObj::~MCRecoParticleAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
