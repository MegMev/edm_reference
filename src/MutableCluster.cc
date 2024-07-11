// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterData.h"
#include "edm4hep/ClusterObj.h"
#include "edm4hep/MutableCluster.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableCluster::MutableCluster() : m_obj(new ClusterObj{}, podio::utils::MarkOwned) {
}

MutableCluster::MutableCluster(std::int32_t type, float energy, float energyError, edm4hep::Vector3f position,
                               edm4hep::CovMatrix3f positionError, float iTheta, float phi,
                               edm4hep::Vector3f directionError) :
    m_obj(new ClusterObj{}, podio::utils::MarkOwned) {
  m_obj->data.type = type;
  m_obj->data.energy = energy;
  m_obj->data.energyError = energyError;
  m_obj->data.position = position;
  m_obj->data.positionError = positionError;
  m_obj->data.iTheta = iTheta;
  m_obj->data.phi = phi;
  m_obj->data.directionError = directionError;
}

MutableCluster& MutableCluster::operator=(MutableCluster other) {
  swap(*this, other);
  return *this;
}

MutableCluster MutableCluster::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new ClusterObj(podio::ObjectID{}, m_obj->data);
    tmp->m_clusters = new std::vector<edm4hep::Cluster>();
    tmp->data.clusters_begin = 0;
    tmp->data.clusters_end = 0;
    tmp->m_hits = new std::vector<edm4hep::CalorimeterHit>();
    tmp->data.hits_begin = 0;
    tmp->data.hits_end = 0;
    tmp->m_shapeParameters = new std::vector<float>();
    tmp->data.shapeParameters_begin = 0;
    tmp->data.shapeParameters_end = 0;
    tmp->m_subdetectorEnergies = new std::vector<float>();
    tmp->data.subdetectorEnergies_begin = 0;
    tmp->data.subdetectorEnergies_end = 0;
    return MutableCluster(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableCluster(podio::utils::MaybeSharedPtr(new ClusterObj(*m_obj), podio::utils::MarkOwned));
}

MutableCluster::MutableCluster(podio::utils::MaybeSharedPtr<ClusterObj> obj) : m_obj(std::move(obj)) {
}

std::int32_t MutableCluster::getType() const {
  return m_obj->data.type;
}
float MutableCluster::getEnergy() const {
  return m_obj->data.energy;
}
float MutableCluster::getEnergyError() const {
  return m_obj->data.energyError;
}
const edm4hep::Vector3f& MutableCluster::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& MutableCluster::getPositionError() const {
  return m_obj->data.positionError;
}
float MutableCluster::getITheta() const {
  return m_obj->data.iTheta;
}
float MutableCluster::getPhi() const {
  return m_obj->data.phi;
}
const edm4hep::Vector3f& MutableCluster::getDirectionError() const {
  return m_obj->data.directionError;
}

void MutableCluster::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableCluster::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableCluster::type() {
  return m_obj->data.type;
}
void MutableCluster::setEnergy(float value) {
  m_obj->data.energy = value;
}
float& MutableCluster::getEnergy() {
  return m_obj->data.energy;
}
float& MutableCluster::energy() {
  return m_obj->data.energy;
}
void MutableCluster::setEnergyError(float value) {
  m_obj->data.energyError = value;
}
float& MutableCluster::getEnergyError() {
  return m_obj->data.energyError;
}
float& MutableCluster::energyError() {
  return m_obj->data.energyError;
}
void MutableCluster::setPosition(edm4hep::Vector3f value) {
  m_obj->data.position = value;
}
edm4hep::Vector3f& MutableCluster::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3f& MutableCluster::position() {
  return m_obj->data.position;
}
void MutableCluster::setPositionError(edm4hep::CovMatrix3f value) {
  m_obj->data.positionError = value;
}
edm4hep::CovMatrix3f& MutableCluster::getPositionError() {
  return m_obj->data.positionError;
}
edm4hep::CovMatrix3f& MutableCluster::positionError() {
  return m_obj->data.positionError;
}
void MutableCluster::setITheta(float value) {
  m_obj->data.iTheta = value;
}
float& MutableCluster::getITheta() {
  return m_obj->data.iTheta;
}
float& MutableCluster::iTheta() {
  return m_obj->data.iTheta;
}
void MutableCluster::setPhi(float value) {
  m_obj->data.phi = value;
}
float& MutableCluster::getPhi() {
  return m_obj->data.phi;
}
float& MutableCluster::phi() {
  return m_obj->data.phi;
}
void MutableCluster::setDirectionError(edm4hep::Vector3f value) {
  m_obj->data.directionError = value;
}
edm4hep::Vector3f& MutableCluster::getDirectionError() {
  return m_obj->data.directionError;
}
edm4hep::Vector3f& MutableCluster::directionError() {
  return m_obj->data.directionError;
}

