// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoClusterParticleAssociation.h"
#include "edm4hep/MCRecoClusterParticleAssociationData.h"
#include "edm4hep/MCRecoClusterParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoClusterParticleAssociation.h"

#include "edm4hep/Cluster.h"
#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableMCRecoClusterParticleAssociation::MutableMCRecoClusterParticleAssociation() :
    m_obj(new MCRecoClusterParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoClusterParticleAssociation::MutableMCRecoClusterParticleAssociation(float weight) :
    m_obj(new MCRecoClusterParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoClusterParticleAssociation&
MutableMCRecoClusterParticleAssociation::operator=(MutableMCRecoClusterParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoClusterParticleAssociation MutableMCRecoClusterParticleAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoClusterParticleAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoClusterParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoClusterParticleAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoClusterParticleAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoClusterParticleAssociation::MutableMCRecoClusterParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoClusterParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::Cluster MutableMCRecoClusterParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::Cluster::makeEmpty();
  }
  return edm4hep::Cluster(*(m_obj->m_rec));
}

const edm4hep::MCParticle MutableMCRecoClusterParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

void MutableMCRecoClusterParticleAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoClusterParticleAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoClusterParticleAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoClusterParticleAssociation::setRec(const edm4hep::Cluster& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::Cluster(value);
}

void MutableMCRecoClusterParticleAssociation::setSim(const edm4hep::MCParticle& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::MCParticle(value);
}

bool MutableMCRecoClusterParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoClusterParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoClusterParticleAssociation::operator==(const MCRecoClusterParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoClusterParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
