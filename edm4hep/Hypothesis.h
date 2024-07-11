// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Hypothesis_H
#define EDM4HEP_Hypothesis_H

#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class Hypothesis
 *
 *  @author:
 */
class Hypothesis {
public:
  float chi2{};     ///< chi2
  float expected{}; ///< expected value
  float sigma{};    ///< sigma value
};

std::ostream& operator<<(std::ostream& o, const edm4hep::Hypothesis& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Hypothesis& value);
#endif

} // namespace edm4hep

#endif
