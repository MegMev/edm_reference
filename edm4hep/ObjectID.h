// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ObjectID_H
#define EDM4HEP_ObjectID_H

#include <cstdint>
#include <ostream>
#include <podio/ObjectID.h>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class ObjectID
 *
 *  @author:
 */
class ObjectID {
public:
  std::int32_t index{};
  std::int32_t collectionID{};

  ObjectID() = default;
  ObjectID(const podio::ObjectID& id) : index(id.index), collectionID(id.collectionID) {
  }
};

std::ostream& operator<<(std::ostream& o, const edm4hep::ObjectID& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ObjectID& value);
#endif

} // namespace edm4hep

#endif
