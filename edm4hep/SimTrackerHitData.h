// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHitDATA_H
#define EDM4HEP_SimTrackerHitDATA_H

#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class SimTrackerHitData
 *  Simulated tracker hit
 *  @author: EDM4hep authors
 */
class SimTrackerHitData {
public:
  std::uint64_t cellID{};         ///< ID of the sensor that created this hit
  float eDep{};                   ///< energy deposited in the hit [GeV]
  float time{};                   ///< proper time of the hit in the lab frame [ns]
  float pathLength{};             ///< path length of the particle in the sensitive material that resulted in this hit
  std::int32_t quality{};         ///< quality bit flag
  ::edm4hep::Vector3d position{}; ///< the hit position [mm]
  ::edm4hep::Vector3f momentum{}; ///< the 3-momentum of the particle at the hits position [GeV]
};

} // namespace edm4hep

#endif
