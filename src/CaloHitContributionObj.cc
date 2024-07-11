// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CaloHitContributionObj.h"
#include "edm4hep/MCParticle.h"
#include "podio/ObjectID.h"

namespace edm4hep {

CaloHitContributionObj::CaloHitContributionObj() : id(), data(), m_particle(nullptr) {
}

CaloHitContributionObj::CaloHitContributionObj(const podio::ObjectID id_, CaloHitContributionData data_) :
    id(id_), data(data_) {
}

CaloHitContributionObj::CaloHitContributionObj(const CaloHitContributionObj& other) :
    id(), data(other.data), m_particle(nullptr) {
  if (other.m_particle) {
    m_particle = new edm4hep::MCParticle(*(other.m_particle));
  }
}

CaloHitContributionObj::~CaloHitContributionObj() {

  delete m_particle;
}
} // namespace edm4hep
