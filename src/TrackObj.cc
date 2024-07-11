// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Track.h"
#include "edm4hep/TrackObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

TrackObj::TrackObj() :
    id(),
    data(),
    m_trackerHits(new std::vector<edm4hep::TrackerHit>()),
    m_tracks(new std::vector<edm4hep::Track>()),
    m_subdetectorHitNumbers(new std::vector<std::int32_t>()),
    m_trackStates(new std::vector<edm4hep::TrackState>()),
    m_dxQuantities(new std::vector<edm4hep::Quantity>()) {
}

TrackObj::TrackObj(const podio::ObjectID id_, TrackData data_) : id(id_), data(data_) {
}

TrackObj::TrackObj(const TrackObj& other) :
    id(),
    data(other.data),
    m_trackerHits(new std::vector<edm4hep::TrackerHit>(*(other.m_trackerHits))),
    m_tracks(new std::vector<edm4hep::Track>(*(other.m_tracks))),
    m_subdetectorHitNumbers(new std::vector<std::int32_t>(*(other.m_subdetectorHitNumbers))),
    m_trackStates(new std::vector<edm4hep::TrackState>(*(other.m_trackStates))),
    m_dxQuantities(new std::vector<edm4hep::Quantity>(*(other.m_dxQuantities))) {
}

TrackObj::~TrackObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_trackerHits;
    delete m_tracks;
    delete m_subdetectorHitNumbers;
    delete m_trackStates;
    delete m_dxQuantities;
  }
}
} // namespace edm4hep
