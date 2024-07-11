// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoTrackParticleAssociation.h"
#include "edm4hep/MCRecoTrackParticleAssociationData.h"
#include "edm4hep/MCRecoTrackParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoTrackParticleAssociation.h"

#include "edm4hep/MCParticle.h"
#include "edm4hep/Track.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoTrackParticleAssociation::MCRecoTrackParticleAssociation() :
    m_obj(new MCRecoTrackParticleAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoTrackParticleAssociation::MCRecoTrackParticleAssociation(float weight) :
    m_obj(new MCRecoTrackParticleAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoTrackParticleAssociation& MCRecoTrackParticleAssociation::operator=(MCRecoTrackParticleAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoTrackParticleAssociation MCRecoTrackParticleAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoTrackParticleAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::Track(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::MCParticle(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoTrackParticleAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoTrackParticleAssociation::MCRecoTrackParticleAssociation(
    podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoTrackParticleAssociation::MCRecoTrackParticleAssociation(const MutableMCRecoTrackParticleAssociation& other) :
    MCRecoTrackParticleAssociation(other.m_obj) {
}

MCRecoTrackParticleAssociation::MCRecoTrackParticleAssociation(MCRecoTrackParticleAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoTrackParticleAssociationObj>(obj)) {
}

MCRecoTrackParticleAssociation MCRecoTrackParticleAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoTrackParticleAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::Track MCRecoTrackParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::Track::makeEmpty();
  }
  return edm4hep::Track(*(m_obj->m_rec));
}

const edm4hep::MCParticle MCRecoTrackParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::MCParticle::makeEmpty();
  }
  return edm4hep::MCParticle(*(m_obj->m_sim));
}

bool MCRecoTrackParticleAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoTrackParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoTrackParticleAssociation::operator==(const MutableMCRecoTrackParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoTrackParticleAssociation& value) {
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
void to_json(nlohmann::json& j, const MCRecoTrackParticleAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
