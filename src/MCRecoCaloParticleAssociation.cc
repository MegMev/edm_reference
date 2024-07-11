// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoCaloParticleAssociation.h"
#include "edm4hep/MCRecoCaloParticleAssociationData.h"
#include "edm4hep/MCRecoCaloParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoCaloParticleAssociation.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/MCParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoCaloParticleAssociation::MCRecoCaloParticleAssociation() :
    m_obj(new MCRecoCaloParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoCaloParticleAssociation::MCRecoCaloParticleAssociation(float weight) :
    m_obj(new MCRecoCaloParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoCaloParticleAssociation& MCRecoCaloParticleAssociation::operator=(MCRecoCaloParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoCaloParticleAssociation MCRecoCaloParticleAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoCaloParticleAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::CalorimeterHit(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::MCParticle(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoCaloParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoCaloParticleAssociation::MCRecoCaloParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoCaloParticleAssociation::MCRecoCaloParticleAssociation(const MutableMCRecoCaloParticleAssociation& other) :
    MCRecoCaloParticleAssociation(other.m_obj) {
}

MCRecoCaloParticleAssociation::MCRecoCaloParticleAssociation(MCRecoCaloParticleAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoCaloParticleAssociationObj>(obj)) {
}

MCRecoCaloParticleAssociation MCRecoCaloParticleAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoCaloParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::CalorimeterHit MCRecoCaloParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::CalorimeterHit::makeEmpty();
  }
  return edm4hep::CalorimeterHit(*(m_obj->m_rec));
}

const edm4hep::MCParticle MCRecoCaloParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

bool MCRecoCaloParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoCaloParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoCaloParticleAssociation::operator==(const MutableMCRecoCaloParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoCaloParticleAssociation& value) {
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
void to_json(nlohmann::json& j, const MCRecoCaloParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
