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

namespace edm4hep {

MutableMCRecoCaloAssociation::MutableMCRecoCaloAssociation() :
    m_obj(new MCRecoCaloAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoCaloAssociation::MutableMCRecoCaloAssociation(float weight) :
    m_obj(new MCRecoCaloAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoCaloAssociation& MutableMCRecoCaloAssociation::operator=(MutableMCRecoCaloAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoCaloAssociation MutableMCRecoCaloAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoCaloAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoCaloAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoCaloAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoCaloAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoCaloAssociation::MutableMCRecoCaloAssociation(podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoCaloAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::CalorimeterHit MutableMCRecoCaloAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::CalorimeterHit::makeEmpty();
  }
  return edm4hep::CalorimeterHit(*(m_obj->m_rec));
}

const edm4hep::SimCalorimeterHit MutableMCRecoCaloAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::SimCalorimeterHit::makeEmpty();
  }
  return edm4hep::SimCalorimeterHit(*(m_obj->m_sim));
}

void MutableMCRecoCaloAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoCaloAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoCaloAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoCaloAssociation::setRec(const edm4hep::CalorimeterHit& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::CalorimeterHit(value);
}

void MutableMCRecoCaloAssociation::setSim(const edm4hep::SimCalorimeterHit& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::SimCalorimeterHit(value);
}

bool MutableMCRecoCaloAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoCaloAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoCaloAssociation::operator==(const MCRecoCaloAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoCaloAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