void MutableCluster::addToClusters(const edm4hep::Cluster& component) {
  m_obj->m_clusters->push_back(component);
  m_obj->data.clusters_end++;
}

std::vector<edm4hep::Cluster>::const_iterator MutableCluster::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<edm4hep::Cluster>::const_iterator MutableCluster::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

std::size_t MutableCluster::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

edm4hep::Cluster MutableCluster::getClusters(std::size_t index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Cluster> MutableCluster::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}

void MutableCluster::addToHits(const edm4hep::CalorimeterHit& component) {
  m_obj->m_hits->push_back(component);
  m_obj->data.hits_end++;
}

std::vector<edm4hep::CalorimeterHit>::const_iterator MutableCluster::hits_begin() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_begin);
  return ret_value;
}

std::vector<edm4hep::CalorimeterHit>::const_iterator MutableCluster::hits_end() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_end);
  return ret_value;
}

std::size_t MutableCluster::hits_size() const {
  return m_obj->data.hits_end - m_obj->data.hits_begin;
}

edm4hep::CalorimeterHit MutableCluster::getHits(std::size_t index) const {
  if (hits_size() > index) {
    return m_obj->m_hits->at(m_obj->data.hits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::CalorimeterHit> MutableCluster::getHits() const {
  auto begin = m_obj->m_hits->begin();
  std::advance(begin, m_obj->data.hits_begin);
  auto end = m_obj->m_hits->begin();
  std::advance(end, m_obj->data.hits_end);
  return {begin, end};
}

void MutableCluster::addToShapeParameters(const float& component) {
  m_obj->m_shapeParameters->push_back(component);
  m_obj->data.shapeParameters_end++;
}

std::vector<float>::const_iterator MutableCluster::shapeParameters_begin() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableCluster::shapeParameters_end() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_end);
  return ret_value;
}

std::size_t MutableCluster::shapeParameters_size() const {
  return m_obj->data.shapeParameters_end - m_obj->data.shapeParameters_begin;
}

float MutableCluster::getShapeParameters(std::size_t index) const {
  if (shapeParameters_size() > index) {
    return m_obj->m_shapeParameters->at(m_obj->data.shapeParameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableCluster::getShapeParameters() const {
  auto begin = m_obj->m_shapeParameters->begin();
  std::advance(begin, m_obj->data.shapeParameters_begin);
  auto end = m_obj->m_shapeParameters->begin();
  std::advance(end, m_obj->data.shapeParameters_end);
  return {begin, end};
}

void MutableCluster::addToSubdetectorEnergies(const float& component) {
  m_obj->m_subdetectorEnergies->push_back(component);
  m_obj->data.subdetectorEnergies_end++;
}

std::vector<float>::const_iterator MutableCluster::subdetectorEnergies_begin() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_begin);
  return ret_value;
}

std::vector<float>::const_iterator MutableCluster::subdetectorEnergies_end() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_end);
  return ret_value;
}

std::size_t MutableCluster::subdetectorEnergies_size() const {
  return m_obj->data.subdetectorEnergies_end - m_obj->data.subdetectorEnergies_begin;
}

float MutableCluster::getSubdetectorEnergies(std::size_t index) const {
  if (subdetectorEnergies_size() > index) {
    return m_obj->m_subdetectorEnergies->at(m_obj->data.subdetectorEnergies_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> MutableCluster::getSubdetectorEnergies() const {
  auto begin = m_obj->m_subdetectorEnergies->begin();
  std::advance(begin, m_obj->data.subdetectorEnergies_begin);
  auto end = m_obj->m_subdetectorEnergies->begin();
  std::advance(end, m_obj->data.subdetectorEnergies_end);
  return {begin, end};
}

bool MutableCluster::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableCluster::operator==(const Cluster& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableCluster& value) {
  j = nlohmann::json{{"type", value.getType()},
                     {"energy", value.getEnergy()},
                     {"energyError", value.getEnergyError()},
                     {"position", value.getPosition()},
                     {"positionError", value.getPositionError()},
                     {"iTheta", value.getITheta()},
                     {"phi", value.getPhi()},
                     {"directionError", value.getDirectionError()},
                     {"shapeParameters", value.getShapeParameters()},
                     {"subdetectorEnergies", value.getSubdetectorEnergies()}};

  j["clusters"] = nlohmann::json::array();
  for (const auto& v : value.getClusters()) {
    j["clusters"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }

  j["hits"] = nlohmann::json::array();
  for (const auto& v : value.getHits()) {
    j["hits"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
