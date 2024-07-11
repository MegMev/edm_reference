// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RawTimeSeriesObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

RawTimeSeriesObj::RawTimeSeriesObj() : id(), data(), m_adcCounts(new std::vector<std::int32_t>()) {
}

RawTimeSeriesObj::RawTimeSeriesObj(const podio::ObjectID id_, RawTimeSeriesData data_) : id(id_), data(data_) {
}

RawTimeSeriesObj::RawTimeSeriesObj(const RawTimeSeriesObj& other) :
    id(), data(other.data), m_adcCounts(new std::vector<std::int32_t>(*(other.m_adcCounts))) {
}

RawTimeSeriesObj::~RawTimeSeriesObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_adcCounts;
  }
}
} // namespace edm4hep
