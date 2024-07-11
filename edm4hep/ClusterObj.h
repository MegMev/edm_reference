// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterOBJ_H
#define EDM4HEP_ClusterOBJ_H

// data model specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/ClusterData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class Cluster;

class ClusterObj {
public:
  /// constructor
  ClusterObj();
  /// copy constructor (does a deep-copy of relation containers)
  ClusterObj(const ClusterObj&);
  /// constructor from ObjectID and ClusterData
  /// does not initialize the internal relation containers
  ClusterObj(const podio::ObjectID id, ClusterData data);
  /// No assignment operator
  ClusterObj& operator=(const ClusterObj&) = delete;
  virtual ~ClusterObj();

public:
  podio::ObjectID id;
  ClusterData data;
  std::vector<edm4hep::Cluster>* m_clusters{nullptr};
  std::vector<edm4hep::CalorimeterHit>* m_hits{nullptr};
  std::vector<float>* m_shapeParameters{nullptr};
  std::vector<float>* m_subdetectorEnergies{nullptr};
};

} // namespace edm4hep

#endif
