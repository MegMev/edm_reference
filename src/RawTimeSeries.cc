// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRawTimeSeries.h"
#include "edm4hep/RawTimeSeries.h"
#include "edm4hep/RawTimeSeriesData.h"
#include "edm4hep/RawTimeSeriesObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

RawTimeSeries::RawTimeSeries() : m_obj(new RawTimeSeriesObj{}, podio::utils::MarkOwned) {
}

RawTimeSeries::RawTimeSeries(std::uint64_t cellID, std::int32_t quality, float time, float charge, float interval) :
    m_obj(new RawTimeSeriesObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
  m_obj->data.interval = interval;
}

RawTimeSeries& RawTimeSeries::operator=(RawTimeSeries other) {
  swap(*this, other);
  return *this;
}

MutableRawTimeSeries RawTimeSeries::clone(bool cloneRelations) const {
  auto tmp = new RawTimeSeriesObj(podio::ObjectID{}, m_obj->data);
  tmp->m_adcCounts = new std::vector<std::int32_t>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_adcCounts->reserve(m_obj->m_adcCounts->size());
    for (size_t i = m_obj->data.adcCounts_begin; i < m_obj->data.adcCounts_end; i++) {
      tmp->m_adcCounts->emplace_back((*m_obj->m_adcCounts)[i]);
    }
    tmp->data.adcCounts_begin = 0;
    tmp->data.adcCounts_end = tmp->m_adcCounts->size();
  } else {
    tmp->data.adcCounts_begin = 0;
    tmp->data.adcCounts_end = 0;
  }
  return MutableRawTimeSeries(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

RawTimeSeries::RawTimeSeries(podio::utils::MaybeSharedPtr<RawTimeSeriesObj> obj) : m_obj(std::move(obj)) {
}

RawTimeSeries::RawTimeSeries(const MutableRawTimeSeries& other) : RawTimeSeries(other.m_obj) {
}

RawTimeSeries::RawTimeSeries(RawTimeSeriesObj* obj) : m_obj(podio::utils::MaybeSharedPtr<RawTimeSeriesObj>(obj)) {
}

RawTimeSeries RawTimeSeries::makeEmpty() {
  return {nullptr};
}

std::uint64_t RawTimeSeries::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t RawTimeSeries::getQuality() const {
  return m_obj->data.quality;
}
float RawTimeSeries::getTime() const {
  return m_obj->data.time;
}
float RawTimeSeries::getCharge() const {
  return m_obj->data.charge;
}
float RawTimeSeries::getInterval() const {
  return m_obj->data.interval;
}

std::vector<std::int32_t>::const_iterator RawTimeSeries::adcCounts_begin() const {
  auto ret_value = m_obj->m_adcCounts->begin();
  std::advance(ret_value, m_obj->data.adcCounts_begin);
  return ret_value;
}

std::vector<std::int32_t>::const_iterator RawTimeSeries::adcCounts_end() const {
  auto ret_value = m_obj->m_adcCounts->begin();
  std::advance(ret_value, m_obj->data.adcCounts_end);
  return ret_value;
}

std::size_t RawTimeSeries::adcCounts_size() const {
  return m_obj->data.adcCounts_end - m_obj->data.adcCounts_begin;
}

std::int32_t RawTimeSeries::getAdcCounts(std::size_t index) const {
  if (adcCounts_size() > index) {
    return m_obj->m_adcCounts->at(m_obj->data.adcCounts_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::int32_t> RawTimeSeries::getAdcCounts() const {
  auto begin = m_obj->m_adcCounts->begin();
  std::advance(begin, m_obj->data.adcCounts_begin);
  auto end = m_obj->m_adcCounts->begin();
  std::advance(end, m_obj->data.adcCounts_end);
  return {begin, end};
}

bool RawTimeSeries::isAvailable() const {
  return m_obj;
}

const podio::ObjectID RawTimeSeries::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool RawTimeSeries::operator==(const MutableRawTimeSeries& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const RawTimeSeries& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " charge : " << value.getCharge() << '\n';
  o << " interval : " << value.getInterval() << '\n';

  o << " adcCounts : ";
  for (unsigned i = 0; i < value.adcCounts_size(); ++i) {
    o << value.getAdcCounts(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RawTimeSeries& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},     {"quality", value.getQuality()},
                     {"time", value.getTime()},         {"charge", value.getCharge()},
                     {"interval", value.getInterval()}, {"adcCounts", value.getAdcCounts()}};
}
#endif

} // namespace edm4hep
