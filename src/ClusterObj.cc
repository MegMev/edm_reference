// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

ClusterObj::ClusterObj() :
    id(),
    data(),
    m_clusters(new std::vector<edm4hep::Cluster>()),
    m_hits(new std::vector<edm4hep::CalorimeterHit>()),
    m_shapeParameters(new std::vector<float>()),
    m_subdetectorEnergies(new std::vector<float>()) {
}

ClusterObj::ClusterObj(const podio::ObjectID id_, ClusterData data_) : id(id_), data(data_) {
}

ClusterObj::ClusterObj(const ClusterObj& other) :
    id(),
    data(other.data),
    m_clusters(new std::vector<edm4hep::Cluster>(*(other.m_clusters))),
    m_hits(new std::vector<edm4hep::CalorimeterHit>(*(other.m_hits))),
    m_shapeParameters(new std::vector<float>(*(other.m_shapeParameters))),
    m_subdetectorEnergies(new std::vector<float>(*(other.m_subdetectorEnergies))) {
}

ClusterObj::~ClusterObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_clusters;
    delete m_hits;
    delete m_shapeParameters;
    delete m_subdetectorEnergies;
  }
}
} // namespace edm4hep
