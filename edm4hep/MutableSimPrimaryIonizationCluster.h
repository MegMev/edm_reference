// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableSimPrimaryIonizationCluster_H
#define EDM4HEP_MutableSimPrimaryIonizationCluster_H

#include "edm4hep/SimPrimaryIonizationClusterObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/SimPrimaryIonizationCluster.h"

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

/** @class MutableSimPrimaryIonizationCluster
 *  Simulated Primary Ionization
 *  @author: Wenxing Fang, IHEP
 */
class MutableSimPrimaryIonizationCluster {

  friend class SimPrimaryIonizationClusterCollection;
  friend class SimPrimaryIonizationClusterMutableCollectionIterator;
  friend class SimPrimaryIonizationCluster;

public:
  using object_type = SimPrimaryIonizationCluster;
  using collection_type = SimPrimaryIonizationClusterCollection;

  /// default constructor
  MutableSimPrimaryIonizationCluster();

  /// Constructor initializing all members
  MutableSimPrimaryIonizationCluster(std::uint64_t cellID, float time, edm4hep::Vector3d position, std::int16_t type);

  /// copy constructor
  MutableSimPrimaryIonizationCluster(const MutableSimPrimaryIonizationCluster& other) = default;

  /// copy-assignment operator
  MutableSimPrimaryIonizationCluster& operator=(MutableSimPrimaryIonizationCluster other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableSimPrimaryIonizationCluster clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableSimPrimaryIonizationCluster() = default;

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

  /// Set the cell id.
  void setCellID(std::uint64_t value);
  /// Get mutable reference to cell id.
  std::uint64_t& getCellID();
  /// Get reference to cell id.
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the the primary ionization's time in the lab frame [ns].
  void setTime(float value);
  /// Get mutable reference to the primary ionization's time in the lab frame [ns].
  float& getTime();
  /// Get reference to the primary ionization's time in the lab frame [ns].
  [[deprecated("use getTime instead")]] float& time();

  /// Set the the primary ionization's position [mm].
  void setPosition(edm4hep::Vector3d value);
  /// Get mutable reference to the primary ionization's position [mm].
  edm4hep::Vector3d& getPosition();
  /// Get reference to the primary ionization's position [mm].
  [[deprecated("use getPosition instead")]] edm4hep::Vector3d& position();

  /// Set the type.
  void setType(std::int16_t value);
  /// Get mutable reference to type.
  std::int16_t& getType();
  /// Get reference to type.
  [[deprecated("use getType instead")]] std::int16_t& type();

  /// Set the the particle that caused the ionizing collisions.
  void setMCParticle(const edm4hep::MCParticle& value);

  void addToElectronCellID(const std::uint64_t&);
  std::size_t electronCellID_size() const;
  std::uint64_t getElectronCellID(std::size_t) const;
  std::vector<std::uint64_t>::const_iterator electronCellID_begin() const;
  std::vector<std::uint64_t>::const_iterator electronCellID_end() const;
  podio::RelationRange<std::uint64_t> getElectronCellID() const;
  void addToElectronTime(const float&);
  std::size_t electronTime_size() const;
  float getElectronTime(std::size_t) const;
  std::vector<float>::const_iterator electronTime_begin() const;
  std::vector<float>::const_iterator electronTime_end() const;
  podio::RelationRange<float> getElectronTime() const;
  void addToElectronPosition(const edm4hep::Vector3d&);
  std::size_t electronPosition_size() const;
  edm4hep::Vector3d getElectronPosition(std::size_t) const;
  std::vector<edm4hep::Vector3d>::const_iterator electronPosition_begin() const;
  std::vector<edm4hep::Vector3d>::const_iterator electronPosition_end() const;
  podio::RelationRange<edm4hep::Vector3d> getElectronPosition() const;
  void addToPulseTime(const float&);
  std::size_t pulseTime_size() const;
  float getPulseTime(std::size_t) const;
  std::vector<float>::const_iterator pulseTime_begin() const;
  std::vector<float>::const_iterator pulseTime_end() const;
  podio::RelationRange<float> getPulseTime() const;
  void addToPulseAmplitude(const float&);
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

  bool operator==(const MutableSimPrimaryIonizationCluster& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const SimPrimaryIonizationCluster& other) const;

  bool operator!=(const MutableSimPrimaryIonizationCluster& other) const {
    return !(*this == other);
  }
  bool operator!=(const SimPrimaryIonizationCluster& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableSimPrimaryIonizationCluster& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableSimPrimaryIonizationCluster& a, MutableSimPrimaryIonizationCluster& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing SimPrimaryIonizationClusterObj
  explicit MutableSimPrimaryIonizationCluster(podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj> obj);

  podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableSimPrimaryIonizationCluster& value);
#endif

} // namespace edm4hep

#endif
