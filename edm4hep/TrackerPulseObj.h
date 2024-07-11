// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerPulseOBJ_H
#define EDM4HEP_TrackerPulseOBJ_H

// data model specific includes
#include "edm4hep/TrackerPulseData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class TimeSeries;
}

namespace edm4hep {

class TrackerPulse;

class TrackerPulseObj {
public:
  /// constructor
  TrackerPulseObj();
  /// copy constructor (does a deep-copy of relation containers)
  TrackerPulseObj(const TrackerPulseObj&);
  /// constructor from ObjectID and TrackerPulseData
  /// does not initialize the internal relation containers
  TrackerPulseObj(const podio::ObjectID id, TrackerPulseData data);
  /// No assignment operator
  TrackerPulseObj& operator=(const TrackerPulseObj&) = delete;
  virtual ~TrackerPulseObj();

public:
  podio::ObjectID id;
  TrackerPulseData data;
  edm4hep::TimeSeries* m_timeSeries{nullptr};
};

} // namespace edm4hep

#endif
