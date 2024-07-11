// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerHit.h"
#include "edm4hep/TrackerHit.h"
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/TrackerHitObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

TrackerHit::TrackerHit() : m_obj(new TrackerHitObj{}, podio::utils::MarkOwned) {
}

TrackerHit::TrackerHit(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep,
                       float eDepError, edm4hep::Vector3d position, std::array<float, 6> covMatrix) :
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

TrackerHit& TrackerHit::operator=(TrackerHit other) {
  swap(*this, other);
  return *this;
}

MutableTrackerHit TrackerHit::clone(bool cloneRelations) const {
  auto tmp = new TrackerHitObj(podio::ObjectID{}, m_obj->data);
  tmp->m_rawHits = new std::vector<edm4hep::ObjectID>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_rawHits->reserve(m_obj->m_rawHits->size());
    for (size_t i = m_obj->data.rawHits_begin; i < m_obj->data.rawHits_end; i++) {
      tmp->m_rawHits->emplace_back((*m_obj->m_rawHits)[i]);
    }
    tmp->data.rawHits_begin = 0;
    tmp->data.rawHits_end = tmp->m_rawHits->size();
  } else {
    tmp->data.rawHits_begin = 0;
    tmp->data.rawHits_end = 0;
  }
  return MutableTrackerHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

TrackerHit::TrackerHit(podio::utils::MaybeSharedPtr<TrackerHitObj> obj) : m_obj(std::move(obj)) {
}

TrackerHit::TrackerHit(const MutableTrackerHit& other) : TrackerHit(other.m_obj) {
}

TrackerHit::TrackerHit(TrackerHitObj* obj) : m_obj(podio::utils::MaybeSharedPtr<TrackerHitObj>(obj)) {
}

TrackerHit TrackerHit::makeEmpty() {
  return {nullptr};
}

std::uint64_t TrackerHit::getCellID() const {
  return m_obj->data.cellID;
}
std::int32_t TrackerHit::getType() const {
  return m_obj->data.type;
}
std::int32_t TrackerHit::getQuality() const {
  return m_obj->data.quality;
}
float TrackerHit::getTime() const {
  return m_obj->data.time;
}
float TrackerHit::getEDep() const {
  return m_obj->data.eDep;
}
float TrackerHit::getEDepError() const {
  return m_obj->data.eDepError;
}
const edm4hep::Vector3d& TrackerHit::getPosition() const {
  return m_obj->data.position;
}
const std::array<float, 6>& TrackerHit::getCovMatrix() const {
  return m_obj->data.covMatrix;
}
float TrackerHit::getCovMatrix(size_t i) const {
  return m_obj->data.covMatrix.at(i);
}

std::vector<edm4hep::ObjectID>::const_iterator TrackerHit::rawHits_begin() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_begin);
  return ret_value;
}

std::vector<edm4hep::ObjectID>::const_iterator TrackerHit::rawHits_end() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_end);
  return ret_value;
}

std::size_t TrackerHit::rawHits_size() const {
  return m_obj->data.rawHits_end - m_obj->data.rawHits_begin;
}

edm4hep::ObjectID TrackerHit::getRawHits(std::size_t index) const {
  if (rawHits_size() > index) {
    return m_obj->m_rawHits->at(m_obj->data.rawHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::ObjectID> TrackerHit::getRawHits() const {
  auto begin = m_obj->m_rawHits->begin();
  std::advance(begin, m_obj->data.rawHits_begin);
  auto end = m_obj->m_rawHits->begin();
  std::advance(end, m_obj->data.rawHits_end);
  return {begin, end};
}

bool TrackerHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID TrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool TrackerHit::operator==(const MutableTrackerHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const TrackerHit& value) {
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
  o << " covMatrix : ";
  for (size_t i = 0; i < 6; ++i) {
    o << value.getCovMatrix()[i] << "|";
  }
  o << '\n';

  o << " rawHits : ";
  for (unsigned i = 0; i < value.rawHits_size(); ++i) {
    o << value.getRawHits(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerHit& value) {
  j = nlohmann::json{
      {"cellID", value.getCellID()},     {"type", value.getType()},           {"quality", value.getQuality()},
      {"time", value.getTime()},         {"eDep", value.getEDep()},           {"eDepError", value.getEDepError()},
      {"position", value.getPosition()}, {"covMatrix", value.getCovMatrix()}, {"rawHits", value.getRawHits()}};
}
#endif

} // namespace edm4hep
