// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoCaloAssociation.h"
#include "edm4hep/MCRecoCaloAssociationData.h"
#include "edm4hep/MCRecoCaloAssociationObj.h"
#include "edm4hep/MutableMCRecoCaloAssociation.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/SimCalorimeterHit.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoCaloAssociation::MCRecoCaloAssociation() : m_obj(new MCRecoCaloAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoCaloAssociation::MCRecoCaloAssociation(float weight) :
    m_obj(new MCRecoCaloAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoCaloAssociation& MCRecoCaloAssociation::operator=(MCRecoCaloAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoCaloAssociation MCRecoCaloAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoCaloAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::CalorimeterHit(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::SimCalorimeterHit(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoCaloAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoCaloAssociation::MCRecoCaloAssociation(podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoCaloAssociation::MCRecoCaloAssociation(const MutableMCRecoCaloAssociation& other) :
    MCRecoCaloAssociation(other.m_obj) {
}

MCRecoCaloAssociation::MCRecoCaloAssociation(MCRecoCaloAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj>(obj)) {
}

MCRecoCaloAssociation MCRecoCaloAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoCaloAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::CalorimeterHit MCRecoCaloAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::CalorimeterHit::makeEmpty();
  }
  return edm4hep::CalorimeterHit(*(m_obj->m_rec));
}

const edm4hep::SimCalorimeterHit MCRecoCaloAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::SimCalorimeterHit::makeEmpty();
  }
  return edm4hep::SimCalorimeterHit(*(m_obj->m_sim));
}

bool MCRecoCaloAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoCaloAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoCaloAssociation::operator==(const MutableMCRecoCaloAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoCaloAssociation& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " rec : " << value.getRec().id() << '\n';
  o << " sim : " << value.getSim().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoCaloAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
