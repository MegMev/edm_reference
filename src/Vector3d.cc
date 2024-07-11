// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Vector3d.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector3d& value) {
  o << value.x << " ";
  o << value.y << " ";
  o << value.z << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector3d& value) {
  j = nlohmann::json{{"x", value.x}, {"y", value.y}, {"z", value.z}};
}
#endif

} // namespace edm4hep
