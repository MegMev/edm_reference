// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHitObj.h"
#include "edm4hep/MutableCalorimeterHit.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

CalorimeterHit::CalorimeterHit() : m_obj(new CalorimeterHitObj{}, podio::utils::MarkOwned) {
}

CalorimeterHit::CalorimeterHit(std::uint64_t cellID, float energy, float energyError, float time,
                               edm4hep::Vector3f position, std::int32_t type) :
    m_obj(new CalorimeterHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.energyError = energyError;
  m_obj->data.time = time;
  m_obj->data.position = position;
  m_obj->data.type = type;
}

CalorimeterHit& CalorimeterHit::operator=(CalorimeterHit other) {
  swap(*this, other);
  return *this;
}

MutableCalorimeterHit CalorimeterHit::clone(bool cloneRelations) const {
  auto tmp = new CalorimeterHitObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
  } else {
  }
  return MutableCalorimeterHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

CalorimeterHit::CalorimeterHit(podio::utils::MaybeSharedPtr<CalorimeterHitObj> obj) : m_obj(std::move(obj)) {
}

CalorimeterHit::CalorimeterHit(const MutableCalorimeterHit& other) : CalorimeterHit(other.m_obj) {
}

CalorimeterHit::CalorimeterHit(CalorimeterHitObj* obj) : m_obj(podio::utils::MaybeSharedPtr<CalorimeterHitObj>(obj)) {
}

CalorimeterHit CalorimeterHit::makeEmpty() {
  return {nullptr};
}

std::uint64_t CalorimeterHit::getCellID() const {
  return m_obj->data.cellID;
}
float CalorimeterHit::getEnergy() const {
  return m_obj->data.energy;
}
float CalorimeterHit::getEnergyError() const {
  return m_obj->data.energyError;
}
float CalorimeterHit::getTime() const {
  return m_obj->data.time;
}
const edm4hep::Vector3f& CalorimeterHit::getPosition() const {
  return m_obj->data.position;
}
std::int32_t CalorimeterHit::getType() const {
  return m_obj->data.type;
}

bool CalorimeterHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID CalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool CalorimeterHit::operator==(const MutableCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const CalorimeterHit& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " energyError : " << value.getEnergyError() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " type : " << value.getType() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const CalorimeterHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},           {"energy", value.getEnergy()},
                     {"energyError", value.getEnergyError()}, {"time", value.getTime()},
                     {"position", value.getPosition()},       {"type", value.getType()}};
}
#endif

} // namespace edm4hep
