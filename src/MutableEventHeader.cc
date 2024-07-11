// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/EventHeader.h"
#include "edm4hep/EventHeaderData.h"
#include "edm4hep/EventHeaderObj.h"
#include "edm4hep/MutableEventHeader.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableEventHeader::MutableEventHeader() : m_obj(new EventHeaderObj{}, podio::utils::MarkOwned) {
}

MutableEventHeader::MutableEventHeader(std::int32_t eventNumber, std::int32_t runNumber, std::uint64_t timeStamp,
                                       double weight) :
    m_obj(new EventHeaderObj{}, podio::utils::MarkOwned) {
  m_obj->data.eventNumber = eventNumber;
  m_obj->data.runNumber = runNumber;
  m_obj->data.timeStamp = timeStamp;
  m_obj->data.weight = weight;
}

MutableEventHeader& MutableEventHeader::operator=(MutableEventHeader other) {
  swap(*this, other);
  return *this;
}

MutableEventHeader MutableEventHeader::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new EventHeaderObj(podio::ObjectID{}, m_obj->data);
    tmp->m_weights = new std::vector<double>();
    tmp->data.weights_begin = 0;
    tmp->data.weights_end = 0;
    return MutableEventHeader(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableEventHeader(podio::utils::MaybeSharedPtr(new EventHeaderObj(*m_obj), podio::utils::MarkOwned));
}

MutableEventHeader::MutableEventHeader(podio::utils::MaybeSharedPtr<EventHeaderObj> obj) : m_obj(std::move(obj)) {
}

std::int32_t MutableEventHeader::getEventNumber() const {
  return m_obj->data.eventNumber;
}
std::int32_t MutableEventHeader::getRunNumber() const {
  return m_obj->data.runNumber;
}
std::uint64_t MutableEventHeader::getTimeStamp() const {
  return m_obj->data.timeStamp;
}
double MutableEventHeader::getWeight() const {
  return m_obj->data.weight;
}

void MutableEventHeader::setEventNumber(std::int32_t value) {
  m_obj->data.eventNumber = value;
}
std::int32_t& MutableEventHeader::getEventNumber() {
  return m_obj->data.eventNumber;
}
std::int32_t& MutableEventHeader::eventNumber() {
  return m_obj->data.eventNumber;
}
void MutableEventHeader::setRunNumber(std::int32_t value) {
  m_obj->data.runNumber = value;
}
std::int32_t& MutableEventHeader::getRunNumber() {
  return m_obj->data.runNumber;
}
std::int32_t& MutableEventHeader::runNumber() {
  return m_obj->data.runNumber;
}
void MutableEventHeader::setTimeStamp(std::uint64_t value) {
  m_obj->data.timeStamp = value;
}
std::uint64_t& MutableEventHeader::getTimeStamp() {
  return m_obj->data.timeStamp;
}
std::uint64_t& MutableEventHeader::timeStamp() {
  return m_obj->data.timeStamp;
}
void MutableEventHeader::setWeight(double value) {
  m_obj->data.weight = value;
}
double& MutableEventHeader::getWeight() {
  return m_obj->data.weight;
}
double& MutableEventHeader::weight() {
  return m_obj->data.weight;
}

void MutableEventHeader::addToWeights(const double& component) {
  m_obj->m_weights->push_back(component);
  m_obj->data.weights_end++;
}

std::vector<double>::const_iterator MutableEventHeader::weights_begin() const {
  auto ret_value = m_obj->m_weights->begin();
  std::advance(ret_value, m_obj->data.weights_begin);
  return ret_value;
}

std::vector<double>::const_iterator MutableEventHeader::weights_end() const {
  auto ret_value = m_obj->m_weights->begin();
  std::advance(ret_value, m_obj->data.weights_end);
  return ret_value;
}

std::size_t MutableEventHeader::weights_size() const {
  return m_obj->data.weights_end - m_obj->data.weights_begin;
}

double MutableEventHeader::getWeights(std::size_t index) const {
  if (weights_size() > index) {
    return m_obj->m_weights->at(m_obj->data.weights_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<double> MutableEventHeader::getWeights() const {
  auto begin = m_obj->m_weights->begin();
  std::advance(begin, m_obj->data.weights_begin);
  auto end = m_obj->m_weights->begin();
  std::advance(end, m_obj->data.weights_end);
  return {begin, end};
}

bool MutableEventHeader::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableEventHeader::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableEventHeader::operator==(const EventHeader& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableEventHeader& value) {
  j = nlohmann::json{{"eventNumber", value.getEventNumber()},
                     {"runNumber", value.getRunNumber()},
                     {"timeStamp", value.getTimeStamp()},
                     {"weight", value.getWeight()},
                     {"weights", value.getWeights()}};
}
#endif

} // namespace edm4hep
