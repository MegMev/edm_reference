// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableParticleID.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/ParticleIDData.h"
#include "edm4hep/ParticleIDObj.h"

#include "edm4hep/ReconstructedParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableParticleID::MutableParticleID() : m_obj(new ParticleIDObj{}, podio::utils::MarkOwned) {
}

MutableParticleID::MutableParticleID(std::int32_t type, std::int32_t PDG, std::int32_t algorithmType,
                                     float likelihood) :
    m_obj(new ParticleIDObj{}, podio::utils::MarkOwned) {
  m_obj->data.type = type;
  m_obj->data.PDG = PDG;
  m_obj->data.algorithmType = algorithmType;
  m_obj->data.likelihood = likelihood;
}

MutableParticleID& MutableParticleID::operator=(MutableParticleID other) {
  swap(*this, other);
  return *this;
}

MutableParticleID MutableParticleID::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new ParticleIDObj(podio::ObjectID{}, m_obj->data);
    tmp->m_parameters = new std::vector<float>();
    tmp->data.parameters_begin = 0;
    tmp->data.parameters_end = 0;
    return MutableParticleID(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableParticleID(podio::utils::MaybeSharedPtr(new ParticleIDObj(*m_obj), podio::utils::MarkOwned));
}

MutableParticleID::MutableParticleID(podio::utils::MaybeSharedPtr<ParticleIDObj> obj) : m_obj(std::move(obj)) {
}

std::int32_t MutableParticleID::getType() const {
  return m_obj->data.type;
}
std::int32_t MutableParticleID::getPDG() const {
  return m_obj->data.PDG;
}
std::int32_t MutableParticleID::getAlgorithmType() const {
  return m_obj->data.algorithmType;
}
float MutableParticleID::getLikelihood() const {
  return m_obj->data.likelihood;
}

const edm4hep::ReconstructedParticle MutableParticleID::getParticle() const {
  if (!m_obj->m_particle) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_particle));
}

void MutableParticleID::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableParticleID::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableParticleID::type() {
  return m_obj->data.type;
}
void MutableParticleID::setPDG(std::int32_t value) {
  m_obj->data.PDG = value;
}
std::int32_t& MutableParticleID::getPDG() {
  return m_obj->data.PDG;
}
std::int32_t& MutableParticleID::PDG() {
  return m_obj->data.PDG;
}
void MutableParticleID::setAlgorithmType(std::int32_t value) {
  m_obj->data.algorithmType = value;
}
std::int32_t& MutableParticleID::getAlgorithmType() {
  return m_obj->data.algorithmType;
}
std::int32_t& MutableParticleID::algorithmType() {
  return m_obj->data.algorithmType;
}
void MutableParticleID::setLikelihood(float value) {
  m_obj->data.likelihood = value;
}
float& MutableParticleID::getLikelihood() {
  return m_obj->data.likelihood;
}
float& MutableParticleID::likelihood() {
  return m_obj->data.likelihood;
}

void MutableParticleID::setParticle(const edm4hep::ReconstructedParticle& value) {
  delete m_obj->m_particle;
  m_obj->m_particle = new edm4hep::ReconstructedParticle(value);
}

void MutableParticleID::addToParameters(const float& component) {
  m_obj->m_parameters->push_back(component);
  m_obj->data.parameters_end++;
}

std::vector<float>::const_iterator MutableParticleID::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableParticleID::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

std::size_t MutableParticleID::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float MutableParticleID::getParameters(std::size_t index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableParticleID::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}

bool MutableParticleID::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableParticleID::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableParticleID::operator==(const ParticleID& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableParticleID& value) {
  j = nlohmann::json{{"type", value.getType()},
                     {"PDG", value.getPDG()},
                     {"algorithmType", value.getAlgorithmType()},
                     {"likelihood", value.getLikelihood()},
                     {"parameters", value.getParameters()}};

  j["particle"] = nlohmann::json{{"collectionID", value.getParticle().getObjectID().collectionID},
                                 {"index", value.getParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
