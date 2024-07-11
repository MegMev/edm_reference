// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/ReconstructedParticleObj.h"
#include "edm4hep/Vertex.h"
#include "podio/ObjectID.h"

namespace edm4hep {

ReconstructedParticleObj::ReconstructedParticleObj() :
    id(),
    data(),
    m_startVertex(nullptr),
    m_clusters(new std::vector<edm4hep::Cluster>()),
    m_tracks(new std::vector<edm4hep::Track>()),
    m_particles(new std::vector<edm4hep::ReconstructedParticle>()) {
}

ReconstructedParticleObj::ReconstructedParticleObj(const podio::ObjectID id_, ReconstructedParticleData data_) :
    id(id_), data(data_) {
}

ReconstructedParticleObj::ReconstructedParticleObj(const ReconstructedParticleObj& other) :
    id(),
    data(other.data),
    m_startVertex(nullptr),
    m_clusters(new std::vector<edm4hep::Cluster>(*(other.m_clusters))),
    m_tracks(new std::vector<edm4hep::Track>(*(other.m_tracks))),
    m_particles(new std::vector<edm4hep::ReconstructedParticle>(*(other.m_particles))) {
  if (other.m_startVertex) {
    m_startVertex = new edm4hep::Vertex(*(other.m_startVertex));
  }
}

ReconstructedParticleObj::~ReconstructedParticleObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_clusters;
    delete m_tracks;
    delete m_particles;
  }

  delete m_startVertex;
}
} // namespace edm4hep
