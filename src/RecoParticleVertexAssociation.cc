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

#include <ostream>

namespace edm4hep {

RecoParticleVertexAssociation::RecoParticleVertexAssociation() :
    m_obj(new RecoParticleVertexAssociationObj{}, podio::utils::MarkOwned) {
}

RecoParticleVertexAssociation::RecoParticleVertexAssociation(float weight) :
    m_obj(new RecoParticleVertexAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

RecoParticleVertexAssociation& RecoParticleVertexAssociation::operator=(RecoParticleVertexAssociation other) {
  swap(*this, other);
  return *this;
}

MutableRecoParticleVertexAssociation RecoParticleVertexAssociation::clone(bool cloneRelations) const {
  auto tmp = new RecoParticleVertexAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::ReconstructedParticle(*m_obj->m_rec);
    }
    if (m_obj->m_vertex) {
      tmp->m_vertex = new edm4hep::Vertex(*m_obj->m_vertex);
    }
  } else {
  }
  return MutableRecoParticleVertexAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

RecoParticleVertexAssociation::RecoParticleVertexAssociation(
    podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

RecoParticleVertexAssociation::RecoParticleVertexAssociation(const MutableRecoParticleVertexAssociation& other) :
    RecoParticleVertexAssociation(other.m_obj) {
}

RecoParticleVertexAssociation::RecoParticleVertexAssociation(RecoParticleVertexAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<RecoParticleVertexAssociationObj>(obj)) {
}

RecoParticleVertexAssociation RecoParticleVertexAssociation::makeEmpty() {
  return {nullptr};
}

float RecoParticleVertexAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::ReconstructedParticle RecoParticleVertexAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_rec));
}

const edm4hep::Vertex RecoParticleVertexAssociation::getVertex() const {
  if (!m_obj->m_vertex) {
    return edm4hep::Vertex::makeEmpty();
  }
  return edm4hep::Vertex(*(m_obj->m_vertex));
}

bool RecoParticleVertexAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID RecoParticleVertexAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool RecoParticleVertexAssociation::operator==(const MutableRecoParticleVertexAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const RecoParticleVertexAssociation& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " rec : " << value.getRec().id() << '\n';
  o << " vertex : " << value.getVertex().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecoParticleVertexAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["vertex"] = nlohmann::json{{"collectionID", value.getVertex().getObjectID().collectionID},
                               {"index", value.getVertex().getObjectID().index}};
}
#endif

} // namespace edm4hep
