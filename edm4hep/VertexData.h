// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_VertexDATA_H
#define EDM4HEP_VertexDATA_H

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class VertexData
 *  Vertex
 *  @author: EDM4hep authors
 */
class VertexData {
public:
  std::int32_t primary{};             ///< boolean flag, if vertex is the primary vertex of the event
  float chi2{};                       ///< chi-squared of the vertex fit
  std::int32_t ndf{};                 ///< number of degrees of freedom of the vertex fit
  ::edm4hep::Vector3f position{};     ///< [mm] position of the vertex
  ::edm4hep::CovMatrix3f covMatrix{}; ///< covariance matrix of the position
  std::int32_t algorithmType{};       ///< type code for the algorithm that has been used to create the vertex

  unsigned int parameters_begin{};
  unsigned int parameters_end{};
};

} // namespace edm4hep

#endif
