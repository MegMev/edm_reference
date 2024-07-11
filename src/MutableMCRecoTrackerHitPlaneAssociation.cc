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

namespace edm4hep {

MutableMCRecoTrackerHitPlaneAssociation::MutableMCRecoTrackerHitPlaneAssociation() :
    m_obj(new MCRecoTrackerHitPlaneAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoTrackerHitPlaneAssociation::MutableMCRecoTrackerHitPlaneAssociation(float weight) :
    m_obj(new MCRecoTrackerHitPlaneAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoTrackerHitPlaneAssociation&
MutableMCRecoTrackerHitPlaneAssociation::operator=(MutableMCRecoTrackerHitPlaneAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoTrackerHitPlaneAssociation MutableMCRecoTrackerHitPlaneAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoTrackerHitPlaneAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoTrackerHitPlaneAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoTrackerHitPlaneAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoTrackerHitPlaneAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoTrackerHitPlaneAssociation::MutableMCRecoTrackerHitPlaneAssociation(
    podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoTrackerHitPlaneAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::TrackerHitPlane MutableMCRecoTrackerHitPlaneAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::TrackerHitPlane::makeEmpty();
  }
  return edm4hep::TrackerHitPlane(*(m_obj->m_rec));
}

const edm4hep::SimTrackerHit MutableMCRecoTrackerHitPlaneAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::SimTrackerHit::makeEmpty();
  }
  return edm4hep::SimTrackerHit(*(m_obj->m_sim));
}

void MutableMCRecoTrackerHitPlaneAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoTrackerHitPlaneAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoTrackerHitPlaneAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoTrackerHitPlaneAssociation::setRec(const edm4hep::TrackerHitPlane& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::TrackerHitPlane(value);
}

void MutableMCRecoTrackerHitPlaneAssociation::setSim(const edm4hep::SimTrackerHit& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::SimTrackerHit(value);
}

bool MutableMCRecoTrackerHitPlaneAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoTrackerHitPlaneAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoTrackerHitPlaneAssociation::operator==(const MCRecoTrackerHitPlaneAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoTrackerHitPlaneAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
