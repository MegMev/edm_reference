// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vector3d_H
#define EDM4HEP_Vector3d_H

#include <cstddef>
#include <edm4hep/Vector3f.h>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class Vector3d
 *
 *  @author:
 */
class Vector3d {
public:
  double x{};
  double y{};
  double z{};

  constexpr Vector3d() : x(0), y(0), z(0) {
  }
  constexpr Vector3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {
  }
  constexpr Vector3d(const double* v) : x(v[0]), y(v[1]), z(v[2]) {
  }
  constexpr Vector3d(const float* v) : x(v[0]), y(v[1]), z(v[2]) {
  }
  [[deprecated("This constructor will be removed again it is mainly here for an easier "
               "transition")]] constexpr Vector3d(const Vector3f& v) :
      x(v.x), y(v.y), z(v.z) {
  }
  constexpr bool operator==(const Vector3d& v) const {
    return (x == v.x && y == v.y && z == v.z);
  }
  constexpr bool operator!=(const Vector3d& v) const {
    return !(*this == v);
  }
  constexpr double operator[](unsigned i) const {
    static_assert((offsetof(Vector3d, x) + sizeof(Vector3d::x) == offsetof(Vector3d, y)) &&
                      (offsetof(Vector3d, y) + sizeof(Vector3d::y) == offsetof(Vector3d, z)),
                  "operator[] requires no padding");
    return *(&x + i);
  }
};

std::ostream& operator<<(std::ostream& o, const edm4hep::Vector3d& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vector3d& value);
#endif

} // namespace edm4hep

#endif
