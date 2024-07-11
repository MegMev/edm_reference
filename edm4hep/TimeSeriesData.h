// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TimeSeriesDATA_H
#define EDM4HEP_TimeSeriesDATA_H

#include <cstdint>

namespace edm4hep {

/** @class TimeSeriesData
 *  Calibrated Detector Data
 *  @author: EDM4hep authors
 */
class TimeSeriesData {
public:
  std::uint64_t cellID{}; ///< cell id
  float time{};           ///< begin time [ns]
  float interval{};       ///< interval of each sampling [ns]

  unsigned int amplitude_begin{};
  unsigned int amplitude_end{};
};

} // namespace edm4hep

#endif
