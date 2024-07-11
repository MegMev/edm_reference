// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoTrackParticleAssociation.h"
#include "edm4hep/MCRecoTrackParticleAssociationData.h"
#include "edm4hep/MCRecoTrackParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoTrackParticleAssociation.h"

#include "edm4hep/MCParticle.h"
#include "edm4hep/Track.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableMCRecoTrackParticleAssociation::MutableMCRecoTrackParticleAssociation() :
    m_obj(new MCRecoTrackParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoTrackParticleAssociation::MutableMCRecoTrackParticleAssociation(float weight) :
    m_obj(new MCRecoTrackParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoTrackParticleAssociation&
MutableMCRecoTrackParticleAssociation::operator=(MutableMCRecoTrackParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoTrackParticleAssociation MutableMCRecoTrackParticleAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoTrackParticleAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoTrackParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoTrackParticleAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoTrackParticleAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoTrackParticleAssociation::MutableMCRecoTrackParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoTrackParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::Track MutableMCRecoTrackParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::Track::makeEmpty();
  }
  return edm4hep::Track(*(m_obj->m_rec));
}

const edm4hep::MCParticle MutableMCRecoTrackParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

void MutableMCRecoTrackParticleAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoTrackParticleAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoTrackParticleAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoTrackParticleAssociation::setRec(const edm4hep::Track& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::Track(value);
}

void MutableMCRecoTrackParticleAssociation::setSim(const edm4hep::MCParticle& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::MCParticle(value);
}

bool MutableMCRecoTrackParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoTrackParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoTrackParticleAssociation::operator==(const MCRecoTrackParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoTrackParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
