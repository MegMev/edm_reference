// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrack.h"
#include "edm4hep/Track.h"
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableTrack::MutableTrack() : m_obj(new TrackObj{}, podio::utils::MarkOwned) {
}

MutableTrack::MutableTrack(std::int32_t type, float chi2, std::int32_t ndf, float dEdx, float dEdxError,
                           float radiusOfInnermostHit) :
    m_obj(new TrackObj{}, podio::utils::MarkOwned) {
  m_obj->data.type = type;
  m_obj->data.chi2 = chi2;
  m_obj->data.ndf = ndf;
  m_obj->data.dEdx = dEdx;
  m_obj->data.dEdxError = dEdxError;
  m_obj->data.radiusOfInnermostHit = radiusOfInnermostHit;
}

MutableTrack& MutableTrack::operator=(MutableTrack other) {
  swap(*this, other);
  return *this;
}

MutableTrack MutableTrack::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new TrackObj(podio::ObjectID{}, m_obj->data);
    tmp->m_trackerHits = new std::vector<edm4hep::TrackerHit>();
    tmp->data.trackerHits_begin = 0;
    tmp->data.trackerHits_end = 0;
    tmp->m_tracks = new std::vector<edm4hep::Track>();
    tmp->data.tracks_begin = 0;
    tmp->data.tracks_end = 0;
    tmp->m_subdetectorHitNumbers = new std::vector<std::int32_t>();
    tmp->data.subdetectorHitNumbers_begin = 0;
    tmp->data.subdetectorHitNumbers_end = 0;
    tmp->m_trackStates = new std::vector<edm4hep::TrackState>();
    tmp->data.trackStates_begin = 0;
    tmp->data.trackStates_end = 0;
    tmp->m_dxQuantities = new std::vector<edm4hep::Quantity>();
    tmp->data.dxQuantities_begin = 0;
    tmp->data.dxQuantities_end = 0;
    return MutableTrack(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableTrack(podio::utils::MaybeSharedPtr(new TrackObj(*m_obj), podio::utils::MarkOwned));
}

MutableTrack::MutableTrack(podio::utils::MaybeSharedPtr<TrackObj> obj) : m_obj(std::move(obj)) {
}

std::int32_t MutableTrack::getType() const {
  return m_obj->data.type;
}
float MutableTrack::getChi2() const {
  return m_obj->data.chi2;
}
std::int32_t MutableTrack::getNdf() const {
  return m_obj->data.ndf;
}
float MutableTrack::getDEdx() const {
  return m_obj->data.dEdx;
}
float MutableTrack::getDEdxError() const {
  return m_obj->data.dEdxError;
}
float MutableTrack::getRadiusOfInnermostHit() const {
  return m_obj->data.radiusOfInnermostHit;
}

void MutableTrack::setType(std::int32_t value) {
  m_obj->data.type = value;
}
std::int32_t& MutableTrack::getType() {
  return m_obj->data.type;
}
std::int32_t& MutableTrack::type() {
  return m_obj->data.type;
}
void MutableTrack::setChi2(float value) {
  m_obj->data.chi2 = value;
}
float& MutableTrack::getChi2() {
  return m_obj->data.chi2;
}
float& MutableTrack::chi2() {
  return m_obj->data.chi2;
}
void MutableTrack::setNdf(std::int32_t value) {
  m_obj->data.ndf = value;
}
std::int32_t& MutableTrack::getNdf() {
  return m_obj->data.ndf;
}
std::int32_t& MutableTrack::ndf() {
  return m_obj->data.ndf;
}
void MutableTrack::setDEdx(float value) {
  m_obj->data.dEdx = value;
}
float& MutableTrack::getDEdx() {
  return m_obj->data.dEdx;
}
float& MutableTrack::dEdx() {
  return m_obj->data.dEdx;
}
void MutableTrack::setDEdxError(float value) {
  m_obj->data.dEdxError = value;
}
float& MutableTrack::getDEdxError() {
  return m_obj->data.dEdxError;
}
float& MutableTrack::dEdxError() {
  return m_obj->data.dEdxError;
}
void MutableTrack::setRadiusOfInnermostHit(float value) {
  m_obj->data.radiusOfInnermostHit = value;
}
float& MutableTrack::getRadiusOfInnermostHit() {
  return m_obj->data.radiusOfInnermostHit;
}
float& MutableTrack::radiusOfInnermostHit() {
  return m_obj->data.radiusOfInnermostHit;
}

void MutableTrack::addToTrackerHits(const edm4hep::TrackerHit& component) {
  m_obj->m_trackerHits->push_back(component);
  m_obj->data.trackerHits_end++;
}

std::vector<edm4hep::TrackerHit>::const_iterator MutableTrack::trackerHits_begin() const {
  auto ret_value = m_obj->m_trackerHits->begin();
  std::advance(ret_value, m_obj->data.trackerHits_begin);
  return ret_value;
}

std::vector<edm4hep::TrackerHit>::const_iterator MutableTrack::trackerHits_end() const {
  auto ret_value = m_obj->m_trackerHits->begin();
  std::advance(ret_value, m_obj->data.trackerHits_end);
  return ret_value;
}

std::size_t MutableTrack::trackerHits_size() const {
  return m_obj->data.trackerHits_end - m_obj->data.trackerHits_begin;
}

