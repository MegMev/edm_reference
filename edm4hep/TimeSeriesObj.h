// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TimeSeriesOBJ_H
#define EDM4HEP_TimeSeriesOBJ_H

// data model specific includes
#include "edm4hep/TimeSeriesData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class TimeSeries;

class TimeSeriesObj {
public:
  /// constructor
  TimeSeriesObj();
  /// copy constructor (does a deep-copy of relation containers)
  TimeSeriesObj(const TimeSeriesObj&);
  /// constructor from ObjectID and TimeSeriesData
  /// does not initialize the internal relation containers
  TimeSeriesObj(const podio::ObjectID id, TimeSeriesData data);
  /// No assignment operator
  TimeSeriesObj& operator=(const TimeSeriesObj&) = delete;
  virtual ~TimeSeriesObj();

public:
  podio::ObjectID id;
  TimeSeriesData data;
  std::vector<float>* m_amplitude{nullptr};
};

} // namespace edm4hep

#endif
