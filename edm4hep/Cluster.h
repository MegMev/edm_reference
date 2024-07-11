// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Cluster_H
#define EDM4HEP_Cluster_H

#include "edm4hep/ClusterObj.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector3f.h"
#include "podio/RelationRange.h"
#include <cstdint>
#include <edm4hep/Constants.h>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableCluster;
class ClusterCollection;
class ClusterCollectionData;

/** @class Cluster
 *  Calorimeter Hit Cluster
 *  @author: EDM4hep authors
 */
class Cluster {

  friend class MutableCluster;
  friend class ClusterCollection;
  friend class edm4hep::ClusterCollectionData;
  friend class ClusterCollectionIterator;

public:
  using mutable_type = MutableCluster;
  using collection_type = ClusterCollection;

  /// default constructor
  Cluster();

  /// Constructor initializing all members
  Cluster(std::int32_t type, float energy, float energyError, edm4hep::Vector3f position,
          edm4hep::CovMatrix3f positionError, float iTheta, float phi, edm4hep::Vector3f directionError);

  /// copy constructor
  Cluster(const Cluster& other) = default;

  /// copy-assignment operator
  Cluster& operator=(Cluster other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableCluster clone(bool cloneRelations = true) const;

  /// destructor
  ~Cluster() = default;

  /// converting constructor from mutable object
  Cluster(const MutableCluster& other);

  static Cluster makeEmpty();

public:
  /// Access the flagword that defines the type of cluster
  std::int32_t getType() const;

  /// Access the energy of the cluster [GeV]
  float getEnergy() const;

  /// Access the error on the energy [GeV]
  float getEnergyError() const;

  /// Access the position of the cluster [mm]
  const edm4hep::Vector3f& getPosition() const;

  /// Access the covariance matrix of the position
  const edm4hep::CovMatrix3f& getPositionError() const;

  /// Access the intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is seen
  /// from IP
  float getITheta() const;

  /// Access the intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is seen
  /// from IP
  float getPhi() const;

  /// Access the covariance matrix of the direction [mm**2]
  const edm4hep::Vector3f& getDirectionError() const;

  std::size_t clusters_size() const;
  edm4hep::Cluster getClusters(std::size_t) const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_begin() const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_end() const;
  podio::RelationRange<edm4hep::Cluster> getClusters() const;
  std::size_t hits_size() const;
  edm4hep::CalorimeterHit getHits(std::size_t) const;
  std::vector<edm4hep::CalorimeterHit>::const_iterator hits_begin() const;
  std::vector<edm4hep::CalorimeterHit>::const_iterator hits_end() const;
  podio::RelationRange<edm4hep::CalorimeterHit> getHits() const;
  std::size_t shapeParameters_size() const;
  float getShapeParameters(std::size_t) const;
  std::vector<float>::const_iterator shapeParameters_begin() const;
  std::vector<float>::const_iterator shapeParameters_end() const;
  podio::RelationRange<float> getShapeParameters() const;
  std::size_t subdetectorEnergies_size() const;
  float getSubdetectorEnergies(std::size_t) const;
  std::vector<float>::const_iterator subdetectorEnergies_begin() const;
  std::vector<float>::const_iterator subdetectorEnergies_end() const;
  podio::RelationRange<float> getSubdetectorEnergies() const;

  /// Get the position error value for the two passed dimensions
  float getPositionError(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getPositionError().getValue(dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ClusterObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<ClusterObj>{nullptr};
  }

  bool operator==(const Cluster& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableCluster& other) const;

  bool operator!=(const Cluster& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableCluster& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const Cluster& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(Cluster& a, Cluster& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing ClusterObj
  explicit Cluster(podio::utils::MaybeSharedPtr<ClusterObj> obj);
  Cluster(ClusterObj* obj);

  podio::utils::MaybeSharedPtr<ClusterObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const Cluster& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Cluster& value);
#endif

} // namespace edm4hep

#endif
