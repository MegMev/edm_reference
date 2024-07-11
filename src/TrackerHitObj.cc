// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackerHitObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

TrackerHitObj::TrackerHitObj() : id(), data(), m_rawHits(new std::vector<edm4hep::ObjectID>()) {
}

TrackerHitObj::TrackerHitObj(const podio::ObjectID id_, TrackerHitData data_) : id(id_), data(data_) {
}

TrackerHitObj::TrackerHitObj(const TrackerHitObj& other) :
    id(), data(other.data), m_rawHits(new std::vector<edm4hep::ObjectID>(*(other.m_rawHits))) {
}

TrackerHitObj::~TrackerHitObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_rawHits;
  }
}
} // namespace edm4hep
