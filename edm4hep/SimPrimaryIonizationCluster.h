// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimPrimaryIonizationCluster_H
#define EDM4HEP_SimPrimaryIonizationCluster_H

#include "edm4hep/SimPrimaryIonizationClusterObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/RelationRange.h"
#include <cstdint>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class MCParticle;
class MutableMCParticle;
} // namespace edm4hep

namespace edm4hep {

class MutableSimPrimaryIonizationCluster;
class SimPrimaryIonizationClusterCollection;
class SimPrimaryIonizationClusterCollectionData;

/** @class SimPrimaryIonizationCluster
 *  Simulated Primary Ionization
 *  @author: Wenxing Fang, IHEP
 */
class SimPrimaryIonizationCluster {

  friend class MutableSimPrimaryIonizationCluster;
  friend class SimPrimaryIonizationClusterCollection;
  friend class edm4hep::SimPrimaryIonizationClusterCollectionData;
  friend class SimPrimaryIonizationClusterCollectionIterator;

public:
  using mutable_type = MutableSimPrimaryIonizationCluster;
  using collection_type = SimPrimaryIonizationClusterCollection;

  /// default constructor
  SimPrimaryIonizationCluster();

  /// Constructor initializing all members
  SimPrimaryIonizationCluster(std::uint64_t cellID, float time, edm4hep::Vector3d position, std::int16_t type);

  /// copy constructor
  SimPrimaryIonizationCluster(const SimPrimaryIonizationCluster& other) = default;

  /// copy-assignment operator
  SimPrimaryIonizationCluster& operator=(SimPrimaryIonizationCluster other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableSimPrimaryIonizationCluster clone(bool cloneRelations = true) const;

  /// destructor
  ~SimPrimaryIonizationCluster() = default;

  /// converting constructor from mutable object
  SimPrimaryIonizationCluster(const MutableSimPrimaryIonizationCluster& other);

  static SimPrimaryIonizationCluster makeEmpty();

public:
  /// Access the cell id.
  std::uint64_t getCellID() const;

  /// Access the the primary ionization's time in the lab frame [ns].
  float getTime() const;

  /// Access the the primary ionization's position [mm].
  const edm4hep::Vector3d& getPosition() const;

  /// Access the type.
  std::int16_t getType() const;

  /// Access the the particle that caused the ionizing collisions.
  const edm4hep::MCParticle getMCParticle() const;

  std::size_t electronCellID_size() const;
  std::uint64_t getElectronCellID(std::size_t) const;
  std::vector<std::uint64_t>::const_iterator electronCellID_begin() const;
  std::vector<std::uint64_t>::const_iterator electronCellID_end() const;
  podio::RelationRange<std::uint64_t> getElectronCellID() const;
  std::size_t electronTime_size() const;
  float getElectronTime(std::size_t) const;
  std::vector<float>::const_iterator electronTime_begin() const;
  std::vector<float>::const_iterator electronTime_end() const;
  podio::RelationRange<float> getElectronTime() const;
  std::size_t electronPosition_size() const;
  edm4hep::Vector3d getElectronPosition(std::size_t) const;
  std::vector<edm4hep::Vector3d>::const_iterator electronPosition_begin() const;
  std::vector<edm4hep::Vector3d>::const_iterator electronPosition_end() const;
  podio::RelationRange<edm4hep::Vector3d> getElectronPosition() const;
  std::size_t pulseTime_size() const;
  float getPulseTime(std::size_t) const;
  std::vector<float>::const_iterator pulseTime_begin() const;
  std::vector<float>::const_iterator pulseTime_end() const;
  podio::RelationRange<float> getPulseTime() const;
  std::size_t pulseAmplitude_size() const;
  float getPulseAmplitude(std::size_t) const;
  std::vector<float>::const_iterator pulseAmplitude_begin() const;
  std::vector<float>::const_iterator pulseAmplitude_end() const;
  podio::RelationRange<float> getPulseAmplitude() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimPrimaryIonizationClusterObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj>{nullptr};
  }

  bool operator==(const SimPrimaryIonizationCluster& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableSimPrimaryIonizationCluster& other) const;

  bool operator!=(const SimPrimaryIonizationCluster& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableSimPrimaryIonizationCluster& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimPrimaryIonizationCluster& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(SimPrimaryIonizationCluster& a, SimPrimaryIonizationCluster& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing SimPrimaryIonizationClusterObj
  explicit SimPrimaryIonizationCluster(podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj> obj);
  SimPrimaryIonizationCluster(SimPrimaryIonizationClusterObj* obj);

  podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const SimPrimaryIonizationCluster& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimPrimaryIonizationCluster& value);
#endif

} // namespace edm4hep

#endif
