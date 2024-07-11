// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TimeSeriesObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

TimeSeriesObj::TimeSeriesObj() : id(), data(), m_amplitude(new std::vector<float>()) {
}

TimeSeriesObj::TimeSeriesObj(const podio::ObjectID id_, TimeSeriesData data_) : id(id_), data(data_) {
}

TimeSeriesObj::TimeSeriesObj(const TimeSeriesObj& other) :
    id(), data(other.data), m_amplitude(new std::vector<float>(*(other.m_amplitude))) {
}

TimeSeriesObj::~TimeSeriesObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_amplitude;
  }
}
} // namespace edm4hep
