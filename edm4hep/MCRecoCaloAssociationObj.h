// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloAssociationOBJ_H
#define EDM4HEP_MCRecoCaloAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoCaloAssociationData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class CalorimeterHit;
class SimCalorimeterHit;
} // namespace edm4hep

namespace edm4hep {

class MCRecoCaloAssociation;

class MCRecoCaloAssociationObj {
public:
  /// constructor
  MCRecoCaloAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoCaloAssociationObj(const MCRecoCaloAssociationObj&);
  /// constructor from ObjectID and MCRecoCaloAssociationData
  /// does not initialize the internal relation containers
  MCRecoCaloAssociationObj(const podio::ObjectID id, MCRecoCaloAssociationData data);
  /// No assignment operator
  MCRecoCaloAssociationObj& operator=(const MCRecoCaloAssociationObj&) = delete;
  virtual ~MCRecoCaloAssociationObj();

public:
  podio::ObjectID id;
  MCRecoCaloAssociationData data;
  edm4hep::CalorimeterHit* m_rec{nullptr};
  edm4hep::SimCalorimeterHit* m_sim{nullptr};
};

} // namespace edm4hep

#endif
