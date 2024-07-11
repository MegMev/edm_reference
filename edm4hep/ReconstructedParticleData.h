// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticleDATA_H
#define EDM4HEP_ReconstructedParticleDATA_H

#include "edm4hep/CovMatrix4f.h"
#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class ReconstructedParticleData
 *  Reconstructed Particle
 *  @author: EDM4hep authors
 */
class ReconstructedParticleData {
public:
  std::int32_t PDG{}; ///< PDG of the reconstructed particle.
  float energy{}; ///< energy of the reconstructed particle. Four momentum state is not kept consistent internally [GeV]
  ::edm4hep::Vector3f momentum{}; ///< particle momentum. Four momentum state is not kept consistent internally [GeV]
  ::edm4hep::Vector3f referencePoint{}; ///< reference, i.e. where the particle has been measured [mm]
  float charge{};                       ///< charge of the reconstructed particle
  float mass{}; ///< mass of the reconstructed particle, set independently from four vector. Four momentum state is not
                ///< kept consistent internally [GeV]
  float goodnessOfPID{};              ///< overall goodness of the PID on a scale of [0;1]
  ::edm4hep::CovMatrix4f covMatrix{}; ///< covariance matrix of the reconstructed particle 4vector

  unsigned int clusters_begin{};
  unsigned int clusters_end{};
  unsigned int tracks_begin{};
  unsigned int tracks_end{};
  unsigned int particles_begin{};
  unsigned int particles_end{};
};

} // namespace edm4hep

#endif
