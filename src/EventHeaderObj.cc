// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/EventHeaderObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

EventHeaderObj::EventHeaderObj() : id(), data(), m_weights(new std::vector<double>()) {
}

EventHeaderObj::EventHeaderObj(const podio::ObjectID id_, EventHeaderData data_) : id(id_), data(data_) {
}

EventHeaderObj::EventHeaderObj(const EventHeaderObj& other) :
    id(), data(other.data), m_weights(new std::vector<double>(*(other.m_weights))) {
}

EventHeaderObj::~EventHeaderObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_weights;
  }
}
} // namespace edm4hep
