// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticleDATA_H
#define EDM4HEP_MCParticleDATA_H

#include "edm4hep/Vector2i.h"
#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class MCParticleData
 *  The Monte Carlo particle - based on the lcio::MCParticle.
 *  @author: EDM4hep authors
 */
class MCParticleData {
public:
  std::int32_t PDG{};             ///< PDG code of the particle
  std::int32_t generatorStatus{}; ///< status of the particle as defined by the generator
  std::int32_t simulatorStatus{}; ///< status of the particle from the simulation program - use BIT constants below
  float charge{};                 ///< particle charge
  float time{};  ///< creation time of the particle in wrt. the event, e.g. for preassigned decays or decays in flight
                 ///< from the simulator [ns]
  double mass{}; ///< mass of the particle [GeV]
  ::edm4hep::Vector3d vertex{};             ///< production vertex of the particle [mm]
  ::edm4hep::Vector3d endpoint{};           ///< endpoint of the particle [mm]
  ::edm4hep::Vector3d momentum{};           ///< particle 3-momentum at the production vertex [GeV]
  ::edm4hep::Vector3d momentumAtEndpoint{}; ///< particle 3-momentum at the endpoint [GeV]
  ::edm4hep::Vector3f spin{};               ///< spin (helicity) vector of the particle
  ::edm4hep::Vector2i colorFlow{};          ///< color flow as defined by the generator

  unsigned int parents_begin{};
  unsigned int parents_end{};
  unsigned int daughters_begin{};
  unsigned int daughters_end{};
};

} // namespace edm4hep

#endif
