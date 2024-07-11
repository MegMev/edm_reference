// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_HitLevelData_H
#define EDM4HEP_HitLevelData_H

#include <cstdint>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class HitLevelData
 *
 *  @author:
 */
class HitLevelData {
public:
  std::uint64_t cellID{}; ///< cell id
  std::uint32_t N{};      ///< number of reconstructed ionization cluster.
  float eDep{};           ///< reconstructed energy deposit [GeV].
  float pathLength{};     ///< track path length [mm].
};

std::ostream& operator<<(std::ostream& o, const edm4hep::HitLevelData& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const HitLevelData& value);
#endif

} // namespace edm4hep

#endif
