// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRecIonizationCluster.h"
#include "edm4hep/RecIonizationCluster.h"
#include "edm4hep/RecIonizationClusterData.h"
#include "edm4hep/RecIonizationClusterObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

RecIonizationCluster::RecIonizationCluster() : m_obj(new RecIonizationClusterObj{}, podio::utils::MarkOwned) {
}

RecIonizationCluster::RecIonizationCluster(std::uint64_t cellID, float significance, std::int16_t type) :
    m_obj(new RecIonizationClusterObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.significance = significance;
  m_obj->data.type = type;
}

RecIonizationCluster& RecIonizationCluster::operator=(RecIonizationCluster other) {
  swap(*this, other);
  return *this;
}

MutableRecIonizationCluster RecIonizationCluster::clone(bool cloneRelations) const {
  auto tmp = new RecIonizationClusterObj(podio::ObjectID{}, m_obj->data);
  tmp->m_trackerPulse = new std::vector<edm4hep::TrackerPulse>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_trackerPulse->reserve(m_obj->m_trackerPulse->size());
    for (size_t i = m_obj->data.trackerPulse_begin; i < m_obj->data.trackerPulse_end; i++) {
      tmp->m_trackerPulse->emplace_back((*m_obj->m_trackerPulse)[i]);
    }
    tmp->data.trackerPulse_begin = 0;
    tmp->data.trackerPulse_end = tmp->m_trackerPulse->size();
  } else {
    tmp->data.trackerPulse_begin = 0;
    tmp->data.trackerPulse_end = 0;
  }
  return MutableRecIonizationCluster(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

RecIonizationCluster::RecIonizationCluster(podio::utils::MaybeSharedPtr<RecIonizationClusterObj> obj) :
    m_obj(std::move(obj)) {
}

RecIonizationCluster::RecIonizationCluster(const MutableRecIonizationCluster& other) :
    RecIonizationCluster(other.m_obj) {
}

RecIonizationCluster::RecIonizationCluster(RecIonizationClusterObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<RecIonizationClusterObj>(obj)) {
}

RecIonizationCluster RecIonizationCluster::makeEmpty() {
  return {nullptr};
}

std::uint64_t RecIonizationCluster::getCellID() const {
  return m_obj->data.cellID;
}
float RecIonizationCluster::getSignificance() const {
  return m_obj->data.significance;
}
std::int16_t RecIonizationCluster::getType() const {
  return m_obj->data.type;
}

std::vector<edm4hep::TrackerPulse>::const_iterator RecIonizationCluster::trackerPulse_begin() const {
  auto ret_value = m_obj->m_trackerPulse->begin();
  std::advance(ret_value, m_obj->data.trackerPulse_begin);
  return ret_value;
}

std::vector<edm4hep::TrackerPulse>::const_iterator RecIonizationCluster::trackerPulse_end() const {
  auto ret_value = m_obj->m_trackerPulse->begin();
  std::advance(ret_value, m_obj->data.trackerPulse_end);
  return ret_value;
}

std::size_t RecIonizationCluster::trackerPulse_size() const {
  return m_obj->data.trackerPulse_end - m_obj->data.trackerPulse_begin;
}

edm4hep::TrackerPulse RecIonizationCluster::getTrackerPulse(std::size_t index) const {
  if (trackerPulse_size() > index) {
    return m_obj->m_trackerPulse->at(m_obj->data.trackerPulse_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::TrackerPulse> RecIonizationCluster::getTrackerPulse() const {
  auto begin = m_obj->m_trackerPulse->begin();
  std::advance(begin, m_obj->data.trackerPulse_begin);
  auto end = m_obj->m_trackerPulse->begin();
  std::advance(end, m_obj->data.trackerPulse_end);
  return {begin, end};
}

bool RecIonizationCluster::isAvailable() const {
  return m_obj;
}

const podio::ObjectID RecIonizationCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool RecIonizationCluster::operator==(const MutableRecIonizationCluster& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const RecIonizationCluster& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " significance : " << value.getSignificance() << '\n';
  o << " type : " << value.getType() << '\n';

  o << " trackerPulse : ";
  for (unsigned i = 0; i < value.trackerPulse_size(); ++i) {
    o << value.getTrackerPulse(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecIonizationCluster& value) {
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
