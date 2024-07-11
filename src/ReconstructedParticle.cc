// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableReconstructedParticle.h"
#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/ReconstructedParticleObj.h"

#include "edm4hep/Vertex.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

ReconstructedParticle::ReconstructedParticle() : m_obj(new ReconstructedParticleObj{}, podio::utils::MarkOwned) {
}

ReconstructedParticle::ReconstructedParticle(std::int32_t PDG, float energy, edm4hep::Vector3f momentum,
                                             edm4hep::Vector3f referencePoint, float charge, float mass,
                                             float goodnessOfPID, edm4hep::CovMatrix4f covMatrix) :
    m_obj(new ReconstructedParticleObj{}, podio::utils::MarkOwned) {
  m_obj->data.PDG = PDG;
  m_obj->data.energy = energy;
  m_obj->data.momentum = momentum;
  m_obj->data.referencePoint = referencePoint;
  m_obj->data.charge = charge;
  m_obj->data.mass = mass;
  m_obj->data.goodnessOfPID = goodnessOfPID;
  m_obj->data.covMatrix = covMatrix;
}

ReconstructedParticle& ReconstructedParticle::operator=(ReconstructedParticle other) {
  swap(*this, other);
  return *this;
}

MutableReconstructedParticle ReconstructedParticle::clone(bool cloneRelations) const {
  auto tmp = new ReconstructedParticleObj(podio::ObjectID{}, m_obj->data);
  tmp->m_clusters = new std::vector<edm4hep::Cluster>();
  tmp->m_tracks = new std::vector<edm4hep::Track>();
  tmp->m_particles = new std::vector<edm4hep::ReconstructedParticle>();
  if (cloneRelations) {
    if (m_obj->m_startVertex) {
      tmp->m_startVertex = new edm4hep::Vertex(*m_obj->m_startVertex);
    }
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
    tmp->m_tracks->reserve(m_obj->m_tracks->size());
    for (size_t i = m_obj->data.tracks_begin; i < m_obj->data.tracks_end; i++) {
      tmp->m_tracks->emplace_back((*m_obj->m_tracks)[i]);
    }
    tmp->data.tracks_begin = 0;
    tmp->data.tracks_end = tmp->m_tracks->size();
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_particles->reserve(m_obj->m_particles->size());
    for (size_t i = m_obj->data.particles_begin; i < m_obj->data.particles_end; i++) {
      tmp->m_particles->emplace_back((*m_obj->m_particles)[i]);
    }
    tmp->data.particles_begin = 0;
    tmp->data.particles_end = tmp->m_particles->size();
  } else {
    tmp->data.clusters_begin = 0;
    tmp->data.clusters_end = 0;
    tmp->data.tracks_begin = 0;
    tmp->data.tracks_end = 0;
    tmp->data.particles_begin = 0;
    tmp->data.particles_end = 0;
  }
  return MutableReconstructedParticle(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

ReconstructedParticle::ReconstructedParticle(podio::utils::MaybeSharedPtr<ReconstructedParticleObj> obj) :
    m_obj(std::move(obj)) {
}

ReconstructedParticle::ReconstructedParticle(const MutableReconstructedParticle& other) :
    ReconstructedParticle(other.m_obj) {
}

ReconstructedParticle::ReconstructedParticle(ReconstructedParticleObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<ReconstructedParticleObj>(obj)) {
}

ReconstructedParticle ReconstructedParticle::makeEmpty() {
  return {nullptr};
}

std::int32_t ReconstructedParticle::getPDG() const {
  return m_obj->data.PDG;
}
float ReconstructedParticle::getEnergy() const {
  return m_obj->data.energy;
}
const edm4hep::Vector3f& ReconstructedParticle::getMomentum() const {
  return m_obj->data.momentum;
}
const edm4hep::Vector3f& ReconstructedParticle::getReferencePoint() const {
  return m_obj->data.referencePoint;
}
float ReconstructedParticle::getCharge() const {
  return m_obj->data.charge;
}
float ReconstructedParticle::getMass() const {
  return m_obj->data.mass;
}
float ReconstructedParticle::getGoodnessOfPID() const {
  return m_obj->data.goodnessOfPID;
}
const edm4hep::CovMatrix4f& ReconstructedParticle::getCovMatrix() const {
  return m_obj->data.covMatrix;
}

const edm4hep::Vertex ReconstructedParticle::getStartVertex() const {
  if (!m_obj->m_startVertex) {
    return edm4hep::Vertex::makeEmpty();
  }
  return edm4hep::Vertex(*(m_obj->m_startVertex));
}

std::vector<edm4hep::Cluster>::const_iterator ReconstructedParticle::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<edm4hep::Cluster>::const_iterator ReconstructedParticle::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

std::size_t ReconstructedParticle::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

edm4hep::Cluster ReconstructedParticle::getClusters(std::size_t index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Cluster> ReconstructedParticle::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}

std::vector<edm4hep::Track>::const_iterator ReconstructedParticle::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<edm4hep::Track>::const_iterator ReconstructedParticle::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

std::size_t ReconstructedParticle::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

edm4hep::Track ReconstructedParticle::getTracks(std::size_t index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Track> ReconstructedParticle::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}

std::vector<edm4hep::ReconstructedParticle>::const_iterator ReconstructedParticle::particles_begin() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_begin);
  return ret_value;
}

