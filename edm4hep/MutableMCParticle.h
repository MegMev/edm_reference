// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCParticle_H
#define EDM4HEP_MutableMCParticle_H

#include "edm4hep/MCParticleObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCParticle.h"

#include "edm4hep/Vector2i.h"
#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include "podio/RelationRange.h"
#include <cmath>
#include <cstdint>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class MutableMCParticle
 *  The Monte Carlo particle - based on the lcio::MCParticle.
 *  @author: EDM4hep authors
 */
class MutableMCParticle {

  friend class MCParticleCollection;
  friend class MCParticleMutableCollectionIterator;
  friend class MCParticle;

public:
  using object_type = MCParticle;
  using collection_type = MCParticleCollection;

  /// default constructor
  MutableMCParticle();

  /// Constructor initializing all members
  MutableMCParticle(std::int32_t PDG, std::int32_t generatorStatus, std::int32_t simulatorStatus, float charge,
                    float time, double mass, edm4hep::Vector3d vertex, edm4hep::Vector3d endpoint,
                    edm4hep::Vector3d momentum, edm4hep::Vector3d momentumAtEndpoint, edm4hep::Vector3f spin,
                    edm4hep::Vector2i colorFlow);

  /// copy constructor
  MutableMCParticle(const MutableMCParticle& other) = default;

