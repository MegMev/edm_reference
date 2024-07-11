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

#include <ostream>

namespace edm4hep {

CaloHitContribution::CaloHitContribution() : m_obj(new CaloHitContributionObj{}, podio::utils::MarkOwned) {
}

CaloHitContribution::CaloHitContribution(std::int32_t PDG, float energy, float time, edm4hep::Vector3f stepPosition) :
    m_obj(new CaloHitContributionObj{}, podio::utils::MarkOwned) {
  m_obj->data.PDG = PDG;
  m_obj->data.energy = energy;
  m_obj->data.time = time;
  m_obj->data.stepPosition = stepPosition;
}

CaloHitContribution& CaloHitContribution::operator=(CaloHitContribution other) {
  swap(*this, other);
  return *this;
}

MutableCaloHitContribution CaloHitContribution::clone(bool cloneRelations) const {
  auto tmp = new CaloHitContributionObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_particle) {
      tmp->m_particle = new edm4hep::MCParticle(*m_obj->m_particle);
    }
  } else {
  }
  return MutableCaloHitContribution(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

CaloHitContribution::CaloHitContribution(podio::utils::MaybeSharedPtr<CaloHitContributionObj> obj) :
    m_obj(std::move(obj)) {
}

CaloHitContribution::CaloHitContribution(const MutableCaloHitContribution& other) : CaloHitContribution(other.m_obj) {
}

CaloHitContribution::CaloHitContribution(CaloHitContributionObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<CaloHitContributionObj>(obj)) {
}

CaloHitContribution CaloHitContribution::makeEmpty() {
  return {nullptr};
}

std::int32_t CaloHitContribution::getPDG() const {
  return m_obj->data.PDG;
}
float CaloHitContribution::getEnergy() const {
  return m_obj->data.energy;
}
float CaloHitContribution::getTime() const {
  return m_obj->data.time;
}
const edm4hep::Vector3f& CaloHitContribution::getStepPosition() const {
  return m_obj->data.stepPosition;
}

const edm4hep::MCParticle CaloHitContribution::getParticle() const {
  if (!m_obj->m_particle) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_particle));
}

bool CaloHitContribution::isAvailable() const {
  return m_obj;
}

const podio::ObjectID CaloHitContribution::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool CaloHitContribution::operator==(const MutableCaloHitContribution& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const CaloHitContribution& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " stepPosition : " << value.getStepPosition() << '\n';

  o << " particle : " << value.getParticle().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const CaloHitContribution& value) {
  j = nlohmann::json{{"PDG", value.getPDG()},
                     {"energy", value.getEnergy()},
                     {"time", value.getTime()},
                     {"stepPosition", value.getStepPosition()}};

  j["particle"] = nlohmann::json{{"collectionID", value.getParticle().getObjectID().collectionID},
                                 {"index", value.getParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
