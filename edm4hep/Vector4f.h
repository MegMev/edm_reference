// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vector4f_H
#define EDM4HEP_Vector4f_H

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class Vector4f
 *  Generic vector for storing classical 4D coordinates in memory. Four momentum helper functions are in edm4hep::utils
 *  @author:
 */
class Vector4f {
public:
  float x{};
  float y{};
  float z{};
  float t{};

  constexpr Vector4f() : x(0), y(0), z(0), t(0) {
  }
  constexpr Vector4f(float xx, float yy, float zz, float tt) : x(xx), y(yy), z(zz), t(tt) {
  }
  constexpr Vector4f(const float* v) : x(v[0]), y(v[1]), z(v[2]), t(v[3]) {
  }
  constexpr bool operator==(const Vector4f& v) const {
    return (x == v.x && y == v.y && z == v.z && t == v.t);
  }
  constexpr bool operator!=(const Vector4f& v) const {
    return !(*this == v);
  }
  constexpr float operator[](unsigned i) const {
    static_assert((offsetof(Vector4f, x) + sizeof(Vector4f::x) == offsetof(Vector4f, y)) &&
                      (offsetof(Vector4f, y) + sizeof(Vector4f::y) == offsetof(Vector4f, z)) &&
                      (offsetof(Vector4f, z) + sizeof(Vector4f::z) == offsetof(Vector4f, t)),
                  "operator[] requires no padding");
    return *(&x + i);
  }
};

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector4f& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector4f& value);
#endif

} // namespace edm4hep

#endif
