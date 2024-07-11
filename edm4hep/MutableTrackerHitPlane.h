// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableTrackerHitPlane_H
#define EDM4HEP_MutableTrackerHitPlane_H

#include "edm4hep/TrackerHitPlaneObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/TrackerHitPlane.h"

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

/** @class MutableTrackerHitPlane
 *  Tracker hit plane
 *  @author: EDM4hep authors
 */
class MutableTrackerHitPlane {

  friend class TrackerHitPlaneCollection;
  friend class TrackerHitPlaneMutableCollectionIterator;
  friend class TrackerHitPlane;

public:
  using object_type = TrackerHitPlane;
  using collection_type = TrackerHitPlaneCollection;

  /// default constructor
  MutableTrackerHitPlane();

  /// Constructor initializing all members
  MutableTrackerHitPlane(std::uint64_t cellID, std::int32_t type, std::int32_t quality, float time, float eDep,
                         float eDepError, edm4hep::Vector2f u, edm4hep::Vector2f v, float du, float dv,
                         edm4hep::Vector3d position, edm4hep::CovMatrix3f covMatrix);

  /// copy constructor
  MutableTrackerHitPlane(const MutableTrackerHitPlane& other) = default;

  /// copy-assignment operator
  MutableTrackerHitPlane& operator=(MutableTrackerHitPlane other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableTrackerHitPlane clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableTrackerHitPlane() = default;

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

  /// Set the ID of the sensor that created this hit
  void setCellID(std::uint64_t value);
  /// Get mutable reference to ID of the sensor that created this hit
  std::uint64_t& getCellID();
  /// Get reference to ID of the sensor that created this hit
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the type of raw data hit
  void setType(std::int32_t value);
  /// Get mutable reference to type of raw data hit
  std::int32_t& getType();
  /// Get reference to type of raw data hit
  [[deprecated("use getType instead")]] std::int32_t& type();

  /// Set the quality bit flag of the hit
  void setQuality(std::int32_t value);
  /// Get mutable reference to quality bit flag of the hit
  std::int32_t& getQuality();
  /// Get reference to quality bit flag of the hit
  [[deprecated("use getQuality instead")]] std::int32_t& quality();

  /// Set the time of the hit [ns]
  void setTime(float value);
  /// Get mutable reference to time of the hit [ns]
  float& getTime();
  /// Get reference to time of the hit [ns]
  [[deprecated("use getTime instead")]] float& time();

  /// Set the energy deposited on the hit [GeV]
  void setEDep(float value);
  /// Get mutable reference to energy deposited on the hit [GeV]
  float& getEDep();
  /// Get reference to energy deposited on the hit [GeV]
  [[deprecated("use getEDep instead")]] float& eDep();

  /// Set the error measured on EDep [GeV]
  void setEDepError(float value);
  /// Get mutable reference to error measured on EDep [GeV]
  float& getEDepError();
  /// Get reference to error measured on EDep [GeV]
  [[deprecated("use getEDepError instead")]] float& eDepError();

  /// Set the measurement direction vector, u lies in the x-y plane
  void setU(edm4hep::Vector2f value);
  /// Get mutable reference to measurement direction vector, u lies in the x-y plane
  edm4hep::Vector2f& getU();
  /// Get reference to measurement direction vector, u lies in the x-y plane
  [[deprecated("use getU instead")]] edm4hep::Vector2f& u();

  /// Set the measurement direction vector, v is along z
  void setV(edm4hep::Vector2f value);
  /// Get mutable reference to measurement direction vector, v is along z
  edm4hep::Vector2f& getV();
  /// Get reference to measurement direction vector, v is along z
  [[deprecated("use getV instead")]] edm4hep::Vector2f& v();

  /// Set the measurement error along the direction
  void setDu(float value);
  /// Get mutable reference to measurement error along the direction
  float& getDu();
  /// Get reference to measurement error along the direction
  [[deprecated("use getDu instead")]] float& du();

  /// Set the measurement error along the direction
  void setDv(float value);
  /// Get mutable reference to measurement error along the direction
  float& getDv();
  /// Get reference to measurement error along the direction
  [[deprecated("use getDv instead")]] float& dv();

  /// Set the hit position [mm]
  void setPosition(edm4hep::Vector3d value);
  /// Get mutable reference to hit position [mm]
  edm4hep::Vector3d& getPosition();
  /// Get reference to hit position [mm]
  [[deprecated("use getPosition instead")]] edm4hep::Vector3d& position();

  /// Set the covariance of the position (x,y,z)
  void setCovMatrix(edm4hep::CovMatrix3f value);
  /// Get mutable reference to covariance of the position (x,y,z)
  edm4hep::CovMatrix3f& getCovMatrix();
  /// Get reference to covariance of the position (x,y,z)
  [[deprecated("use getCovMatrix instead")]] edm4hep::CovMatrix3f& covMatrix();

  /// Get the position covariance matrix value for the two passed dimensions
  float getCovMatrix(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getCovMatrix().getValue(dimI, dimJ);
  }

  /// Set the position covariance matrix value for the two passed dimensions
  void setCovMatrix(float value, edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) {
    getCovMatrix().setValue(value, dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerHitPlaneObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<TrackerHitPlaneObj>{nullptr};
  }

  bool operator==(const MutableTrackerHitPlane& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const TrackerHitPlane& other) const;

  bool operator!=(const MutableTrackerHitPlane& other) const {
    return !(*this == other);
  }
  bool operator!=(const TrackerHitPlane& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableTrackerHitPlane& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableTrackerHitPlane& a, MutableTrackerHitPlane& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing TrackerHitPlaneObj
  explicit MutableTrackerHitPlane(podio::utils::MaybeSharedPtr<TrackerHitPlaneObj> obj);

  podio::utils::MaybeSharedPtr<TrackerHitPlaneObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableTrackerHitPlane& value);
#endif

} // namespace edm4hep

#endif
