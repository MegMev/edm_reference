// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/GeneratorEventParameters.h"
#include "edm4hep/GeneratorEventParametersData.h"
#include "edm4hep/GeneratorEventParametersObj.h"
#include "edm4hep/MutableGeneratorEventParameters.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableGeneratorEventParameters::MutableGeneratorEventParameters() :
    m_obj(new GeneratorEventParametersObj{}, podio::utils::MarkOwned) {
}

MutableGeneratorEventParameters::MutableGeneratorEventParameters(double eventScale, double alphaQED, double alphaQCD,
                                                                 int signalProcessId, double sqrts) :
    m_obj(new GeneratorEventParametersObj{}, podio::utils::MarkOwned) {
  m_obj->data.eventScale = eventScale;
  m_obj->data.alphaQED = alphaQED;
  m_obj->data.alphaQCD = alphaQCD;
  m_obj->data.signalProcessId = signalProcessId;
  m_obj->data.sqrts = sqrts;
}

MutableGeneratorEventParameters& MutableGeneratorEventParameters::operator=(MutableGeneratorEventParameters other) {
  swap(*this, other);
  return *this;
}

MutableGeneratorEventParameters MutableGeneratorEventParameters::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new GeneratorEventParametersObj(podio::ObjectID{}, m_obj->data);
    tmp->m_signalVertex = new std::vector<edm4hep::MCParticle>();
    tmp->data.signalVertex_begin = 0;
    tmp->data.signalVertex_end = 0;
    tmp->m_crossSections = new std::vector<double>();
    tmp->data.crossSections_begin = 0;
    tmp->data.crossSections_end = 0;
    tmp->m_crossSectionErrors = new std::vector<double>();
    tmp->data.crossSectionErrors_begin = 0;
    tmp->data.crossSectionErrors_end = 0;
    return MutableGeneratorEventParameters(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableGeneratorEventParameters(
      podio::utils::MaybeSharedPtr(new GeneratorEventParametersObj(*m_obj), podio::utils::MarkOwned));
}

MutableGeneratorEventParameters::MutableGeneratorEventParameters(
    podio::utils::MaybeSharedPtr<GeneratorEventParametersObj> obj) :
    m_obj(std::move(obj)) {
}

double MutableGeneratorEventParameters::getEventScale() const {
  return m_obj->data.eventScale;
}
double MutableGeneratorEventParameters::getAlphaQED() const {
  return m_obj->data.alphaQED;
}
double MutableGeneratorEventParameters::getAlphaQCD() const {
  return m_obj->data.alphaQCD;
}
int MutableGeneratorEventParameters::getSignalProcessId() const {
  return m_obj->data.signalProcessId;
}
double MutableGeneratorEventParameters::getSqrts() const {
  return m_obj->data.sqrts;
}

void MutableGeneratorEventParameters::setEventScale(double value) {
  m_obj->data.eventScale = value;
}
double& MutableGeneratorEventParameters::getEventScale() {
  return m_obj->data.eventScale;
}
double& MutableGeneratorEventParameters::eventScale() {
  return m_obj->data.eventScale;
}
void MutableGeneratorEventParameters::setAlphaQED(double value) {
  m_obj->data.alphaQED = value;
}
double& MutableGeneratorEventParameters::getAlphaQED() {
  return m_obj->data.alphaQED;
}
double& MutableGeneratorEventParameters::alphaQED() {
  return m_obj->data.alphaQED;
}
void MutableGeneratorEventParameters::setAlphaQCD(double value) {
  m_obj->data.alphaQCD = value;
}
double& MutableGeneratorEventParameters::getAlphaQCD() {
  return m_obj->data.alphaQCD;
}
double& MutableGeneratorEventParameters::alphaQCD() {
  return m_obj->data.alphaQCD;
}
void MutableGeneratorEventParameters::setSignalProcessId(int value) {
  m_obj->data.signalProcessId = value;
}
int& MutableGeneratorEventParameters::getSignalProcessId() {
  return m_obj->data.signalProcessId;
}
int& MutableGeneratorEventParameters::signalProcessId() {
  return m_obj->data.signalProcessId;
}
void MutableGeneratorEventParameters::setSqrts(double value) {
  m_obj->data.sqrts = value;
}
double& MutableGeneratorEventParameters::getSqrts() {
  return m_obj->data.sqrts;
}
double& MutableGeneratorEventParameters::sqrts() {
  return m_obj->data.sqrts;
}

