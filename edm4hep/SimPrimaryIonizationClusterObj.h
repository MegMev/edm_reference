// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimPrimaryIonizationClusterOBJ_H
#define EDM4HEP_SimPrimaryIonizationClusterOBJ_H

// data model specific includes
#include "edm4hep/SimPrimaryIonizationClusterData.h"
#include "edm4hep/Vector3d.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>
// forward declarations
namespace edm4hep {
class MCParticle;
}

namespace edm4hep {

class SimPrimaryIonizationCluster;

class SimPrimaryIonizationClusterObj {
public:
  /// constructor
  SimPrimaryIonizationClusterObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimPrimaryIonizationClusterObj(const SimPrimaryIonizationClusterObj&);
  /// constructor from ObjectID and SimPrimaryIonizationClusterData
  /// does not initialize the internal relation containers
  SimPrimaryIonizationClusterObj(const podio::ObjectID id, SimPrimaryIonizationClusterData data);
  /// No assignment operator
  SimPrimaryIonizationClusterObj& operator=(const SimPrimaryIonizationClusterObj&) = delete;
  virtual ~SimPrimaryIonizationClusterObj();

public:
  podio::ObjectID id;
  SimPrimaryIonizationClusterData data;
  edm4hep::MCParticle* m_MCParticle{nullptr};
  std::vector<std::uint64_t>* m_electronCellID{nullptr};
  std::vector<float>* m_electronTime{nullptr};
  std::vector<edm4hep::Vector3d>* m_electronPosition{nullptr};
  std::vector<float>* m_pulseTime{nullptr};
  std::vector<float>* m_pulseAmplitude{nullptr};
};

} // namespace edm4hep

#endif
