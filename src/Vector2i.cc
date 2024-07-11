// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Vector2i.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector2i& value) {
  o << value.a << " ";
  o << value.b << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector2i& value) {
  j = nlohmann::json{{"a", value.a}, {"b", value.b}};
}
#endif

} // namespace edm4hep