void MutableGeneratorEventParameters::addToSignalVertex(const edm4hep::MCParticle& component) {
  m_obj->m_signalVertex->push_back(component);
  m_obj->data.signalVertex_end++;
}

std::vector<edm4hep::MCParticle>::const_iterator MutableGeneratorEventParameters::signalVertex_begin() const {
  auto ret_value = m_obj->m_signalVertex->begin();
  std::advance(ret_value, m_obj->data.signalVertex_begin);
  return ret_value;
}

std::vector<edm4hep::MCParticle>::const_iterator MutableGeneratorEventParameters::signalVertex_end() const {
  auto ret_value = m_obj->m_signalVertex->begin();
  std::advance(ret_value, m_obj->data.signalVertex_end);
  return ret_value;
}

std::size_t MutableGeneratorEventParameters::signalVertex_size() const {
  return m_obj->data.signalVertex_end - m_obj->data.signalVertex_begin;
}

edm4hep::MCParticle MutableGeneratorEventParameters::getSignalVertex(std::size_t index) const {
  if (signalVertex_size() > index) {
    return m_obj->m_signalVertex->at(m_obj->data.signalVertex_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::MCParticle> MutableGeneratorEventParameters::getSignalVertex() const {
  auto begin = m_obj->m_signalVertex->begin();
  std::advance(begin, m_obj->data.signalVertex_begin);
  auto end = m_obj->m_signalVertex->begin();
  std::advance(end, m_obj->data.signalVertex_end);
  return {begin, end};
}

void MutableGeneratorEventParameters::addToCrossSections(const double& component) {
  m_obj->m_crossSections->push_back(component);
  m_obj->data.crossSections_end++;
}

std::vector<double>::const_iterator MutableGeneratorEventParameters::crossSections_begin() const {
  auto ret_value = m_obj->m_crossSections->begin();
  std::advance(ret_value, m_obj->data.crossSections_begin);
  return ret_value;
}

std::vector<double>::const_iterator MutableGeneratorEventParameters::crossSections_end() const {
  auto ret_value = m_obj->m_crossSections->begin();
  std::advance(ret_value, m_obj->data.crossSections_end);
  return ret_value;
}

std::size_t MutableGeneratorEventParameters::crossSections_size() const {
  return m_obj->data.crossSections_end - m_obj->data.crossSections_begin;
}

double MutableGeneratorEventParameters::getCrossSections(std::size_t index) const {
  if (crossSections_size() > index) {
    return m_obj->m_crossSections->at(m_obj->data.crossSections_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<double> MutableGeneratorEventParameters::getCrossSections() const {
  auto begin = m_obj->m_crossSections->begin();
  std::advance(begin, m_obj->data.crossSections_begin);
  auto end = m_obj->m_crossSections->begin();
  std::advance(end, m_obj->data.crossSections_end);
  return {begin, end};
}

void MutableGeneratorEventParameters::addToCrossSectionErrors(const double& component) {
  m_obj->m_crossSectionErrors->push_back(component);
  m_obj->data.crossSectionErrors_end++;
}

std::vector<double>::const_iterator MutableGeneratorEventParameters::crossSectionErrors_begin() const {
  auto ret_value = m_obj->m_crossSectionErrors->begin();
  std::advance(ret_value, m_obj->data.crossSectionErrors_begin);
  return ret_value;
}

std::vector<double>::const_iterator MutableGeneratorEventParameters::crossSectionErrors_end() const {
  auto ret_value = m_obj->m_crossSectionErrors->begin();
  std::advance(ret_value, m_obj->data.crossSectionErrors_end);
  return ret_value;
}

std::size_t MutableGeneratorEventParameters::crossSectionErrors_size() const {
  return m_obj->data.crossSectionErrors_end - m_obj->data.crossSectionErrors_begin;
}

double MutableGeneratorEventParameters::getCrossSectionErrors(std::size_t index) const {
  if (crossSectionErrors_size() > index) {
    return m_obj->m_crossSectionErrors->at(m_obj->data.crossSectionErrors_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<double> MutableGeneratorEventParameters::getCrossSectionErrors() const {
  auto begin = m_obj->m_crossSectionErrors->begin();
  std::advance(begin, m_obj->data.crossSectionErrors_begin);
  auto end = m_obj->m_crossSectionErrors->begin();
  std::advance(end, m_obj->data.crossSectionErrors_end);
  return {begin, end};
}

bool MutableGeneratorEventParameters::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableGeneratorEventParameters::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableGeneratorEventParameters::operator==(const GeneratorEventParameters& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableGeneratorEventParameters& value) {
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
