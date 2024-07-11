// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticleOBJ_H
#define EDM4HEP_MCParticleOBJ_H

// data model specific includes
#include "edm4hep/MCParticleData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class MCParticle;

class MCParticleObj {
public:
  /// constructor
  MCParticleObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCParticleObj(const MCParticleObj&);
  /// constructor from ObjectID and MCParticleData
  /// does not initialize the internal relation containers
  MCParticleObj(const podio::ObjectID id, MCParticleData data);
  /// No assignment operator
  MCParticleObj& operator=(const MCParticleObj&) = delete;
  virtual ~MCParticleObj();

public:
  podio::ObjectID id;
  MCParticleData data;
  std::vector<edm4hep::MCParticle>* m_parents{nullptr};
  std::vector<edm4hep::MCParticle>* m_daughters{nullptr};
};

} // namespace edm4hep

#endif
