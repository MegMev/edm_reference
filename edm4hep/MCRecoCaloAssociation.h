// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloAssociation_H
#define EDM4HEP_MCRecoCaloAssociation_H

#include "edm4hep/MCRecoCaloAssociationObj.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class CalorimeterHit;
class MutableCalorimeterHit;
class SimCalorimeterHit;
class MutableSimCalorimeterHit;
} // namespace edm4hep

namespace edm4hep {

class MutableMCRecoCaloAssociation;
class MCRecoCaloAssociationCollection;
class MCRecoCaloAssociationCollectionData;

/** @class MCRecoCaloAssociation
 *  Association between a CalorimeterHit and the corresponding SimCalorimeterHit
 *  @author: EDM4hep authors
 */
class MCRecoCaloAssociation {

  friend class MutableMCRecoCaloAssociation;
  friend class MCRecoCaloAssociationCollection;
  friend class edm4hep::MCRecoCaloAssociationCollectionData;
  friend class MCRecoCaloAssociationCollectionIterator;

public:
  using mutable_type = MutableMCRecoCaloAssociation;
  using collection_type = MCRecoCaloAssociationCollection;

  /// default constructor
  MCRecoCaloAssociation();

  /// Constructor initializing all members
  MCRecoCaloAssociation(float weight);

  /// copy constructor
  MCRecoCaloAssociation(const MCRecoCaloAssociation& other) = default;

  /// copy-assignment operator
  MCRecoCaloAssociation& operator=(MCRecoCaloAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoCaloAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MCRecoCaloAssociation() = default;

  /// converting constructor from mutable object
  MCRecoCaloAssociation(const MutableMCRecoCaloAssociation& other);

  static MCRecoCaloAssociation makeEmpty();

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::CalorimeterHit getRec() const;
  /// Access the reference to the simulated hit
  const edm4hep::SimCalorimeterHit getSim() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoCaloAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj>{nullptr};
  }

  bool operator==(const MCRecoCaloAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableMCRecoCaloAssociation& other) const;

  bool operator!=(const MCRecoCaloAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableMCRecoCaloAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoCaloAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MCRecoCaloAssociation& a, MCRecoCaloAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoCaloAssociationObj
  explicit MCRecoCaloAssociation(podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj> obj);
  MCRecoCaloAssociation(MCRecoCaloAssociationObj* obj);

  podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const MCRecoCaloAssociation& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoCaloAssociation& value);
#endif

} // namespace edm4hep

#endif
