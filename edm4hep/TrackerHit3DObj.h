// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit3DOBJ_H
#define EDM4HEP_TrackerHit3DOBJ_H

// data model specific includes
#include "edm4hep/TrackerHit3DData.h"

#include "podio/ObjectID.h"

namespace edm4hep {

class TrackerHit3D;

class TrackerHit3DObj {
public:
  /// constructor
  TrackerHit3DObj();
  /// copy constructor (does a deep-copy of relation containers)
  TrackerHit3DObj(const TrackerHit3DObj&);
  /// constructor from ObjectID and TrackerHit3DData
  /// does not initialize the internal relation containers
  TrackerHit3DObj(const podio::ObjectID id, TrackerHit3DData data);
  /// No assignment operator
  TrackerHit3DObj& operator=(const TrackerHit3DObj&) = delete;
  virtual ~TrackerHit3DObj() = default;

public:
  podio::ObjectID id;
  TrackerHit3DData data;
};

} // namespace edm4hep

#endif
