// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerPulse.h"
#include "edm4hep/TrackerPulse.h"
#include "edm4hep/TrackerPulseData.h"
#include "edm4hep/TrackerPulseObj.h"

#include "edm4hep/TimeSeries.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableTrackerPulse::MutableTrackerPulse() : m_obj(new TrackerPulseObj{}, podio::utils::MarkOwned) {
}

MutableTrackerPulse::MutableTrackerPulse(std::uint64_t cellID, float time, float charge, std::int16_t quality,
                                         std::array<float, 3> covMatrix) :
    m_obj(new TrackerPulseObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
  m_obj->data.quality = quality;
  m_obj->data.covMatrix = covMatrix;
}

MutableTrackerPulse& MutableTrackerPulse::operator=(MutableTrackerPulse other) {
  swap(*this, other);
  return *this;
}

MutableTrackerPulse MutableTrackerPulse::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new TrackerPulseObj(podio::ObjectID{}, m_obj->data);
    return MutableTrackerPulse(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableTrackerPulse(podio::utils::MaybeSharedPtr(new TrackerPulseObj(*m_obj), podio::utils::MarkOwned));
}

MutableTrackerPulse::MutableTrackerPulse(podio::utils::MaybeSharedPtr<TrackerPulseObj> obj) : m_obj(std::move(obj)) {
}

std::uint64_t MutableTrackerPulse::getCellID() const {
  return m_obj->data.cellID;
}
float MutableTrackerPulse::getTime() const {
  return m_obj->data.time;
}
float MutableTrackerPulse::getCharge() const {
  return m_obj->data.charge;
}
std::int16_t MutableTrackerPulse::getQuality() const {
  return m_obj->data.quality;
}
const std::array<float, 3>& MutableTrackerPulse::getCovMatrix() const {
  return m_obj->data.covMatrix;
}
float MutableTrackerPulse::getCovMatrix(size_t i) const {
  return m_obj->data.covMatrix.at(i);
}

const edm4hep::TimeSeries MutableTrackerPulse::getTimeSeries() const {
  if (!m_obj->m_timeSeries) {
    return edm4hep::TimeSeries::makeEmpty();
  }
  return edm4hep::TimeSeries(*(m_obj->m_timeSeries));
}

void MutableTrackerPulse::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableTrackerPulse::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableTrackerPulse::cellID() {
  return m_obj->data.cellID;
}
void MutableTrackerPulse::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableTrackerPulse::getTime() {
  return m_obj->data.time;
}
float& MutableTrackerPulse::time() {
  return m_obj->data.time;
}
void MutableTrackerPulse::setCharge(float value) {
  m_obj->data.charge = value;
}
float& MutableTrackerPulse::getCharge() {
  return m_obj->data.charge;
}
float& MutableTrackerPulse::charge() {
  return m_obj->data.charge;
}
void MutableTrackerPulse::setQuality(std::int16_t value) {
  m_obj->data.quality = value;
}
std::int16_t& MutableTrackerPulse::getQuality() {
  return m_obj->data.quality;
}
std::int16_t& MutableTrackerPulse::quality() {
  return m_obj->data.quality;
}
void MutableTrackerPulse::setCovMatrix(std::array<float, 3> value) {
  m_obj->data.covMatrix = value;
}
void MutableTrackerPulse::setCovMatrix(size_t i, float value) {
  m_obj->data.covMatrix.at(i) = value;
}
std::array<float, 3>& MutableTrackerPulse::getCovMatrix() {
  return m_obj->data.covMatrix;
}
std::array<float, 3>& MutableTrackerPulse::covMatrix() {
  return m_obj->data.covMatrix;
}

void MutableTrackerPulse::setTimeSeries(const edm4hep::TimeSeries& value) {
  delete m_obj->m_timeSeries;
  m_obj->m_timeSeries = new edm4hep::TimeSeries(value);
}

bool MutableTrackerPulse::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableTrackerPulse::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableTrackerPulse::operator==(const TrackerPulse& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerPulse& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"time", value.getTime()},
                     {"charge", value.getCharge()},
                     {"quality", value.getQuality()},
                     {"covMatrix", value.getCovMatrix()}};

  j["timeSeries"] = nlohmann::json{{"collectionID", value.getTimeSeries().getObjectID().collectionID},
                                   {"index", value.getTimeSeries().getObjectID().index}};
}
#endif

} // namespace edm4hep
