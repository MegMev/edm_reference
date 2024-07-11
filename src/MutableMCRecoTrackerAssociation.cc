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

namespace edm4hep {

MutableMCRecoTrackerAssociation::MutableMCRecoTrackerAssociation() :
    m_obj(new MCRecoTrackerAssociationObj{}, podio::utils::MarkOwned) {
}

MutableMCRecoTrackerAssociation::MutableMCRecoTrackerAssociation(float weight) :
    m_obj(new MCRecoTrackerAssociationObj{}, podio::utils::MarkOwned) {
  m_obj->data.weight = weight;
}

MutableMCRecoTrackerAssociation& MutableMCRecoTrackerAssociation::operator=(MutableMCRecoTrackerAssociation other) {
  swap(*this, other);
  return *this;
}

MutableMCRecoTrackerAssociation MutableMCRecoTrackerAssociation::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new MCRecoTrackerAssociationObj(podio::ObjectID{}, m_obj->data);
    return MutableMCRecoTrackerAssociation(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableMCRecoTrackerAssociation(
      podio::utils::MaybeSharedPtr(new MCRecoTrackerAssociationObj(*m_obj), podio::utils::MarkOwned));
}

MutableMCRecoTrackerAssociation::MutableMCRecoTrackerAssociation(
    podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj> obj) :
    m_obj(std::move(obj)) {
}

float MutableMCRecoTrackerAssociation::getWeight() const {
  return m_obj->data.weight;
}

const edm4hep::TrackerHit MutableMCRecoTrackerAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return edm4hep::TrackerHit::makeEmpty();
  }
  return edm4hep::TrackerHit(*(m_obj->m_rec));
}

const edm4hep::SimTrackerHit MutableMCRecoTrackerAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return edm4hep::SimTrackerHit::makeEmpty();
  }
  return edm4hep::SimTrackerHit(*(m_obj->m_sim));
}

void MutableMCRecoTrackerAssociation::setWeight(float value) {
  m_obj->data.weight = value;
}
float& MutableMCRecoTrackerAssociation::getWeight() {
  return m_obj->data.weight;
}
float& MutableMCRecoTrackerAssociation::weight() {
  return m_obj->data.weight;
}

void MutableMCRecoTrackerAssociation::setRec(const edm4hep::TrackerHit& value) {
  delete m_obj->m_rec;
  m_obj->m_rec = new edm4hep::TrackerHit(value);
}

void MutableMCRecoTrackerAssociation::setSim(const edm4hep::SimTrackerHit& value) {
  delete m_obj->m_sim;
  m_obj->m_sim = new edm4hep::SimTrackerHit(value);
}

bool MutableMCRecoTrackerAssociation::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableMCRecoTrackerAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableMCRecoTrackerAssociation::operator==(const MCRecoTrackerAssociation& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoTrackerAssociation& value) {
  j = nlohmann::json{{"weight", value.getWeight()}};

  j["rec"] = nlohmann::json{{"collectionID", value.getRec().getObjectID().collectionID},
                            {"index", value.getRec().getObjectID().index}};

  j["sim"] = nlohmann::json{{"collectionID", value.getSim().getObjectID().collectionID},
                            {"index", value.getSim().getObjectID().index}};
}
#endif

} // namespace edm4hep
