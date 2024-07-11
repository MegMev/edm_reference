// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleIDOBJ_H
#define EDM4HEP_ParticleIDOBJ_H

// data model specific includes
#include "edm4hep/ParticleIDData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>
// forward declarations
namespace edm4hep {
class ReconstructedParticle;
}

namespace edm4hep {

class ParticleID;

class ParticleIDObj {
public:
  /// constructor
  ParticleIDObj();
  /// copy constructor (does a deep-copy of relation containers)
  ParticleIDObj(const ParticleIDObj&);
  /// constructor from ObjectID and ParticleIDData
  /// does not initialize the internal relation containers
  ParticleIDObj(const podio::ObjectID id, ParticleIDData data);
  /// No assignment operator
  ParticleIDObj& operator=(const ParticleIDObj&) = delete;
  virtual ~ParticleIDObj();

public:
  podio::ObjectID id;
  ParticleIDData data;
  edm4hep::ReconstructedParticle* m_particle{nullptr};
  std::vector<float>* m_parameters{nullptr};
};

} // namespace edm4hep

#endif
