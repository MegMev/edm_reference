// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecDqdx_H
#define EDM4HEP_RecDqdx_H

#include "edm4hep/RecDqdxObj.h"

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

class MutableRecDqdx;
class RecDqdxCollection;
class RecDqdxCollectionData;

/** @class RecDqdx
 *  dN/dx or dE/dx info of Track.
 *  @author: EDM4hep authors
 */
class RecDqdx {

  friend class MutableRecDqdx;
  friend class RecDqdxCollection;
  friend class edm4hep::RecDqdxCollectionData;
  friend class RecDqdxCollectionIterator;

public:
  using mutable_type = MutableRecDqdx;
  using collection_type = RecDqdxCollection;

  /// default constructor
  RecDqdx();

  /// Constructor initializing all members
  RecDqdx(edm4hep::Quantity dQdx);

  /// copy constructor
  RecDqdx(const RecDqdx& other) = default;

  /// copy-assignment operator
  RecDqdx& operator=(RecDqdx other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRecDqdx clone(bool cloneRelations = true) const;

  /// destructor
  ~RecDqdx() = default;

  /// converting constructor from mutable object
  RecDqdx(const MutableRecDqdx& other);

  static RecDqdx makeEmpty();

public:
  /// Access the the reconstructed dEdx or dNdx and its error
  const edm4hep::Quantity& getDQdx() const;

  /// Access the the corresponding track
  const edm4hep::Track getTrack() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecDqdxObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RecDqdxObj>{nullptr};
  }

  bool operator==(const RecDqdx& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableRecDqdx& other) const;

  bool operator!=(const RecDqdx& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableRecDqdx& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RecDqdx& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(RecDqdx& a, RecDqdx& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RecDqdxObj
  explicit RecDqdx(podio::utils::MaybeSharedPtr<RecDqdxObj> obj);
  RecDqdx(RecDqdxObj* obj);

  podio::utils::MaybeSharedPtr<RecDqdxObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const RecDqdx& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecDqdx& value);
#endif

} // namespace edm4hep

#endif
