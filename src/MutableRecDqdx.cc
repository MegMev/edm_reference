// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableRecDqdx.h"
#include "edm4hep/RecDqdx.h"
#include "edm4hep/RecDqdxData.h"
#include "edm4hep/RecDqdxObj.h"

#include "edm4hep/Track.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableRecDqdx::MutableRecDqdx() : m_obj(new RecDqdxObj{}, podio::utils::MarkOwned) {
}

MutableRecDqdx::MutableRecDqdx(edm4hep::Quantity dQdx) : m_obj(new RecDqdxObj{}, podio::utils::MarkOwned) {
  m_obj->data.dQdx = dQdx;
}

MutableRecDqdx& MutableRecDqdx::operator=(MutableRecDqdx other) {
  swap(*this, other);
  return *this;
}

MutableRecDqdx MutableRecDqdx::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new RecDqdxObj(podio::ObjectID{}, m_obj->data);
    return MutableRecDqdx(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableRecDqdx(podio::utils::MaybeSharedPtr(new RecDqdxObj(*m_obj), podio::utils::MarkOwned));
}

MutableRecDqdx::MutableRecDqdx(podio::utils::MaybeSharedPtr<RecDqdxObj> obj) : m_obj(std::move(obj)) {
}

const edm4hep::Quantity& MutableRecDqdx::getDQdx() const {
  return m_obj->data.dQdx;
}

const edm4hep::Track MutableRecDqdx::getTrack() const {
  if (!m_obj->m_track) {
    return edm4hep::Track::makeEmpty();
  }
  return edm4hep::Track(*(m_obj->m_track));
}

void MutableRecDqdx::setDQdx(edm4hep::Quantity value) {
  m_obj->data.dQdx = value;
}
edm4hep::Quantity& MutableRecDqdx::getDQdx() {
  return m_obj->data.dQdx;
}
edm4hep::Quantity& MutableRecDqdx::dQdx() {
  return m_obj->data.dQdx;
}

void MutableRecDqdx::setTrack(const edm4hep::Track& value) {
  delete m_obj->m_track;
  m_obj->m_track = new edm4hep::Track(value);
}

bool MutableRecDqdx::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableRecDqdx::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableRecDqdx::operator==(const RecDqdx& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRecDqdx& value) {
  j = nlohmann::json{{"dQdx", value.getDQdx()}};

  j["track"] = nlohmann::json{{"collectionID", value.getTrack().getObjectID().collectionID},
                              {"index", value.getTrack().getObjectID().index}};
}
#endif

} // namespace edm4hep
