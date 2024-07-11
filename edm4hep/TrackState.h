// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackState_H
#define EDM4HEP_TrackState_H

#include "edm4hep/CovMatrix6f.h"
#include "edm4hep/Vector3f.h"
#include <cstdint>
#include <edm4hep/Constants.h>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class TrackState
 *
 *  @author:
 */
class TrackState {
public:
  std::int32_t location{}; ///< for use with At{Other|IP|FirstHit|LastHit|Calorimeter|Vertex}|LastLocation
  float D0{};              ///< transverse impact parameter
  float phi{};             ///< azimuthal angle
  float omega{};
  float Z0{};                           ///< longitudinal impact parameter
  float tanLambda{};                    ///< lambda is the dip angle of the track in r-z
  float time{};                         ///< time of the track at this trackstate [ns]
  ::edm4hep::Vector3f referencePoint{}; ///< Reference point of the track parameters, e.g. the origin at the IP, or the
                                        ///< position  of the first/last hits or the entry point into the calorimeter
                                        ///< [mm]
  ::edm4hep::CovMatrix6f covMatrix{};   ///< covariance matrix of the track parameters.

  static const int AtOther = 0; // any location other than the ones defined below
  static const int AtIP = 1;
  static const int AtFirstHit = 2;
  static const int AtLastHit = 3;
  static const int AtCalorimeter = 4;
  static const int AtVertex = 5;
  static const int LastLocation = AtVertex;

  /// Get the covariance matrix value for the two passed parameters
  constexpr float getCovMatrix(edm4hep::TrackParams parI, edm4hep::TrackParams parJ) const {
    return covMatrix.getValue(parI, parJ);
  }
  /// Set the covariance matrix value for the two passed parameters
  constexpr void setCovMatrix(float value, edm4hep::TrackParams parI, edm4hep::TrackParams parJ) {
    covMatrix.setValue(value, parI, parJ);
  }
};

std::ostream& operator<<(std::ostream& o, const edm4hep::TrackState& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackState& value);
#endif

} // namespace edm4hep

#endif
