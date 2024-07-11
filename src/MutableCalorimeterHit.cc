// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHitObj.h"
#include "edm4hep/MutableCalorimeterHit.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableCalorimeterHit::MutableCalorimeterHit() : m_obj(new CalorimeterHitObj{}, podio::utils::MarkOwned) {
}

MutableCalorimeterHit::MutableCalorimeterHit(std::uint64_t cellID, float energy, float energyError, float time,
                                             edm4hep::Vector3f position, std::int32_t type) :
    m_obj(new CalorimeterHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.energyError = energyError;
  m_obj->data.time = time;
  m_obj->data.position = position;
  m_obj->data.type = type;
}

MutableCalorimeterHit& MutableCalorimeterHit::operator=(MutableCalorimeterHit other) {
  swap(*this, other);
  return *this;
}

MutableCalorimeterHit MutableCalorimeterHit::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new CalorimeterHitObj(podio::ObjectID{}, m_obj->data);
    return MutableCalorimeterHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableCalorimeterHit(podio::utils::MaybeSharedPtr(new CalorimeterHitObj(*m_obj), podio::utils::MarkOwned));
}

MutableCalorimeterHit::MutableCalorimeterHit(podio::utils::MaybeSharedPtr<CalorimeterHitObj> obj) :
    m_obj(std::move(obj)) {
}

std::uint64_t MutableCalorimeterHit::getCellID() const {
  return m_obj->data.cellID;
}
float MutableCalorimeterHit::getEnergy() const {
  return m_obj->data.energy;
}
float MutableCalorimeterHit::getEnergyError() const {
  return m_obj->data.energyError;
}
float MutableCalorimeterHit::getTime() const {
  return m_obj->data.time;
}
const edm4hep::Vector3f& MutableCalorimeterHit::getPosition() const {
  return m_obj->data.position;
}
std::int32_t MutableCalorimeterHit::getType() const {
  return m_obj->data.type;
}

void MutableCalorimeterHit::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableCalorimeterHit::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableCalorimeterHit::cellID() {
  return m_obj->data.cellID;
}
void MutableCalorimeterHit::setEnergy(float value) {
  m_obj->data.energy = value;
}
float& MutableCalorimeterHit::getEnergy() {
  return m_obj->data.energy;
}
float& MutableCalorimeterHit::energy() {
  return m_obj->data.energy;
}
void MutableCalorimeterHit::setEnergyError(float value) {
  m_obj->data.energyError = value;
}
float& MutableCalorimeterHit::getEnergyError() {
  return m_obj->data.energyError;
}
float& MutableCalorimeterHit::energyError() {
  return m_obj->data.energyError;
}
void MutableCalorimeterHit::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableCalorimeterHit::getTime() {
  return m_obj->data.time;
}
float& MutableCalorimeterHit::time() {
  return m_obj->data.time;
}
void MutableCalorimeterHit::setPosition(edm4hep::Vector3f value) {
  m_obj->data.position = value;
}
edm4hep::Vector3f& MutableCalorimeterHit::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3f& MutableCalorimeterHit::position() {
  return m_obj->data.position;
}
void MutableCalorimeterHit::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableCalorimeterHit::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableCalorimeterHit::type() {
  return m_obj->data.type;
}

bool MutableCalorimeterHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableCalorimeterHit::operator==(const CalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableCalorimeterHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},           {"energy", value.getEnergy()},
                     {"energyError", value.getEnergyError()}, {"time", value.getTime()},
                     {"position", value.getPosition()},       {"type", value.getType()}};
}
#endif

} // namespace edm4hep
