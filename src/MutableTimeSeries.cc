// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTimeSeries.h"
#include "edm4hep/TimeSeries.h"
#include "edm4hep/TimeSeriesData.h"
#include "edm4hep/TimeSeriesObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableTimeSeries::MutableTimeSeries() : m_obj(new TimeSeriesObj{}, podio::utils::MarkOwned) {
}

MutableTimeSeries::MutableTimeSeries(std::uint64_t cellID, float time, float interval) :
    m_obj(new TimeSeriesObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.interval = interval;
}

MutableTimeSeries& MutableTimeSeries::operator=(MutableTimeSeries other) {
  swap(*this, other);
  return *this;
}

MutableTimeSeries MutableTimeSeries::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new TimeSeriesObj(podio::ObjectID{}, m_obj->data);
    tmp->m_amplitude = new std::vector<float>();
    tmp->data.amplitude_begin = 0;
    tmp->data.amplitude_end = 0;
    return MutableTimeSeries(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableTimeSeries(podio::utils::MaybeSharedPtr(new TimeSeriesObj(*m_obj), podio::utils::MarkOwned));
}

MutableTimeSeries::MutableTimeSeries(podio::utils::MaybeSharedPtr<TimeSeriesObj> obj) : m_obj(std::move(obj)) {
}

std::uint64_t MutableTimeSeries::getCellID() const {
  return m_obj->data.cellID;
}
float MutableTimeSeries::getTime() const {
  return m_obj->data.time;
}
float MutableTimeSeries::getInterval() const {
  return m_obj->data.interval;
}

void MutableTimeSeries::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableTimeSeries::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableTimeSeries::cellID() {
  return m_obj->data.cellID;
}
void MutableTimeSeries::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableTimeSeries::getTime() {
  return m_obj->data.time;
}
float& MutableTimeSeries::time() {
  return m_obj->data.time;
}
void MutableTimeSeries::setInterval(float value) {
  m_obj->data.interval = value;
}
float& MutableTimeSeries::getInterval() {
  return m_obj->data.interval;
}
float& MutableTimeSeries::interval() {
  return m_obj->data.interval;
}

void MutableTimeSeries::addToAmplitude(const float& component) {
  m_obj->m_amplitude->push_back(component);
  m_obj->data.amplitude_end++;
}

std::vector<float>::const_iterator MutableTimeSeries::amplitude_begin() const {
  auto ret_value = m_obj->m_amplitude->begin();
  std::advance(ret_value, m_obj->data.amplitude_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableTimeSeries::amplitude_end() const {
  auto ret_value = m_obj->m_amplitude->begin();
  std::advance(ret_value, m_obj->data.amplitude_end);
  return ret_value;
}

std::size_t MutableTimeSeries::amplitude_size() const {
  return m_obj->data.amplitude_end - m_obj->data.amplitude_begin;
}

float MutableTimeSeries::getAmplitude(std::size_t index) const {
  if (amplitude_size() > index) {
    return m_obj->m_amplitude->at(m_obj->data.amplitude_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableTimeSeries::getAmplitude() const {
  auto begin = m_obj->m_amplitude->begin();
  std::advance(begin, m_obj->data.amplitude_begin);
  auto end = m_obj->m_amplitude->begin();
  std::advance(end, m_obj->data.amplitude_end);
  return {begin, end};
}

bool MutableTimeSeries::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableTimeSeries::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableTimeSeries::operator==(const TimeSeries& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTimeSeries& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"time", value.getTime()},
                     {"interval", value.getInterval()},
                     {"amplitude", value.getAmplitude()}};
}
#endif

} // namespace edm4hep
