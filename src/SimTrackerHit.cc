// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableSimTrackerHit.h"
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/SimTrackerHitData.h"
#include "edm4hep/SimTrackerHitObj.h"

#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

SimTrackerHit::SimTrackerHit() : m_obj(new SimTrackerHitObj{}, podio::utils::MarkOwned) {
}

SimTrackerHit::SimTrackerHit(std::uint64_t cellID, float eDep, float time, float pathLength, std::int32_t quality,
                             edm4hep::Vector3d position, edm4hep::Vector3f momentum) :
    m_obj(new SimTrackerHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.eDep = eDep;
  m_obj->data.time = time;
  m_obj->data.pathLength = pathLength;
  m_obj->data.quality = quality;
  m_obj->data.position = position;
  m_obj->data.momentum = momentum;
}

SimTrackerHit& SimTrackerHit::operator=(SimTrackerHit other) {
  swap(*this, other);
  return *this;
}

MutableSimTrackerHit SimTrackerHit::clone(bool cloneRelations) const {
  auto tmp = new SimTrackerHitObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_particle) {
      tmp->m_particle = new edm4hep::MCParticle(*m_obj->m_particle);
    }
  } else {
  }
  return MutableSimTrackerHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

SimTrackerHit::SimTrackerHit(podio::utils::MaybeSharedPtr<SimTrackerHitObj> obj) : m_obj(std::move(obj)) {
}

SimTrackerHit::SimTrackerHit(const MutableSimTrackerHit& other) : SimTrackerHit(other.m_obj) {
}

SimTrackerHit::SimTrackerHit(SimTrackerHitObj* obj) : m_obj(podio::utils::MaybeSharedPtr<SimTrackerHitObj>(obj)) {
}

SimTrackerHit SimTrackerHit::makeEmpty() {
  return {nullptr};
}

std::uint64_t SimTrackerHit::getCellID() const {
  return m_obj->data.cellID;
}
float SimTrackerHit::getEDep() const {
  return m_obj->data.eDep;
}
float SimTrackerHit::getTime() const {
  return m_obj->data.time;
}
float SimTrackerHit::getPathLength() const {
  return m_obj->data.pathLength;
}
std::int32_t SimTrackerHit::getQuality() const {
  return m_obj->data.quality;
}
const edm4hep::Vector3d& SimTrackerHit::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::Vector3f& SimTrackerHit::getMomentum() const {
  return m_obj->data.momentum;
}

const edm4hep::MCParticle SimTrackerHit::getParticle() const {
  if (!m_obj->m_particle) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_particle));
}

bool SimTrackerHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID SimTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool SimTrackerHit::operator==(const MutableSimTrackerHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const SimTrackerHit& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " eDep : " << value.getEDep() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " pathLength : " << value.getPathLength() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " momentum : " << value.getMomentum() << '\n';

  o << " particle : " << value.getParticle().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimTrackerHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},    {"eDep", value.getEDep()},
                     {"time", value.getTime()},        {"pathLength", value.getPathLength()},
                     {"quality", value.getQuality()},  {"position", value.getPosition()},
                     {"momentum", value.getMomentum()}};

  j["particle"] = nlohmann::json{{"collectionID", value.getParticle().getObjectID().collectionID},
                                 {"index", value.getParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
