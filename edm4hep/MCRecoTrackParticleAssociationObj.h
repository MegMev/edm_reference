// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackParticleAssociationOBJ_H
#define EDM4HEP_MCRecoTrackParticleAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoTrackParticleAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class Track;
class MCParticle;
} // namespace edm4hep

namespace edm4hep {

class MCRecoTrackParticleAssociation;

class MCRecoTrackParticleAssociationObj {
public:
  /// constructor
  MCRecoTrackParticleAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoTrackParticleAssociationObj(const MCRecoTrackParticleAssociationObj&);
  /// constructor from ObjectID and MCRecoTrackParticleAssociationData
  /// does not initialize the internal relation containers
  MCRecoTrackParticleAssociationObj(const podio::ObjectID id, MCRecoTrackParticleAssociationData data);
  /// No assignment operator
  MCRecoTrackParticleAssociationObj& operator=(const MCRecoTrackParticleAssociationObj&) = delete;
  virtual ~MCRecoTrackParticleAssociationObj();

public:
  podio::ObjectID id;
  MCRecoTrackParticleAssociationData data;
  edm4hep::Track* m_rec{nullptr};
  edm4hep::MCParticle* m_sim{nullptr};
};

} // namespace edm4hep

#endif
