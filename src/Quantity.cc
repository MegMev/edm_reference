// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Quantity.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::Quantity& value) {
  o << value.type << " ";
  o << value.value << " ";
  o << value.error << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Quantity& value) {
  j = nlohmann::json{{"type", value.type}, {"value", value.value}, {"error", value.error}};
}
#endif

} // namespace edm4hep
