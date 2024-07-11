// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/Hypothesis.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::Hypothesis& value) {
  o << value.chi2 << " ";
  o << value.expected << " ";
  o << value.sigma << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Hypothesis& value) {
  j = nlohmann::json{{"chi2", value.chi2}, {"expected", value.expected}, {"sigma", value.sigma}};
}
#endif

} // namespace edm4hep
