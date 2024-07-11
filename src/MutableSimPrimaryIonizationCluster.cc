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

namespace edm4hep {

MutableSimPrimaryIonizationCluster::MutableSimPrimaryIonizationCluster() :
    m_obj(new SimPrimaryIonizationClusterObj{}, podio::utils::MarkOwned) {
}

MutableSimPrimaryIonizationCluster::MutableSimPrimaryIonizationCluster(std::uint64_t cellID, float time,
                                                                       edm4hep::Vector3d position, std::int16_t type) :
    m_obj(new SimPrimaryIonizationClusterObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.position = position;
  m_obj->data.type = type;
}

MutableSimPrimaryIonizationCluster&
MutableSimPrimaryIonizationCluster::operator=(MutableSimPrimaryIonizationCluster other) {
  swap(*this, other);
  return *this;
}

MutableSimPrimaryIonizationCluster MutableSimPrimaryIonizationCluster::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new SimPrimaryIonizationClusterObj(podio::ObjectID{}, m_obj->data);
    tmp->m_electronCellID = new std::vector<std::uint64_t>();
    tmp->data.electronCellID_begin = 0;
    tmp->data.electronCellID_end = 0;
    tmp->m_electronTime = new std::vector<float>();
    tmp->data.electronTime_begin = 0;
    tmp->data.electronTime_end = 0;
    tmp->m_electronPosition = new std::vector<edm4hep::Vector3d>();
    tmp->data.electronPosition_begin = 0;
    tmp->data.electronPosition_end = 0;
    tmp->m_pulseTime = new std::vector<float>();
    tmp->data.pulseTime_begin = 0;
    tmp->data.pulseTime_end = 0;
    tmp->m_pulseAmplitude = new std::vector<float>();
    tmp->data.pulseAmplitude_begin = 0;
    tmp->data.pulseAmplitude_end = 0;
    return MutableSimPrimaryIonizationCluster(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableSimPrimaryIonizationCluster(
      podio::utils::MaybeSharedPtr(new SimPrimaryIonizationClusterObj(*m_obj), podio::utils::MarkOwned));
}

MutableSimPrimaryIonizationCluster::MutableSimPrimaryIonizationCluster(
    podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj> obj) :
    m_obj(std::move(obj)) {
}

std::uint64_t MutableSimPrimaryIonizationCluster::getCellID() const {
  return m_obj->data.cellID;
}
float MutableSimPrimaryIonizationCluster::getTime() const {
  return m_obj->data.time;
}
const edm4hep::Vector3d& MutableSimPrimaryIonizationCluster::getPosition() const {
  return m_obj->data.position;
}
std::int16_t MutableSimPrimaryIonizationCluster::getType() const {
  return m_obj->data.type;
}

const edm4hep::MCParticle MutableSimPrimaryIonizationCluster::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_MCParticle));
}

void MutableSimPrimaryIonizationCluster::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableSimPrimaryIonizationCluster::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableSimPrimaryIonizationCluster::cellID() {
  return m_obj->data.cellID;
}
void MutableSimPrimaryIonizationCluster::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableSimPrimaryIonizationCluster::getTime() {
  return m_obj->data.time;
}
float& MutableSimPrimaryIonizationCluster::time() {
  return m_obj->data.time;
}
void MutableSimPrimaryIonizationCluster::setPosition(edm4hep::Vector3d value) {
  m_obj->data.position = value;
}
edm4hep::Vector3d& MutableSimPrimaryIonizationCluster::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3d& MutableSimPrimaryIonizationCluster::position() {
  return m_obj->data.position;
}
void MutableSimPrimaryIonizationCluster::setType(std::int16_t value) {
  m_obj->data.type = value;
}
std::int16_t& MutableSimPrimaryIonizationCluster::getType() {
  return m_obj->data.type;
}
std::int16_t& MutableSimPrimaryIonizationCluster::type() {
  return m_obj->data.type;
}

