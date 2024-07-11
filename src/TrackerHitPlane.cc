// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerHitPlane.h"
#include "edm4hep/TrackerHitPlane.h"
#include "edm4hep/TrackerHitPlaneData.h"
#include "edm4hep/TrackerHitPlaneObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

TrackerHitPlane::TrackerHitPlane() : m_obj(new TrackerHitPlaneObj{}, podio::utils::MarkOwned) {
}

TrackerHitPlane::TrackerHitPlane(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep,
                                 float eDepError, edm4hep::Vector2f u, edm4hep::Vector2f v, float du, float dv,
                                 edm4hep::Vector3d position, edm4hep::CovMatrix3f covMatrix) :
    m_obj(new TrackerHitPlaneObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.type = type;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.eDep = eDep;
  m_obj->data.eDepError = eDepError;
  m_obj->data.u = u;
  m_obj->data.v = v;
  m_obj->data.du = du;
  m_obj->data.dv = dv;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
}

TrackerHitPlane& TrackerHitPlane::operator=(TrackerHitPlane other) {
  swap(*this, other);
  return *this;
}

MutableTrackerHitPlane TrackerHitPlane::clone(bool cloneRelations) const {
  auto tmp = new TrackerHitPlaneObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
  } else {
  }
  return MutableTrackerHitPlane(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

TrackerHitPlane::TrackerHitPlane(podio::utils::MaybeSharedPtr<TrackerHitPlaneObj> obj) : m_obj(std::move(obj)) {
}

TrackerHitPlane::TrackerHitPlane(const MutableTrackerHitPlane& other) : TrackerHitPlane(other.m_obj) {
}

TrackerHitPlane::TrackerHitPlane(TrackerHitPlaneObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<TrackerHitPlaneObj>(obj)) {
}

TrackerHitPlane TrackerHitPlane::makeEmpty() {
  return {nullptr};
}

std::uint64_t TrackerHitPlane::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t TrackerHitPlane::getType() const {
  return m_obj->data.type;
}
std::int32_t TrackerHitPlane::getQuality() const {
  return m_obj->data.quality;
}
float TrackerHitPlane::getTime() const {
  return m_obj->data.time;
}
float TrackerHitPlane::getEDep() const {
  return m_obj->data.eDep;
}
float TrackerHitPlane::getEDepError() const {
  return m_obj->data.eDepError;
}
const edm4hep::Vector2f& TrackerHitPlane::getU() const {
  return m_obj->data.u;
}
const edm4hep::Vector2f& TrackerHitPlane::getV() const {
  return m_obj->data.v;
}
float TrackerHitPlane::getDu() const {
  return m_obj->data.du;
}
float TrackerHitPlane::getDv() const {
  return m_obj->data.dv;
}
const edm4hep::Vector3d& TrackerHitPlane::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& TrackerHitPlane::getCovMatrix() const {
  return m_obj->data.covMatrix;
}

bool TrackerHitPlane::isAvailable() const {
  return m_obj;
}

const podio::ObjectID TrackerHitPlane::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool TrackerHitPlane::operator==(const MutableTrackerHitPlane& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const TrackerHitPlane& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " eDep : " << value.getEDep() << '\n';
  o << " eDepError : " << value.getEDepError() << '\n';
  o << " u : " << value.getU() << '\n';
  o << " v : " << value.getV() << '\n';
  o << " du : " << value.getDu() << '\n';
  o << " dv : " << value.getDv() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " covMatrix : " << value.getCovMatrix() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerHitPlane& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"type", value.getType()},
                     {"quality", value.getQuality()},
                     {"time", value.getTime()},
                     {"eDep", value.getEDep()},
                     {"eDepError", value.getEDepError()},
                     {"u", value.getU()},
                     {"v", value.getV()},
                     {"du", value.getDu()},
                     {"dv", value.getDv()},
                     {"position", value.getPosition()},
                     {"covMatrix", value.getCovMatrix()}};
}
#endif

} // namespace edm4hep
