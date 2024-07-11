// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitPlaneOBJ_H
#define EDM4HEP_TrackerHitPlaneOBJ_H

// data model specific includes
#include "edm4hep/TrackerHitPlaneData.h"

#include "podio/ObjectID.h"

namespace edm4hep {

class TrackerHitPlane;

class TrackerHitPlaneObj {
public:
  /// constructor
  TrackerHitPlaneObj();
  /// copy constructor (does a deep-copy of relation containers)
  TrackerHitPlaneObj(const TrackerHitPlaneObj&);
  /// constructor from ObjectID and TrackerHitPlaneData
  /// does not initialize the internal relation containers
  TrackerHitPlaneObj(const podio::ObjectID id, TrackerHitPlaneData data);
  /// No assignment operator
  TrackerHitPlaneObj& operator=(const TrackerHitPlaneObj&) = delete;
  virtual ~TrackerHitPlaneObj() = default;

public:
  podio::ObjectID id;
  TrackerHitPlaneData data;
};

} // namespace edm4hep

#endif
