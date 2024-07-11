// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableMCRecoCaloAssociation_H
#define EDM4HEP_MutableMCRecoCaloAssociation_H

#include "edm4hep/MCRecoCaloAssociationObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/MCRecoCaloAssociation.h"

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

/** @class MutableMCRecoCaloAssociation
 *  Association between a CalorimeterHit and the corresponding SimCalorimeterHit
 *  @author: EDM4hep authors
 */
class MutableMCRecoCaloAssociation {

  friend class MCRecoCaloAssociationCollection;
  friend class MCRecoCaloAssociationMutableCollectionIterator;
  friend class MCRecoCaloAssociation;

public:
  using object_type = MCRecoCaloAssociation;
  using collection_type = MCRecoCaloAssociationCollection;

  /// default constructor
  MutableMCRecoCaloAssociation();

  /// Constructor initializing all members
  MutableMCRecoCaloAssociation(float weight);

  /// copy constructor
  MutableMCRecoCaloAssociation(const MutableMCRecoCaloAssociation& other) = default;

  /// copy-assignment operator
  MutableMCRecoCaloAssociation& operator=(MutableMCRecoCaloAssociation other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableMCRecoCaloAssociation clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableMCRecoCaloAssociation() = default;

public:
  /// Access the weight of this association
  float getWeight() const;

  /// Access the reference to the reconstructed hit
  const edm4hep::CalorimeterHit getRec() const;
  /// Access the reference to the simulated hit
  const edm4hep::SimCalorimeterHit getSim() const;

  /// Set the weight of this association
  void setWeight(float value);
  /// Get mutable reference to weight of this association
  float& getWeight();
  /// Get reference to weight of this association
  [[deprecated("use getWeight instead")]] float& weight();

  /// Set the reference to the reconstructed hit
  void setRec(const edm4hep::CalorimeterHit& value);
  /// Set the reference to the simulated hit
  void setSim(const edm4hep::SimCalorimeterHit& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoCaloAssociationObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj>{nullptr};
  }

  bool operator==(const MutableMCRecoCaloAssociation& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MCRecoCaloAssociation& other) const;

  bool operator!=(const MutableMCRecoCaloAssociation& other) const {
    return !(*this == other);
  }
  bool operator!=(const MCRecoCaloAssociation& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableMCRecoCaloAssociation& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableMCRecoCaloAssociation& a, MutableMCRecoCaloAssociation& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing MCRecoCaloAssociationObj
  explicit MutableMCRecoCaloAssociation(podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj> obj);

  podio::utils::MaybeSharedPtr<MCRecoCaloAssociationObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableMCRecoCaloAssociation& value);
#endif

} // namespace edm4hep

#endif
