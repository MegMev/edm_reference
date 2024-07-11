// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitPlane_H
#define EDM4HEP_TrackerHitPlane_H

#include "edm4hep/TrackerHitPlaneObj.h"

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector2f.h"
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

class MutableTrackerHitPlane;
class TrackerHitPlaneCollection;
class TrackerHitPlaneCollectionData;

/** @class TrackerHitPlane
 *  Tracker hit plane
 *  @author: EDM4hep authors
 */
class TrackerHitPlane {

  friend class MutableTrackerHitPlane;
  friend class TrackerHitPlaneCollection;
  friend class edm4hep::TrackerHitPlaneCollectionData;
  friend class TrackerHitPlaneCollectionIterator;
  friend class edm4hep::TrackerHit;

public:
  using mutable_type = MutableTrackerHitPlane;
  using collection_type = TrackerHitPlaneCollection;

  /// default constructor
  TrackerHitPlane();

  /// Constructor initializing all members
  TrackerHitPlane(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep,
                  float eDepError, edm4hep::Vector2f u, edm4hep::Vector2f v, float du, float dv,
                  edm4hep::Vector3d position, edm4hep::CovMatrix3f covMatrix);

  /// copy constructor
  TrackerHitPlane(const TrackerHitPlane& other) = default;

  /// copy-assignment operator
  TrackerHitPlane& operator=(TrackerHitPlane other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrackerHitPlane clone(bool cloneRelations = true) const;

  /// destructor
  ~TrackerHitPlane() = default;

  /// converting constructor from mutable object
  TrackerHitPlane(const MutableTrackerHitPlane& other);

  static TrackerHitPlane makeEmpty();

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

  /// Access the measurement direction vector, u lies in the x-y plane
  const edm4hep::Vector2f& getU() const;

  /// Access the measurement direction vector, v is along z
  const edm4hep::Vector2f& getV() const;

  /// Access the measurement error along the direction
  float getDu() const;

  /// Access the measurement error along the direction
  float getDv() const;

  /// Access the hit position [mm]
  const edm4hep::Vector3d& getPosition() const;

  /// Access the covariance of the position (x,y,z)
  const edm4hep::CovMatrix3f& getCovMatrix() const;

  /// Get the position covariance matrix value for the two passed dimensions
  float getCovMatrix(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getCovMatrix().getValue(dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerHitPlaneObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackerHitPlaneObj>{nullptr};
  }

  bool operator==(const TrackerHitPlane& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableTrackerHitPlane& other) const;

  bool operator!=(const TrackerHitPlane& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableTrackerHitPlane& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const TrackerHitPlane& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(TrackerHitPlane& a, TrackerHitPlane& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackerHitPlaneObj
  explicit TrackerHitPlane(podio::utils::MaybeSharedPtr<TrackerHitPlaneObj> obj);
  TrackerHitPlane(TrackerHitPlaneObj* obj);

  podio::utils::MaybeSharedPtr<TrackerHitPlaneObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const TrackerHitPlane& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerHitPlane& value);
#endif

} // namespace edm4hep

#endif
