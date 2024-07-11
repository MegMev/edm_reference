// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTimeSeries.h"
#include "edm4hep/TimeSeries.h"
#include "edm4hep/TimeSeriesData.h"
#include "edm4hep/TimeSeriesObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

TimeSeries::TimeSeries() : m_obj(new TimeSeriesObj{}, podio::utils::MarkOwned) {
}

TimeSeries::TimeSeries(std::uint64_t cellID, float time, float interval) :
    m_obj(new TimeSeriesObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.interval = interval;
}

TimeSeries& TimeSeries::operator=(TimeSeries other) {
  swap(*this, other);
  return *this;
}

MutableTimeSeries TimeSeries::clone(bool cloneRelations) const {
  auto tmp = new TimeSeriesObj(podio::ObjectID{}, m_obj->data);
  tmp->m_amplitude = new std::vector<float>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_amplitude->reserve(m_obj->m_amplitude->size());
    for (size_t i = m_obj->data.amplitude_begin; i < m_obj->data.amplitude_end; i++) {
      tmp->m_amplitude->emplace_back((*m_obj->m_amplitude)[i]);
    }
    tmp->data.amplitude_begin = 0;
    tmp->data.amplitude_end = tmp->m_amplitude->size();
  } else {
    tmp->data.amplitude_begin = 0;
    tmp->data.amplitude_end = 0;
  }
  return MutableTimeSeries(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

TimeSeries::TimeSeries(podio::utils::MaybeSharedPtr<TimeSeriesObj> obj) : m_obj(std::move(obj)) {
}

TimeSeries::TimeSeries(const MutableTimeSeries& other) : TimeSeries(other.m_obj) {
}

TimeSeries::TimeSeries(TimeSeriesObj* obj) : m_obj(podio::utils::MaybeSharedPtr<TimeSeriesObj>(obj)) {
}

TimeSeries TimeSeries::makeEmpty() {
  return {nullptr};
}

std::uint64_t TimeSeries::getCellID() const {
  return m_obj->data.cellID;
}
float TimeSeries::getTime() const {
  return m_obj->data.time;
}
float TimeSeries::getInterval() const {
  return m_obj->data.interval;
}

std::vector<float>::const_iterator TimeSeries::amplitude_begin() const {
  auto ret_value = m_obj->m_amplitude->begin();
  std::advance(ret_value, m_obj->data.amplitude_begin);
  return ret_value;
}

std::vector<float>::const_iterator TimeSeries::amplitude_end() const {
  auto ret_value = m_obj->m_amplitude->begin();
  std::advance(ret_value, m_obj->data.amplitude_end);
  return ret_value;
}

std::size_t TimeSeries::amplitude_size() const {
  return m_obj->data.amplitude_end - m_obj->data.amplitude_begin;
}

float TimeSeries::getAmplitude(std::size_t index) const {
  if (amplitude_size() > index) {
    return m_obj->m_amplitude->at(m_obj->data.amplitude_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> TimeSeries::getAmplitude() const {
  auto begin = m_obj->m_amplitude->begin();
  std::advance(begin, m_obj->data.amplitude_begin);
  auto end = m_obj->m_amplitude->begin();
  std::advance(end, m_obj->data.amplitude_end);
  return {begin, end};
}

bool TimeSeries::isAvailable() const {
  return m_obj;
}

const podio::ObjectID TimeSeries::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool TimeSeries::operator==(const MutableTimeSeries& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const TimeSeries& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " interval : " << value.getInterval() << '\n';

  o << " amplitude : ";
  for (unsigned i = 0; i < value.amplitude_size(); ++i) {
    o << value.getAmplitude(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TimeSeries& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"time", value.getTime()},
                     {"interval", value.getInterval()},
                     {"amplitude", value.getAmplitude()}};
}
#endif

} // namespace edm4hep
