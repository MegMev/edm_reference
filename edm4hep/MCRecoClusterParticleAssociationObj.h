// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoClusterParticleAssociationOBJ_H
#define EDM4HEP_MCRecoClusterParticleAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoClusterParticleAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class Cluster;
class MCParticle;
} // namespace edm4hep

namespace edm4hep {

class MCRecoClusterParticleAssociation;

class MCRecoClusterParticleAssociationObj {
public:
  /// constructor
  MCRecoClusterParticleAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoClusterParticleAssociationObj(const MCRecoClusterParticleAssociationObj&);
  /// constructor from ObjectID and MCRecoClusterParticleAssociationData
  /// does not initialize the internal relation containers
  MCRecoClusterParticleAssociationObj(const podio::ObjectID id, MCRecoClusterParticleAssociationData data);
  /// No assignment operator
  MCRecoClusterParticleAssociationObj& operator=(const MCRecoClusterParticleAssociationObj&) = delete;
  virtual ~MCRecoClusterParticleAssociationObj();

public:
  podio::ObjectID id;
  MCRecoClusterParticleAssociationData data;
  edm4hep::Cluster* m_rec{nullptr};
  edm4hep::MCParticle* m_sim{nullptr};
};

} // namespace edm4hep

#endif
