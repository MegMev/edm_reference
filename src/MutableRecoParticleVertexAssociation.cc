// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRecoParticleVertexAssociation.h"
#include "edm4hep/RecoParticleVertexAssociation.h"
#include "edm4hep/RecoParticleVertexAssociationData.h"
#include "edm4hep/RecoParticleVertexAssociationObj.h"

#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/Vertex.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableRecoParticleVertexAssociation::MutableRecoParticleVertexAssociation() :
    m_obj(new RecoParticleVertexAssociationObj{}, podio::utils::MarkOwned) {
}

MutableRecoParticleVertexAssociation::MutableRecoParticleVertexAssociation(float weight) :
    m_obj(new RecoParticleVertexAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableRecoParticleVertexAssociation&
MutableRecoParticleVertexAssociation::operator=(MutableRecoParticleVertexAssociation other) {
  swap(*this, other);
  return *this;
}

MutableRecoParticleVertexAssociation MutableRecoParticleVertexAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new RecoParticleVertexAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableRecoParticleVertexAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableRecoParticleVertexAssociation(
      podio::utils::MaybeSharedPtr(new RecoParticleVertexAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableRecoParticleVertexAssociation::MutableRecoParticleVertexAssociation(
    podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableRecoParticleVertexAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::ReconstructedParticle MutableRecoParticleVertexAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_rec));
}

const edm4hep::Vertex MutableRecoParticleVertexAssociation::getVertex() const {
  if (!m_obj->m_vertex) {
    return edm4hep::Vertex::makeEmpty();
  }
  return edm4hep::Vertex(*(m_obj->m_vertex));
}

void MutableRecoParticleVertexAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableRecoParticleVertexAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableRecoParticleVertexAssociation::weight() {
  return m_obj->data.weight;
}

void MutableRecoParticleVertexAssociation::setRec(const edm4hep::ReconstructedParticle& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::ReconstructedParticle(value);
}

void MutableRecoParticleVertexAssociation::setVertex(const edm4hep::Vertex& value) {
  delete m_obj->m_vertex;
  m_obj->m_vertex = new edm4hep::Vertex(value);
}

bool MutableRecoParticleVertexAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableRecoParticleVertexAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableRecoParticleVertexAssociation::operator==(const RecoParticleVertexAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRecoParticleVertexAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["vertex"] = nlohmann::json{{"collectionID", value.getVertex().getObjectID().collectionID},
                               {"index", value.getVertex().getObjectID().index}};
}
#endif

} // namespace edm4hep
