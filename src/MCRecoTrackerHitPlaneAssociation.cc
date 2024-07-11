// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoTrackerHitPlaneAssociation.h"
#include "edm4hep/MCRecoTrackerHitPlaneAssociationData.h"
#include "edm4hep/MCRecoTrackerHitPlaneAssociationObj.h"
#include "edm4hep/MutableMCRecoTrackerHitPlaneAssociation.h"

#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHitPlane.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoTrackerHitPlaneAssociation::MCRecoTrackerHitPlaneAssociation() :
    m_obj(new MCRecoTrackerHitPlaneAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoTrackerHitPlaneAssociation::MCRecoTrackerHitPlaneAssociation(float weight) :
    m_obj(new MCRecoTrackerHitPlaneAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoTrackerHitPlaneAssociation& MCRecoTrackerHitPlaneAssociation::operator=(MCRecoTrackerHitPlaneAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoTrackerHitPlaneAssociation MCRecoTrackerHitPlaneAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoTrackerHitPlaneAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::TrackerHitPlane(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::SimTrackerHit(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoTrackerHitPlaneAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoTrackerHitPlaneAssociation::MCRecoTrackerHitPlaneAssociation(
    podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoTrackerHitPlaneAssociation::MCRecoTrackerHitPlaneAssociation(
    const MutableMCRecoTrackerHitPlaneAssociation& other) :
    MCRecoTrackerHitPlaneAssociation(other.m_obj) {
}

MCRecoTrackerHitPlaneAssociation::MCRecoTrackerHitPlaneAssociation(MCRecoTrackerHitPlaneAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj>(obj)) {
}

MCRecoTrackerHitPlaneAssociation MCRecoTrackerHitPlaneAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoTrackerHitPlaneAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::TrackerHitPlane MCRecoTrackerHitPlaneAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::TrackerHitPlane::makeEmpty();
  }
  return edm4hep::TrackerHitPlane(*(m_obj->m_rec));
}

const edm4hep::SimTrackerHit MCRecoTrackerHitPlaneAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::SimTrackerHit::makeEmpty();
  }
  return edm4hep::SimTrackerHit(*(m_obj->m_sim));
}

bool MCRecoTrackerHitPlaneAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoTrackerHitPlaneAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoTrackerHitPlaneAssociation::operator==(const MutableMCRecoTrackerHitPlaneAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoTrackerHitPlaneAssociation& value) {
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
void to_json(nlohmann::json& j, const MCRecoTrackerHitPlaneAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
