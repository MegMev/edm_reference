// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimPrimaryIonizationClusterDATA_H
#define EDM4HEP_SimPrimaryIonizationClusterDATA_H

#include "edm4hep/Vector3d.h"
#include <cstdint>

namespace edm4hep {

/** @class SimPrimaryIonizationClusterData
 *  Simulated Primary Ionization
 *  @author: Wenxing Fang, IHEP
 */
class SimPrimaryIonizationClusterData {
public:
  std::uint64_t cellID{};         ///< cell id.
  float time{};                   ///< the primary ionization's time in the lab frame [ns].
  ::edm4hep::Vector3d position{}; ///< the primary ionization's position [mm].
  std::int16_t type{};            ///< type.

  unsigned int electronCellID_begin{};
  unsigned int electronCellID_end{};
  unsigned int electronTime_begin{};
  unsigned int electronTime_end{};
  unsigned int electronPosition_begin{};
  unsigned int electronPosition_end{};
  unsigned int pulseTime_begin{};
  unsigned int pulseTime_end{};
  unsigned int pulseAmplitude_begin{};
  unsigned int pulseAmplitude_end{};
};

} // namespace edm4hep

#endif
