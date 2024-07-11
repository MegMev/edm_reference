// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoParticleAssociation.h"
#include "edm4hep/MCRecoParticleAssociationData.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoParticleAssociation.h"

#include "edm4hep/MCParticle.h"
#include "edm4hep/ReconstructedParticle.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoParticleAssociation::MCRecoParticleAssociation() :
    m_obj(new MCRecoParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoParticleAssociation::MCRecoParticleAssociation(float weight) :
    m_obj(new MCRecoParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoParticleAssociation& MCRecoParticleAssociation::operator=(MCRecoParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoParticleAssociation MCRecoParticleAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoParticleAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::ReconstructedParticle(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::MCParticle(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoParticleAssociation::MCRecoParticleAssociation(podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoParticleAssociation::MCRecoParticleAssociation(const MutableMCRecoParticleAssociation& other) :
    MCRecoParticleAssociation(other.m_obj) {
}

MCRecoParticleAssociation::MCRecoParticleAssociation(MCRecoParticleAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj>(obj)) {
}

MCRecoParticleAssociation MCRecoParticleAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::ReconstructedParticle MCRecoParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::ReconstructedParticle::makeEmpty();
  }
  return edm4hep::ReconstructedParticle(*(m_obj->m_rec));
}

const edm4hep::MCParticle MCRecoParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

bool MCRecoParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoParticleAssociation::operator==(const MutableMCRecoParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoParticleAssociation& value) {
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
void to_json(nlohmann::json& j, const MCRecoParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
