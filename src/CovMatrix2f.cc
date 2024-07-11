// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CovMatrix2f.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::CovMatrix2f& value) {
  for (int i = 0; i < 3; ++i) {
    o << value.values[i] << "|";
  }
  o << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const CovMatrix2f& value) {
  j = nlohmann::json{{"values", value.values}};
}
#endif

} // namespace edm4hep
