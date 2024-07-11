// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit3D_H
#define EDM4HEP_TrackerHit3D_H

#include "edm4hep/TrackerHit3DObj.h"

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector3d.h"
#include <cstdint>
#include <edm4hep/Constants.h>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class TrackerHit;
}

namespace edm4hep {

class MutableTrackerHit3D;
class TrackerHit3DCollection;
class TrackerHit3DCollectionData;

/** @class TrackerHit3D
 *  Tracker hit
 *  @author: EDM4hep authors
 */
class TrackerHit3D {

  friend class MutableTrackerHit3D;
  friend class TrackerHit3DCollection;
  friend class edm4hep::TrackerHit3DCollectionData;
  friend class TrackerHit3DCollectionIterator;
  friend class edm4hep::TrackerHit;

public:
  using mutable_type = MutableTrackerHit3D;
  using collection_type = TrackerHit3DCollection;

  /// default constructor
  TrackerHit3D();

  /// Constructor initializing all members
  TrackerHit3D(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep, float eDepError,
               edm4hep::Vector3d position, edm4hep::CovMatrix3f covMatrix);

  /// copy constructor
  TrackerHit3D(const TrackerHit3D& other) = default;

  /// copy-assignment operator
  TrackerHit3D& operator=(TrackerHit3D other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrackerHit3D clone(bool cloneRelations = true) const;

  /// destructor
  ~TrackerHit3D() = default;

  /// converting constructor from mutable object
  TrackerHit3D(const MutableTrackerHit3D& other);

  static TrackerHit3D makeEmpty();

public:
  /// Access the ID of the sensor that created this hit
  std::uint64_t getCellID() const;

  /// Access the type of raw data hit
  std::int32_t getType() const;

  /// Access the quality bit flag of the hit
  std::int32_t getQuality() const;

  /// Access the time of the hit [ns]
  float getTime() const;

  /// Access the energy deposited on the hit [GeV]
  float getEDep() const;

  /// Access the error measured on EDep [GeV]
  float getEDepError() const;

  /// Access the hit position [mm]
  const edm4hep::Vector3d& getPosition() const;

  /// Access the covariance matrix of the position (x,y,z)
  const edm4hep::CovMatrix3f& getCovMatrix() const;

  /// Get the position covariance matrix value for the two passed dimensions
  float getCovMatrix(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getCovMatrix().getValue(dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerHit3DObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackerHit3DObj>{nullptr};
  }

  bool operator==(const TrackerHit3D& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableTrackerHit3D& other) const;

  bool operator!=(const TrackerHit3D& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableTrackerHit3D& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const TrackerHit3D& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(TrackerHit3D& a, TrackerHit3D& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackerHit3DObj
  explicit TrackerHit3D(podio::utils::MaybeSharedPtr<TrackerHit3DObj> obj);
  TrackerHit3D(TrackerHit3DObj* obj);

  podio::utils::MaybeSharedPtr<TrackerHit3DObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const TrackerHit3D& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerHit3D& value);
#endif

} // namespace edm4hep

#endif
