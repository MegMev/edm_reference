// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticle_H
#define EDM4HEP_MCParticle_H

#include "edm4hep/MCParticleObj.h"

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

class MutableMCParticle;
class MCParticleCollection;
class MCParticleCollectionData;

/** @class MCParticle
 *  The Monte Carlo particle - based on the lcio::MCParticle.
 *  @author: EDM4hep authors
 */
class MCParticle {

  friend class MutableMCParticle;
  friend class MCParticleCollection;
  friend class edm4hep::MCParticleCollectionData;
  friend class MCParticleCollectionIterator;

public:
  using mutable_type = MutableMCParticle;
  using collection_type = MCParticleCollection;

  /// default constructor
  MCParticle();

  /// Constructor initializing all members
  MCParticle(std::int32_t PDG, std::int32_t generatorStatus, std::int32_t simulatorStatus, float charge, float time,
             double mass, edm4hep::Vector3d vertex, edm4hep::Vector3d endpoint, edm4hep::Vector3d momentum,
             edm4hep::Vector3d momentumAtEndpoint, edm4hep::Vector3f spin, edm4hep::Vector2i colorFlow);

  /// copy constructor
  MCParticle(const MCParticle& other) = default;

  /// copy-assignment operator
  MCParticle& operator=(MCParticle other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCParticle clone(bool cloneRelations = true) const;

  /// destructor
  ~MCParticle() = default;

  /// converting constructor from mutable object
  MCParticle(const MutableMCParticle& other);

  static MCParticle makeEmpty();

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

  std::size_t parents_size() const;
  edm4hep::MCParticle getParents(std::size_t) const;
  std::vector<edm4hep::MCParticle>::const_iterator parents_begin() const;
  std::vector<edm4hep::MCParticle>::const_iterator parents_end() const;
  podio::RelationRange<edm4hep::MCParticle> getParents() const;
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

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCParticleObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCParticleObj>{nullptr};
  }

  bool operator==(const MCParticle& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCParticle& other) const;

  bool operator!=(const MCParticle& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCParticle& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCParticle& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCParticle& a, MCParticle& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCParticleObj
  explicit MCParticle(podio::utils::MaybeSharedPtr<MCParticleObj> obj);
  MCParticle(MCParticleObj* obj);

  podio::utils::MaybeSharedPtr<MCParticleObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCParticle& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCParticle& value);
#endif

} // namespace edm4hep

#endif
