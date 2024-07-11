// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerHitPlaneAssociationOBJ_H
#define EDM4HEP_MCRecoTrackerHitPlaneAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoTrackerHitPlaneAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class TrackerHitPlane;
class SimTrackerHit;
} // namespace edm4hep

namespace edm4hep {

class MCRecoTrackerHitPlaneAssociation;

class MCRecoTrackerHitPlaneAssociationObj {
public:
  /// constructor
  MCRecoTrackerHitPlaneAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoTrackerHitPlaneAssociationObj(const MCRecoTrackerHitPlaneAssociationObj&);
  /// constructor from ObjectID and MCRecoTrackerHitPlaneAssociationData
  /// does not initialize the internal relation containers
  MCRecoTrackerHitPlaneAssociationObj(const podio::ObjectID id, MCRecoTrackerHitPlaneAssociationData data);
  /// No assignment operator
  MCRecoTrackerHitPlaneAssociationObj& operator=(const MCRecoTrackerHitPlaneAssociationObj&) = delete;
  virtual ~MCRecoTrackerHitPlaneAssociationObj();

public:
  podio::ObjectID id;
  MCRecoTrackerHitPlaneAssociationData data;
  edm4hep::TrackerHitPlane* m_rec{nullptr};
  edm4hep::SimTrackerHit* m_sim{nullptr};
};

} // namespace edm4hep

#endif
