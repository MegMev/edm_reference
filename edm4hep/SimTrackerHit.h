// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHit_H
#define EDM4HEP_SimTrackerHit_H

#include "edm4hep/SimTrackerHitObj.h"

#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include <cmath>
#include <cstdint>
#include <edm4hep/MCParticle.h>

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

class MutableSimTrackerHit;
class SimTrackerHitCollection;
class SimTrackerHitCollectionData;

/** @class SimTrackerHit
 *  Simulated tracker hit
 *  @author: EDM4hep authors
 */
class SimTrackerHit {

  friend class MutableSimTrackerHit;
  friend class SimTrackerHitCollection;
  friend class edm4hep::SimTrackerHitCollectionData;
  friend class SimTrackerHitCollectionIterator;

public:
  using mutable_type = MutableSimTrackerHit;
  using collection_type = SimTrackerHitCollection;

  /// default constructor
  SimTrackerHit();

  /// Constructor initializing all members
  SimTrackerHit(std::uint64_t cellID, float eDep, float time, float pathLength, std::int32_t quality,
                edm4hep::Vector3d position, edm4hep::Vector3f momentum);

  /// copy constructor
  SimTrackerHit(const SimTrackerHit& other) = default;

  /// copy-assignment operator
  SimTrackerHit& operator=(SimTrackerHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableSimTrackerHit clone(bool cloneRelations = true) const;

  /// destructor
  ~SimTrackerHit() = default;

  /// converting constructor from mutable object
  SimTrackerHit(const MutableSimTrackerHit& other);

  static SimTrackerHit makeEmpty();

public:
  /// Access the ID of the sensor that created this hit
  std::uint64_t getCellID() const;

  /// Access the energy deposited in the hit [GeV]
  float getEDep() const;

  /// Access the proper time of the hit in the lab frame [ns]
  float getTime() const;

  /// Access the path length of the particle in the sensitive material that resulted in this hit
  float getPathLength() const;

  /// Access the quality bit flag
  std::int32_t getQuality() const;

  /// Access the the hit position [mm]
  const edm4hep::Vector3d& getPosition() const;

  /// Access the the 3-momentum of the particle at the hits position [GeV]
  const edm4hep::Vector3f& getMomentum() const;

  /// Access the MCParticle that caused the hit
  const edm4hep::MCParticle getParticle() const;

  static const int BITOverlay = 31;
  static const int BITProducedBySecondary = 30;
  bool isOverlay() const {
    return getQuality() & (1 << BITOverlay);
  }
  bool isProducedBySecondary() const {
    return getQuality() & (1 << BITProducedBySecondary);
  }
  double x() const {
    return getPosition()[0];
  }
  double y() const {
    return getPosition()[1];
  }
  double z() const {
    return getPosition()[2];
  }
  double rho() const {
    return sqrt(x() * x() + y() * y());
  }
  [[deprecated("use getParticle instead")]] edm4hep::MCParticle getMCParticle() const {
    return getParticle();
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimTrackerHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<SimTrackerHitObj>{nullptr};
  }

  bool operator==(const SimTrackerHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableSimTrackerHit& other) const;

  bool operator!=(const SimTrackerHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableSimTrackerHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimTrackerHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(SimTrackerHit& a, SimTrackerHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing SimTrackerHitObj
  explicit SimTrackerHit(podio::utils::MaybeSharedPtr<SimTrackerHitObj> obj);
  SimTrackerHit(SimTrackerHitObj* obj);

  podio::utils::MaybeSharedPtr<SimTrackerHitObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const SimTrackerHit& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimTrackerHit& value);
#endif

} // namespace edm4hep

#endif
