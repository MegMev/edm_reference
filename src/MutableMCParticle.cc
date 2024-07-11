// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticleObj.h"
#include "edm4hep/MutableMCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableMCParticle::MutableMCParticle() : m_obj(new MCParticleObj{}, podio::utils::MarkOwned) {
}

MutableMCParticle::MutableMCParticle(std::int32_t PDG, std::int32_t generatorStatus, std::int32_t simulatorStatus,
                                     float charge, float time, double mass, edm4hep::Vector3d vertex,
                                     edm4hep::Vector3d endpoint, edm4hep::Vector3d momentum,
                                     edm4hep::Vector3d momentumAtEndpoint, edm4hep::Vector3f spin,
                                     edm4hep::Vector2i colorFlow) :
    m_obj(new MCParticleObj{}, podio::utils::MarkOwned) {
  m_obj->data.PDG = PDG;
  m_obj->data.generatorStatus = generatorStatus;
  m_obj->data.simulatorStatus = simulatorStatus;
  m_obj->data.charge = charge;
  m_obj->data.time = time;
  m_obj->data.mass = mass;
  m_obj->data.vertex = vertex;
  m_obj->data.endpoint = endpoint;
  m_obj->data.momentum = momentum;
  m_obj->data.momentumAtEndpoint = momentumAtEndpoint;
  m_obj->data.spin = spin;
  m_obj->data.colorFlow = colorFlow;
}

MutableMCParticle& MutableMCParticle::operator=(MutableMCParticle other) {
  swap(*this, other);
  return *this;
}

MutableMCParticle MutableMCParticle::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCParticleObj(podio::ObjectID{}, m_obj->data);
    tmp->m_parents = new std::vector<edm4hep::MCParticle>();
    tmp->data.parents_begin = 0;
    tmp->data.parents_end = 0;
    tmp->m_daughters = new std::vector<edm4hep::MCParticle>();
    tmp->data.daughters_begin = 0;
    tmp->data.daughters_end = 0;
    return MutableMCParticle(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCParticle(podio::utils::MaybeSharedPtr(new MCParticleObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCParticle::MutableMCParticle(podio::utils::MaybeSharedPtr<MCParticleObj> obj) : m_obj(std::move(obj)) {
}

std::int32_t MutableMCParticle::getPDG() const {
  return m_obj->data.PDG;
}
std::int32_t MutableMCParticle::getGeneratorStatus() const {
  return m_obj->data.generatorStatus;
}
std::int32_t MutableMCParticle::getSimulatorStatus() const {
  return m_obj->data.simulatorStatus;
}
float MutableMCParticle::getCharge() const {
  return m_obj->data.charge;
}
float MutableMCParticle::getTime() const {
  return m_obj->data.time;
}
double MutableMCParticle::getMass() const {
  return m_obj->data.mass;
}
const edm4hep::Vector3d& MutableMCParticle::getVertex() const {
  return m_obj->data.vertex;
}
const edm4hep::Vector3d& MutableMCParticle::getEndpoint() const {
  return m_obj->data.endpoint;
}
const edm4hep::Vector3d& MutableMCParticle::getMomentum() const {
  return m_obj->data.momentum;
}
const edm4hep::Vector3d& MutableMCParticle::getMomentumAtEndpoint() const {
  return m_obj->data.momentumAtEndpoint;
}
const edm4hep::Vector3f& MutableMCParticle::getSpin() const {
  return m_obj->data.spin;
}
const edm4hep::Vector2i& MutableMCParticle::getColorFlow() const {
  return m_obj->data.colorFlow;
}

void MutableMCParticle::setPDG(std::int32_t value) {
  m_obj->data.PDG = value;
}
std::int32_t& MutableMCParticle::getPDG() {
  return m_obj->data.PDG;
}
std::int32_t& MutableMCParticle::PDG() {
  return m_obj->data.PDG;
}
void MutableMCParticle::setGeneratorStatus(std::int32_t value) {
  m_obj->data.generatorStatus = value;
}
std::int32_t& MutableMCParticle::getGeneratorStatus() {
  return m_obj->data.generatorStatus;
}
std::int32_t& MutableMCParticle::generatorStatus() {
  return m_obj->data.generatorStatus;
}
void MutableMCParticle::setSimulatorStatus(std::int32_t value) {
  m_obj->data.simulatorStatus = value;
}
std::int32_t& MutableMCParticle::getSimulatorStatus() {
  return m_obj->data.simulatorStatus;
}
std::int32_t& MutableMCParticle::simulatorStatus() {
  return m_obj->data.simulatorStatus;
}
void MutableMCParticle::setCharge(float value) {
  m_obj->data.charge = value;
}
float& MutableMCParticle::getCharge() {
  return m_obj->data.charge;
}
float& MutableMCParticle::charge() {
  return m_obj->data.charge;
}
void MutableMCParticle::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableMCParticle::getTime() {
  return m_obj->data.time;
}
float& MutableMCParticle::time() {
  return m_obj->data.time;
}
void MutableMCParticle::setMass(double value) {
  m_obj->data.mass = value;
}
double& MutableMCParticle::getMass() {
  return m_obj->data.mass;
}
double& MutableMCParticle::mass() {
  return m_obj->data.mass;
}
void MutableMCParticle::setVertex(edm4hep::Vector3d value) {
  m_obj->data.vertex = value;
}
edm4hep::Vector3d& MutableMCParticle::getVertex() {
  return m_obj->data.vertex;
}
edm4hep::Vector3d& MutableMCParticle::vertex() {
  return m_obj->data.vertex;
}
void MutableMCParticle::setEndpoint(edm4hep::Vector3d value) {
  m_obj->data.endpoint = value;
}
edm4hep::Vector3d& MutableMCParticle::getEndpoint() {
  return m_obj->data.endpoint;
}
edm4hep::Vector3d& MutableMCParticle::endpoint() {
  return m_obj->data.endpoint;
}
void MutableMCParticle::setMomentum(edm4hep::Vector3d value) {
  m_obj->data.momentum = value;
}
edm4hep::Vector3d& MutableMCParticle::getMomentum() {
  return m_obj->data.momentum;
}
edm4hep::Vector3d& MutableMCParticle::momentum() {
  return m_obj->data.momentum;
}
void MutableMCParticle::setMomentumAtEndpoint(edm4hep::Vector3d value) {
  m_obj->data.momentumAtEndpoint = value;
}
edm4hep::Vector3d& MutableMCParticle::getMomentumAtEndpoint() {
  return m_obj->data.momentumAtEndpoint;
}
edm4hep::Vector3d& MutableMCParticle::momentumAtEndpoint() {
  return m_obj->data.momentumAtEndpoint;
}
void MutableMCParticle::setSpin(edm4hep::Vector3f value) {
  m_obj->data.spin = value;
}
edm4hep::Vector3f& MutableMCParticle::getSpin() {
  return m_obj->data.spin;
}
edm4hep::Vector3f& MutableMCParticle::spin() {
  return m_obj->data.spin;
}
void MutableMCParticle::setColorFlow(edm4hep::Vector2i value) {
  m_obj->data.colorFlow = value;
}
edm4hep::Vector2i& MutableMCParticle::getColorFlow() {
  return m_obj->data.colorFlow;
}
edm4hep::Vector2i& MutableMCParticle::colorFlow() {
  return m_obj->data.colorFlow;
}

void MutableMCParticle::addToParents(const edm4hep::MCParticle& component) {
  m_obj->m_parents->push_back(component);
  m_obj->data.parents_end++;
}

std::vector<edm4hep::MCParticle>::const_iterator MutableMCParticle::parents_begin() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_begin);
  return ret_value;
}

std::vector<edm4hep::MCParticle>::const_iterator MutableMCParticle::parents_end() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_end);
  return ret_value;
}

