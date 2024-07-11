// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoTrackerAssociationObj.h"
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHit.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoTrackerAssociationObj::MCRecoTrackerAssociationObj() : id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoTrackerAssociationObj::MCRecoTrackerAssociationObj(const podio::ObjectID id_,
                                                         MCRecoTrackerAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoTrackerAssociationObj::MCRecoTrackerAssociationObj(const MCRecoTrackerAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::TrackerHit(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::SimTrackerHit(*(other.m_sim));
  }
}

MCRecoTrackerAssociationObj::~MCRecoTrackerAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
