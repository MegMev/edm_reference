// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecIonizationClusterOBJ_H
#define EDM4HEP_RecIonizationClusterOBJ_H

// data model specific includes
#include "edm4hep/RecIonizationClusterData.h"
#include "edm4hep/TrackerPulse.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class RecIonizationCluster;

class RecIonizationClusterObj {
public:
  /// constructor
  RecIonizationClusterObj();
  /// copy constructor (does a deep-copy of relation containers)
  RecIonizationClusterObj(const RecIonizationClusterObj&);
  /// constructor from ObjectID and RecIonizationClusterData
  /// does not initialize the internal relation containers
  RecIonizationClusterObj(const podio::ObjectID id, RecIonizationClusterData data);
  /// No assignment operator
  RecIonizationClusterObj& operator=(const RecIonizationClusterObj&) = delete;
  virtual ~RecIonizationClusterObj();

public:
  podio::ObjectID id;
  RecIonizationClusterData data;
  std::vector<edm4hep::TrackerPulse>* m_trackerPulse{nullptr};
};

} // namespace edm4hep

#endif
