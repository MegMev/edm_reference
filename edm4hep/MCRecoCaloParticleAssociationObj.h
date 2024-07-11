// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloParticleAssociationOBJ_H
#define EDM4HEP_MCRecoCaloParticleAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoCaloParticleAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class CalorimeterHit;
class MCParticle;
} // namespace edm4hep

namespace edm4hep {

class MCRecoCaloParticleAssociation;

class MCRecoCaloParticleAssociationObj {
public:
  /// constructor
  MCRecoCaloParticleAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoCaloParticleAssociationObj(const MCRecoCaloParticleAssociationObj&);
  /// constructor from ObjectID and MCRecoCaloParticleAssociationData
  /// does not initialize the internal relation containers
  MCRecoCaloParticleAssociationObj(const podio::ObjectID id, MCRecoCaloParticleAssociationData data);
  /// No assignment operator
  MCRecoCaloParticleAssociationObj& operator=(const MCRecoCaloParticleAssociationObj&) = delete;
  virtual ~MCRecoCaloParticleAssociationObj();

public:
  podio::ObjectID id;
  MCRecoCaloParticleAssociationData data;
  edm4hep::CalorimeterHit* m_rec{nullptr};
  edm4hep::MCParticle* m_sim{nullptr};
};

} // namespace edm4hep

#endif
