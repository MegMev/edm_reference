// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit3DDATA_H
#define EDM4HEP_TrackerHit3DDATA_H

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector3d.h"
#include <cstdint>

namespace edm4hep {

/** @class TrackerHit3DData
 *  Tracker hit
 *  @author: EDM4hep authors
 */
class TrackerHit3DData {
public:
  std::uint64_t cellID{};             ///< ID of the sensor that created this hit
  std::int32_t type{};                ///< type of raw data hit
  std::int32_t quality{};             ///< quality bit flag of the hit
  float time{};                       ///< time of the hit [ns]
  float eDep{};                       ///< energy deposited on the hit [GeV]
  float eDepError{};                  ///< error measured on EDep [GeV]
  ::edm4hep::Vector3d position{};     ///< hit position [mm]
  ::edm4hep::CovMatrix3f covMatrix{}; ///< covariance matrix of the position (x,y,z)
};

} // namespace edm4hep

#endif
