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

#include <ostream>

namespace edm4hep {

Vertex::Vertex() : m_obj(new VertexObj{}, podio::utils::MarkOwned) {
}

Vertex::Vertex(std::int32_t primary, float chi2, std::int32_t ndf, edm4hep::Vector3f position,
               edm4hep::CovMatrix3f covMatrix, std::int32_t algorithmType) :
    m_obj(new VertexObj{}, podio::utils::MarkOwned) {
  m_obj->data.primary = primary;
  m_obj->data.chi2 = chi2;
  m_obj->data.ndf = ndf;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
  m_obj->data.algorithmType = algorithmType;
}

Vertex& Vertex::operator=(Vertex other) {
  swap(*this, other);
  return *this;
}

MutableVertex Vertex::clone(bool cloneRelations) const {
  auto tmp = new VertexObj(podio::ObjectID{}, m_obj->data);
  tmp->m_parameters = new std::vector<float>();
  if (cloneRelations) {
    if (m_obj->m_associatedParticle) {
      tmp->m_associatedParticle = new edm4hep::ReconstructedParticle(*m_obj->m_associatedParticle);
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
  return MutableVertex(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

Vertex::Vertex(podio::utils::MaybeSharedPtr<VertexObj> obj) : m_obj(std::move(obj)) {
}

Vertex::Vertex(const MutableVertex& other) : Vertex(other.m_obj) {
}

Vertex::Vertex(VertexObj* obj) : m_obj(podio::utils::MaybeSharedPtr<VertexObj>(obj)) {
}

Vertex Vertex::makeEmpty() {
  return {nullptr};
}

std::int32_t Vertex::getPrimary() const {
  return m_obj->data.primary;
}
float Vertex::getChi2() const {
  return m_obj->data.chi2;
}
std::int32_t Vertex::getNdf() const {
  return m_obj->data.ndf;
}
const edm4hep::Vector3f& Vertex::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& Vertex::getCovMatrix() const {
  return m_obj->data.covMatrix;
}
std::int32_t Vertex::getAlgorithmType() const {
  return m_obj->data.algorithmType;
}

const edm4hep::ReconstructedParticle Vertex::getAssociatedParticle() const {
  if (!m_obj->m_associatedParticle) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_associatedParticle));
}

std::vector<float>::const_iterator Vertex::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator Vertex::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

std::size_t Vertex::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float Vertex::getParameters(std::size_t index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Vertex::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}

bool Vertex::isAvailable() const {
  return m_obj;
}

const podio::ObjectID Vertex::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool Vertex::operator==(const MutableVertex& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const Vertex& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " primary : " << value.getPrimary() << '\n';
  o << " chi2 : " << value.getChi2() << '\n';
  o << " ndf : " << value.getNdf() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " covMatrix : " << value.getCovMatrix() << '\n';
  o << " algorithmType : " << value.getAlgorithmType() << '\n';

  o << " associatedParticle : " << value.getAssociatedParticle().id() << '\n';

  o << " parameters : ";
  for (unsigned i = 0; i < value.parameters_size(); ++i) {
    o << value.getParameters(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vertex& value) {
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
