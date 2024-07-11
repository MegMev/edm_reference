// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticleObj.h"
#include "edm4hep/MutableMCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCParticle::MCParticle() : m_obj(new MCParticleObj{}, podio::utils::MarkOwned) {
}

MCParticle::MCParticle(std::int32_t PDG, std::int32_t generatorStatus, std::int32_t simulatorStatus, float charge,
                       float time, double mass, edm4hep::Vector3d vertex, edm4hep::Vector3d endpoint,
                       edm4hep::Vector3d momentum, edm4hep::Vector3d momentumAtEndpoint, edm4hep::Vector3f spin,
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

MCParticle& MCParticle::operator=(MCParticle other) {
  swap(*this, other);
  return *this;
}

MutableMCParticle MCParticle::clone(bool cloneRelations) const {
  auto tmp = new MCParticleObj(podio::ObjectID{}, m_obj->data);
  tmp->m_parents = new std::vector<edm4hep::MCParticle>();
  tmp->m_daughters = new std::vector<edm4hep::MCParticle>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_parents->reserve(m_obj->m_parents->size());
    for (size_t i = m_obj->data.parents_begin; i < m_obj->data.parents_end; i++) {
      tmp->m_parents->emplace_back((*m_obj->m_parents)[i]);
    }
    tmp->data.parents_begin = 0;
    tmp->data.parents_end = tmp->m_parents->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_daughters->reserve(m_obj->m_daughters->size());
    for (size_t i = m_obj->data.daughters_begin; i < m_obj->data.daughters_end; i++) {
      tmp->m_daughters->emplace_back((*m_obj->m_daughters)[i]);
    }
    tmp->data.daughters_begin = 0;
    tmp->data.daughters_end = tmp->m_daughters->size();
  } else {
    tmp->data.parents_begin = 0;
    tmp->data.parents_end = 0;
    tmp->data.daughters_begin = 0;
    tmp->data.daughters_end = 0;
  }
  return MutableMCParticle(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCParticle::MCParticle(podio::utils::MaybeSharedPtr<MCParticleObj> obj) : m_obj(std::move(obj)) {
}

MCParticle::MCParticle(const MutableMCParticle& other) : MCParticle(other.m_obj) {
}

MCParticle::MCParticle(MCParticleObj* obj) : m_obj(podio::utils::MaybeSharedPtr<MCParticleObj>(obj)) {
}

MCParticle MCParticle::makeEmpty() {
  return {nullptr};
}

std::int32_t MCParticle::getPDG() const {
  return m_obj->data.PDG;
}
std::int32_t MCParticle::getGeneratorStatus() const {
  return m_obj->data.generatorStatus;
}
std::int32_t MCParticle::getSimulatorStatus() const {
  return m_obj->data.simulatorStatus;
}
float MCParticle::getCharge() const {
  return m_obj->data.charge;
}
float MCParticle::getTime() const {
  return m_obj->data.time;
}
double MCParticle::getMass() const {
  return m_obj->data.mass;
}
const edm4hep::Vector3d& MCParticle::getVertex() const {
  return m_obj->data.vertex;
}
const edm4hep::Vector3d& MCParticle::getEndpoint() const {
  return m_obj->data.endpoint;
}
const edm4hep::Vector3d& MCParticle::getMomentum() const {
  return m_obj->data.momentum;
}
const edm4hep::Vector3d& MCParticle::getMomentumAtEndpoint() const {
  return m_obj->data.momentumAtEndpoint;
}
const edm4hep::Vector3f& MCParticle::getSpin() const {
  return m_obj->data.spin;
}
const edm4hep::Vector2i& MCParticle::getColorFlow() const {
  return m_obj->data.colorFlow;
}

std::vector<edm4hep::MCParticle>::const_iterator MCParticle::parents_begin() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_begin);
  return ret_value;
}

std::vector<edm4hep::MCParticle>::const_iterator MCParticle::parents_end() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_end);
  return ret_value;
}

std::size_t MCParticle::parents_size() const {
  return m_obj->data.parents_end - m_obj->data.parents_begin;
}

edm4hep::MCParticle MCParticle::getParents(std::size_t index) const {
  if (parents_size() > index) {
    return m_obj->m_parents->at(m_obj->data.parents_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::MCParticle> MCParticle::getParents() const {
  auto begin = m_obj->m_parents->begin();
  std::advance(begin, m_obj->data.parents_begin);
  auto end = m_obj->m_parents->begin();
  std::advance(end, m_obj->data.parents_end);
  return {begin, end};
}

std::vector<edm4hep::MCParticle>::const_iterator MCParticle::daughters_begin() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_begin);
  return ret_value;
}

std::vector<edm4hep::MCParticle>::const_iterator MCParticle::daughters_end() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_end);
  return ret_value;
}

std::size_t MCParticle::daughters_size() const {
  return m_obj->data.daughters_end - m_obj->data.daughters_begin;
}

edm4hep::MCParticle MCParticle::getDaughters(std::size_t index) const {
  if (daughters_size() > index) {
    return m_obj->m_daughters->at(m_obj->data.daughters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::MCParticle> MCParticle::getDaughters() const {
  auto begin = m_obj->m_daughters->begin();
  std::advance(begin, m_obj->data.daughters_begin);
  auto end = m_obj->m_daughters->begin();
  std::advance(end, m_obj->data.daughters_end);
  return {begin, end};
}

bool MCParticle::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCParticle::operator==(const MutableMCParticle& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCParticle& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " generatorStatus : " << value.getGeneratorStatus() << '\n';
  o << " simulatorStatus : " << value.getSimulatorStatus() << '\n';
  o << " charge : " << value.getCharge() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " mass : " << value.getMass() << '\n';
  o << " vertex : " << value.getVertex() << '\n';
  o << " endpoint : " << value.getEndpoint() << '\n';
  o << " momentum : " << value.getMomentum() << '\n';
  o << " momentumAtEndpoint : " << value.getMomentumAtEndpoint() << '\n';
  o << " spin : " << value.getSpin() << '\n';
  o << " colorFlow : " << value.getColorFlow() << '\n';

  o << " parents : ";
  for (unsigned i = 0; i < value.parents_size(); ++i) {
    o << value.getParents(i).id() << " ";
  }
  o << '\n';
  o << " daughters : ";
  for (unsigned i = 0; i < value.daughters_size(); ++i) {
    o << value.getDaughters(i).id() << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCParticle& value) {
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
