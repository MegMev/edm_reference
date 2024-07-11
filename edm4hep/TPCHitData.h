// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHitDATA_H
#define EDM4HEP_TPCHitDATA_H

#include <cstdint>

namespace edm4hep {

/** @class TPCHitData
 *  Time Projection Chamber Hit
 *  @author: F.Gaede, DESY
 */
class TPCHitData {
public:
  std::uint64_t cellID{}; ///< detector specific cell id.
  std::int32_t quality{}; ///< quality flag for the hit.
  float time{};           ///< time of the hit.
  float charge{};         ///< integrated charge of the hit.

  unsigned int rawDataWords_begin{};
  unsigned int rawDataWords_end{};
};

} // namespace edm4hep

#endif
