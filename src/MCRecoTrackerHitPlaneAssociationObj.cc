// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoTrackerHitPlaneAssociationObj.h"
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHitPlane.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoTrackerHitPlaneAssociationObj::MCRecoTrackerHitPlaneAssociationObj() :
    id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoTrackerHitPlaneAssociationObj::MCRecoTrackerHitPlaneAssociationObj(const podio::ObjectID id_,
                                                                         MCRecoTrackerHitPlaneAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoTrackerHitPlaneAssociationObj::MCRecoTrackerHitPlaneAssociationObj(
    const MCRecoTrackerHitPlaneAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::TrackerHitPlane(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::SimTrackerHit(*(other.m_sim));
  }
}

MCRecoTrackerHitPlaneAssociationObj::~MCRecoTrackerHitPlaneAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
