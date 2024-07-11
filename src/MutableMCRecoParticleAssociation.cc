// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoParticleAssociation.h"
#include "edm4hep/MCRecoParticleAssociationData.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoParticleAssociation.h"

#include "edm4hep/MCParticle.h"
#include "edm4hep/ReconstructedParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableMCRecoParticleAssociation::MutableMCRecoParticleAssociation() :
    m_obj(new MCRecoParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoParticleAssociation::MutableMCRecoParticleAssociation(float weight) :
    m_obj(new MCRecoParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoParticleAssociation& MutableMCRecoParticleAssociation::operator=(MutableMCRecoParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoParticleAssociation MutableMCRecoParticleAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoParticleAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoParticleAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoParticleAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoParticleAssociation::MutableMCRecoParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::ReconstructedParticle MutableMCRecoParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_rec));
}

const edm4hep::MCParticle MutableMCRecoParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

void MutableMCRecoParticleAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoParticleAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoParticleAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoParticleAssociation::setRec(const edm4hep::ReconstructedParticle& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::ReconstructedParticle(value);
}

void MutableMCRecoParticleAssociation::setSim(const edm4hep::MCParticle& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::MCParticle(value);
}

bool MutableMCRecoParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoParticleAssociation::operator==(const MCRecoParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
