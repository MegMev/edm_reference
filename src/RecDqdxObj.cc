// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RecDqdxObj.h"
#include "edm4hep/Track.h"
#include "podio/ObjectID.h"

namespace edm4hep {

RecDqdxObj::RecDqdxObj() : id(), data(), m_track(nullptr) {
}

RecDqdxObj::RecDqdxObj(const podio::ObjectID id_, RecDqdxData data_) : id(id_), data(data_) {
}

RecDqdxObj::RecDqdxObj(const RecDqdxObj& other) : id(), data(other.data), m_track(nullptr) {
  if (other.m_track) {
    m_track = new edm4hep::Track(*(other.m_track));
  }
}

RecDqdxObj::~RecDqdxObj() {

  delete m_track;
}
} // namespace edm4hep
