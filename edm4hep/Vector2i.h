// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vector2i_H
#define EDM4HEP_Vector2i_H

#include <cstddef>
#include <cstdint>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class Vector2i
 *
 *  @author:
 */
class Vector2i {
public:
  std::int32_t a{};
  std::int32_t b{};

  constexpr Vector2i() : a(0), b(0) {
  }
  constexpr Vector2i(int32_t aa, int32_t bb) : a(aa), b(bb) {
  }
  constexpr Vector2i(const int32_t* v) : a(v[0]), b(v[1]) {
  }
  constexpr bool operator==(const Vector2i& v) const {
    return (a == v.a && b == v.b);
  }
  constexpr bool operator!=(const Vector2i& v) const {
    return !(*this == v);
  }
  constexpr int operator[](unsigned i) const {
    static_assert(offsetof(Vector2i, a) + sizeof(Vector2i::a) == offsetof(Vector2i, b),
                  "operator[] requires no padding");
    return *(&a + i);
  }
};

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector2i& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector2i& value);
#endif

} // namespace edm4hep

#endif
