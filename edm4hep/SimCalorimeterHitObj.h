// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHitOBJ_H
#define EDM4HEP_SimCalorimeterHitOBJ_H

// data model specific includes
#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/SimCalorimeterHitData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class SimCalorimeterHit;

class SimCalorimeterHitObj {
public:
  /// constructor
  SimCalorimeterHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimCalorimeterHitObj(const SimCalorimeterHitObj&);
  /// constructor from ObjectID and SimCalorimeterHitData
  /// does not initialize the internal relation containers
  SimCalorimeterHitObj(const podio::ObjectID id, SimCalorimeterHitData data);
  /// No assignment operator
  SimCalorimeterHitObj& operator=(const SimCalorimeterHitObj&) = delete;
  virtual ~SimCalorimeterHitObj();

public:
  podio::ObjectID id;
  SimCalorimeterHitData data;
  std::vector<edm4hep::CaloHitContribution>* m_contributions{nullptr};
};

} // namespace edm4hep

#endif
