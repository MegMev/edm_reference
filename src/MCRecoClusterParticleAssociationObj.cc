// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Cluster.h"
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCRecoClusterParticleAssociationObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoClusterParticleAssociationObj::MCRecoClusterParticleAssociationObj() :
    id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoClusterParticleAssociationObj::MCRecoClusterParticleAssociationObj(const podio::ObjectID id_,
                                                                         MCRecoClusterParticleAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoClusterParticleAssociationObj::MCRecoClusterParticleAssociationObj(
    const MCRecoClusterParticleAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::Cluster(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::MCParticle(*(other.m_sim));
  }
}

MCRecoClusterParticleAssociationObj::~MCRecoClusterParticleAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
