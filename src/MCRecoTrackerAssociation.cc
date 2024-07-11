// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoTrackerAssociation.h"
#include "edm4hep/MCRecoTrackerAssociationData.h"
#include "edm4hep/MCRecoTrackerAssociationObj.h"
#include "edm4hep/MutableMCRecoTrackerAssociation.h"

#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHit.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

MCRecoTrackerAssociation::MCRecoTrackerAssociation() :
    m_obj(new MCRecoTrackerAssociationObj{}, podio::utils::MarkOwned) {
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation(float weight) :
    m_obj(new MCRecoTrackerAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MCRecoTrackerAssociation& MCRecoTrackerAssociation::operator=(MCRecoTrackerAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoTrackerAssociation MCRecoTrackerAssociation::clone(bool cloneRelations) const {
  auto tmp = new MCRecoTrackerAssociationObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_rec) {
      tmp->m_rec = new edm4hep::TrackerHit(*m_obj->m_rec);
    }
    if (m_obj->m_sim) {
      tmp->m_sim = new edm4hep::SimTrackerHit(*m_obj->m_sim);
    }
  } else {
  }
  return MutableMCRecoTrackerAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation(podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation(const MutableMCRecoTrackerAssociation& other) :
    MCRecoTrackerAssociation(other.m_obj) {
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation(MCRecoTrackerAssociationObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj>(obj)) {
}

MCRecoTrackerAssociation MCRecoTrackerAssociation::makeEmpty() {
  return {nullptr};
}

float MCRecoTrackerAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::TrackerHit MCRecoTrackerAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::TrackerHit::makeEmpty();
  }
  return edm4hep::TrackerHit(*(m_obj->m_rec));
}

const edm4hep::SimTrackerHit MCRecoTrackerAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::SimTrackerHit::makeEmpty();
  }
  return edm4hep::SimTrackerHit(*(m_obj->m_sim));
}

bool MCRecoTrackerAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MCRecoTrackerAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MCRecoTrackerAssociation::operator==(const MutableMCRecoTrackerAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const MCRecoTrackerAssociation& value) {
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
void to_json(nlohmann::json& j, const MCRecoTrackerAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
