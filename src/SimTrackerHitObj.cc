// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticle.h"
#include "edm4hep/SimTrackerHitObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

SimTrackerHitObj::SimTrackerHitObj() : id(), data(), m_particle(nullptr) {
}

SimTrackerHitObj::SimTrackerHitObj(const podio::ObjectID id_, SimTrackerHitData data_) : id(id_), data(data_) {
}

SimTrackerHitObj::SimTrackerHitObj(const SimTrackerHitObj& other) : id(), data(other.data), m_particle(nullptr) {
  if (other.m_particle) {
    m_particle = new edm4hep::MCParticle(*(other.m_particle));
  }
}

SimTrackerHitObj::~SimTrackerHitObj() {

  delete m_particle;
}
} // namespace edm4hep
