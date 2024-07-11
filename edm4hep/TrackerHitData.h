// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitDATA_H
#define EDM4HEP_TrackerHitDATA_H

#include "edm4hep/Vector3d.h"
#include <array>
#include <cstdint>

namespace edm4hep {

/** @class TrackerHitData
 *  Tracker hit
 *  @author: F.Gaede, DESY
 */
class TrackerHitData {
public:
  std::uint64_t cellID{}; ///< ID of the sensor that created this hit
  std::int32_t type{};    ///< type of raw data hit, either one of edm4hep::RawTimeSeries, edm4hep::SIMTRACKERHIT - see
                          ///< collection parameters "TrackerHitTypeNames" and "TrackerHitTypeValues".
  std::int32_t quality{}; ///< quality bit flag of the hit.
  float time{};           ///< time of the hit [ns].
  float eDep{};           ///< energy deposited on the hit [GeV].
  float eDepError{};      ///< error measured on EDep [GeV].
  ::edm4hep::Vector3d position{};   ///< hit position in [mm].
  std::array<float, 6> covMatrix{}; ///< covariance of the position (x,y,z), stored as lower triangle matrix. i.e.
                                    ///< cov(x,x) , cov(y,x) , cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)

  unsigned int rawHits_begin{};
  unsigned int rawHits_end{};
};

} // namespace edm4hep

#endif
