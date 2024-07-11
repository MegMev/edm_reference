// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableSimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/SimCalorimeterHitObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableSimCalorimeterHit::MutableSimCalorimeterHit() : m_obj(new SimCalorimeterHitObj{}, podio::utils::MarkOwned) {
}

MutableSimCalorimeterHit::MutableSimCalorimeterHit(std::uint64_t cellID, float energy, edm4hep::Vector3f position) :
    m_obj(new SimCalorimeterHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.position = position;
}

MutableSimCalorimeterHit& MutableSimCalorimeterHit::operator=(MutableSimCalorimeterHit other) {
  swap(*this, other);
  return *this;
}

MutableSimCalorimeterHit MutableSimCalorimeterHit::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new SimCalorimeterHitObj(podio::ObjectID{}, m_obj->data);
    tmp->m_contributions = new std::vector<edm4hep::CaloHitContribution>();
    tmp->data.contributions_begin = 0;
    tmp->data.contributions_end = 0;
    return MutableSimCalorimeterHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableSimCalorimeterHit(
      podio::utils::MaybeSharedPtr(new SimCalorimeterHitObj(*m_obj), podio::utils::MarkOwned));
}

MutableSimCalorimeterHit::MutableSimCalorimeterHit(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj> obj) :
    m_obj(std::move(obj)) {
}

std::uint64_t MutableSimCalorimeterHit::getCellID() const {
  return m_obj->data.cellID;
}
float MutableSimCalorimeterHit::getEnergy() const {
  return m_obj->data.energy;
}
const edm4hep::Vector3f& MutableSimCalorimeterHit::getPosition() const {
  return m_obj->data.position;
}

void MutableSimCalorimeterHit::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableSimCalorimeterHit::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableSimCalorimeterHit::cellID() {
  return m_obj->data.cellID;
}
void MutableSimCalorimeterHit::setEnergy(float value) {
  m_obj->data.energy = value;
}
float& MutableSimCalorimeterHit::getEnergy() {
  return m_obj->data.energy;
}
float& MutableSimCalorimeterHit::energy() {
  return m_obj->data.energy;
}
void MutableSimCalorimeterHit::setPosition(edm4hep::Vector3f value) {
  m_obj->data.position = value;
}
edm4hep::Vector3f& MutableSimCalorimeterHit::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3f& MutableSimCalorimeterHit::position() {
  return m_obj->data.position;
}

void MutableSimCalorimeterHit::addToContributions(const edm4hep::CaloHitContribution& component) {
  m_obj->m_contributions->push_back(component);
  m_obj->data.contributions_end++;
}

std::vector<edm4hep::CaloHitContribution>::const_iterator MutableSimCalorimeterHit::contributions_begin() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_begin);
  return ret_value;
}

std::vector<edm4hep::CaloHitContribution>::const_iterator MutableSimCalorimeterHit::contributions_end() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_end);
  return ret_value;
}

std::size_t MutableSimCalorimeterHit::contributions_size() const {
  return m_obj->data.contributions_end - m_obj->data.contributions_begin;
}

edm4hep::CaloHitContribution MutableSimCalorimeterHit::getContributions(std::size_t index) const {
  if (contributions_size() > index) {
    return m_obj->m_contributions->at(m_obj->data.contributions_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::CaloHitContribution> MutableSimCalorimeterHit::getContributions() const {
  auto begin = m_obj->m_contributions->begin();
  std::advance(begin, m_obj->data.contributions_begin);
  auto end = m_obj->m_contributions->begin();
  std::advance(end, m_obj->data.contributions_end);
  return {begin, end};
}

bool MutableSimCalorimeterHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableSimCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableSimCalorimeterHit::operator==(const SimCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableSimCalorimeterHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()}, {"energy", value.getEnergy()}, {"position", value.getPosition()}};

  j["contributions"] = nlohmann::json::array();
  for (const auto& v : value.getContributions()) {
    j["contributions"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
