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

#include <ostream>

namespace edm4hep {

RecDqdx::RecDqdx() : m_obj(new RecDqdxObj{}, podio::utils::MarkOwned) {
}

RecDqdx::RecDqdx(edm4hep::Quantity dQdx) : m_obj(new RecDqdxObj{}, podio::utils::MarkOwned) {
  m_obj->data.dQdx = dQdx;
}

RecDqdx& RecDqdx::operator=(RecDqdx other) {
  swap(*this, other);
  return *this;
}

MutableRecDqdx RecDqdx::clone(bool cloneRelations) const {
  auto tmp = new RecDqdxObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_track) {
      tmp->m_track = new edm4hep::Track(*m_obj->m_track);
    }
  } else {
  }
  return MutableRecDqdx(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

RecDqdx::RecDqdx(podio::utils::MaybeSharedPtr<RecDqdxObj> obj) : m_obj(std::move(obj)) {
}

RecDqdx::RecDqdx(const MutableRecDqdx& other) : RecDqdx(other.m_obj) {
}

RecDqdx::RecDqdx(RecDqdxObj* obj) : m_obj(podio::utils::MaybeSharedPtr<RecDqdxObj>(obj)) {
}

RecDqdx RecDqdx::makeEmpty() {
  return {nullptr};
}

const edm4hep::Quantity& RecDqdx::getDQdx() const {
  return m_obj->data.dQdx;
}

const edm4hep::Track RecDqdx::getTrack() const {
  if (!m_obj->m_track) {
    return edm4hep::Track::makeEmpty();
  }
  return edm4hep::Track(*(m_obj->m_track));
}

bool RecDqdx::isAvailable() const {
  return m_obj;
}

const podio::ObjectID RecDqdx::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool RecDqdx::operator==(const MutableRecDqdx& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const RecDqdx& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " dQdx : " << value.getDQdx() << '\n';

  o << " track : " << value.getTrack().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecDqdx& value) {
  j = nlohmann::json{{"dQdx", value.getDQdx()}};

  j["track"] = nlohmann::json{{"collectionID", value.getTrack().getObjectID().collectionID},
                              {"index", value.getTrack().getObjectID().index}};
}
#endif

} // namespace edm4hep