void MutableSimPrimaryIonizationCluster::setMCParticle(const edm4hep::MCParticle& value) {
  delete m_obj->m_MCParticle;
  m_obj->m_MCParticle = new edm4hep::MCParticle(value);
}

void MutableSimPrimaryIonizationCluster::addToElectronCellID(const std::uint64_t& component) {
  m_obj->m_electronCellID->push_back(component);
  m_obj->data.electronCellID_end++;
}

std::vector<std::uint64_t>::const_iterator MutableSimPrimaryIonizationCluster::electronCellID_begin() const {
  auto ret_value = m_obj->m_electronCellID->begin();
  std::advance(ret_value, m_obj->data.electronCellID_begin);
  return ret_value;
}

std::vector<std::uint64_t>::const_iterator MutableSimPrimaryIonizationCluster::electronCellID_end() const {
  auto ret_value = m_obj->m_electronCellID->begin();
  std::advance(ret_value, m_obj->data.electronCellID_end);
  return ret_value;
}

std::size_t MutableSimPrimaryIonizationCluster::electronCellID_size() const {
  return m_obj->data.electronCellID_end - m_obj->data.electronCellID_begin;
}

std::uint64_t MutableSimPrimaryIonizationCluster::getElectronCellID(std::size_t index) const {
  if (electronCellID_size() > index) {
    return m_obj->m_electronCellID->at(m_obj->data.electronCellID_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::uint64_t> MutableSimPrimaryIonizationCluster::getElectronCellID() const {
  auto begin = m_obj->m_electronCellID->begin();
  std::advance(begin, m_obj->data.electronCellID_begin);
  auto end = m_obj->m_electronCellID->begin();
  std::advance(end, m_obj->data.electronCellID_end);
  return {begin, end};
}

void MutableSimPrimaryIonizationCluster::addToElectronTime(const float& component) {
  m_obj->m_electronTime->push_back(component);
  m_obj->data.electronTime_end++;
}

std::vector<float>::const_iterator MutableSimPrimaryIonizationCluster::electronTime_begin() const {
  auto ret_value = m_obj->m_electronTime->begin();
  std::advance(ret_value, m_obj->data.electronTime_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableSimPrimaryIonizationCluster::electronTime_end() const {
  auto ret_value = m_obj->m_electronTime->begin();
  std::advance(ret_value, m_obj->data.electronTime_end);
  return ret_value;
}

std::size_t MutableSimPrimaryIonizationCluster::electronTime_size() const {
  return m_obj->data.electronTime_end - m_obj->data.electronTime_begin;
}

float MutableSimPrimaryIonizationCluster::getElectronTime(std::size_t index) const {
  if (electronTime_size() > index) {
    return m_obj->m_electronTime->at(m_obj->data.electronTime_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableSimPrimaryIonizationCluster::getElectronTime() const {
  auto begin = m_obj->m_electronTime->begin();
  std::advance(begin, m_obj->data.electronTime_begin);
  auto end = m_obj->m_electronTime->begin();
  std::advance(end, m_obj->data.electronTime_end);
  return {begin, end};
}

void MutableSimPrimaryIonizationCluster::addToElectronPosition(const edm4hep::Vector3d& component) {
  m_obj->m_electronPosition->push_back(component);
  m_obj->data.electronPosition_end++;
}

std::vector<edm4hep::Vector3d>::const_iterator MutableSimPrimaryIonizationCluster::electronPosition_begin() const {
  auto ret_value = m_obj->m_electronPosition->begin();
  std::advance(ret_value, m_obj->data.electronPosition_begin);
  return ret_value;
}

std::vector<edm4hep::Vector3d>::const_iterator MutableSimPrimaryIonizationCluster::electronPosition_end() const {
  auto ret_value = m_obj->m_electronPosition->begin();
  std::advance(ret_value, m_obj->data.electronPosition_end);
  return ret_value;
}

std::size_t MutableSimPrimaryIonizationCluster::electronPosition_size() const {
  return m_obj->data.electronPosition_end - m_obj->data.electronPosition_begin;
}

edm4hep::Vector3d MutableSimPrimaryIonizationCluster::getElectronPosition(std::size_t index) const {
  if (electronPosition_size() > index) {
    return m_obj->m_electronPosition->at(m_obj->data.electronPosition_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Vector3d> MutableSimPrimaryIonizationCluster::getElectronPosition() const {
  auto begin = m_obj->m_electronPosition->begin();
  std::advance(begin, m_obj->data.electronPosition_begin);
  auto end = m_obj->m_electronPosition->begin();
  std::advance(end, m_obj->data.electronPosition_end);
  return {begin, end};
}

void MutableSimPrimaryIonizationCluster::addToPulseTime(const float& component) {
  m_obj->m_pulseTime->push_back(component);
  m_obj->data.pulseTime_end++;
}

std::vector<float>::const_iterator MutableSimPrimaryIonizationCluster::pulseTime_begin() const {
  auto ret_value = m_obj->m_pulseTime->begin();
  std::advance(ret_value, m_obj->data.pulseTime_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableSimPrimaryIonizationCluster::pulseTime_end() const {
  auto ret_value = m_obj->m_pulseTime->begin();
  std::advance(ret_value, m_obj->data.pulseTime_end);
  return ret_value;
}

std::size_t MutableSimPrimaryIonizationCluster::pulseTime_size() const {
  return m_obj->data.pulseTime_end - m_obj->data.pulseTime_begin;
}

float MutableSimPrimaryIonizationCluster::getPulseTime(std::size_t index) const {
  if (pulseTime_size() > index) {
    return m_obj->m_pulseTime->at(m_obj->data.pulseTime_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableSimPrimaryIonizationCluster::getPulseTime() const {
  auto begin = m_obj->m_pulseTime->begin();
  std::advance(begin, m_obj->data.pulseTime_begin);
  auto end = m_obj->m_pulseTime->begin();
  std::advance(end, m_obj->data.pulseTime_end);
  return {begin, end};
}

void MutableSimPrimaryIonizationCluster::addToPulseAmplitude(const float& component) {
  m_obj->m_pulseAmplitude->push_back(component);
  m_obj->data.pulseAmplitude_end++;
}

std::vector<float>::const_iterator MutableSimPrimaryIonizationCluster::pulseAmplitude_begin() const {
  auto ret_value = m_obj->m_pulseAmplitude->begin();
  std::advance(ret_value, m_obj->data.pulseAmplitude_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableSimPrimaryIonizationCluster::pulseAmplitude_end() const {
  auto ret_value = m_obj->m_pulseAmplitude->begin();
  std::advance(ret_value, m_obj->data.pulseAmplitude_end);
  return ret_value;
}

std::size_t MutableSimPrimaryIonizationCluster::pulseAmplitude_size() const {
  return m_obj->data.pulseAmplitude_end - m_obj->data.pulseAmplitude_begin;
}

float MutableSimPrimaryIonizationCluster::getPulseAmplitude(std::size_t index) const {
  if (pulseAmplitude_size() > index) {
    return m_obj->m_pulseAmplitude->at(m_obj->data.pulseAmplitude_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableSimPrimaryIonizationCluster::getPulseAmplitude() const {
  auto begin = m_obj->m_pulseAmplitude->begin();
  std::advance(begin, m_obj->data.pulseAmplitude_begin);
  auto end = m_obj->m_pulseAmplitude->begin();
  std::advance(end, m_obj->data.pulseAmplitude_end);
  return {begin, end};
}

bool MutableSimPrimaryIonizationCluster::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableSimPrimaryIonizationCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableSimPrimaryIonizationCluster::operator==(const SimPrimaryIonizationCluster& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableSimPrimaryIonizationCluster& value) {
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