  /// copy-assignment operator
  MutableMCParticle& operator=(MutableMCParticle other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCParticle clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCParticle() = default;

public:
  /// Access the PDG code of the particle
  std::int32_t getPDG() const;

  /// Access the status of the particle as defined by the generator
  std::int32_t getGeneratorStatus() const;

  /// Access the status of the particle from the simulation program - use BIT constants below
  std::int32_t getSimulatorStatus() const;

  /// Access the particle charge
  float getCharge() const;

  /// Access the creation time of the particle in wrt. the event, e.g. for preassigned decays or decays in flight from
  /// the simulator [ns]
  float getTime() const;

  /// Access the mass of the particle [GeV]
  double getMass() const;

  /// Access the production vertex of the particle [mm]
  const edm4hep::Vector3d& getVertex() const;

  /// Access the endpoint of the particle [mm]
  const edm4hep::Vector3d& getEndpoint() const;

  /// Access the particle 3-momentum at the production vertex [GeV]
  const edm4hep::Vector3d& getMomentum() const;

  /// Access the particle 3-momentum at the endpoint [GeV]
  const edm4hep::Vector3d& getMomentumAtEndpoint() const;

  /// Access the spin (helicity) vector of the particle
  const edm4hep::Vector3f& getSpin() const;

  /// Access the color flow as defined by the generator
  const edm4hep::Vector2i& getColorFlow() const;

  /// Set the PDG code of the particle
  void setPDG(std::int32_t value);
  /// Get mutable reference to PDG code of the particle
  std::int32_t& getPDG();
  /// Get reference to PDG code of the particle
  [[deprecated("use getPDG instead")]] std::int32_t& PDG();

  /// Set the status of the particle as defined by the generator
  void setGeneratorStatus(std::int32_t value);
  /// Get mutable reference to status of the particle as defined by the generator
  std::int32_t& getGeneratorStatus();
  /// Get reference to status of the particle as defined by the generator
  [[deprecated("use getGeneratorStatus instead")]] std::int32_t& generatorStatus();

  /// Set the status of the particle from the simulation program - use BIT constants below
  void setSimulatorStatus(std::int32_t value);
  /// Get mutable reference to status of the particle from the simulation program - use BIT constants below
  std::int32_t& getSimulatorStatus();
  /// Get reference to status of the particle from the simulation program - use BIT constants below
  [[deprecated("use getSimulatorStatus instead")]] std::int32_t& simulatorStatus();

  /// Set the particle charge
  void setCharge(float value);
  /// Get mutable reference to particle charge
  float& getCharge();
  /// Get reference to particle charge
  [[deprecated("use getCharge instead")]] float& charge();

  /// Set the creation time of the particle in wrt. the event, e.g. for preassigned decays or decays in flight from the
  /// simulator [ns]
  void setTime(float value);
  /// Get mutable reference to creation time of the particle in wrt. the event, e.g. for preassigned decays or decays in
  /// flight from the simulator [ns]
  float& getTime();
  /// Get reference to creation time of the particle in wrt. the event, e.g. for preassigned decays or decays in flight
  /// from the simulator [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the mass of the particle [GeV]
  void setMass(double value);
  /// Get mutable reference to mass of the particle [GeV]
  double& getMass();
  /// Get reference to mass of the particle [GeV]
  [[deprecated("use getMass instead")]] double& mass();

  /// Set the production vertex of the particle [mm]
  void setVertex(edm4hep::Vector3d value);
  /// Get mutable reference to production vertex of the particle [mm]
  edm4hep::Vector3d& getVertex();
  /// Get reference to production vertex of the particle [mm]
  [[deprecated("use getVertex instead")]] edm4hep::Vector3d& vertex();

  /// Set the endpoint of the particle [mm]
  void setEndpoint(edm4hep::Vector3d value);
  /// Get mutable reference to endpoint of the particle [mm]
  edm4hep::Vector3d& getEndpoint();
  /// Get reference to endpoint of the particle [mm]
  [[deprecated("use getEndpoint instead")]] edm4hep::Vector3d& endpoint();

  /// Set the particle 3-momentum at the production vertex [GeV]
  void setMomentum(edm4hep::Vector3d value);
  /// Get mutable reference to particle 3-momentum at the production vertex [GeV]
  edm4hep::Vector3d& getMomentum();
  /// Get reference to particle 3-momentum at the production vertex [GeV]
  [[deprecated("use getMomentum instead")]] edm4hep::Vector3d& momentum();

  /// Set the particle 3-momentum at the endpoint [GeV]
  void setMomentumAtEndpoint(edm4hep::Vector3d value);
  /// Get mutable reference to particle 3-momentum at the endpoint [GeV]
  edm4hep::Vector3d& getMomentumAtEndpoint();
  /// Get reference to particle 3-momentum at the endpoint [GeV]
  [[deprecated("use getMomentumAtEndpoint instead")]] edm4hep::Vector3d& momentumAtEndpoint();

  /// Set the spin (helicity) vector of the particle
  void setSpin(edm4hep::Vector3f value);
  /// Get mutable reference to spin (helicity) vector of the particle
  edm4hep::Vector3f& getSpin();
  /// Get reference to spin (helicity) vector of the particle
  [[deprecated("use getSpin instead")]] edm4hep::Vector3f& spin();

  /// Set the color flow as defined by the generator
  void setColorFlow(edm4hep::Vector2i value);
  /// Get mutable reference to color flow as defined by the generator
  edm4hep::Vector2i& getColorFlow();
  /// Get reference to color flow as defined by the generator
  [[deprecated("use getColorFlow instead")]] edm4hep::Vector2i& colorFlow();

  void addToParents(const edm4hep::MCParticle&);
  std::size_t parents_size() const;
  edm4hep::MCParticle getParents(std::size_t) const;
  std::vector<edm4hep::MCParticle>::const_iterator parents_begin() const;
  std::vector<edm4hep::MCParticle>::const_iterator parents_end() const;
  podio::RelationRange<edm4hep::MCParticle> getParents() const;
  void addToDaughters(const edm4hep::MCParticle&);
  std::size_t daughters_size() const;
  edm4hep::MCParticle getDaughters(std::size_t) const;
  std::vector<edm4hep::MCParticle>::const_iterator daughters_begin() const;
  std::vector<edm4hep::MCParticle>::const_iterator daughters_end() const;
  podio::RelationRange<edm4hep::MCParticle> getDaughters() const;

  // define the bit positions for the simulation flag
  static const int BITCreatedInSimulation = 30;
  static const int BITBackscatter = 29;
  static const int BITVertexIsNotEndpointOfParent = 28;
  static const int BITDecayedInTracker = 27;
  static const int BITDecayedInCalorimeter = 26;
  static const int BITLeftDetector = 25;
  static const int BITStopped = 24;
  static const int BITOverlay = 23;
  /// return energy computed from momentum and mass
  double getEnergy() const {
    return sqrt(getMomentum()[0] * getMomentum()[0] + getMomentum()[1] * getMomentum()[1] +
                getMomentum()[2] * getMomentum()[2] + getMass() * getMass());
  }

  /// True if the particle has been created by the simulation program (rather than the generator).
  bool isCreatedInSimulation() const {
    return (getSimulatorStatus() & (0x1 << BITCreatedInSimulation));
  }
  /// True if the particle is the result of a backscatter from a calorimeter shower.
  bool isBackscatter() const {
    return (getSimulatorStatus() & (0x1 << BITBackscatter));
  }
  /// True if the particle's vertex is not the endpoint of the  parent particle.
  bool vertexIsNotEndpointOfParent() const {
    return (getSimulatorStatus() & (0x1 << BITVertexIsNotEndpointOfParent));
  }
  /// True if the particle has interacted in a tracking region.
  bool isDecayedInTracker() const {
    return (getSimulatorStatus() & (0x1 << BITDecayedInTracker));
  }
  /// True if the particle has interacted in a calorimeter region.
  bool isDecayedInCalorimeter() const {
    return (getSimulatorStatus() & (0x1 << BITDecayedInCalorimeter));
  }
  /// True if the particle has left the world volume undecayed.
  bool hasLeftDetector() const {
    return (getSimulatorStatus() & (0x1 << BITLeftDetector));
  }
  /// True if the particle has been stopped by the simulation program.
  bool isStopped() const {
    return (getSimulatorStatus() & (0x1 << BITStopped));
  }
  /// True if the particle has been overlayed by the simulation (or digitization)  program.
  bool isOverlay() const {
    return (getSimulatorStatus() & (0x1 << BITOverlay));
  }

  int32_t set_bit(int32_t val, int num, bool bitval) {
    return (val & ~(1 << num)) | (bitval << num);
  }
  void setCreatedInSimulation(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITCreatedInSimulation, bitval));
  }
  void setBackscatter(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITBackscatter, bitval));
  }
  void setVertexIsNotEndpointOfParent(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITVertexIsNotEndpointOfParent, bitval));
  }
  void setDecayedInTracker(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITDecayedInTracker, bitval));
  }
  void setDecayedInCalorimeter(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITDecayedInCalorimeter, bitval));
  }
  void setHasLeftDetector(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITLeftDetector, bitval));
  }
  void setStopped(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITStopped, bitval));
  }
  void setOverlay(bool bitval) {
    setSimulatorStatus(set_bit(getSimulatorStatus(), BITOverlay, bitval));
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCParticleObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCParticleObj>{nullptr};
  }

  bool operator==(const MutableMCParticle& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCParticle& other) const;

  bool operator!=(const MutableMCParticle& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCParticle& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCParticle& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCParticle& a, MutableMCParticle& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCParticleObj
  explicit MutableMCParticle(podio::utils::MaybeSharedPtr<MCParticleObj> obj);

  podio::utils::MaybeSharedPtr<MCParticleObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCParticle& value);
#endif

} // namespace edm4hep

#endif
