// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecIonizationClusterDATA_H
#define EDM4HEP_RecIonizationClusterDATA_H

#include <cstdint>

namespace edm4hep {

/** @class RecIonizationClusterData
 *  Reconstructed Ionization Cluster
 *  @author: Wenxing Fang, IHEP
 */
class RecIonizationClusterData {
public:
  std::uint64_t cellID{}; ///< cell id.
  float significance{};   ///< significance.
  std::int16_t type{};    ///< type.

  unsigned int trackerPulse_begin{};
  unsigned int trackerPulse_end{};
};

} // namespace edm4hep

#endif
