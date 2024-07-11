// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/HitLevelData.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::HitLevelData& value) {
  o << value.cellID << " ";
  o << value.N << " ";
  o << value.eDep << " ";
  o << value.pathLength << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const HitLevelData& value) {
  j = nlohmann::json{{"cellID", value.cellID}, {"N", value.N}, {"eDep", value.eDep}, {"pathLength", value.pathLength}};
}
#endif

} // namespace edm4hep
