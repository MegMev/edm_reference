// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHitOBJ_H
#define EDM4HEP_CalorimeterHitOBJ_H

// data model specific includes
#include "edm4hep/CalorimeterHitData.h"

#include "podio/ObjectID.h"

namespace edm4hep {

class CalorimeterHit;

class CalorimeterHitObj {
public:
  /// constructor
  CalorimeterHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  CalorimeterHitObj(const CalorimeterHitObj&);
  /// constructor from ObjectID and CalorimeterHitData
  /// does not initialize the internal relation containers
  CalorimeterHitObj(const podio::ObjectID id, CalorimeterHitData data);
  /// No assignment operator
  CalorimeterHitObj& operator=(const CalorimeterHitObj&) = delete;
  virtual ~CalorimeterHitObj() = default;

public:
  podio::ObjectID id;
  CalorimeterHitData data;
};

} // namespace edm4hep

#endif
