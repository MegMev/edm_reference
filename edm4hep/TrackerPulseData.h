// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerPulseDATA_H
#define EDM4HEP_TrackerPulseDATA_H

#include <array>
#include <cstdint>

namespace edm4hep {

/** @class TrackerPulseData
 *  Reconstructed Tracker Pulse
 *  @author: Wenxing Fang, IHEP
 */
class TrackerPulseData {
public:
  std::uint64_t cellID{};           ///< cell id.
  float time{};                     ///< time [ns].
  float charge{};                   ///< charge [fC].
  std::int16_t quality{};           ///< quality.
  std::array<float, 3> covMatrix{}; ///< lower triangle covariance matrix of the charge(c) and time(t) measurements.
};

} // namespace edm4hep

#endif
