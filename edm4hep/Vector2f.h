// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vector2f_H
#define EDM4HEP_Vector2f_H

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class Vector2f
 *
 *  @author:
 */
class Vector2f {
public:
  float a{};
  float b{};

  constexpr Vector2f() : a(0), b(0) {
  }
  constexpr Vector2f(float aa, float bb) : a(aa), b(bb) {
  }
  constexpr Vector2f(const float* v) : a(v[0]), b(v[1]) {
  }
  constexpr bool operator==(const Vector2f& v) const {
    return (a == v.a && b == v.b);
  }
  constexpr bool operator!=(const Vector2f& v) const {
    return !(*this == v);
  }
  constexpr float operator[](unsigned i) const {
    static_assert(offsetof(Vector2f, a) + sizeof(Vector2f::a) == offsetof(Vector2f, b),
                  "operator[] requires no padding");
    return *(&a + i);
  }
};

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector2f& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector2f& value);
#endif

} // namespace edm4hep

#endif
