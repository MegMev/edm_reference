// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerHitPlaneAssociation_H
#define EDM4HEP_MCRecoTrackerHitPlaneAssociation_H

#include "edm4hep/MCRecoTrackerHitPlaneAssociationObj.h"

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

class MutableMCRecoTrackerHitPlaneAssociation;
class MCRecoTrackerHitPlaneAssociationCollection;
class MCRecoTrackerHitPlaneAssociationCollectionData;

/** @class MCRecoTrackerHitPlaneAssociation
 *  Association between a TrackerHitPlane and the corresponding simulated TrackerHit
 *  @author: Placido Fernandez Declara
 */
class MCRecoTrackerHitPlaneAssociation {

  friend class MutableMCRecoTrackerHitPlaneAssociation;
  friend class MCRecoTrackerHitPlaneAssociationCollection;
  friend class edm4hep::MCRecoTrackerHitPlaneAssociationCollectionData;
  friend class MCRecoTrackerHitPlaneAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoTrackerHitPlaneAssociation;
  using collection_type = MCRecoTrackerHitPlaneAssociationCollection;

  /// default constructor
  MCRecoTrackerHitPlaneAssociation();

  /// Constructor initializing all members
  MCRecoTrackerHitPlaneAssociation(float weight);

  /// copy constructor
  MCRecoTrackerHitPlaneAssociation(const MCRecoTrackerHitPlaneAssociation& other) = default;

  /// copy-assignment operator
  MCRecoTrackerHitPlaneAssociation& operator=(MCRecoTrackerHitPlaneAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoTrackerHitPlaneAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoTrackerHitPlaneAssociation() = default;

  /// converting constructor from mutable object
  MCRecoTrackerHitPlaneAssociation(const MutableMCRecoTrackerHitPlaneAssociation& other);

  static MCRecoTrackerHitPlaneAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::TrackerHitPlane getRec() const;
  /// Access the reference to the simulated hit
  const edm4hep::SimTrackerHit getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackerHitPlaneAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoTrackerHitPlaneAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoTrackerHitPlaneAssociation& other) const;

  bool operator!=(const MCRecoTrackerHitPlaneAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoTrackerHitPlaneAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoTrackerHitPlaneAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoTrackerHitPlaneAssociation& a, MCRecoTrackerHitPlaneAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoTrackerHitPlaneAssociationObj
  explicit MCRecoTrackerHitPlaneAssociation(podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj> obj);
  MCRecoTrackerHitPlaneAssociation(MCRecoTrackerHitPlaneAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoTrackerHitPlaneAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoTrackerHitPlaneAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoTrackerHitPlaneAssociation& value);
#endif

} // namespace edm4hep

#endif
