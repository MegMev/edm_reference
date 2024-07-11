// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerHitPlane.h"
#include "edm4hep/TrackerHitPlane.h"
#include "edm4hep/TrackerHitPlaneData.h"
#include "edm4hep/TrackerHitPlaneObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableTrackerHitPlane::MutableTrackerHitPlane() : m_obj(new TrackerHitPlaneObj{}, podio::utils::MarkOwned) {
}

MutableTrackerHitPlane::MutableTrackerHitPlane(std::uint64_t cellID, std::int32_t type, std::int32_t quality,
                                               float time, float eDep, float eDepError, edm4hep::Vector2f u,
                                               edm4hep::Vector2f v, float du, float dv, edm4hep::Vector3d position,
                                               edm4hep::CovMatrix3f covMatrix) :
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

MutableTrackerHitPlane& MutableTrackerHitPlane::operator=(MutableTrackerHitPlane other) {
  swap(*this, other);
  return *this;
}

MutableTrackerHitPlane MutableTrackerHitPlane::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new TrackerHitPlaneObj(podio::ObjectID{}, m_obj->data);
    return MutableTrackerHitPlane(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableTrackerHitPlane(podio::utils::MaybeSharedPtr(new TrackerHitPlaneObj(*m_obj), podio::utils::MarkOwned));
}

MutableTrackerHitPlane::MutableTrackerHitPlane(podio::utils::MaybeSharedPtr<TrackerHitPlaneObj> obj) :
    m_obj(std::move(obj)) {
}

std::uint64_t MutableTrackerHitPlane::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t MutableTrackerHitPlane::getType() const {
  return m_obj->data.type;
}
std::int32_t MutableTrackerHitPlane::getQuality() const {
  return m_obj->data.quality;
}
float MutableTrackerHitPlane::getTime() const {
  return m_obj->data.time;
}
float MutableTrackerHitPlane::getEDep() const {
  return m_obj->data.eDep;
}
float MutableTrackerHitPlane::getEDepError() const {
  return m_obj->data.eDepError;
}
const edm4hep::Vector2f& MutableTrackerHitPlane::getU() const {
  return m_obj->data.u;
}
const edm4hep::Vector2f& MutableTrackerHitPlane::getV() const {
  return m_obj->data.v;
}
float MutableTrackerHitPlane::getDu() const {
  return m_obj->data.du;
}
float MutableTrackerHitPlane::getDv() const {
  return m_obj->data.dv;
}
const edm4hep::Vector3d& MutableTrackerHitPlane::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& MutableTrackerHitPlane::getCovMatrix() const {
  return m_obj->data.covMatrix;
}

void MutableTrackerHitPlane::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableTrackerHitPlane::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableTrackerHitPlane::cellID() {
  return m_obj->data.cellID;
}
void MutableTrackerHitPlane::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableTrackerHitPlane::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableTrackerHitPlane::type() {
  return m_obj->data.type;
}
void MutableTrackerHitPlane::setQuality(std::int32_t value) {
  m_obj->data.quality = value;
}
std::int32_t& MutableTrackerHitPlane::getQuality() {
  return m_obj->data.quality;
}
std::int32_t& MutableTrackerHitPlane::quality() {
  return m_obj->data.quality;
}
void MutableTrackerHitPlane::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableTrackerHitPlane::getTime() {
  return m_obj->data.time;
}
float& MutableTrackerHitPlane::time() {
  return m_obj->data.time;
}
void MutableTrackerHitPlane::setEDep(float value) {
  m_obj->data.eDep = value;
}
float& MutableTrackerHitPlane::getEDep() {
  return m_obj->data.eDep;
}
float& MutableTrackerHitPlane::eDep() {
  return m_obj->data.eDep;
}
void MutableTrackerHitPlane::setEDepError(float value) {
  m_obj->data.eDepError = value;
}
float& MutableTrackerHitPlane::getEDepError() {
  return m_obj->data.eDepError;
}
float& MutableTrackerHitPlane::eDepError() {
  return m_obj->data.eDepError;
}
void MutableTrackerHitPlane::setU(edm4hep::Vector2f value) {
  m_obj->data.u = value;
}
edm4hep::Vector2f& MutableTrackerHitPlane::getU() {
  return m_obj->data.u;
}
edm4hep::Vector2f& MutableTrackerHitPlane::u() {
  return m_obj->data.u;
}
void MutableTrackerHitPlane::setV(edm4hep::Vector2f value) {
  m_obj->data.v = value;
}
edm4hep::Vector2f& MutableTrackerHitPlane::getV() {
  return m_obj->data.v;
}
edm4hep::Vector2f& MutableTrackerHitPlane::v() {
  return m_obj->data.v;
}
void MutableTrackerHitPlane::setDu(float value) {
  m_obj->data.du = value;
}
float& MutableTrackerHitPlane::getDu() {
  return m_obj->data.du;
}
float& MutableTrackerHitPlane::du() {
  return m_obj->data.du;
}
void MutableTrackerHitPlane::setDv(float value) {
  m_obj->data.dv = value;
}
float& MutableTrackerHitPlane::getDv() {
  return m_obj->data.dv;
}
float& MutableTrackerHitPlane::dv() {
  return m_obj->data.dv;
}
void MutableTrackerHitPlane::setPosition(edm4hep::Vector3d value) {
  m_obj->data.position = value;
}
edm4hep::Vector3d& MutableTrackerHitPlane::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3d& MutableTrackerHitPlane::position() {
  return m_obj->data.position;
}
void MutableTrackerHitPlane::setCovMatrix(edm4hep::CovMatrix3f value) {
  m_obj->data.covMatrix = value;
}
edm4hep::CovMatrix3f& MutableTrackerHitPlane::getCovMatrix() {
  return m_obj->data.covMatrix;
}
edm4hep::CovMatrix3f& MutableTrackerHitPlane::covMatrix() {
  return m_obj->data.covMatrix;
}

bool MutableTrackerHitPlane::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableTrackerHitPlane::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableTrackerHitPlane::operator==(const TrackerHitPlane& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerHitPlane& value) {
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