edm4hep::TrackerHit MutableTrack::getTrackerHits(std::size_t index) const {
  if (trackerHits_size() > index) {
    return m_obj->m_trackerHits->at(m_obj->data.trackerHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::TrackerHit> MutableTrack::getTrackerHits() const {
  auto begin = m_obj->m_trackerHits->begin();
  std::advance(begin, m_obj->data.trackerHits_begin);
  auto end = m_obj->m_trackerHits->begin();
  std::advance(end, m_obj->data.trackerHits_end);
  return {begin, end};
}

void MutableTrack::addToTracks(const edm4hep::Track& component) {
  m_obj->m_tracks->push_back(component);
  m_obj->data.tracks_end++;
}

std::vector<edm4hep::Track>::const_iterator MutableTrack::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<edm4hep::Track>::const_iterator MutableTrack::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

std::size_t MutableTrack::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

edm4hep::Track MutableTrack::getTracks(std::size_t index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Track> MutableTrack::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}

void MutableTrack::addToSubdetectorHitNumbers(const std::int32_t& component) {
  m_obj->m_subdetectorHitNumbers->push_back(component);
  m_obj->data.subdetectorHitNumbers_end++;
}

std::vector<std::int32_t>::const_iterator MutableTrack::subdetectorHitNumbers_begin() const {
  auto ret_value = m_obj->m_subdetectorHitNumbers->begin();
  std::advance(ret_value, m_obj->data.subdetectorHitNumbers_begin);
  return ret_value;
}

std::vector<std::int32_t>::const_iterator MutableTrack::subdetectorHitNumbers_end() const {
  auto ret_value = m_obj->m_subdetectorHitNumbers->begin();
  std::advance(ret_value, m_obj->data.subdetectorHitNumbers_end);
  return ret_value;
}

std::size_t MutableTrack::subdetectorHitNumbers_size() const {
  return m_obj->data.subdetectorHitNumbers_end - m_obj->data.subdetectorHitNumbers_begin;
}

std::int32_t MutableTrack::getSubdetectorHitNumbers(std::size_t index) const {
  if (subdetectorHitNumbers_size() > index) {
    return m_obj->m_subdetectorHitNumbers->at(m_obj->data.subdetectorHitNumbers_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::int32_t> MutableTrack::getSubdetectorHitNumbers() const {
  auto begin = m_obj->m_subdetectorHitNumbers->begin();
  std::advance(begin, m_obj->data.subdetectorHitNumbers_begin);
  auto end = m_obj->m_subdetectorHitNumbers->begin();
  std::advance(end, m_obj->data.subdetectorHitNumbers_end);
  return {begin, end};
}

void MutableTrack::addToTrackStates(const edm4hep::TrackState& component) {
  m_obj->m_trackStates->push_back(component);
  m_obj->data.trackStates_end++;
}

std::vector<edm4hep::TrackState>::const_iterator MutableTrack::trackStates_begin() const {
  auto ret_value = m_obj->m_trackStates->begin();
  std::advance(ret_value, m_obj->data.trackStates_begin);
  return ret_value;
}

std::vector<edm4hep::TrackState>::const_iterator MutableTrack::trackStates_end() const {
  auto ret_value = m_obj->m_trackStates->begin();
  std::advance(ret_value, m_obj->data.trackStates_end);
  return ret_value;
}

std::size_t MutableTrack::trackStates_size() const {
  return m_obj->data.trackStates_end - m_obj->data.trackStates_begin;
}

edm4hep::TrackState MutableTrack::getTrackStates(std::size_t index) const {
  if (trackStates_size() > index) {
    return m_obj->m_trackStates->at(m_obj->data.trackStates_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::TrackState> MutableTrack::getTrackStates() const {
  auto begin = m_obj->m_trackStates->begin();
  std::advance(begin, m_obj->data.trackStates_begin);
  auto end = m_obj->m_trackStates->begin();
  std::advance(end, m_obj->data.trackStates_end);
  return {begin, end};
}

void MutableTrack::addToDxQuantities(const edm4hep::Quantity& component) {
  m_obj->m_dxQuantities->push_back(component);
  m_obj->data.dxQuantities_end++;
}

std::vector<edm4hep::Quantity>::const_iterator MutableTrack::dxQuantities_begin() const {
  auto ret_value = m_obj->m_dxQuantities->begin();
  std::advance(ret_value, m_obj->data.dxQuantities_begin);
  return ret_value;
}

std::vector<edm4hep::Quantity>::const_iterator MutableTrack::dxQuantities_end() const {
  auto ret_value = m_obj->m_dxQuantities->begin();
  std::advance(ret_value, m_obj->data.dxQuantities_end);
  return ret_value;
}

std::size_t MutableTrack::dxQuantities_size() const {
  return m_obj->data.dxQuantities_end - m_obj->data.dxQuantities_begin;
}

edm4hep::Quantity MutableTrack::getDxQuantities(std::size_t index) const {
  if (dxQuantities_size() > index) {
    return m_obj->m_dxQuantities->at(m_obj->data.dxQuantities_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::Quantity> MutableTrack::getDxQuantities() const {
  auto begin = m_obj->m_dxQuantities->begin();
  std::advance(begin, m_obj->data.dxQuantities_begin);
  auto end = m_obj->m_dxQuantities->begin();
  std::advance(end, m_obj->data.dxQuantities_end);
  return {begin, end};
}

bool MutableTrack::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableTrack::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableTrack::operator==(const Track& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrack& value) {
  j = nlohmann::json{{"type", value.getType()},
                     {"chi2", value.getChi2()},
                     {"ndf", value.getNdf()},
                     {"dEdx", value.getDEdx()},
                     {"dEdxError", value.getDEdxError()},
                     {"radiusOfInnermostHit", value.getRadiusOfInnermostHit()},
                     {"subdetectorHitNumbers", value.getSubdetectorHitNumbers()},
                     {"trackStates", value.getTrackStates()},
                     {"dxQuantities", value.getDxQuantities()}};

  j["trackerHits"] = nlohmann::json::array();
  for (const auto& v : value.getTrackerHits()) {
    j["trackerHits"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }

  j["tracks"] = nlohmann::json::array();
  for (const auto& v : value.getTracks()) {
    j["tracks"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
