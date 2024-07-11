// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticleOBJ_H
#define EDM4HEP_ReconstructedParticleOBJ_H

// data model specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/Track.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>
// forward declarations
namespace edm4hep {
class Vertex;
}

namespace edm4hep {

class ReconstructedParticle;

class ReconstructedParticleObj {
public:
  /// constructor
  ReconstructedParticleObj();
  /// copy constructor (does a deep-copy of relation containers)
  ReconstructedParticleObj(const ReconstructedParticleObj&);
  /// constructor from ObjectID and ReconstructedParticleData
  /// does not initialize the internal relation containers
  ReconstructedParticleObj(const podio::ObjectID id, ReconstructedParticleData data);
  /// No assignment operator
  ReconstructedParticleObj& operator=(const ReconstructedParticleObj&) = delete;
  virtual ~ReconstructedParticleObj();

public:
  podio::ObjectID id;
  ReconstructedParticleData data;
  edm4hep::Vertex* m_startVertex{nullptr};
  std::vector<edm4hep::Cluster>* m_clusters{nullptr};
  std::vector<edm4hep::Track>* m_tracks{nullptr};
  std::vector<edm4hep::ReconstructedParticle>* m_particles{nullptr};
};

} // namespace edm4hep

#endif
