// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableTPCHit_H
#define EDM4HEP_MutableTPCHit_H

#include "edm4hep/TPCHitObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/TPCHit.h"

#include "podio/ObjectID.h"
#include "podio/RelationRange.h"
#include <cstddef>
#include <cstdint>
#include <ostream>
#include <vector>

#ifdef PODIO_JSON_OUTPUT
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

/** @class MutableTPCHit
 *  Time Projection Chamber Hit
 *  @author: F.Gaede, DESY
 */
class MutableTPCHit {

  friend class TPCHitCollection;
  friend class TPCHitMutableCollectionIterator;
  friend class TPCHit;

public:
  /// default constructor
  MutableTPCHit();
  MutableTPCHit(std::uint64_t cellID, std::int32_t quality, float time, float charge);

  /// constructor from existing TPCHitObj
  MutableTPCHit(TPCHitObj* obj);

  /// copy constructor
  MutableTPCHit(const MutableTPCHit& other);

  /// copy-assignment operator
  MutableTPCHit& operator=(MutableTPCHit other);

  /// create a mutable deep-copy of the object with identical relations
  MutableTPCHit clone() const;

  /// destructor
  ~MutableTPCHit();

  /// conversion to const object
  operator TPCHit() const;

public:
  /// Access the detector specific cell id.
  const std::uint64_t& getCellID() const;

  /// Access the quality flag for the hit.
  const std::int32_t& getQuality() const;

  /// Access the time of the hit.
  const float& getTime() const;

  /// Access the integrated charge of the hit.
  const float& getCharge() const;

  /// Set the detector specific cell id.
  void setCellID(std::uint64_t value);

  /// Set the quality flag for the hit.
  void setQuality(std::int32_t value);

  /// Set the time of the hit.
  void setTime(float value);

  /// Set the integrated charge of the hit.
  void setCharge(float value);

  void addToRawDataWords(std::int32_t);
  std::size_t rawDataWords_size() const;
  std::int32_t getRawDataWords(std::size_t) const;
  std::vector<std::int32_t>::const_iterator rawDataWords_begin() const;
  std::vector<std::int32_t>::const_iterator rawDataWords_end() const;
  podio::RelationRange<std::int32_t> getRawDataWords() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TPCHitObj instance
  void unlink() {
    m_obj = nullptr;
  }

  bool operator==(const MutableTPCHit& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const TPCHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableTPCHit& other) const {
    return m_obj < other.m_obj;
  }

  unsigned int id() const {
    return getObjectID().collectionID * 10000000 + getObjectID().index;
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableTPCHit& a, MutableTPCHit& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  TPCHitObj* m_obj;
};

#ifdef PODIO_JSON_OUTPUT
void to_json(nlohmann::json& j, const MutableTPCHit& value);
#endif

} // namespace edm4hep

#endif
