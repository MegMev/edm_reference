// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerHit3D.h"
#include "edm4hep/TrackerHit3D.h"
#include "edm4hep/TrackerHit3DData.h"
#include "edm4hep/TrackerHit3DObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

TrackerHit3D::TrackerHit3D() : m_obj(new TrackerHit3DObj{}, podio::utils::MarkOwned) {
}

TrackerHit3D::TrackerHit3D(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep,
                           float eDepError, edm4hep::Vector3d position, edm4hep::CovMatrix3f covMatrix) :
    m_obj(new TrackerHit3DObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.type = type;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.eDep = eDep;
  m_obj->data.eDepError = eDepError;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
}

TrackerHit3D& TrackerHit3D::operator=(TrackerHit3D other) {
  swap(*this, other);
  return *this;
}

MutableTrackerHit3D TrackerHit3D::clone(bool cloneRelations) const {
  auto tmp = new TrackerHit3DObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
  } else {
  }
  return MutableTrackerHit3D(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

TrackerHit3D::TrackerHit3D(podio::utils::MaybeSharedPtr<TrackerHit3DObj> obj) : m_obj(std::move(obj)) {
}

TrackerHit3D::TrackerHit3D(const MutableTrackerHit3D& other) : TrackerHit3D(other.m_obj) {
}

TrackerHit3D::TrackerHit3D(TrackerHit3DObj* obj) : m_obj(podio::utils::MaybeSharedPtr<TrackerHit3DObj>(obj)) {
}

TrackerHit3D TrackerHit3D::makeEmpty() {
  return {nullptr};
}

std::uint64_t TrackerHit3D::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t TrackerHit3D::getType() const {
  return m_obj->data.type;
}
std::int32_t TrackerHit3D::getQuality() const {
  return m_obj->data.quality;
}
float TrackerHit3D::getTime() const {
  return m_obj->data.time;
}
float TrackerHit3D::getEDep() const {
  return m_obj->data.eDep;
}
float TrackerHit3D::getEDepError() const {
  return m_obj->data.eDepError;
}
const edm4hep::Vector3d& TrackerHit3D::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& TrackerHit3D::getCovMatrix() const {
  return m_obj->data.covMatrix;
}

bool TrackerHit3D::isAvailable() const {
  return m_obj;
}

const podio::ObjectID TrackerHit3D::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool TrackerHit3D::operator==(const MutableTrackerHit3D& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const TrackerHit3D& value) {
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
  o << " position : " << value.getPosition() << '\n';
  o << " covMatrix : " << value.getCovMatrix() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerHit3D& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},     {"type", value.getType()},
                     {"quality", value.getQuality()},   {"time", value.getTime()},
                     {"eDep", value.getEDep()},         {"eDepError", value.getEDepError()},
                     {"position", value.getPosition()}, {"covMatrix", value.getCovMatrix()}};
}
#endif

} // namespace edm4hep
