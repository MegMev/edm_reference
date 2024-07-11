// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRawTimeSeries.h"
#include "edm4hep/RawTimeSeries.h"
#include "edm4hep/RawTimeSeriesData.h"
#include "edm4hep/RawTimeSeriesObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableRawTimeSeries::MutableRawTimeSeries() : m_obj(new RawTimeSeriesObj{}, podio::utils::MarkOwned) {
}

MutableRawTimeSeries::MutableRawTimeSeries(std::uint64_t cellID, std::int32_t quality, float time, float charge,
                                           float interval) :
    m_obj(new RawTimeSeriesObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
  m_obj->data.interval = interval;
}

MutableRawTimeSeries& MutableRawTimeSeries::operator=(MutableRawTimeSeries other) {
  swap(*this, other);
  return *this;
}

MutableRawTimeSeries MutableRawTimeSeries::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new RawTimeSeriesObj(podio::ObjectID{}, m_obj->data);
    tmp->m_adcCounts = new std::vector<std::int32_t>();
    tmp->data.adcCounts_begin = 0;
    tmp->data.adcCounts_end = 0;
    return MutableRawTimeSeries(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableRawTimeSeries(podio::utils::MaybeSharedPtr(new RawTimeSeriesObj(*m_obj), podio::utils::MarkOwned));
}

MutableRawTimeSeries::MutableRawTimeSeries(podio::utils::MaybeSharedPtr<RawTimeSeriesObj> obj) : m_obj(std::move(obj)) {
}

std::uint64_t MutableRawTimeSeries::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t MutableRawTimeSeries::getQuality() const {
  return m_obj->data.quality;
}
float MutableRawTimeSeries::getTime() const {
  return m_obj->data.time;
}
float MutableRawTimeSeries::getCharge() const {
  return m_obj->data.charge;
}
float MutableRawTimeSeries::getInterval() const {
  return m_obj->data.interval;
}

void MutableRawTimeSeries::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableRawTimeSeries::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableRawTimeSeries::cellID() {
  return m_obj->data.cellID;
}
void MutableRawTimeSeries::setQuality(std::int32_t value) {
  m_obj->data.quality = value;
}
std::int32_t& MutableRawTimeSeries::getQuality() {
  return m_obj->data.quality;
}
std::int32_t& MutableRawTimeSeries::quality() {
  return m_obj->data.quality;
}
void MutableRawTimeSeries::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableRawTimeSeries::getTime() {
  return m_obj->data.time;
}
float& MutableRawTimeSeries::time() {
  return m_obj->data.time;
}
void MutableRawTimeSeries::setCharge(float value) {
  m_obj->data.charge = value;
}
float& MutableRawTimeSeries::getCharge() {
  return m_obj->data.charge;
}
float& MutableRawTimeSeries::charge() {
  return m_obj->data.charge;
}
void MutableRawTimeSeries::setInterval(float value) {
  m_obj->data.interval = value;
}
float& MutableRawTimeSeries::getInterval() {
  return m_obj->data.interval;
}
float& MutableRawTimeSeries::interval() {
  return m_obj->data.interval;
}

void MutableRawTimeSeries::addToAdcCounts(const std::int32_t& component) {
  m_obj->m_adcCounts->push_back(component);
  m_obj->data.adcCounts_end++;
}

std::vector<std::int32_t>::const_iterator MutableRawTimeSeries::adcCounts_begin() const {
  auto ret_value = m_obj->m_adcCounts->begin();
  std::advance(ret_value, m_obj->data.adcCounts_begin);
  return ret_value;
}

std::vector<std::int32_t>::const_iterator MutableRawTimeSeries::adcCounts_end() const {
  auto ret_value = m_obj->m_adcCounts->begin();
  std::advance(ret_value, m_obj->data.adcCounts_end);
  return ret_value;
}

std::size_t MutableRawTimeSeries::adcCounts_size() const {
  return m_obj->data.adcCounts_end - m_obj->data.adcCounts_begin;
}

std::int32_t MutableRawTimeSeries::getAdcCounts(std::size_t index) const {
  if (adcCounts_size() > index) {
    return m_obj->m_adcCounts->at(m_obj->data.adcCounts_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::int32_t> MutableRawTimeSeries::getAdcCounts() const {
  auto begin = m_obj->m_adcCounts->begin();
  std::advance(begin, m_obj->data.adcCounts_begin);
  auto end = m_obj->m_adcCounts->begin();
  std::advance(end, m_obj->data.adcCounts_end);
  return {begin, end};
}

bool MutableRawTimeSeries::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableRawTimeSeries::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableRawTimeSeries::operator==(const RawTimeSeries& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRawTimeSeries& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},     {"quality", value.getQuality()},
                     {"time", value.getTime()},         {"charge", value.getCharge()},
                     {"interval", value.getInterval()}, {"adcCounts", value.getAdcCounts()}};
}
#endif

} // namespace edm4hep
