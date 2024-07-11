// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/MCRecoCaloAssociationObj.h"
#include "edm4hep/SimCalorimeterHit.h"
#include "podio/ObjectID.h"

namespace edm4hep {

MCRecoCaloAssociationObj::MCRecoCaloAssociationObj() : id(), data(), m_rec(nullptr), m_sim(nullptr) {
}

MCRecoCaloAssociationObj::MCRecoCaloAssociationObj(const podio::ObjectID id_, MCRecoCaloAssociationData data_) :
    id(id_), data(data_) {
}

MCRecoCaloAssociationObj::MCRecoCaloAssociationObj(const MCRecoCaloAssociationObj& other) :
    id(), data(other.data), m_rec(nullptr), m_sim(nullptr) {
  if (other.m_rec) {
    m_rec = new edm4hep::CalorimeterHit(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new edm4hep::SimCalorimeterHit(*(other.m_sim));
  }
}

MCRecoCaloAssociationObj::~MCRecoCaloAssociationObj() {

  delete m_rec;
  delete m_sim;
}
} // namespace edm4hep
