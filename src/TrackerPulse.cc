// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTrackerPulse.h"
#include "edm4hep/TrackerPulse.h"
#include "edm4hep/TrackerPulseData.h"
#include "edm4hep/TrackerPulseObj.h"

#include "edm4hep/TimeSeries.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

TrackerPulse::TrackerPulse() : m_obj(new TrackerPulseObj{}, podio::utils::MarkOwned) {
}

TrackerPulse::TrackerPulse(std::uint64_t cellID, float time, float charge, std::int16_t quality,
                           std::array<float, 3> covMatrix) :
    m_obj(new TrackerPulseObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
  m_obj->data.quality = quality;
  m_obj->data.covMatrix = covMatrix;
}

TrackerPulse& TrackerPulse::operator=(TrackerPulse other) {
  swap(*this, other);
  return *this;
}

MutableTrackerPulse TrackerPulse::clone(bool cloneRelations) const {
  auto tmp = new TrackerPulseObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
    if (m_obj->m_timeSeries) {
      tmp->m_timeSeries = new edm4hep::TimeSeries(*m_obj->m_timeSeries);
    }
  } else {
  }
  return MutableTrackerPulse(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

TrackerPulse::TrackerPulse(podio::utils::MaybeSharedPtr<TrackerPulseObj> obj) : m_obj(std::move(obj)) {
}

TrackerPulse::TrackerPulse(const MutableTrackerPulse& other) : TrackerPulse(other.m_obj) {
}

TrackerPulse::TrackerPulse(TrackerPulseObj* obj) : m_obj(podio::utils::MaybeSharedPtr<TrackerPulseObj>(obj)) {
}

TrackerPulse TrackerPulse::makeEmpty() {
  return {nullptr};
}

std::uint64_t TrackerPulse::getCellID() const {
  return m_obj->data.cellID;
}
float TrackerPulse::getTime() const {
  return m_obj->data.time;
}
float TrackerPulse::getCharge() const {
  return m_obj->data.charge;
}
std::int16_t TrackerPulse::getQuality() const {
  return m_obj->data.quality;
}
const std::array<float, 3>& TrackerPulse::getCovMatrix() const {
  return m_obj->data.covMatrix;
}
float TrackerPulse::getCovMatrix(size_t i) const {
  return m_obj->data.covMatrix.at(i);
}

const edm4hep::TimeSeries TrackerPulse::getTimeSeries() const {
  if (!m_obj->m_timeSeries) {
    return edm4hep::TimeSeries::makeEmpty();
  }
  return edm4hep::TimeSeries(*(m_obj->m_timeSeries));
}

bool TrackerPulse::isAvailable() const {
  return m_obj;
}

const podio::ObjectID TrackerPulse::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool TrackerPulse::operator==(const MutableTrackerPulse& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const TrackerPulse& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " charge : " << value.getCharge() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " covMatrix : ";
  for (size_t i = 0; i < 3; ++i) {
    o << value.getCovMatrix()[i] << "|";
  }
  o << '\n';

  o << " timeSeries : " << value.getTimeSeries().id() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerPulse& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"time", value.getTime()},
                     {"charge", value.getCharge()},
                     {"quality", value.getQuality()},
                     {"covMatrix", value.getCovMatrix()}};

  j["timeSeries"] = nlohmann::json{{"collectionID", value.getTimeSeries().getObjectID().collectionID},
                                   {"index", value.getTimeSeries().getObjectID().index}};
}
#endif

} // namespace edm4hep
