// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoTrackerAssociation_H
#define EDM4HEP_MutableMCRecoTrackerAssociation_H

#include "edm4hep/MCRecoTrackerAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoTrackerAssociation.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class TrackerHit;
class MutableTrackerHit;
class SimTrackerHit;
class MutableSimTrackerHit;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableMCRecoTrackerAssociation
 *  Association between a TrackerHit and the corresponding SimTrackerHit
 *  @author: EDM4hep authors
 */
class MutableMCRecoTrackerAssociation {

  friend class MCRecoTrackerAssociationCollection;
  friend class MCRecoTrackerAssociationMutableCollectionIterator;
  friend class MCRecoTrackerAssociation;

public:
  using object_type = MCRecoTrackerAssociation;
  using collection_type = MCRecoTrackerAssociationCollection;

  /// default constructor
  MutableMCRecoTrackerAssociation();

  /// Constructor initializing all members
  MutableMCRecoTrackerAssociation(float weight);

  /// copy constructor
  MutableMCRecoTrackerAssociation(const MutableMCRecoTrackerAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoTrackerAssociation& operator=(MutableMCRecoTrackerAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoTrackerAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoTrackerAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::TrackerHit getRec() const;
  /// Access the reference to the simulated hit
  const edm4hep::SimTrackerHit getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the reconstructed hit
  void setRec(const edm4hep::TrackerHit& value);
  /// Set the reference to the simulated hit
  void setSim(const edm4hep::SimTrackerHit& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackerAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoTrackerAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoTrackerAssociation& other) const;

  bool operator!=(const MutableMCRecoTrackerAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoTrackerAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoTrackerAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoTrackerAssociation& a, MutableMCRecoTrackerAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoTrackerAssociationObj
  explicit MutableMCRecoTrackerAssociation(podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoTrackerAssociation& value);
#endif

} // namespace edm4hep

#endif
