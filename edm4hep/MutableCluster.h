// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableCluster_H
#define EDM4HEP_MutableCluster_H

#include "edm4hep/ClusterObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/Cluster.h"

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

/** @class MutableCluster
 *  Calorimeter Hit Cluster
 *  @author: EDM4hep authors
 */
class MutableCluster {

  friend class ClusterCollection;
  friend class ClusterMutableCollectionIterator;
  friend class Cluster;

public:
  using object_type = Cluster;
  using collection_type = ClusterCollection;

  /// default constructor
  MutableCluster();

  /// Constructor initializing all members
  MutableCluster(std::int32_t type, float energy, float energyError, edm4hep::Vector3f position,
                 edm4hep::CovMatrix3f positionError, float iTheta, float phi, edm4hep::Vector3f directionError);

  /// copy constructor
  MutableCluster(const MutableCluster& other) = default;

  /// copy-assignment operator
  MutableCluster& operator=(MutableCluster other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableCluster clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableCluster() = default;

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

  /// Set the flagword that defines the type of cluster
  void setType(std::int32_t value);
  /// Get mutable reference to flagword that defines the type of cluster
  std::int32_t& getType();
  /// Get reference to flagword that defines the type of cluster
  [[deprecated("use getType instead")]] std::int32_t& type();

  /// Set the energy of the cluster [GeV]
  void setEnergy(float value);
  /// Get mutable reference to energy of the cluster [GeV]
  float& getEnergy();
  /// Get reference to energy of the cluster [GeV]
  [[deprecated("use getEnergy instead")]] float& energy();

  /// Set the error on the energy [GeV]
  void setEnergyError(float value);
  /// Get mutable reference to error on the energy [GeV]
  float& getEnergyError();
  /// Get reference to error on the energy [GeV]
  [[deprecated("use getEnergyError instead")]] float& energyError();

  /// Set the position of the cluster [mm]
  void setPosition(edm4hep::Vector3f value);
  /// Get mutable reference to position of the cluster [mm]
  edm4hep::Vector3f& getPosition();
  /// Get reference to position of the cluster [mm]
  [[deprecated("use getPosition instead")]] edm4hep::Vector3f& position();

  /// Set the covariance matrix of the position
  void setPositionError(edm4hep::CovMatrix3f value);
  /// Get mutable reference to covariance matrix of the position
  edm4hep::CovMatrix3f& getPositionError();
  /// Get reference to covariance matrix of the position
  [[deprecated("use getPositionError instead")]] edm4hep::CovMatrix3f& positionError();

  /// Set the intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is seen from
  /// IP
  void setITheta(float value);
  /// Get mutable reference to intrinsic direction of cluster at position  Theta. Not to be confused with direction
  /// cluster is seen from IP
  float& getITheta();
  /// Get reference to intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is
  /// seen from IP
  [[deprecated("use getITheta instead")]] float& iTheta();

  /// Set the intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is seen from
  /// IP
  void setPhi(float value);
  /// Get mutable reference to intrinsic direction of cluster at position - Phi. Not to be confused with direction
  /// cluster is seen from IP
  float& getPhi();
  /// Get reference to intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is
  /// seen from IP
  [[deprecated("use getPhi instead")]] float& phi();

  /// Set the covariance matrix of the direction [mm**2]
  void setDirectionError(edm4hep::Vector3f value);
  /// Get mutable reference to covariance matrix of the direction [mm**2]
  edm4hep::Vector3f& getDirectionError();
  /// Get reference to covariance matrix of the direction [mm**2]
  [[deprecated("use getDirectionError instead")]] edm4hep::Vector3f& directionError();

  void addToClusters(const edm4hep::Cluster&);
  std::size_t clusters_size() const;
  edm4hep::Cluster getClusters(std::size_t) const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_begin() const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_end() const;
  podio::RelationRange<edm4hep::Cluster> getClusters() const;
  void addToHits(const edm4hep::CalorimeterHit&);
  std::size_t hits_size() const;
  edm4hep::CalorimeterHit getHits(std::size_t) const;
  std::vector<edm4hep::CalorimeterHit>::const_iterator hits_begin() const;
  std::vector<edm4hep::CalorimeterHit>::const_iterator hits_end() const;
  podio::RelationRange<edm4hep::CalorimeterHit> getHits() const;
  void addToShapeParameters(const float&);
  std::size_t shapeParameters_size() const;
  float getShapeParameters(std::size_t) const;
  std::vector<float>::const_iterator shapeParameters_begin() const;
  std::vector<float>::const_iterator shapeParameters_end() const;
  podio::RelationRange<float> getShapeParameters() const;
  void addToSubdetectorEnergies(const float&);
  std::size_t subdetectorEnergies_size() const;
  float getSubdetectorEnergies(std::size_t) const;
  std::vector<float>::const_iterator subdetectorEnergies_begin() const;
  std::vector<float>::const_iterator subdetectorEnergies_end() const;
  podio::RelationRange<float> getSubdetectorEnergies() const;

  /// Get the position error value for the two passed dimensions
  float getPositionError(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getPositionError().getValue(dimI, dimJ);
  }

  /// Set the position error value for the two passed dimensions
  void setPositionError(float value, edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) {
    return getPositionError().setValue(value, dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ClusterObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<ClusterObj>{nullptr};
  }

  bool operator==(const MutableCluster& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const Cluster& other) const;

  bool operator!=(const MutableCluster& other) const {
    return !(*this == other);
  }
  bool operator!=(const Cluster& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableCluster& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableCluster& a, MutableCluster& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing ClusterObj
  explicit MutableCluster(podio::utils::MaybeSharedPtr<ClusterObj> obj);

  podio::utils::MaybeSharedPtr<ClusterObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableCluster& value);
#endif

} // namespace edm4hep

#endif
