// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Quantity_H
#define EDM4HEP_Quantity_H

#include <cstdint>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class Quantity
 *
 *  @author:
 */
class Quantity {
public:
  std::int16_t type{}; ///< flag identifying how to interpret the quantity
  float value{};       ///< value of the quantity
  float error{};       ///< error on the value of the quantity
};

std::ostream& operator<<(std::ostream& o, const edm4hep::Quantity& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Quantity& value);
#endif

} // namespace edm4hep

#endif
