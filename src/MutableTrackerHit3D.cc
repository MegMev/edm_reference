// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerHit3D.h"
#include "edm4hep/TrackerHit3D.h"
#include "edm4hep/TrackerHit3DData.h"
#include "edm4hep/TrackerHit3DObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableTrackerHit3D::MutableTrackerHit3D() : m_obj(new TrackerHit3DObj{}, podio::utils::MarkOwned) {
}

MutableTrackerHit3D::MutableTrackerHit3D(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time,
                                         float eDep, float eDepError, edm4hep::Vector3d position,
                                         edm4hep::CovMatrix3f covMatrix) :
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

MutableTrackerHit3D& MutableTrackerHit3D::operator=(MutableTrackerHit3D other) {
  swap(*this, other);
  return *this;
}

MutableTrackerHit3D MutableTrackerHit3D::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new TrackerHit3DObj(podio::ObjectID{}, m_obj->data);
    return MutableTrackerHit3D(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableTrackerHit3D(podio::utils::MaybeSharedPtr(new TrackerHit3DObj(*m_obj), podio::utils::MarkOwned));
}

MutableTrackerHit3D::MutableTrackerHit3D(podio::utils::MaybeSharedPtr<TrackerHit3DObj> obj) : m_obj(std::move(obj)) {
}

std::uint64_t MutableTrackerHit3D::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t MutableTrackerHit3D::getType() const {
  return m_obj->data.type;
}
std::int32_t MutableTrackerHit3D::getQuality() const {
  return m_obj->data.quality;
}
float MutableTrackerHit3D::getTime() const {
  return m_obj->data.time;
}
float MutableTrackerHit3D::getEDep() const {
  return m_obj->data.eDep;
}
float MutableTrackerHit3D::getEDepError() const {
  return m_obj->data.eDepError;
}
const edm4hep::Vector3d& MutableTrackerHit3D::getPosition() const {
  return m_obj->data.position;
}
const edm4hep::CovMatrix3f& MutableTrackerHit3D::getCovMatrix() const {
  return m_obj->data.covMatrix;
}

void MutableTrackerHit3D::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableTrackerHit3D::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableTrackerHit3D::cellID() {
  return m_obj->data.cellID;
}
void MutableTrackerHit3D::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableTrackerHit3D::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableTrackerHit3D::type() {
  return m_obj->data.type;
}
void MutableTrackerHit3D::setQuality(std::int32_t value) {
  m_obj->data.quality = value;
}
std::int32_t& MutableTrackerHit3D::getQuality() {
  return m_obj->data.quality;
}
std::int32_t& MutableTrackerHit3D::quality() {
  return m_obj->data.quality;
}
void MutableTrackerHit3D::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableTrackerHit3D::getTime() {
  return m_obj->data.time;
}
float& MutableTrackerHit3D::time() {
  return m_obj->data.time;
}
void MutableTrackerHit3D::setEDep(float value) {
  m_obj->data.eDep = value;
}
float& MutableTrackerHit3D::getEDep() {
  return m_obj->data.eDep;
}
float& MutableTrackerHit3D::eDep() {
  return m_obj->data.eDep;
}
void MutableTrackerHit3D::setEDepError(float value) {
  m_obj->data.eDepError = value;
}
float& MutableTrackerHit3D::getEDepError() {
  return m_obj->data.eDepError;
}
float& MutableTrackerHit3D::eDepError() {
  return m_obj->data.eDepError;
}
void MutableTrackerHit3D::setPosition(edm4hep::Vector3d value) {
  m_obj->data.position = value;
}
edm4hep::Vector3d& MutableTrackerHit3D::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3d& MutableTrackerHit3D::position() {
  return m_obj->data.position;
}
void MutableTrackerHit3D::setCovMatrix(edm4hep::CovMatrix3f value) {
  m_obj->data.covMatrix = value;
}
edm4hep::CovMatrix3f& MutableTrackerHit3D::getCovMatrix() {
  return m_obj->data.covMatrix;
}
edm4hep::CovMatrix3f& MutableTrackerHit3D::covMatrix() {
  return m_obj->data.covMatrix;
}

bool MutableTrackerHit3D::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableTrackerHit3D::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableTrackerHit3D::operator==(const TrackerHit3D& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerHit3D& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},     {"type", value.getType()},
                     {"quality", value.getQuality()},   {"time", value.getTime()},
                     {"eDep", value.getEDep()},         {"eDepError", value.getEDepError()},
                     {"position", value.getPosition()}, {"covMatrix", value.getCovMatrix()}};
}
#endif

} // namespace edm4hep
