// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/EventHeader.h"
#include "edm4hep/EventHeaderData.h"
#include "edm4hep/EventHeaderObj.h"
#include "edm4hep/MutableEventHeader.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

EventHeader::EventHeader() : m_obj(new EventHeaderObj{}, podio::utils::MarkOwned) {
}

EventHeader::EventHeader(std::int32_t eventNumber, std::int32_t runNumber, std::uint64_t timeStamp, double weight) :
    m_obj(new EventHeaderObj{}, podio::utils::MarkOwned) {
  m_obj->data.eventNumber = eventNumber;
  m_obj->data.runNumber = runNumber;
  m_obj->data.timeStamp = timeStamp;
  m_obj->data.weight = weight;
}

EventHeader& EventHeader::operator=(EventHeader other) {
  swap(*this, other);
  return *this;
}

MutableEventHeader EventHeader::clone(bool cloneRelations) const {
  auto tmp = new EventHeaderObj(podio::ObjectID{}, m_obj->data);
  tmp->m_weights = new std::vector<double>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_weights->reserve(m_obj->m_weights->size());
    for (size_t i = m_obj->data.weights_begin; i < m_obj->data.weights_end; i++) {
      tmp->m_weights->emplace_back((*m_obj->m_weights)[i]);
    }
    tmp->data.weights_begin = 0;
    tmp->data.weights_end = tmp->m_weights->size();
  } else {
    tmp->data.weights_begin = 0;
    tmp->data.weights_end = 0;
  }
  return MutableEventHeader(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

EventHeader::EventHeader(podio::utils::MaybeSharedPtr<EventHeaderObj> obj) : m_obj(std::move(obj)) {
}

EventHeader::EventHeader(const MutableEventHeader& other) : EventHeader(other.m_obj) {
}

EventHeader::EventHeader(EventHeaderObj* obj) : m_obj(podio::utils::MaybeSharedPtr<EventHeaderObj>(obj)) {
}

EventHeader EventHeader::makeEmpty() {
  return {nullptr};
}

std::int32_t EventHeader::getEventNumber() const {
  return m_obj->data.eventNumber;
}
std::int32_t EventHeader::getRunNumber() const {
  return m_obj->data.runNumber;
}
std::uint64_t EventHeader::getTimeStamp() const {
  return m_obj->data.timeStamp;
}
double EventHeader::getWeight() const {
  return m_obj->data.weight;
}

std::vector<double>::const_iterator EventHeader::weights_begin() const {
  auto ret_value = m_obj->m_weights->begin();
  std::advance(ret_value, m_obj->data.weights_begin);
  return ret_value;
}

std::vector<double>::const_iterator EventHeader::weights_end() const {
  auto ret_value = m_obj->m_weights->begin();
  std::advance(ret_value, m_obj->data.weights_end);
  return ret_value;
}

std::size_t EventHeader::weights_size() const {
  return m_obj->data.weights_end - m_obj->data.weights_begin;
}

double EventHeader::getWeights(std::size_t index) const {
  if (weights_size() > index) {
    return m_obj->m_weights->at(m_obj->data.weights_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<double> EventHeader::getWeights() const {
  auto begin = m_obj->m_weights->begin();
  std::advance(begin, m_obj->data.weights_begin);
  auto end = m_obj->m_weights->begin();
  std::advance(end, m_obj->data.weights_end);
  return {begin, end};
}

bool EventHeader::isAvailable() const {
  return m_obj;
}

const podio::ObjectID EventHeader::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool EventHeader::operator==(const MutableEventHeader& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const EventHeader& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " eventNumber : " << value.getEventNumber() << '\n';
  o << " runNumber : " << value.getRunNumber() << '\n';
  o << " timeStamp : " << value.getTimeStamp() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " weights : ";
  for (unsigned i = 0; i < value.weights_size(); ++i) {
    o << value.getWeights(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const EventHeader& value) {
  j = nlohmann::json{{"eventNumber", value.getEventNumber()},
                     {"runNumber", value.getRunNumber()},
                     {"timeStamp", value.getTimeStamp()},
                     {"weight", value.getWeight()},
                     {"weights", value.getWeights()}};
}
#endif

} // namespace edm4hep
