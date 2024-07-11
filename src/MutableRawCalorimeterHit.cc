// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHitData.h"
#include "edm4hep/RawCalorimeterHitObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableRawCalorimeterHit::MutableRawCalorimeterHit() : m_obj(new RawCalorimeterHitObj{}, podio::utils::MarkOwned) {
}

MutableRawCalorimeterHit::MutableRawCalorimeterHit(std::uint64_t cellID, std::int32_t amplitude,
                                                   std::int32_t timeStamp) :
    m_obj(new RawCalorimeterHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.amplitude = amplitude;
  m_obj->data.timeStamp = timeStamp;
}

MutableRawCalorimeterHit& MutableRawCalorimeterHit::operator=(MutableRawCalorimeterHit other) {
  swap(*this, other);
  return *this;
}

MutableRawCalorimeterHit MutableRawCalorimeterHit::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new RawCalorimeterHitObj(podio::ObjectID{}, m_obj->data);
    return MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableRawCalorimeterHit(
      podio::utils::MaybeSharedPtr(new RawCalorimeterHitObj(*m_obj), podio::utils::MarkOwned));
}

MutableRawCalorimeterHit::MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr<RawCalorimeterHitObj> obj) :
    m_obj(std::move(obj)) {
}

std::uint64_t MutableRawCalorimeterHit::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t MutableRawCalorimeterHit::getAmplitude() const {
  return m_obj->data.amplitude;
}
std::int32_t MutableRawCalorimeterHit::getTimeStamp() const {
  return m_obj->data.timeStamp;
}

void MutableRawCalorimeterHit::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableRawCalorimeterHit::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableRawCalorimeterHit::cellID() {
  return m_obj->data.cellID;
}
void MutableRawCalorimeterHit::setAmplitude(std::int32_t value) {
  m_obj->data.amplitude = value;
}
std::int32_t& MutableRawCalorimeterHit::getAmplitude() {
  return m_obj->data.amplitude;
}
std::int32_t& MutableRawCalorimeterHit::amplitude() {
  return m_obj->data.amplitude;
}
void MutableRawCalorimeterHit::setTimeStamp(std::int32_t value) {
  m_obj->data.timeStamp = value;
}
std::int32_t& MutableRawCalorimeterHit::getTimeStamp() {
  return m_obj->data.timeStamp;
}
std::int32_t& MutableRawCalorimeterHit::timeStamp() {
  return m_obj->data.timeStamp;
}

bool MutableRawCalorimeterHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableRawCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableRawCalorimeterHit::operator==(const RawCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRawCalorimeterHit& value) {
  j = nlohmann::json{
      {"cellID", value.getCellID()}, {"amplitude", value.getAmplitude()}, {"timeStamp", value.getTimeStamp()}};
}
#endif

} // namespace edm4hep
