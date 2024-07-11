// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerAssociation_H
#define EDM4HEP_MCRecoTrackerAssociation_H

#include "edm4hep/MCRecoTrackerAssociationObj.h"

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

class MutableMCRecoTrackerAssociation;
class MCRecoTrackerAssociationCollection;
class MCRecoTrackerAssociationCollectionData;

/** @class MCRecoTrackerAssociation
 *  Association between a TrackerHit and the corresponding SimTrackerHit
 *  @author: EDM4hep authors
 */
class MCRecoTrackerAssociation {

  friend class MutableMCRecoTrackerAssociation;
  friend class MCRecoTrackerAssociationCollection;
  friend class edm4hep::MCRecoTrackerAssociationCollectionData;
  friend class MCRecoTrackerAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoTrackerAssociation;
  using collection_type = MCRecoTrackerAssociationCollection;

  /// default constructor
  MCRecoTrackerAssociation();

  /// Constructor initializing all members
  MCRecoTrackerAssociation(float weight);

  /// copy constructor
  MCRecoTrackerAssociation(const MCRecoTrackerAssociation& other) = default;

  /// copy-assignment operator
  MCRecoTrackerAssociation& operator=(MCRecoTrackerAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoTrackerAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoTrackerAssociation() = default;

  /// converting constructor from mutable object
  MCRecoTrackerAssociation(const MutableMCRecoTrackerAssociation& other);

  static MCRecoTrackerAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::TrackerHit getRec() const;
  /// Access the reference to the simulated hit
  const edm4hep::SimTrackerHit getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackerAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoTrackerAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoTrackerAssociation& other) const;

  bool operator!=(const MCRecoTrackerAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoTrackerAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoTrackerAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoTrackerAssociation& a, MCRecoTrackerAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoTrackerAssociationObj
  explicit MCRecoTrackerAssociation(podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj> obj);
  MCRecoTrackerAssociation(MCRecoTrackerAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoTrackerAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoTrackerAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoTrackerAssociation& value);
#endif

} // namespace edm4hep

#endif
