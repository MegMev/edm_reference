// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Vector4f.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector4f& value) {
  o << value.x << " ";
  o << value.y << " ";
  o << value.z << " ";
  o << value.t << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector4f& value) {
  j = nlohmann::json{{"x", value.x}, {"y", value.y}, {"z", value.z}, {"t", value.t}};
}
#endif

} // namespace edm4hep