std::vector<edm4hep::ReconstructedParticle>::const_iterator ReconstructedParticle::particles_end() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_end);
  return ret_value;
}

std::size_t ReconstructedParticle::particles_size() const {
  return m_obj->data.particles_end - m_obj->data.particles_begin;
}

edm4hep::ReconstructedParticle ReconstructedParticle::getParticles(std::size_t index) const {
  if (particles_size() > index) {
    return m_obj->m_particles->at(m_obj->data.particles_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::ReconstructedParticle> ReconstructedParticle::getParticles() const {
  auto begin = m_obj->m_particles->begin();
  std::advance(begin, m_obj->data.particles_begin);
  auto end = m_obj->m_particles->begin();
  std::advance(end, m_obj->data.particles_end);
  return {begin, end};
}

bool ReconstructedParticle::isAvailable() const {
  return m_obj;
}

const podio::ObjectID ReconstructedParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool ReconstructedParticle::operator==(const MutableReconstructedParticle& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ReconstructedParticle& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " momentum : " << value.getMomentum() << '\n';
  o << " referencePoint : " << value.getReferencePoint() << '\n';
  o << " charge : " << value.getCharge() << '\n';
  o << " mass : " << value.getMass() << '\n';
  o << " goodnessOfPID : " << value.getGoodnessOfPID() << '\n';
  o << " covMatrix : " << value.getCovMatrix() << '\n';

  o << " startVertex : " << value.getStartVertex().id() << '\n';

  o << " clusters : ";
  for (unsigned i = 0; i < value.clusters_size(); ++i) {
    o << value.getClusters(i) << " ";
  }
  o << '\n';
  o << " tracks : ";
  for (unsigned i = 0; i < value.tracks_size(); ++i) {
    o << value.getTracks(i) << " ";
  }
  o << '\n';
  o << " particles : ";
  for (unsigned i = 0; i < value.particles_size(); ++i) {
    o << value.getParticles(i).id() << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ReconstructedParticle& value) {
  j = nlohmann::json{{"PDG", value.getPDG()},
                     {"energy", value.getEnergy()},
                     {"momentum", value.getMomentum()},
                     {"referencePoint", value.getReferencePoint()},
                     {"charge", value.getCharge()},
                     {"mass", value.getMass()},
                     {"goodnessOfPID", value.getGoodnessOfPID()},
                     {"covMatrix", value.getCovMatrix()}};

  j["startVertex"] = nlohmann::json{{"collectionID", value.getStartVertex().getObjectID().collectionID},
                                    {"index", value.getStartVertex().getObjectID().index}};

  j["clusters"] = nlohmann::json::array();
  for (const auto& v : value.getClusters()) {
    j["clusters"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }

  j["tracks"] = nlohmann::json::array();
  for (const auto& v : value.getTracks()) {
    j["tracks"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }

  j["particles"] = nlohmann::json::array();
  for (const auto& v : value.getParticles()) {
    j["particles"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
