// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterData.h"
#include "edm4hep/ClusterObj.h"
#include "edm4hep/MutableCluster.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

Cluster::Cluster() : m_obj(new ClusterObj{}, podio::utils::MarkOwned) {
}

Cluster::Cluster(std::int32_t type, float energy, float energyError, edm4hep::Vector3f position,
                 edm4hep::CovMatrix3f positionError, float iTheta, float phi, edm4hep::Vector3f directionError) :
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

Cluster& Cluster::operator=(Cluster other) {
  swap(*this, other);
  return *this;
}

MutableCluster Cluster::clone(bool cloneRelations) const {
  auto tmp = new ClusterObj(podio::ObjectID{}, m_obj->data);
  tmp->m_clusters = new std::vector<edm4hep::Cluster>();
  tmp->m_hits = new std::vector<edm4hep::CalorimeterHit>();
  tmp->m_shapeParameters = new std::vector<float>();
  tmp->m_subdetectorEnergies = new std::vector<float>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_clusters->reserve(m_obj->m_clusters->size());
    for (size_t i = m_obj->data.clusters_begin; i < m_obj->data.clusters_end; i++) {
      tmp->m_clusters->emplace_back((*m_obj->m_clusters)[i]);
    }
    tmp->data.clusters_begin = 0;
    tmp->data.clusters_end = tmp->m_clusters->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_hits->reserve(m_obj->m_hits->size());
    for (size_t i = m_obj->data.hits_begin; i < m_obj->data.hits_end; i++) {
      tmp->m_hits->emplace_back((*m_obj->m_hits)[i]);
    }
    tmp->data.hits_begin = 0;
    tmp->data.hits_end = tmp->m_hits->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_shapeParameters->reserve(m_obj->m_shapeParameters->size());
    for (size_t i = m_obj->data.shapeParameters_begin; i < m_obj->data.shapeParameters_end; i++) {
      tmp->m_shapeParameters->emplace_back((*m_obj->m_shapeParameters)[i]);
    }
    tmp->data.shapeParameters_begin = 0;
    tmp->data.shapeParameters_end = tmp->m_shapeParameters->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_subdetectorEnergies->reserve(m_obj->m_subdetectorEnergies->size());
    for (size_t i = m_obj->data.subdetectorEnergies_begin; i < m_obj->data.subdetectorEnergies_end; i++) {
      tmp->m_subdetectorEnergies->emplace_back((*m_obj->m_subdetectorEnergies)[i]);
    }
    tmp->data.subdetectorEnergies_begin = 0;
    tmp->data.subdetectorEnergies_end = tmp->m_subdetectorEnergies->size();
  } else {
    tmp->data.clusters_begin = 0;
    tmp->data.clusters_end = 0;
    tmp->data.hits_begin = 0;
    tmp->data.hits_end = 0;
    tmp->data.shapeParameters_begin = 0;
    tmp->data.shapeParameters_end = 0;
    tmp->data.subdetectorEnergies_begin = 0;
    tmp->data.subdetectorEnergies_end = 0;
  }
  return MutableCluster(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

Cluster::Cluster(podio::utils::MaybeSharedPtr<ClusterObj> obj) : m_obj(std::move(obj)) {
}

Cluster::Cluster(const MutableCluster& other) : Cluster(other.m_obj) {
}

Cluster::Cluster(ClusterObj* obj) : m_obj(podio::utils::MaybeSharedPtr<ClusterObj>(obj)) {
}

Cluster Cluster::makeEmpty() {
  return {nullptr};
}

std::int32_t Cluster::getType() const {
  return m_obj->data.type;
}
float Cluster::getEnergy() const {
  return m_obj->data.energy;
}
float Cluster::getEnergyError() const {
  return m_obj->data.energyError;
}
const edm4hep::Vector3f& Cluster::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& Cluster::getPositionError() const {
  return m_obj->data.positionError;
}
float Cluster::getITheta() const {
  return m_obj->data.iTheta;
}
float Cluster::getPhi() const {
  return m_obj->data.phi;
}
const edm4hep::Vector3f& Cluster::getDirectionError() const {
  return m_obj->data.directionError;
}

std::vector<edm4hep::Cluster>::const_iterator Cluster::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<edm4hep::Cluster>::const_iterator Cluster::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

std::size_t Cluster::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

edm4hep::Cluster Cluster::getClusters(std::size_t index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Cluster> Cluster::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}

std::vector<edm4hep::CalorimeterHit>::const_iterator Cluster::hits_begin() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_begin);
  return ret_value;
}

