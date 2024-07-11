// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimCalorimeterHitObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

SimCalorimeterHitObj::SimCalorimeterHitObj() :
    id(), data(), m_contributions(new std::vector<edm4hep::CaloHitContribution>()) {
}

SimCalorimeterHitObj::SimCalorimeterHitObj(const podio::ObjectID id_, SimCalorimeterHitData data_) :
    id(id_), data(data_) {
}

SimCalorimeterHitObj::SimCalorimeterHitObj(const SimCalorimeterHitObj& other) :
    id(), data(other.data), m_contributions(new std::vector<edm4hep::CaloHitContribution>(*(other.m_contributions))) {
}

SimCalorimeterHitObj::~SimCalorimeterHitObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_contributions;
  }
}
} // namespace edm4hep
