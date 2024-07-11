// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHitOBJ_H
#define EDM4HEP_SimTrackerHitOBJ_H

// data model specific includes
#include "edm4hep/SimTrackerHitData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class MCParticle;
}

namespace edm4hep {

class SimTrackerHit;

class SimTrackerHitObj {
public:
  /// constructor
  SimTrackerHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimTrackerHitObj(const SimTrackerHitObj&);
  /// constructor from ObjectID and SimTrackerHitData
  /// does not initialize the internal relation containers
  SimTrackerHitObj(const podio::ObjectID id, SimTrackerHitData data);
  /// No assignment operator
  SimTrackerHitObj& operator=(const SimTrackerHitObj&) = delete;
  virtual ~SimTrackerHitObj();

public:
  podio::ObjectID id;
  SimTrackerHitData data;
  edm4hep::MCParticle* m_particle{nullptr};
};

} // namespace edm4hep

#endif
