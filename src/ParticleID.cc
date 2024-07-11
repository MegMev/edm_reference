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

#include <ostream>

namespace edm4hep {

ParticleID::ParticleID() : m_obj(new ParticleIDObj{}, podio::utils::MarkOwned) {
}

ParticleID::ParticleID(std::int32_t type, std::int32_t PDG, std::int32_t algorithmType, float likelihood) :
    m_obj(new ParticleIDObj{}, podio::utils::MarkOwned) {
  m_obj->data.type = type;
  m_obj->data.PDG = PDG;
  m_obj->data.algorithmType = algorithmType;
  m_obj->data.likelihood = likelihood;
}

ParticleID& ParticleID::operator=(ParticleID other) {
  swap(*this, other);
  return *this;
}

MutableParticleID ParticleID::clone(bool cloneRelations) const {
  auto tmp = new ParticleIDObj(podio::ObjectID{}, m_obj->data);
  tmp->m_parameters = new std::vector<float>();
  if (cloneRelations) {
    if (m_obj->m_particle) {
      tmp->m_particle = new edm4hep::ReconstructedParticle(*m_obj->m_particle);
    }
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_parameters->reserve(m_obj->m_parameters->size());
    for (size_t i = m_obj->data.parameters_begin; i < m_obj->data.parameters_end; i++) {
      tmp->m_parameters->emplace_back((*m_obj->m_parameters)[i]);
    }
    tmp->data.parameters_begin = 0;
    tmp->data.parameters_end = tmp->m_parameters->size();
  } else {
    tmp->data.parameters_begin = 0;
    tmp->data.parameters_end = 0;
  }
  return MutableParticleID(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

ParticleID::ParticleID(podio::utils::MaybeSharedPtr<ParticleIDObj> obj) : m_obj(std::move(obj)) {
}

ParticleID::ParticleID(const MutableParticleID& other) : ParticleID(other.m_obj) {
}

ParticleID::ParticleID(ParticleIDObj* obj) : m_obj(podio::utils::MaybeSharedPtr<ParticleIDObj>(obj)) {
}

ParticleID ParticleID::makeEmpty() {
  return {nullptr};
}

std::int32_t ParticleID::getType() const {
  return m_obj->data.type;
}
std::int32_t ParticleID::getPDG() const {
  return m_obj->data.PDG;
}
std::int32_t ParticleID::getAlgorithmType() const {
  return m_obj->data.algorithmType;
}
float ParticleID::getLikelihood() const {
  return m_obj->data.likelihood;
}

const edm4hep::ReconstructedParticle ParticleID::getParticle() const {
  if (!m_obj->m_particle) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_particle));
}

std::vector<float>::const_iterator ParticleID::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator ParticleID::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

std::size_t ParticleID::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float ParticleID::getParameters(std::size_t index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ParticleID::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}

bool ParticleID::isAvailable() const {
  return m_obj;
}

const podio::ObjectID ParticleID::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool ParticleID::operator==(const MutableParticleID& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ParticleID& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " algorithmType : " << value.getAlgorithmType() << '\n';
  o << " likelihood : " << value.getLikelihood() << '\n';

  o << " particle : " << value.getParticle().id() << '\n';

  o << " parameters : ";
  for (unsigned i = 0; i < value.parameters_size(); ++i) {
    o << value.getParameters(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ParticleID& value) {
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
