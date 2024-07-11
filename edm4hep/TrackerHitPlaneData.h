// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitPlaneDATA_H
#define EDM4HEP_TrackerHitPlaneDATA_H

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector2f.h"
#include "edm4hep/Vector3d.h"
#include <cstdint>

namespace edm4hep {

/** @class TrackerHitPlaneData
 *  Tracker hit plane
 *  @author: EDM4hep authors
 */
class TrackerHitPlaneData {
public:
  std::uint64_t cellID{};             ///< ID of the sensor that created this hit
  std::int32_t type{};                ///< type of raw data hit
  std::int32_t quality{};             ///< quality bit flag of the hit
  float time{};                       ///< time of the hit [ns]
  float eDep{};                       ///< energy deposited on the hit [GeV]
  float eDepError{};                  ///< error measured on EDep [GeV]
  ::edm4hep::Vector2f u{};            ///< measurement direction vector, u lies in the x-y plane
  ::edm4hep::Vector2f v{};            ///< measurement direction vector, v is along z
  float du{};                         ///< measurement error along the direction
  float dv{};                         ///< measurement error along the direction
  ::edm4hep::Vector3d position{};     ///< hit position [mm]
  ::edm4hep::CovMatrix3f covMatrix{}; ///< covariance of the position (x,y,z)
};

} // namespace edm4hep

#endif
