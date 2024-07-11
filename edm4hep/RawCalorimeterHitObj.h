// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawCalorimeterHitOBJ_H
#define EDM4HEP_RawCalorimeterHitOBJ_H

// data model specific includes
#include "edm4hep/RawCalorimeterHitData.h"

#include "podio/ObjectID.h"

namespace edm4hep {

class RawCalorimeterHit;

class RawCalorimeterHitObj {
public:
  /// constructor
  RawCalorimeterHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  RawCalorimeterHitObj(const RawCalorimeterHitObj&);
  /// constructor from ObjectID and RawCalorimeterHitData
  /// does not initialize the internal relation containers
  RawCalorimeterHitObj(const podio::ObjectID id, RawCalorimeterHitData data);
  /// No assignment operator
  RawCalorimeterHitObj& operator=(const RawCalorimeterHitObj&) = delete;
  virtual ~RawCalorimeterHitObj() = default;

public:
  podio::ObjectID id;
  RawCalorimeterHitData data;
};

} // namespace edm4hep

#endif
