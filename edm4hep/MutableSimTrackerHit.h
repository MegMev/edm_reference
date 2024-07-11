// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableSimTrackerHit_H
#define EDM4HEP_MutableSimTrackerHit_H

#include "edm4hep/SimTrackerHitObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/SimTrackerHit.h"

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

/** @class MutableSimTrackerHit
 *  Simulated tracker hit
 *  @author: EDM4hep authors
 */
class MutableSimTrackerHit {

  friend class SimTrackerHitCollection;
  friend class SimTrackerHitMutableCollectionIterator;
  friend class SimTrackerHit;

public:
  using object_type = SimTrackerHit;
  using collection_type = SimTrackerHitCollection;

  /// default constructor
  MutableSimTrackerHit();

  /// Constructor initializing all members
  MutableSimTrackerHit(std::uint64_t cellID, float eDep, float time, float pathLength, std::int32_t quality,
                       edm4hep::Vector3d position, edm4hep::Vector3f momentum);

  /// copy constructor
  MutableSimTrackerHit(const MutableSimTrackerHit& other) = default;

  /// copy-assignment operator
  MutableSimTrackerHit& operator=(MutableSimTrackerHit other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableSimTrackerHit clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableSimTrackerHit() = default;

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

  /// Set the ID of the sensor that created this hit
  void setCellID(std::uint64_t value);
  /// Get mutable reference to ID of the sensor that created this hit
  std::uint64_t& getCellID();
  /// Get reference to ID of the sensor that created this hit
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the energy deposited in the hit [GeV]
  void setEDep(float value);
  /// Get mutable reference to energy deposited in the hit [GeV]
  float& getEDep();
  /// Get reference to energy deposited in the hit [GeV]
  [[deprecated("use getEDep instead")]] float& eDep();

  /// Set the proper time of the hit in the lab frame [ns]
  void setTime(float value);
  /// Get mutable reference to proper time of the hit in the lab frame [ns]
  float& getTime();
  /// Get reference to proper time of the hit in the lab frame [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the path length of the particle in the sensitive material that resulted in this hit
  void setPathLength(float value);
  /// Get mutable reference to path length of the particle in the sensitive material that resulted in this hit
  float& getPathLength();
  /// Get reference to path length of the particle in the sensitive material that resulted in this hit
  [[deprecated("use getPathLength instead")]] float& pathLength();

  /// Set the quality bit flag
  void setQuality(std::int32_t value);
  /// Get mutable reference to quality bit flag
  std::int32_t& getQuality();
  /// Get reference to quality bit flag
  [[deprecated("use getQuality instead")]] std::int32_t& quality();

  /// Set the the hit position [mm]
  void setPosition(edm4hep::Vector3d value);
  /// Get mutable reference to the hit position [mm]
  edm4hep::Vector3d& getPosition();
  /// Get reference to the hit position [mm]
  [[deprecated("use getPosition instead")]] edm4hep::Vector3d& position();

  /// Set the the 3-momentum of the particle at the hits position [GeV]
  void setMomentum(edm4hep::Vector3f value);
  /// Get mutable reference to the 3-momentum of the particle at the hits position [GeV]
  edm4hep::Vector3f& getMomentum();
  /// Get reference to the 3-momentum of the particle at the hits position [GeV]
  [[deprecated("use getMomentum instead")]] edm4hep::Vector3f& momentum();

  /// Set the MCParticle that caused the hit
  void setParticle(const edm4hep::MCParticle& value);

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

  int32_t set_bit(int32_t val, int num, bool bitval) {
    return (val & ~(1 << num)) | (bitval << num);
  }
  void setOverlay(bool val) {
    setQuality(set_bit(getQuality(), BITOverlay, val));
  }
  void setProducedBySecondary(bool val) {
    setQuality(set_bit(getQuality(), BITProducedBySecondary, val));
  }
  [[deprecated("use setParticle instead")]] void setMCParticle(edm4hep::MCParticle particle) {
    setParticle(std::move(particle));
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimTrackerHitObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<SimTrackerHitObj>{nullptr};
  }

  bool operator==(const MutableSimTrackerHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const SimTrackerHit& other) const;

  bool operator!=(const MutableSimTrackerHit& other) const {
    return !(*this == other);
  }
  bool operator!=(const SimTrackerHit& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableSimTrackerHit& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableSimTrackerHit& a, MutableSimTrackerHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing SimTrackerHitObj
  explicit MutableSimTrackerHit(podio::utils::MaybeSharedPtr<SimTrackerHitObj> obj);

  podio::utils::MaybeSharedPtr<SimTrackerHitObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableSimTrackerHit& value);
#endif

} // namespace edm4hep

#endif
