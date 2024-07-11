// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TimeSeries.h"
#include "edm4hep/TrackerPulseObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

TrackerPulseObj::TrackerPulseObj() : id(), data(), m_timeSeries(nullptr) {
}

TrackerPulseObj::TrackerPulseObj(const podio::ObjectID id_, TrackerPulseData data_) : id(id_), data(data_) {
}

TrackerPulseObj::TrackerPulseObj(const TrackerPulseObj& other) : id(), data(other.data), m_timeSeries(nullptr) {
  if (other.m_timeSeries) {
    m_timeSeries = new edm4hep::TimeSeries(*(other.m_timeSeries));
  }
}

TrackerPulseObj::~TrackerPulseObj() {

  delete m_timeSeries;
}
} // namespace edm4hep
