// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerHit.h"
#include "edm4hep/TrackerHit.h"
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/TrackerHitObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableTrackerHit::MutableTrackerHit() : m_obj(new TrackerHitObj{}, podio::utils::MarkOwned) {
}

MutableTrackerHit::MutableTrackerHit(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time,
                                     float eDep, float eDepError, edm4hep::Vector3d position,
                                     std::array<float, 6> covMatrix) :
    m_obj(new TrackerHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.type = type;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.eDep = eDep;
  m_obj->data.eDepError = eDepError;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
}

MutableTrackerHit& MutableTrackerHit::operator=(MutableTrackerHit other) {
  swap(*this, other);
  return *this;
}

MutableTrackerHit MutableTrackerHit::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new TrackerHitObj(podio::ObjectID{}, m_obj->data);
    tmp->m_rawHits = new std::vector<edm4hep::ObjectID>();
    tmp->data.rawHits_begin = 0;
    tmp->data.rawHits_end = 0;
    return MutableTrackerHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableTrackerHit(podio::utils::MaybeSharedPtr(new TrackerHitObj(*m_obj), podio::utils::MarkOwned));
}

MutableTrackerHit::MutableTrackerHit(podio::utils::MaybeSharedPtr<TrackerHitObj> obj) : m_obj(std::move(obj)) {
}

std::uint64_t MutableTrackerHit::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t MutableTrackerHit::getType() const {
  return m_obj->data.type;
}
std::int32_t MutableTrackerHit::getQuality() const {
  return m_obj->data.quality;
}
float MutableTrackerHit::getTime() const {
  return m_obj->data.time;
}
float MutableTrackerHit::getEDep() const {
  return m_obj->data.eDep;
}
float MutableTrackerHit::getEDepError() const {
  return m_obj->data.eDepError;
}
const edm4hep::Vector3d& MutableTrackerHit::getPosition() const {
  return m_obj->data.position;
}
const std::array<float, 6>& MutableTrackerHit::getCovMatrix() const {
  return m_obj->data.covMatrix;
}
float MutableTrackerHit::getCovMatrix(size_t i) const {
  return m_obj->data.covMatrix.at(i);
}

void MutableTrackerHit::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
std::uint64_t& MutableTrackerHit::getCellID() {
  return m_obj->data.cellID;
}
std::uint64_t& MutableTrackerHit::cellID() {
  return m_obj->data.cellID;
}
void MutableTrackerHit::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableTrackerHit::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableTrackerHit::type() {
  return m_obj->data.type;
}
void MutableTrackerHit::setQuality(std::int32_t value) {
  m_obj->data.quality = value;
}
std::int32_t& MutableTrackerHit::getQuality() {
  return m_obj->data.quality;
}
std::int32_t& MutableTrackerHit::quality() {
  return m_obj->data.quality;
}
void MutableTrackerHit::setTime(float value) {
  m_obj->data.time = value;
}
float& MutableTrackerHit::getTime() {
  return m_obj->data.time;
}
float& MutableTrackerHit::time() {
  return m_obj->data.time;
}
void MutableTrackerHit::setEDep(float value) {
  m_obj->data.eDep = value;
}
float& MutableTrackerHit::getEDep() {
  return m_obj->data.eDep;
}
float& MutableTrackerHit::eDep() {
  return m_obj->data.eDep;
}
void MutableTrackerHit::setEDepError(float value) {
  m_obj->data.eDepError = value;
}
float& MutableTrackerHit::getEDepError() {
  return m_obj->data.eDepError;
}
float& MutableTrackerHit::eDepError() {
  return m_obj->data.eDepError;
}
void MutableTrackerHit::setPosition(edm4hep::Vector3d value) {
  m_obj->data.position = value;
}
edm4hep::Vector3d& MutableTrackerHit::getPosition() {
  return m_obj->data.position;
}
edm4hep::Vector3d& MutableTrackerHit::position() {
  return m_obj->data.position;
}
void MutableTrackerHit::setCovMatrix(std::array<float, 6> value) {
  m_obj->data.covMatrix = value;
}
void MutableTrackerHit::setCovMatrix(size_t i, float value) {
  m_obj->data.covMatrix.at(i) = value;
}
std::array<float, 6>& MutableTrackerHit::getCovMatrix() {
  return m_obj->data.covMatrix;
}
std::array<float, 6>& MutableTrackerHit::covMatrix() {
  return m_obj->data.covMatrix;
}

void MutableTrackerHit::addToRawHits(const edm4hep::ObjectID& component) {
  m_obj->m_rawHits->push_back(component);
  m_obj->data.rawHits_end++;
}

std::vector<edm4hep::ObjectID>::const_iterator MutableTrackerHit::rawHits_begin() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_begin);
  return ret_value;
}

std::vector<edm4hep::ObjectID>::const_iterator MutableTrackerHit::rawHits_end() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_end);
  return ret_value;
}

std::size_t MutableTrackerHit::rawHits_size() const {
  return m_obj->data.rawHits_end - m_obj->data.rawHits_begin;
}

edm4hep::ObjectID MutableTrackerHit::getRawHits(std::size_t index) const {
  if (rawHits_size() > index) {
    return m_obj->m_rawHits->at(m_obj->data.rawHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::ObjectID> MutableTrackerHit::getRawHits() const {
  auto begin = m_obj->m_rawHits->begin();
  std::advance(begin, m_obj->data.rawHits_begin);
  auto end = m_obj->m_rawHits->begin();
  std::advance(end, m_obj->data.rawHits_end);
  return {begin, end};
}

bool MutableTrackerHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableTrackerHit::operator==(const TrackerHit& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerHit& value) {
  j = nlohmann::json{
      {"cellID", value.getCellID()},     {"type", value.getType()},           {"quality", value.getQuality()},
      {"time", value.getTime()},         {"eDep", value.getEDep()},           {"eDepError", value.getEDepError()},
      {"position", value.getPosition()}, {"covMatrix", value.getCovMatrix()}, {"rawHits", value.getRawHits()}};
}
#endif

} // namespace edm4hep
