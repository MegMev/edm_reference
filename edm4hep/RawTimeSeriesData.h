// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawTimeSeriesDATA_H
#define EDM4HEP_RawTimeSeriesDATA_H

#include <cstdint>

namespace edm4hep {

/** @class RawTimeSeriesData
 *  Raw data of a detector readout
 *  @author: EDM4hep authors
 */
class RawTimeSeriesData {
public:
  std::uint64_t cellID{}; ///< detector specific cell id
  std::int32_t quality{}; ///< quality flag for the hit
  float time{};           ///< time of the hit [ns]
  float charge{};         ///< integrated charge of the hit [fC]
  float interval{};       ///< interval of each sampling [ns]

  unsigned int adcCounts_begin{};
  unsigned int adcCounts_end{};
};

} // namespace edm4hep

#endif
