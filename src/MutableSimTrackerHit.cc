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

namespace edm4hep {

MutableSimTrackerHit::MutableSimTrackerHit() : m_obj(new SimTrackerHitObj{}, podio::utils::MarkOwned) {
}

MutableSimTrackerHit::MutableSimTrackerHit(std::uint64_t cellID, float eDep, float time, float pathLength,
                                           std::int32_t quality, edm4hep::Vector3d position,
                                           edm4hep::Vector3f momentum) :
    m_obj(new SimTrackerHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.eDep = eDep;
  m_obj->data.time = time;
  m_obj->data.pathLength = pathLength;
  m_obj->data.quality = quality;
  m_obj->data.position = position;
  m_obj->data.momentum = momentum;
}

MutableSimTrackerHit& MutableSimTrackerHit::operator=(MutableSimTrackerHit other) {
  swap(*this, other);
  return *this;
}

MutableSimTrackerHit MutableSimTrackerHit::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new SimTrackerHitObj(podio::ObjectID{}, m_obj->data);
    return MutableSimTrackerHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableSimTrackerHit(podio::utils::MaybeSharedPtr(new SimTrackerHitObj(*m_obj), podio::utils::MarkOwned));
}

MutableSimTrackerHit::MutableSimTrackerHit(podio::utils::MaybeSharedPtr<SimTrackerHitObj> obj) : m_obj(std::move(obj)) {
}

std::uint64_t MutableSimTrackerHit::getCellID() const {
  return m_obj->data.cellID;
}
float MutableSimTrackerHit::getEDep() const {
  return m_obj->data.eDep;
}
float MutableSimTrackerHit::getTime() const {
  return m_obj->data.time;
}
float MutableSimTrackerHit::getPathLength() const {
  return m_obj->data.pathLength;
}
std::int32_t MutableSimTrackerHit::getQuality() const {
  return m_obj->data.quality;
}
const edm4hep::Vector3d& MutableSimTrackerHit::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::Vector3f& MutableSimTrackerHit::getMomentum() const {
  return m_obj->data.momentum;
}

const edm4hep::MCParticle MutableSimTrackerHit::getParticle() const {
  if (!m_obj->m_particle) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_particle));
}

void MutableSimTrackerHit::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableSimTrackerHit::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableSimTrackerHit::cellID() {
  return m_obj->data.cellID;
}
void MutableSimTrackerHit::setEDep(float value) {
  m_obj->data.eDep = value;
}
float& MutableSimTrackerHit::getEDep() {
  return m_obj->data.eDep;
}
float& MutableSimTrackerHit::eDep() {
  return m_obj->data.eDep;
}
void MutableSimTrackerHit::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableSimTrackerHit::getTime() {
  return m_obj->data.time;
}
float& MutableSimTrackerHit::time() {
  return m_obj->data.time;
}
void MutableSimTrackerHit::setPathLength(float value) {
  m_obj->data.pathLength = value;
}
float& MutableSimTrackerHit::getPathLength() {
  return m_obj->data.pathLength;
}
float& MutableSimTrackerHit::pathLength() {
  return m_obj->data.pathLength;
}
void MutableSimTrackerHit::setQuality(std::int32_t value) {
  m_obj->data.quality = value;
}
std::int32_t& MutableSimTrackerHit::getQuality() {
  return m_obj->data.quality;
}
std::int32_t& MutableSimTrackerHit::quality() {
  return m_obj->data.quality;
}
void MutableSimTrackerHit::setPosition(edm4hep::Vector3d value) {
  m_obj->data.position = value;
}
edm4hep::Vector3d& MutableSimTrackerHit::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3d& MutableSimTrackerHit::position() {
  return m_obj->data.position;
}
void MutableSimTrackerHit::setMomentum(edm4hep::Vector3f value) {
  m_obj->data.momentum = value;
}
edm4hep::Vector3f& MutableSimTrackerHit::getMomentum() {
  return m_obj->data.momentum;
}
edm4hep::Vector3f& MutableSimTrackerHit::momentum() {
  return m_obj->data.momentum;
}

void MutableSimTrackerHit::setParticle(const edm4hep::MCParticle& value) {
  delete m_obj->m_particle;
  m_obj->m_particle = new edm4hep::MCParticle(value);
}

bool MutableSimTrackerHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableSimTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableSimTrackerHit::operator==(const SimTrackerHit& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableSimTrackerHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},    {"eDep", value.getEDep()},
                     {"time", value.getTime()},        {"pathLength", value.getPathLength()},
                     {"quality", value.getQuality()},  {"position", value.getPosition()},
                     {"momentum", value.getMomentum()}};

  j["particle"] = nlohmann::json{{"collectionID", value.getParticle().getObjectID().collectionID},
                                 {"index", value.getParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