std::size_t MutableMCParticle::parents_size() const {
  return m_obj->data.parents_end - m_obj->data.parents_begin;
}

edm4hep::MCParticle MutableMCParticle::getParents(std::size_t index) const {
  if (parents_size() > index) {
    return m_obj->m_parents->at(m_obj->data.parents_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::MCParticle> MutableMCParticle::getParents() const {
  auto begin = m_obj->m_parents->begin();
  std::advance(begin, m_obj->data.parents_begin);
  auto end = m_obj->m_parents->begin();
  std::advance(end, m_obj->data.parents_end);
  return {begin, end};
}

void MutableMCParticle::addToDaughters(const edm4hep::MCParticle& component) {
  m_obj->m_daughters->push_back(component);
  m_obj->data.daughters_end++;
}

std::vector<edm4hep::MCParticle>::const_iterator MutableMCParticle::daughters_begin() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_begin);
  return ret_value;
}

std::vector<edm4hep::MCParticle>::const_iterator MutableMCParticle::daughters_end() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_end);
  return ret_value;
}

std::size_t MutableMCParticle::daughters_size() const {
  return m_obj->data.daughters_end - m_obj->data.daughters_begin;
}

edm4hep::MCParticle MutableMCParticle::getDaughters(std::size_t index) const {
  if (daughters_size() > index) {
    return m_obj->m_daughters->at(m_obj->data.daughters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::MCParticle> MutableMCParticle::getDaughters() const {
  auto begin = m_obj->m_daughters->begin();
  std::advance(begin, m_obj->data.daughters_begin);
  auto end = m_obj->m_daughters->begin();
  std::advance(end, m_obj->data.daughters_end);
  return {begin, end};
}

bool MutableMCParticle::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCParticle::operator==(const MCParticle& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCParticle& value) {
  j = nlohmann::json{{"PDG", value.getPDG()},
                     {"generatorStatus", value.getGeneratorStatus()},
                     {"simulatorStatus", value.getSimulatorStatus()},
                     {"charge", value.getCharge()},
                     {"time", value.getTime()},
                     {"mass", value.getMass()},
                     {"vertex", value.getVertex()},
                     {"endpoint", value.getEndpoint()},
                     {"momentum", value.getMomentum()},
                     {"momentumAtEndpoint", value.getMomentumAtEndpoint()},
                     {"spin", value.getSpin()},
                     {"colorFlow", value.getColorFlow()}};

  j["parents"] = nlohmann::json::array();
  for (const auto& v : value.getParents()) {
    j["parents"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }

  j["daughters"] = nlohmann::json::array();
  for (const auto& v : value.getDaughters()) {
    j["daughters"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
