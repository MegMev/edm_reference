// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableRecDqdx_H
#define EDM4HEP_MutableRecDqdx_H

#include "edm4hep/RecDqdxObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/RecDqdx.h"

#include "edm4hep/Quantity.h"

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class Track;
class MutableTrack;
} // namespace edm4hep

namespace edm4hep {

/** @class MutableRecDqdx
 *  dN/dx or dE/dx info of Track.
 *  @author: EDM4hep authors
 */
class MutableRecDqdx {

  friend class RecDqdxCollection;
  friend class RecDqdxMutableCollectionIterator;
  friend class RecDqdx;

public:
  using object_type = RecDqdx;
  using collection_type = RecDqdxCollection;

  /// default constructor
  MutableRecDqdx();

  /// Constructor initializing all members
  MutableRecDqdx(edm4hep::Quantity dQdx);

  /// copy constructor
  MutableRecDqdx(const MutableRecDqdx& other) = default;

  /// copy-assignment operator
  MutableRecDqdx& operator=(MutableRecDqdx other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRecDqdx clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableRecDqdx() = default;

public:
  /// Access the the reconstructed dEdx or dNdx and its error
  const edm4hep::Quantity& getDQdx() const;

  /// Access the the corresponding track
  const edm4hep::Track getTrack() const;

  /// Set the the reconstructed dEdx or dNdx and its error
  void setDQdx(edm4hep::Quantity value);
  /// Get mutable reference to the reconstructed dEdx or dNdx and its error
  edm4hep::Quantity& getDQdx();
  /// Get reference to the reconstructed dEdx or dNdx and its error
  [[deprecated("use getDQdx instead")]] edm4hep::Quantity& dQdx();

  /// Set the the corresponding track
  void setTrack(const edm4hep::Track& value);

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecDqdxObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RecDqdxObj>{nullptr};
  }

  bool operator==(const MutableRecDqdx& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const RecDqdx& other) const;

  bool operator!=(const MutableRecDqdx& other) const {
    return !(*this == other);
  }
  bool operator!=(const RecDqdx& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableRecDqdx& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableRecDqdx& a, MutableRecDqdx& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RecDqdxObj
  explicit MutableRecDqdx(podio::utils::MaybeSharedPtr<RecDqdxObj> obj);

  podio::utils::MaybeSharedPtr<RecDqdxObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRecDqdx& value);
#endif

} // namespace edm4hep

#endif
