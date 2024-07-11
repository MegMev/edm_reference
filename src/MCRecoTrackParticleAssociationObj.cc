// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticle.h"
#include "edm4hep/MCRecoTrackParticleAssociationObj.h"
#include "edm4hep/Track.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoTrackParticleAssociationObj::MCRecoTrackParticleAssociationObj() : id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoTrackParticleAssociationObj::MCRecoTrackParticleAssociationObj(const podio::ObjectID id_,
                                                                     MCRecoTrackParticleAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoTrackParticleAssociationObj::MCRecoTrackParticleAssociationObj(const MCRecoTrackParticleAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::Track(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::MCParticle(*(other.m_sim));
  }
}

MCRecoTrackParticleAssociationObj::~MCRecoTrackParticleAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
