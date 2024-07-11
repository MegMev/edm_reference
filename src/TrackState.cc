// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackState.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

std::ostream& operator<<(std::ostream& o, const edm4hep::TrackState& value) {
  o << value.location << " ";
  o << value.D0 << " ";
  o << value.phi << " ";
  o << value.omega << " ";
  o << value.Z0 << " ";
  o << value.tanLambda << " ";
  o << value.time << " ";
  o << value.referencePoint << " ";
  o << value.covMatrix << " ";

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackState& value) {
  j = nlohmann::json{{"location", value.location},
                     {"D0", value.D0},
                     {"phi", value.phi},
                     {"omega", value.omega},
                     {"Z0", value.Z0},
                     {"tanLambda", value.tanLambda},
                     {"time", value.time},
                     {"referencePoint", value.referencePoint},
                     {"covMatrix", value.covMatrix}};
}
#endif

} // namespace edm4hep
