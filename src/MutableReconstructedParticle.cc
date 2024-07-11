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

namespace edm4hep {

MutableReconstructedParticle::MutableReconstructedParticle() :
    m_obj(new ReconstructedParticleObj{}, podio::utils::MarkOwned) {
}

MutableReconstructedParticle::MutableReconstructedParticle(std::int32_t PDG, float energy, edm4hep::Vector3f momentum,
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

MutableReconstructedParticle& MutableReconstructedParticle::operator=(MutableReconstructedParticle other) {
  swap(*this, other);
  return *this;
}

MutableReconstructedParticle MutableReconstructedParticle::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new ReconstructedParticleObj(podio::ObjectID{}, m_obj->data);
    tmp->m_clusters = new std::vector<edm4hep::Cluster>();
    tmp->data.clusters_begin = 0;
    tmp->data.clusters_end = 0;
    tmp->m_tracks = new std::vector<edm4hep::Track>();
    tmp->data.tracks_begin = 0;
    tmp->data.tracks_end = 0;
    tmp->m_particles = new std::vector<edm4hep::ReconstructedParticle>();
    tmp->data.particles_begin = 0;
    tmp->data.particles_end = 0;
    return MutableReconstructedParticle(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableReconstructedParticle(
      podio::utils::MaybeSharedPtr(new ReconstructedParticleObj(*m_obj), podio::utils::MarkOwned));
}

MutableReconstructedParticle::MutableReconstructedParticle(podio::utils::MaybeSharedPtr<ReconstructedParticleObj> obj) :
    m_obj(std::move(obj)) {
}

std::int32_t MutableReconstructedParticle::getPDG() const {
  return m_obj->data.PDG;
}
float MutableReconstructedParticle::getEnergy() const {
  return m_obj->data.energy;
}
const edm4hep::Vector3f& MutableReconstructedParticle::getMomentum() const {
  return m_obj->data.momentum;
}
const edm4hep::Vector3f& MutableReconstructedParticle::getReferencePoint() const {
  return m_obj->data.referencePoint;
}
float MutableReconstructedParticle::getCharge() const {
  return m_obj->data.charge;
}
float MutableReconstructedParticle::getMass() const {
  return m_obj->data.mass;
}
float MutableReconstructedParticle::getGoodnessOfPID() const {
  return m_obj->data.goodnessOfPID;
}
const edm4hep::CovMatrix4f& MutableReconstructedParticle::getCovMatrix() const {
  return m_obj->data.covMatrix;
}

const edm4hep::Vertex MutableReconstructedParticle::getStartVertex() const {
  if (!m_obj->m_startVertex) {
    return edm4hep::Vertex::makeEmpty();
  }
  return edm4hep::Vertex(*(m_obj->m_startVertex));
}

void MutableReconstructedParticle::setPDG(std::int32_t value) {
  m_obj->data.PDG = value;
}
std::int32_t& MutableReconstructedParticle::getPDG() {
  return m_obj->data.PDG;
}
std::int32_t& MutableReconstructedParticle::PDG() {
  return m_obj->data.PDG;
}
void MutableReconstructedParticle::setEnergy(float value) {
  m_obj->data.energy = value;
}
float& MutableReconstructedParticle::getEnergy() {
  return m_obj->data.energy;
}
float& MutableReconstructedParticle::energy() {
  return m_obj->data.energy;
}
void MutableReconstructedParticle::setMomentum(edm4hep::Vector3f value) {
  m_obj->data.momentum = value;
}
edm4hep::Vector3f& MutableReconstructedParticle::getMomentum() {
  return m_obj->data.momentum;
}
edm4hep::Vector3f& MutableReconstructedParticle::momentum() {
  return m_obj->data.momentum;
}
void MutableReconstructedParticle::setReferencePoint(edm4hep::Vector3f value) {
  m_obj->data.referencePoint = value;
}
edm4hep::Vector3f& MutableReconstructedParticle::getReferencePoint() {
  return m_obj->data.referencePoint;
}
edm4hep::Vector3f& MutableReconstructedParticle::referencePoint() {
  return m_obj->data.referencePoint;
}
void MutableReconstructedParticle::setCharge(float value) {
  m_obj->data.charge = value;
}
float& MutableReconstructedParticle::getCharge() {
  return m_obj->data.charge;
}
float& MutableReconstructedParticle::charge() {
  return m_obj->data.charge;
}
void MutableReconstructedParticle::setMass(float value) {
  m_obj->data.mass = value;
}
float& MutableReconstructedParticle::getMass() {
  return m_obj->data.mass;
}
float& MutableReconstructedParticle::mass() {
  return m_obj->data.mass;
}
void MutableReconstructedParticle::setGoodnessOfPID(float value) {
  m_obj->data.goodnessOfPID = value;
}
float& MutableReconstructedParticle::getGoodnessOfPID() {
  return m_obj->data.goodnessOfPID;
}
float& MutableReconstructedParticle::goodnessOfPID() {
  return m_obj->data.goodnessOfPID;
}
void MutableReconstructedParticle::setCovMatrix(edm4hep::CovMatrix4f value) {
  m_obj->data.covMatrix = value;
}
edm4hep::CovMatrix4f& MutableReconstructedParticle::getCovMatrix() {
  return m_obj->data.covMatrix;
}
edm4hep::CovMatrix4f& MutableReconstructedParticle::covMatrix() {
  return m_obj->data.covMatrix;
}

void MutableReconstructedParticle::setStartVertex(const edm4hep::Vertex& value) {
  delete m_obj->m_startVertex;
  m_obj->m_startVertex = new edm4hep::Vertex(value);
}

void MutableReconstructedParticle::addToClusters(const edm4hep::Cluster& component) {
  m_obj->m_clusters->push_back(component);
  m_obj->data.clusters_end++;
}

std::vector<edm4hep::Cluster>::const_iterator MutableReconstructedParticle::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<edm4hep::Cluster>::const_iterator MutableReconstructedParticle::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

std::size_t MutableReconstructedParticle::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

edm4hep::Cluster MutableReconstructedParticle::getClusters(std::size_t index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Cluster> MutableReconstructedParticle::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}

void MutableReconstructedParticle::addToTracks(const edm4hep::Track& component) {
  m_obj->m_tracks->push_back(component);
  m_obj->data.tracks_end++;
}

std::vector<edm4hep::Track>::const_iterator MutableReconstructedParticle::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<edm4hep::Track>::const_iterator MutableReconstructedParticle::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

std::size_t MutableReconstructedParticle::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

edm4hep::Track MutableReconstructedParticle::getTracks(std::size_t index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Track> MutableReconstructedParticle::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}

void MutableReconstructedParticle::addToParticles(const edm4hep::ReconstructedParticle& component) {
  m_obj->m_particles->push_back(component);
  m_obj->data.particles_end++;
}

std::vector<edm4hep::ReconstructedParticle>::const_iterator MutableReconstructedParticle::particles_begin() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_begin);
  return ret_value;
}

std::vector<edm4hep::ReconstructedParticle>::const_iterator MutableReconstructedParticle::particles_end() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_end);
  return ret_value;
}

std::size_t MutableReconstructedParticle::particles_size() const {
  return m_obj->data.particles_end - m_obj->data.particles_begin;
}

edm4hep::ReconstructedParticle MutableReconstructedParticle::getParticles(std::size_t index) const {
  if (particles_size() > index) {
    return m_obj->m_particles->at(m_obj->data.particles_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::ReconstructedParticle> MutableReconstructedParticle::getParticles() const {
  auto begin = m_obj->m_particles->begin();
  std::advance(begin, m_obj->data.particles_begin);
  auto end = m_obj->m_particles->begin();
  std::advance(end, m_obj->data.particles_end);
  return {begin, end};
}

bool MutableReconstructedParticle::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableReconstructedParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableReconstructedParticle::operator==(const ReconstructedParticle& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableReconstructedParticle& value) {
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
