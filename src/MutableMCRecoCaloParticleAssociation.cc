// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoCaloParticleAssociation.h"
#include "edm4hep/MCRecoCaloParticleAssociationData.h"
#include "edm4hep/MCRecoCaloParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoCaloParticleAssociation.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableMCRecoCaloParticleAssociation::MutableMCRecoCaloParticleAssociation() :
    m_obj(new MCRecoCaloParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoCaloParticleAssociation::MutableMCRecoCaloParticleAssociation(float weight) :
    m_obj(new MCRecoCaloParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoCaloParticleAssociation&
MutableMCRecoCaloParticleAssociation::operator=(MutableMCRecoCaloParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoCaloParticleAssociation MutableMCRecoCaloParticleAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoCaloParticleAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoCaloParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoCaloParticleAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoCaloParticleAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoCaloParticleAssociation::MutableMCRecoCaloParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoCaloParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::CalorimeterHit MutableMCRecoCaloParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::CalorimeterHit::makeEmpty();
  }
  return edm4hep::CalorimeterHit(*(m_obj->m_rec));
}

const edm4hep::MCParticle MutableMCRecoCaloParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

void MutableMCRecoCaloParticleAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoCaloParticleAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoCaloParticleAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoCaloParticleAssociation::setRec(const edm4hep::CalorimeterHit& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::CalorimeterHit(value);
}

void MutableMCRecoCaloParticleAssociation::setSim(const edm4hep::MCParticle& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::MCParticle(value);
}

bool MutableMCRecoCaloParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoCaloParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoCaloParticleAssociation::operator==(const MCRecoCaloParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoCaloParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
