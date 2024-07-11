// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableVertex.h"
#include "edm4hep/Vertex.h"
#include "edm4hep/VertexData.h"
#include "edm4hep/VertexObj.h"

#include "edm4hep/ReconstructedParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableVertex::MutableVertex() : m_obj(new VertexObj{}, podio::utils::MarkOwned) {
}

MutableVertex::MutableVertex(std::int32_t primary, float chi2, std::int32_t ndf, edm4hep::Vector3f position,
                             edm4hep::CovMatrix3f covMatrix, std::int32_t algorithmType) :
    m_obj(new VertexObj{}, podio::utils::MarkOwned) {
  m_obj->data.primary = primary;
  m_obj->data.chi2 = chi2;
  m_obj->data.ndf = ndf;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
  m_obj->data.algorithmType = algorithmType;
}

MutableVertex& MutableVertex::operator=(MutableVertex other) {
  swap(*this, other);
  return *this;
}

MutableVertex MutableVertex::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new VertexObj(podio::ObjectID{}, m_obj->data);
    tmp->m_parameters = new std::vector<float>();
    tmp->data.parameters_begin = 0;
    tmp->data.parameters_end = 0;
    return MutableVertex(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableVertex(podio::utils::MaybeSharedPtr(new VertexObj(*m_obj), podio::utils::MarkOwned));
}

MutableVertex::MutableVertex(podio::utils::MaybeSharedPtr<VertexObj> obj) : m_obj(std::move(obj)) {
}

std::int32_t MutableVertex::getPrimary() const {
  return m_obj->data.primary;
}
float MutableVertex::getChi2() const {
  return m_obj->data.chi2;
}
std::int32_t MutableVertex::getNdf() const {
  return m_obj->data.ndf;
}
const edm4hep::Vector3f& MutableVertex::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& MutableVertex::getCovMatrix() const {
  return m_obj->data.covMatrix;
}
std::int32_t MutableVertex::getAlgorithmType() const {
  return m_obj->data.algorithmType;
}

const edm4hep::ReconstructedParticle MutableVertex::getAssociatedParticle() const {
  if (!m_obj->m_associatedParticle) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_associatedParticle));
}

void MutableVertex::setPrimary(std::int32_t value) {
  m_obj->data.primary = value;
}
std::int32_t& MutableVertex::getPrimary() {
  return m_obj->data.primary;
}
std::int32_t& MutableVertex::primary() {
  return m_obj->data.primary;
}
void MutableVertex::setChi2(float value) {
  m_obj->data.chi2 = value;
}
float& MutableVertex::getChi2() {
  return m_obj->data.chi2;
}
float& MutableVertex::chi2() {
  return m_obj->data.chi2;
}
void MutableVertex::setNdf(std::int32_t value) {
  m_obj->data.ndf = value;
}
std::int32_t& MutableVertex::getNdf() {
  return m_obj->data.ndf;
}
std::int32_t& MutableVertex::ndf() {
  return m_obj->data.ndf;
}
void MutableVertex::setPosition(edm4hep::Vector3f value) {
  m_obj->data.position = value;
}
edm4hep::Vector3f& MutableVertex::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3f& MutableVertex::position() {
  return m_obj->data.position;
}
void MutableVertex::setCovMatrix(edm4hep::CovMatrix3f value) {
  m_obj->data.covMatrix = value;
}
edm4hep::CovMatrix3f& MutableVertex::getCovMatrix() {
  return m_obj->data.covMatrix;
}
edm4hep::CovMatrix3f& MutableVertex::covMatrix() {
  return m_obj->data.covMatrix;
}
void MutableVertex::setAlgorithmType(std::int32_t value) {
  m_obj->data.algorithmType = value;
}
std::int32_t& MutableVertex::getAlgorithmType() {
  return m_obj->data.algorithmType;
}
std::int32_t& MutableVertex::algorithmType() {
  return m_obj->data.algorithmType;
}

void MutableVertex::setAssociatedParticle(const edm4hep::ReconstructedParticle& value) {
  delete m_obj->m_associatedParticle;
  m_obj->m_associatedParticle = new edm4hep::ReconstructedParticle(value);
}

void MutableVertex::addToParameters(const float& component) {
  m_obj->m_parameters->push_back(component);
  m_obj->data.parameters_end++;
}

std::vector<float>::const_iterator MutableVertex::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableVertex::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

std::size_t MutableVertex::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float MutableVertex::getParameters(std::size_t index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableVertex::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}

bool MutableVertex::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableVertex::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableVertex::operator==(const Vertex& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableVertex& value) {
  j = nlohmann::json{{"primary", value.getPrimary()},
                     {"chi2", value.getChi2()},
                     {"ndf", value.getNdf()},
                     {"position", value.getPosition()},
                     {"covMatrix", value.getCovMatrix()},
                     {"algorithmType", value.getAlgorithmType()},
                     {"parameters", value.getParameters()}};

  j["associatedParticle"] = nlohmann::json{{"collectionID", value.getAssociatedParticle().getObjectID().collectionID},
                                           {"index", value.getAssociatedParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
