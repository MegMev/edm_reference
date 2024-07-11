// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableSimPrimaryIonizationCluster.h"
#include "edm4hep/SimPrimaryIonizationCluster.h"
#include "edm4hep/SimPrimaryIonizationClusterData.h"
#include "edm4hep/SimPrimaryIonizationClusterObj.h"

#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster() :
    m_obj(new SimPrimaryIonizationClusterObj{}, podio::utils::MarkOwned) {
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster(std::uint64_t cellID, float time, edm4hep::Vector3d position,
                                                         std::int16_t type) :
    m_obj(new SimPrimaryIonizationClusterObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.position = position;
  m_obj->data.type = type;
}

SimPrimaryIonizationCluster& SimPrimaryIonizationCluster::operator=(SimPrimaryIonizationCluster other) {
  swap(*this, other);
  return *this;
}

MutableSimPrimaryIonizationCluster SimPrimaryIonizationCluster::clone(bool cloneRelations) const {
  auto tmp = new SimPrimaryIonizationClusterObj(podio::ObjectID{}, m_obj->data);
  tmp->m_electronCellID = new std::vector<std::uint64_t>();
  tmp->m_electronTime = new std::vector<float>();
  tmp->m_electronPosition = new std::vector<edm4hep::Vector3d>();
  tmp->m_pulseTime = new std::vector<float>();
  tmp->m_pulseAmplitude = new std::vector<float>();
  if (cloneRelations) {
    if (m_obj->m_MCParticle) {
      tmp->m_MCParticle = new edm4hep::MCParticle(*m_obj->m_MCParticle);
    }
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_electronCellID->reserve(m_obj->m_electronCellID->size());
    for (size_t i = m_obj->data.electronCellID_begin; i < m_obj->data.electronCellID_end; i++) {
      tmp->m_electronCellID->emplace_back((*m_obj->m_electronCellID)[i]);
    }
    tmp->data.electronCellID_begin = 0;
    tmp->data.electronCellID_end = tmp->m_electronCellID->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_electronTime->reserve(m_obj->m_electronTime->size());
    for (size_t i = m_obj->data.electronTime_begin; i < m_obj->data.electronTime_end; i++) {
      tmp->m_electronTime->emplace_back((*m_obj->m_electronTime)[i]);
    }
    tmp->data.electronTime_begin = 0;
    tmp->data.electronTime_end = tmp->m_electronTime->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_electronPosition->reserve(m_obj->m_electronPosition->size());
    for (size_t i = m_obj->data.electronPosition_begin; i < m_obj->data.electronPosition_end; i++) {
      tmp->m_electronPosition->emplace_back((*m_obj->m_electronPosition)[i]);
    }
    tmp->data.electronPosition_begin = 0;
    tmp->data.electronPosition_end = tmp->m_electronPosition->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_pulseTime->reserve(m_obj->m_pulseTime->size());
    for (size_t i = m_obj->data.pulseTime_begin; i < m_obj->data.pulseTime_end; i++) {
      tmp->m_pulseTime->emplace_back((*m_obj->m_pulseTime)[i]);
    }
    tmp->data.pulseTime_begin = 0;
    tmp->data.pulseTime_end = tmp->m_pulseTime->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_pulseAmplitude->reserve(m_obj->m_pulseAmplitude->size());
    for (size_t i = m_obj->data.pulseAmplitude_begin; i < m_obj->data.pulseAmplitude_end; i++) {
      tmp->m_pulseAmplitude->emplace_back((*m_obj->m_pulseAmplitude)[i]);
    }
    tmp->data.pulseAmplitude_begin = 0;
    tmp->data.pulseAmplitude_end = tmp->m_pulseAmplitude->size();
  } else {
    tmp->data.electronCellID_begin = 0;
    tmp->data.electronCellID_end = 0;
    tmp->data.electronTime_begin = 0;
    tmp->data.electronTime_end = 0;
    tmp->data.electronPosition_begin = 0;
    tmp->data.electronPosition_end = 0;
    tmp->data.pulseTime_begin = 0;
    tmp->data.pulseTime_end = 0;
    tmp->data.pulseAmplitude_begin = 0;
    tmp->data.pulseAmplitude_end = 0;
  }
  return MutableSimPrimaryIonizationCluster(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster(
    podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj> obj) :
    m_obj(std::move(obj)) {
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster(const MutableSimPrimaryIonizationCluster& other) :
    SimPrimaryIonizationCluster(other.m_obj) {
}

SimPrimaryIonizationCluster::SimPrimaryIonizationCluster(SimPrimaryIonizationClusterObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj>(obj)) {
}

SimPrimaryIonizationCluster SimPrimaryIonizationCluster::makeEmpty() {
  return {nullptr};
}

std::uint64_t SimPrimaryIonizationCluster::getCellID() const {
  return m_obj->data.cellID;
}
float SimPrimaryIonizationCluster::getTime() const {
  return m_obj->data.time;
}
const edm4hep::Vector3d& SimPrimaryIonizationCluster::getPosition() const {
  return m_obj->data.position;
}
std::int16_t SimPrimaryIonizationCluster::getType() const {
  return m_obj->data.type;
}

const edm4hep::MCParticle SimPrimaryIonizationCluster::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_MCParticle));
}

std::vector<std::uint64_t>::const_iterator SimPrimaryIonizationCluster::electronCellID_begin() const {
  auto ret_value = m_obj->m_electronCellID->begin();
  std::advance(ret_value, m_obj->data.electronCellID_begin);
  return ret_value;
}

std::vector<std::uint64_t>::const_iterator SimPrimaryIonizationCluster::electronCellID_end() const {
  auto ret_value = m_obj->m_electronCellID->begin();
  std::advance(ret_value, m_obj->data.electronCellID_end);
  return ret_value;
}

std::size_t SimPrimaryIonizationCluster::electronCellID_size() const {
  return m_obj->data.electronCellID_end - m_obj->data.electronCellID_begin;
}

std::uint64_t SimPrimaryIonizationCluster::getElectronCellID(std::size_t index) const {
  if (electronCellID_size() > index) {
    return m_obj->m_electronCellID->at(m_obj->data.electronCellID_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::uint64_t> SimPrimaryIonizationCluster::getElectronCellID() const {
  auto begin = m_obj->m_electronCellID->begin();
  std::advance(begin, m_obj->data.electronCellID_begin);
  auto end = m_obj->m_electronCellID->begin();
  std::advance(end, m_obj->data.electronCellID_end);
  return {begin, end};
}

std::vector<float>::const_iterator SimPrimaryIonizationCluster::electronTime_begin() const {
  auto ret_value = m_obj->m_electronTime->begin();
  std::advance(ret_value, m_obj->data.electronTime_begin);
  return ret_value;
}

std::vector<float>::const_iterator SimPrimaryIonizationCluster::electronTime_end() const {
  auto ret_value = m_obj->m_electronTime->begin();
  std::advance(ret_value, m_obj->data.electronTime_end);
  return ret_value;
}

std::size_t SimPrimaryIonizationCluster::electronTime_size() const {
  return m_obj->data.electronTime_end - m_obj->data.electronTime_begin;
}

float SimPrimaryIonizationCluster::getElectronTime(std::size_t index) const {
  if (electronTime_size() > index) {
    return m_obj->m_electronTime->at(m_obj->data.electronTime_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> SimPrimaryIonizationCluster::getElectronTime() const {
  auto begin = m_obj->m_electronTime->begin();
  std::advance(begin, m_obj->data.electronTime_begin);
  auto end = m_obj->m_electronTime->begin();
  std::advance(end, m_obj->data.electronTime_end);
  return {begin, end};
}

std::vector<edm4hep::Vector3d>::const_iterator SimPrimaryIonizationCluster::electronPosition_begin() const {
  auto ret_value = m_obj->m_electronPosition->begin();
  std::advance(ret_value, m_obj->data.electronPosition_begin);
  return ret_value;
}

std::vector<edm4hep::Vector3d>::const_iterator SimPrimaryIonizationCluster::electronPosition_end() const {
  auto ret_value = m_obj->m_electronPosition->begin();
  std::advance(ret_value, m_obj->data.electronPosition_end);
  return ret_value;
}

std::size_t SimPrimaryIonizationCluster::electronPosition_size() const {
  return m_obj->data.electronPosition_end - m_obj->data.electronPosition_begin;
}

edm4hep::Vector3d SimPrimaryIonizationCluster::getElectronPosition(std::size_t index) const {
  if (electronPosition_size() > index) {
    return m_obj->m_electronPosition->at(m_obj->data.electronPosition_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Vector3d> SimPrimaryIonizationCluster::getElectronPosition() const {
  auto begin = m_obj->m_electronPosition->begin();
  std::advance(begin, m_obj->data.electronPosition_begin);
  auto end = m_obj->m_electronPosition->begin();
  std::advance(end, m_obj->data.electronPosition_end);
  return {begin, end};
}

std::vector<float>::const_iterator SimPrimaryIonizationCluster::pulseTime_begin() const {
  auto ret_value = m_obj->m_pulseTime->begin();
  std::advance(ret_value, m_obj->data.pulseTime_begin);
  return ret_value;
}

std::vector<float>::const_iterator SimPrimaryIonizationCluster::pulseTime_end() const {
  auto ret_value = m_obj->m_pulseTime->begin();
  std::advance(ret_value, m_obj->data.pulseTime_end);
  return ret_value;
}

std::size_t SimPrimaryIonizationCluster::pulseTime_size() const {
  return m_obj->data.pulseTime_end - m_obj->data.pulseTime_begin;
}

float SimPrimaryIonizationCluster::getPulseTime(std::size_t index) const {
  if (pulseTime_size() > index) {
    return m_obj->m_pulseTime->at(m_obj->data.pulseTime_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> SimPrimaryIonizationCluster::getPulseTime() const {
  auto begin = m_obj->m_pulseTime->begin();
  std::advance(begin, m_obj->data.pulseTime_begin);
  auto end = m_obj->m_pulseTime->begin();
  std::advance(end, m_obj->data.pulseTime_end);
  return {begin, end};
}

std::vector<float>::const_iterator SimPrimaryIonizationCluster::pulseAmplitude_begin() const {
  auto ret_value = m_obj->m_pulseAmplitude->begin();
  std::advance(ret_value, m_obj->data.pulseAmplitude_begin);
  return ret_value;
}

std::vector<float>::const_iterator SimPrimaryIonizationCluster::pulseAmplitude_end() const {
  auto ret_value = m_obj->m_pulseAmplitude->begin();
  std::advance(ret_value, m_obj->data.pulseAmplitude_end);
  return ret_value;
}

std::size_t SimPrimaryIonizationCluster::pulseAmplitude_size() const {
  return m_obj->data.pulseAmplitude_end - m_obj->data.pulseAmplitude_begin;
}

float SimPrimaryIonizationCluster::getPulseAmplitude(std::size_t index) const {
  if (pulseAmplitude_size() > index) {
    return m_obj->m_pulseAmplitude->at(m_obj->data.pulseAmplitude_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> SimPrimaryIonizationCluster::getPulseAmplitude() const {
  auto begin = m_obj->m_pulseAmplitude->begin();
  std::advance(begin, m_obj->data.pulseAmplitude_begin);
  auto end = m_obj->m_pulseAmplitude->begin();
  std::advance(end, m_obj->data.pulseAmplitude_end);
  return {begin, end};
}

bool SimPrimaryIonizationCluster::isAvailable() const {
  return m_obj;
}

const podio::ObjectID SimPrimaryIonizationCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool SimPrimaryIonizationCluster::operator==(const MutableSimPrimaryIonizationCluster& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const SimPrimaryIonizationCluster& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " type : " << value.getType() << '\n';

  o << " MCParticle : " << value.getMCParticle().id() << '\n';

  o << " electronCellID : ";
  for (unsigned i = 0; i < value.electronCellID_size(); ++i) {
    o << value.getElectronCellID(i) << " ";
  }
  o << '\n';
  o << " electronTime : ";
  for (unsigned i = 0; i < value.electronTime_size(); ++i) {
    o << value.getElectronTime(i) << " ";
  }
  o << '\n';
  o << " electronPosition : ";
  for (unsigned i = 0; i < value.electronPosition_size(); ++i) {
    o << value.getElectronPosition(i) << " ";
  }
  o << '\n';
  o << " pulseTime : ";
  for (unsigned i = 0; i < value.pulseTime_size(); ++i) {
    o << value.getPulseTime(i) << " ";
  }
  o << '\n';
  o << " pulseAmplitude : ";
  for (unsigned i = 0; i < value.pulseAmplitude_size(); ++i) {
    o << value.getPulseAmplitude(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimPrimaryIonizationCluster& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"time", value.getTime()},
                     {"position", value.getPosition()},
                     {"type", value.getType()},
                     {"electronCellID", value.getElectronCellID()},
                     {"electronTime", value.getElectronTime()},
                     {"electronPosition", value.getElectronPosition()},
                     {"pulseTime", value.getPulseTime()},
                     {"pulseAmplitude", value.getPulseAmplitude()}};

  j["MCParticle"] = nlohmann::json{{"collectionID", value.getMCParticle().getObjectID().collectionID},
                                   {"index", value.getMCParticle().getObjectID().index}};
}
#endif

} // namespace edm4hep
