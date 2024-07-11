// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoClusterParticleAssociation.h"
#include "edm4hep/MCRecoClusterParticleAssociationData.h"
#include "edm4hep/MCRecoClusterParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoClusterParticleAssociation.h"

#include "edm4hep/Cluster.h"
#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoClusterParticleAssociation::MCRecoClusterParticleAssociation() :
    m_obj(new MCRecoClusterParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoClusterParticleAssociation::MCRecoClusterParticleAssociation(float weight) :
    m_obj(new MCRecoClusterParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoClusterParticleAssociation& MCRecoClusterParticleAssociation::operator=(MCRecoClusterParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoClusterParticleAssociation MCRecoClusterParticleAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoClusterParticleAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::Cluster(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::MCParticle(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoClusterParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoClusterParticleAssociation::MCRecoClusterParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoClusterParticleAssociation::MCRecoClusterParticleAssociation(
    const MutableMCRecoClusterParticleAssociation& other) :
    MCRecoClusterParticleAssociation(other.m_obj) {
}

MCRecoClusterParticleAssociation::MCRecoClusterParticleAssociation(MCRecoClusterParticleAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj>(obj)) {
}

MCRecoClusterParticleAssociation MCRecoClusterParticleAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoClusterParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::Cluster MCRecoClusterParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::Cluster::makeEmpty();
  }
  return edm4hep::Cluster(*(m_obj->m_rec));
}

const edm4hep::MCParticle MCRecoClusterParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

bool MCRecoClusterParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoClusterParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoClusterParticleAssociation::operator==(const MutableMCRecoClusterParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoClusterParticleAssociation& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " rec : " << value.getRec().id() << '\n';
  o << " sim : " << value.getSim().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoClusterParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
