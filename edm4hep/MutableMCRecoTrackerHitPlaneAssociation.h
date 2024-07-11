// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoTrackerHitPlaneAssociation_H
#define EDM4HEP_MutableMCRecoTrackerHitPlaneAssociation_H

#include "edm4hep/MCRecoTrackerHitPlaneAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoTrackerHitPlaneAssociation.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class TrackerHitPlane;
class MutableTrackerHitPlane;
class SimTrackerHit;
class MutableSimTrackerHit;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableMCRecoTrackerHitPlaneAssociation
 *  Association between a TrackerHitPlane and the corresponding simulated TrackerHit
 *  @author: Placido Fernandez Declara
 */
class MutableMCRecoTrackerHitPlaneAssociation {

  friend class MCRecoTrackerHitPlaneAssociationCollection;
  friend class MCRecoTrackerHitPlaneAssociationMutableCollectionIterator;
  friend class MCRecoTrackerHitPlaneAssociation;

public:
  using object_type = MCRecoTrackerHitPlaneAssociation;
  using collection_type = MCRecoTrackerHitPlaneAssociationCollection;

  /// default constructor
  MutableMCRecoTrackerHitPlaneAssociation();

  /// Constructor initializing all members
  MutableMCRecoTrackerHitPlaneAssociation(float weight);

  /// copy constructor
  MutableMCRecoTrackerHitPlaneAssociation(const MutableMCRecoTrackerHitPlaneAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoTrackerHitPlaneAssociation& operator=(MutableMCRecoTrackerHitPlaneAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoTrackerHitPlaneAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoTrackerHitPlaneAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::TrackerHitPlane getRec() const;
  /// Access the reference to the simulated hit
  const edm4hep::SimTrackerHit getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the reconstructed hit
  void setRec(const edm4hep::TrackerHitPlane& value);
  /// Set the reference to the simulated hit
  void setSim(const edm4hep::SimTrackerHit& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackerHitPlaneAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoTrackerHitPlaneAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoTrackerHitPlaneAssociation& other) const;

  bool operator!=(const MutableMCRecoTrackerHitPlaneAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoTrackerHitPlaneAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoTrackerHitPlaneAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoTrackerHitPlaneAssociation& a, MutableMCRecoTrackerHitPlaneAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoTrackerHitPlaneAssociationObj
  explicit MutableMCRecoTrackerHitPlaneAssociation(
      podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoTrackerHitPlaneAssociation& value);
#endif

} // namespace edm4hep

#endif
