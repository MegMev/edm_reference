// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/GeneratorEventParameters.h"
#include "edm4hep/GeneratorEventParametersData.h"
#include "edm4hep/GeneratorEventParametersObj.h"
#include "edm4hep/MutableGeneratorEventParameters.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

GeneratorEventParameters::GeneratorEventParameters() :
    m_obj(new GeneratorEventParametersObj{}, podio::utils::MarkOwned) {
}

GeneratorEventParameters::GeneratorEventParameters(double eventScale, double alphaQED, double alphaQCD,
                                                   int signalProcessId, double sqrts) :
    m_obj(new GeneratorEventParametersObj{}, podio::utils::MarkOwned) {
  m_obj->data.eventScale = eventScale;
  m_obj->data.alphaQED = alphaQED;
  m_obj->data.alphaQCD = alphaQCD;
  m_obj->data.signalProcessId = signalProcessId;
  m_obj->data.sqrts = sqrts;
}

GeneratorEventParameters& GeneratorEventParameters::operator=(GeneratorEventParameters other) {
  swap(*this, other);
  return *this;
}

MutableGeneratorEventParameters GeneratorEventParameters::clone(bool cloneRelations) const {
  auto tmp = new GeneratorEventParametersObj(podio::ObjectID{}, m_obj->data);
  tmp->m_signalVertex = new std::vector<edm4hep::MCParticle>();
  tmp->m_crossSections = new std::vector<double>();
  tmp->m_crossSectionErrors = new std::vector<double>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_signalVertex->reserve(m_obj->m_signalVertex->size());
    for (size_t i = m_obj->data.signalVertex_begin; i < m_obj->data.signalVertex_end; i++) {
      tmp->m_signalVertex->emplace_back((*m_obj->m_signalVertex)[i]);
    }
    tmp->data.signalVertex_begin = 0;
    tmp->data.signalVertex_end = tmp->m_signalVertex->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_crossSections->reserve(m_obj->m_crossSections->size());
    for (size_t i = m_obj->data.crossSections_begin; i < m_obj->data.crossSections_end; i++) {
      tmp->m_crossSections->emplace_back((*m_obj->m_crossSections)[i]);
    }
    tmp->data.crossSections_begin = 0;
    tmp->data.crossSections_end = tmp->m_crossSections->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_crossSectionErrors->reserve(m_obj->m_crossSectionErrors->size());
    for (size_t i = m_obj->data.crossSectionErrors_begin; i < m_obj->data.crossSectionErrors_end; i++) {
      tmp->m_crossSectionErrors->emplace_back((*m_obj->m_crossSectionErrors)[i]);
    }
    tmp->data.crossSectionErrors_begin = 0;
    tmp->data.crossSectionErrors_end = tmp->m_crossSectionErrors->size();
  } else {
    tmp->data.signalVertex_begin = 0;
    tmp->data.signalVertex_end = 0;
    tmp->data.crossSections_begin = 0;
    tmp->data.crossSections_end = 0;
    tmp->data.crossSectionErrors_begin = 0;
    tmp->data.crossSectionErrors_end = 0;
  }
  return MutableGeneratorEventParameters(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

GeneratorEventParameters::GeneratorEventParameters(podio::utils::MaybeSharedPtr<GeneratorEventParametersObj> obj) :
    m_obj(std::move(obj)) {
}

GeneratorEventParameters::GeneratorEventParameters(const MutableGeneratorEventParameters& other) :
    GeneratorEventParameters(other.m_obj) {
}

GeneratorEventParameters::GeneratorEventParameters(GeneratorEventParametersObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<GeneratorEventParametersObj>(obj)) {
}

GeneratorEventParameters GeneratorEventParameters::makeEmpty() {
  return {nullptr};
}

double GeneratorEventParameters::getEventScale() const {
  return m_obj->data.eventScale;
}
double GeneratorEventParameters::getAlphaQED() const {
  return m_obj->data.alphaQED;
}
double GeneratorEventParameters::getAlphaQCD() const {
  return m_obj->data.alphaQCD;
}
int GeneratorEventParameters::getSignalProcessId() const {
  return m_obj->data.signalProcessId;
}
double GeneratorEventParameters::getSqrts() const {
  return m_obj->data.sqrts;
}

std::vector<edm4hep::MCParticle>::const_iterator GeneratorEventParameters::signalVertex_begin() const {
  auto ret_value = m_obj->m_signalVertex->begin();
  std::advance(ret_value, m_obj->data.signalVertex_begin);
  return ret_value;
}

std::vector<edm4hep::MCParticle>::const_iterator GeneratorEventParameters::signalVertex_end() const {
  auto ret_value = m_obj->m_signalVertex->begin();
  std::advance(ret_value, m_obj->data.signalVertex_end);
  return ret_value;
}

std::size_t GeneratorEventParameters::signalVertex_size() const {
  return m_obj->data.signalVertex_end - m_obj->data.signalVertex_begin;
}

edm4hep::MCParticle GeneratorEventParameters::getSignalVertex(std::size_t index) const {
  if (signalVertex_size() > index) {
    return m_obj->m_signalVertex->at(m_obj->data.signalVertex_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::MCParticle> GeneratorEventParameters::getSignalVertex() const {
  auto begin = m_obj->m_signalVertex->begin();
  std::advance(begin, m_obj->data.signalVertex_begin);
  auto end = m_obj->m_signalVertex->begin();
  std::advance(end, m_obj->data.signalVertex_end);
  return {begin, end};
}

std::vector<double>::const_iterator GeneratorEventParameters::crossSections_begin() const {
  auto ret_value = m_obj->m_crossSections->begin();
  std::advance(ret_value, m_obj->data.crossSections_begin);
  return ret_value;
}

std::vector<double>::const_iterator GeneratorEventParameters::crossSections_end() const {
  auto ret_value = m_obj->m_crossSections->begin();
  std::advance(ret_value, m_obj->data.crossSections_end);
  return ret_value;
}

std::size_t GeneratorEventParameters::crossSections_size() const {
  return m_obj->data.crossSections_end - m_obj->data.crossSections_begin;
}

double GeneratorEventParameters::getCrossSections(std::size_t index) const {
  if (crossSections_size() > index) {
    return m_obj->m_crossSections->at(m_obj->data.crossSections_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<double> GeneratorEventParameters::getCrossSections() const {
  auto begin = m_obj->m_crossSections->begin();
  std::advance(begin, m_obj->data.crossSections_begin);
  auto end = m_obj->m_crossSections->begin();
  std::advance(end, m_obj->data.crossSections_end);
  return {begin, end};
}

std::vector<double>::const_iterator GeneratorEventParameters::crossSectionErrors_begin() const {
  auto ret_value = m_obj->m_crossSectionErrors->begin();
  std::advance(ret_value, m_obj->data.crossSectionErrors_begin);
  return ret_value;
}

std::vector<double>::const_iterator GeneratorEventParameters::crossSectionErrors_end() const {
  auto ret_value = m_obj->m_crossSectionErrors->begin();
  std::advance(ret_value, m_obj->data.crossSectionErrors_end);
  return ret_value;
}

std::size_t GeneratorEventParameters::crossSectionErrors_size() const {
  return m_obj->data.crossSectionErrors_end - m_obj->data.crossSectionErrors_begin;
}

double GeneratorEventParameters::getCrossSectionErrors(std::size_t index) const {
  if (crossSectionErrors_size() > index) {
    return m_obj->m_crossSectionErrors->at(m_obj->data.crossSectionErrors_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<double> GeneratorEventParameters::getCrossSectionErrors() const {
  auto begin = m_obj->m_crossSectionErrors->begin();
  std::advance(begin, m_obj->data.crossSectionErrors_begin);
  auto end = m_obj->m_crossSectionErrors->begin();
  std::advance(end, m_obj->data.crossSectionErrors_end);
  return {begin, end};
}

bool GeneratorEventParameters::isAvailable() const {
  return m_obj;
}

const podio::ObjectID GeneratorEventParameters::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool GeneratorEventParameters::operator==(const MutableGeneratorEventParameters& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const GeneratorEventParameters& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " eventScale : " << value.getEventScale() << '\n';
  o << " alphaQED : " << value.getAlphaQED() << '\n';
  o << " alphaQCD : " << value.getAlphaQCD() << '\n';
  o << " signalProcessId : " << value.getSignalProcessId() << '\n';
  o << " sqrts : " << value.getSqrts() << '\n';

  o << " signalVertex : ";
  for (unsigned i = 0; i < value.signalVertex_size(); ++i) {
    o << value.getSignalVertex(i) << " ";
  }
  o << '\n';
  o << " crossSections : ";
  for (unsigned i = 0; i < value.crossSections_size(); ++i) {
    o << value.getCrossSections(i) << " ";
  }
  o << '\n';
  o << " crossSectionErrors : ";
  for (unsigned i = 0; i < value.crossSectionErrors_size(); ++i) {
    o << value.getCrossSectionErrors(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const GeneratorEventParameters& value) {
  j = nlohmann::json{{"eventScale", value.getEventScale()},
                     {"alphaQED", value.getAlphaQED()},
                     {"alphaQCD", value.getAlphaQCD()},
                     {"signalProcessId", value.getSignalProcessId()},
                     {"sqrts", value.getSqrts()},
                     {"crossSections", value.getCrossSections()},
                     {"crossSectionErrors", value.getCrossSectionErrors()}};

  j["signalVertex"] = nlohmann::json::array();
  for (const auto& v : value.getSignalVertex()) {
    j["signalVertex"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
