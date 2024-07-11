// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawTimeSeriesOBJ_H
#define EDM4HEP_RawTimeSeriesOBJ_H

// data model specific includes
#include "edm4hep/RawTimeSeriesData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class RawTimeSeries;

class RawTimeSeriesObj {
public:
  /// constructor
  RawTimeSeriesObj();
  /// copy constructor (does a deep-copy of relation containers)
  RawTimeSeriesObj(const RawTimeSeriesObj&);
  /// constructor from ObjectID and RawTimeSeriesData
  /// does not initialize the internal relation containers
  RawTimeSeriesObj(const podio::ObjectID id, RawTimeSeriesData data);
  /// No assignment operator
  RawTimeSeriesObj& operator=(const RawTimeSeriesObj&) = delete;
  virtual ~RawTimeSeriesObj();

public:
  podio::ObjectID id;
  RawTimeSeriesData data;
  std::vector<std::int32_t>* m_adcCounts{nullptr};
};

} // namespace edm4hep

#endif
