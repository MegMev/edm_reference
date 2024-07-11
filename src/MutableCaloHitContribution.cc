// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/CaloHitContributionData.h"
#include "edm4hep/CaloHitContributionObj.h"
#include "edm4hep/MutableCaloHitContribution.h"

#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableCaloHitContribution::MutableCaloHitContribution() :
    m_obj(new CaloHitContributionObj{}, podio::utils::MarkOwned) {
}

MutableCaloHitContribution::MutableCaloHitContribution(std::int32_t PDG, float energy, float time,
                                                       edm4hep::Vector3f stepPosition) :
    m_obj(new CaloHitContributionObj{}, podio::utils::MarkOwned) {
  m_obj->data.PDG = PDG;
  m_obj->data.energy = energy;
  m_obj->data.time = time;
  m_obj->data.stepPosition = stepPosition;
}

MutableCaloHitContribution& MutableCaloHitContribution::operator=(MutableCaloHitContribution other) {
  swap(*this, other);
  return *this;
}

MutableCaloHitContribution MutableCaloHitContribution::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new CaloHitContributionObj(podio::ObjectID{}, m_obj->data);
    return MutableCaloHitContribution(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableCaloHitContribution(
      podio::utils::MaybeSharedPtr(new CaloHitContributionObj(*m_obj), podio::utils::MarkOwned));
}

MutableCaloHitContribution::MutableCaloHitContribution(podio::utils::MaybeSharedPtr<CaloHitContributionObj> obj) :
    m_obj(std::move(obj)) {
}

std::int32_t MutableCaloHitContribution::getPDG() const {
  return m_obj->data.PDG;
}
float MutableCaloHitContribution::getEnergy() const {
  return m_obj->data.energy;
}
float MutableCaloHitContribution::getTime() const {
  return m_obj->data.time;
}
const edm4hep::Vector3f& MutableCaloHitContribution::getStepPosition() const {
  return m_obj->data.stepPosition;
}

const edm4hep::MCParticle MutableCaloHitContribution::getParticle() const {
  if (!m_obj->m_particle) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_particle));
}

void MutableCaloHitContribution::setPDG(std::int32_t value) {
  m_obj->data.PDG = value;
}
std::int32_t& MutableCaloHitContribution::getPDG() {
  return m_obj->data.PDG;
}
std::int32_t& MutableCaloHitContribution::PDG() {
  return m_obj->data.PDG;
}
void MutableCaloHitContribution::setEnergy(float value) {
  m_obj->data.energy = value;
}
float& MutableCaloHitContribution::getEnergy() {
  return m_obj->data.energy;
}
float& MutableCaloHitContribution::energy() {
  return m_obj->data.energy;
}
void MutableCaloHitContribution::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableCaloHitContribution::getTime() {
  return m_obj->data.time;
}
float& MutableCaloHitContribution::time() {
  return m_obj->data.time;
}
void MutableCaloHitContribution::setStepPosition(edm4hep::Vector3f value) {
  m_obj->data.stepPosition = value;
}
edm4hep::Vector3f& MutableCaloHitContribution::getStepPosition() {
  return m_obj->data.stepPosition;
}
edm4hep::Vector3f& MutableCaloHitContribution::stepPosition() {
  return m_obj->data.stepPosition;
}

void MutableCaloHitContribution::setParticle(const edm4hep::MCParticle& value) {
  delete m_obj->m_particle;
  m_obj->m_particle = new edm4hep::MCParticle(value);
}

bool MutableCaloHitContribution::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableCaloHitContribution::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableCaloHitContribution::operator==(const CaloHitContribution& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableCaloHitContribution& value) {
  j = nlohmann::json{{"PDG", value.getPDG()},
                     {"energy", value.getEnergy()},
                     {"time", value.getTime()},
                     {"stepPosition", value.getStepPosition()}};

  j["particle"] = nlohmann::json{{"collectionID", value.getParticle().getObjectID().collectionID},
                                 {"index", value.getParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