std::vector<edm4hep::CalorimeterHit>::const_iterator Cluster::hits_end() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_end);
  return ret_value;
}

std::size_t Cluster::hits_size() const {
  return m_obj->data.hits_end - m_obj->data.hits_begin;
}

edm4hep::CalorimeterHit Cluster::getHits(std::size_t index) const {
  if (hits_size() > index) {
    return m_obj->m_hits->at(m_obj->data.hits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::CalorimeterHit> Cluster::getHits() const {
  auto begin = m_obj->m_hits->begin();
  std::advance(begin, m_obj->data.hits_begin);
  auto end = m_obj->m_hits->begin();
  std::advance(end, m_obj->data.hits_end);
  return {begin, end};
}

std::vector<float>::const_iterator Cluster::shapeParameters_begin() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator Cluster::shapeParameters_end() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_end);
  return ret_value;
}

std::size_t Cluster::shapeParameters_size() const {
  return m_obj->data.shapeParameters_end - m_obj->data.shapeParameters_begin;
}

float Cluster::getShapeParameters(std::size_t index) const {
  if (shapeParameters_size() > index) {
    return m_obj->m_shapeParameters->at(m_obj->data.shapeParameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Cluster::getShapeParameters() const {
  auto begin = m_obj->m_shapeParameters->begin();
  std::advance(begin, m_obj->data.shapeParameters_begin);
  auto end = m_obj->m_shapeParameters->begin();
  std::advance(end, m_obj->data.shapeParameters_end);
  return {begin, end};
}

std::vector<float>::const_iterator Cluster::subdetectorEnergies_begin() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_begin);
  return ret_value;
}

std::vector<float>::const_iterator Cluster::subdetectorEnergies_end() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_end);
  return ret_value;
}

std::size_t Cluster::subdetectorEnergies_size() const {
  return m_obj->data.subdetectorEnergies_end - m_obj->data.subdetectorEnergies_begin;
}

float Cluster::getSubdetectorEnergies(std::size_t index) const {
  if (subdetectorEnergies_size() > index) {
    return m_obj->m_subdetectorEnergies->at(m_obj->data.subdetectorEnergies_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Cluster::getSubdetectorEnergies() const {
  auto begin = m_obj->m_subdetectorEnergies->begin();
  std::advance(begin, m_obj->data.subdetectorEnergies_begin);
  auto end = m_obj->m_subdetectorEnergies->begin();
  std::advance(end, m_obj->data.subdetectorEnergies_end);
  return {begin, end};
}

bool Cluster::isAvailable() const {
  return m_obj;
}

const podio::ObjectID Cluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool Cluster::operator==(const MutableCluster& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const Cluster& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " energyError : " << value.getEnergyError() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " positionError : " << value.getPositionError() << '\n';
  o << " iTheta : " << value.getITheta() << '\n';
  o << " phi : " << value.getPhi() << '\n';
  o << " directionError : " << value.getDirectionError() << '\n';

  o << " clusters : ";
  for (unsigned i = 0; i < value.clusters_size(); ++i) {
    o << value.getClusters(i).id() << " ";
  }
  o << '\n';
  o << " hits : ";
  for (unsigned i = 0; i < value.hits_size(); ++i) {
    o << value.getHits(i) << " ";
  }
  o << '\n';
  o << " shapeParameters : ";
  for (unsigned i = 0; i < value.shapeParameters_size(); ++i) {
    o << value.getShapeParameters(i) << " ";
  }
  o << '\n';
  o << " subdetectorEnergies : ";
  for (unsigned i = 0; i < value.subdetectorEnergies_size(); ++i) {
    o << value.getSubdetectorEnergies(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Cluster& value) {
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
