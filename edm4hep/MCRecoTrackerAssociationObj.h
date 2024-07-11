// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerAssociationOBJ_H
#define EDM4HEP_MCRecoTrackerAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoTrackerAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class TrackerHit;
class SimTrackerHit;
} // namespace edm4hep

namespace edm4hep {

class MCRecoTrackerAssociation;

class MCRecoTrackerAssociationObj {
public:
  /// constructor
  MCRecoTrackerAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoTrackerAssociationObj(const MCRecoTrackerAssociationObj&);
  /// constructor from ObjectID and MCRecoTrackerAssociationData
  /// does not initialize the internal relation containers
  MCRecoTrackerAssociationObj(const podio::ObjectID id, MCRecoTrackerAssociationData data);
  /// No assignment operator
  MCRecoTrackerAssociationObj& operator=(const MCRecoTrackerAssociationObj&) = delete;
  virtual ~MCRecoTrackerAssociationObj();

public:
  podio::ObjectID id;
  MCRecoTrackerAssociationData data;
  edm4hep::TrackerHit* m_rec{nullptr};
  edm4hep::SimTrackerHit* m_sim{nullptr};
};

} // namespace edm4hep

#endif
