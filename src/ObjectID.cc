// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ObjectID.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::ObjectID& value) {
  o << value.index << " ";
  o << value.collectionID << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ObjectID& value) {
  j = nlohmann::json{{"index", value.index}, {"collectionID", value.collectionID}};
}
#endif

} // namespace edm4hep
