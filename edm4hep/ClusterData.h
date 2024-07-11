// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterDATA_H
#define EDM4HEP_ClusterDATA_H

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class ClusterData
 *  Calorimeter Hit Cluster
 *  @author: EDM4hep authors
 */
class ClusterData {
public:
  std::int32_t type{};                    ///< flagword that defines the type of cluster
  float energy{};                         ///< energy of the cluster [GeV]
  float energyError{};                    ///< error on the energy [GeV]
  ::edm4hep::Vector3f position{};         ///< position of the cluster [mm]
  ::edm4hep::CovMatrix3f positionError{}; ///< covariance matrix of the position
  float iTheta{}; ///< intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is
                  ///< seen from IP
  float phi{}; ///< intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is seen
               ///< from IP
  ::edm4hep::Vector3f directionError{}; ///< covariance matrix of the direction [mm**2]

  unsigned int shapeParameters_begin{};
  unsigned int shapeParameters_end{};
  unsigned int subdetectorEnergies_begin{};
  unsigned int subdetectorEnergies_end{};
  unsigned int clusters_begin{};
  unsigned int clusters_end{};
  unsigned int hits_begin{};
  unsigned int hits_end{};
};

} // namespace edm4hep

#endif
