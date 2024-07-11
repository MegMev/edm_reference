// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRecIonizationCluster.h"
#include "edm4hep/RecIonizationCluster.h"
#include "edm4hep/RecIonizationClusterData.h"
#include "edm4hep/RecIonizationClusterObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableRecIonizationCluster::MutableRecIonizationCluster() :
    m_obj(new RecIonizationClusterObj{}, podio::utils::MarkOwned) {
}

MutableRecIonizationCluster::MutableRecIonizationCluster(std::uint64_t cellID, float significance, std::int16_t type) :
    m_obj(new RecIonizationClusterObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.significance = significance;
  m_obj->data.type = type;
}

MutableRecIonizationCluster& MutableRecIonizationCluster::operator=(MutableRecIonizationCluster other) {
  swap(*this, other);
  return *this;
}

MutableRecIonizationCluster MutableRecIonizationCluster::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new RecIonizationClusterObj(podio::ObjectID{}, m_obj->data);
    tmp->m_trackerPulse = new std::vector<edm4hep::TrackerPulse>();
    tmp->data.trackerPulse_begin = 0;
    tmp->data.trackerPulse_end = 0;
    return MutableRecIonizationCluster(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableRecIonizationCluster(
      podio::utils::MaybeSharedPtr(new RecIonizationClusterObj(*m_obj), podio::utils::MarkOwned));
}

MutableRecIonizationCluster::MutableRecIonizationCluster(podio::utils::MaybeSharedPtr<RecIonizationClusterObj> obj) :
    m_obj(std::move(obj)) {
}

std::uint64_t MutableRecIonizationCluster::getCellID() const {
  return m_obj->data.cellID;
}
float MutableRecIonizationCluster::getSignificance() const {
  return m_obj->data.significance;
}
std::int16_t MutableRecIonizationCluster::getType() const {
  return m_obj->data.type;
}

void MutableRecIonizationCluster::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableRecIonizationCluster::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableRecIonizationCluster::cellID() {
  return m_obj->data.cellID;
}
void MutableRecIonizationCluster::setSignificance(float value) {
  m_obj->data.significance = value;
}
float& MutableRecIonizationCluster::getSignificance() {
  return m_obj->data.significance;
}
float& MutableRecIonizationCluster::significance() {
  return m_obj->data.significance;
}
void MutableRecIonizationCluster::setType(std::int16_t value) {
  m_obj->data.type = value;
}
std::int16_t& MutableRecIonizationCluster::getType() {
  return m_obj->data.type;
}
std::int16_t& MutableRecIonizationCluster::type() {
  return m_obj->data.type;
}

void MutableRecIonizationCluster::addToTrackerPulse(const edm4hep::TrackerPulse& component) {
  m_obj->m_trackerPulse->push_back(component);
  m_obj->data.trackerPulse_end++;
}

std::vector<edm4hep::TrackerPulse>::const_iterator MutableRecIonizationCluster::trackerPulse_begin() const {
  auto ret_value = m_obj->m_trackerPulse->begin();
  std::advance(ret_value, m_obj->data.trackerPulse_begin);
  return ret_value;
}

std::vector<edm4hep::TrackerPulse>::const_iterator MutableRecIonizationCluster::trackerPulse_end() const {
  auto ret_value = m_obj->m_trackerPulse->begin();
  std::advance(ret_value, m_obj->data.trackerPulse_end);
  return ret_value;
}

std::size_t MutableRecIonizationCluster::trackerPulse_size() const {
  return m_obj->data.trackerPulse_end - m_obj->data.trackerPulse_begin;
}

edm4hep::TrackerPulse MutableRecIonizationCluster::getTrackerPulse(std::size_t index) const {
  if (trackerPulse_size() > index) {
    return m_obj->m_trackerPulse->at(m_obj->data.trackerPulse_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::TrackerPulse> MutableRecIonizationCluster::getTrackerPulse() const {
  auto begin = m_obj->m_trackerPulse->begin();
  std::advance(begin, m_obj->data.trackerPulse_begin);
  auto end = m_obj->m_trackerPulse->begin();
  std::advance(end, m_obj->data.trackerPulse_end);
  return {begin, end};
}

bool MutableRecIonizationCluster::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableRecIonizationCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableRecIonizationCluster::operator==(const RecIonizationCluster& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRecIonizationCluster& value) {
  j = nlohmann::json{
      {"cellID", value.getCellID()}, {"significance", value.getSignificance()}, {"type", value.getType()}};

  j["trackerPulse"] = nlohmann::json::array();
  for (const auto& v : value.getTrackerPulse()) {
    j["trackerPulse"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
