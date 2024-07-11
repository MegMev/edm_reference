// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHitData.h"
#include "edm4hep/RawCalorimeterHitObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

RawCalorimeterHit::RawCalorimeterHit() : m_obj(new RawCalorimeterHitObj{}, podio::utils::MarkOwned) {
}

RawCalorimeterHit::RawCalorimeterHit(std::uint64_t cellID, std::int32_t amplitude, std::int32_t timeStamp) :
    m_obj(new RawCalorimeterHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.amplitude = amplitude;
  m_obj->data.timeStamp = timeStamp;
}

RawCalorimeterHit& RawCalorimeterHit::operator=(RawCalorimeterHit other) {
  swap(*this, other);
  return *this;
}

MutableRawCalorimeterHit RawCalorimeterHit::clone(bool cloneRelations) const {
  auto tmp = new RawCalorimeterHitObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
  } else {
  }
  return MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

RawCalorimeterHit::RawCalorimeterHit(podio::utils::MaybeSharedPtr<RawCalorimeterHitObj> obj) : m_obj(std::move(obj)) {
}

RawCalorimeterHit::RawCalorimeterHit(const MutableRawCalorimeterHit& other) : RawCalorimeterHit(other.m_obj) {
}

RawCalorimeterHit::RawCalorimeterHit(RawCalorimeterHitObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>(obj)) {
}

RawCalorimeterHit RawCalorimeterHit::makeEmpty() {
  return {nullptr};
}

std::uint64_t RawCalorimeterHit::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t RawCalorimeterHit::getAmplitude() const {
  return m_obj->data.amplitude;
}
std::int32_t RawCalorimeterHit::getTimeStamp() const {
  return m_obj->data.timeStamp;
}

bool RawCalorimeterHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID RawCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool RawCalorimeterHit::operator==(const MutableRawCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const RawCalorimeterHit& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " amplitude : " << value.getAmplitude() << '\n';
  o << " timeStamp : " << value.getTimeStamp() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RawCalorimeterHit& value) {
  j = nlohmann::json{
      {"cellID", value.getCellID()}, {"amplitude", value.getAmplitude()}, {"timeStamp", value.getTimeStamp()}};
}
#endif

} // namespace edm4hep
