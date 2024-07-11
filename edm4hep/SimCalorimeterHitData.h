// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHitDATA_H
#define EDM4HEP_SimCalorimeterHitDATA_H

#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class SimCalorimeterHitData
 *  Simulated calorimeter hit
 *  @author: EDM4hep authors
 */
class SimCalorimeterHitData {
public:
  std::uint64_t cellID{};         ///< ID of the sensor that created this hit
  float energy{};                 ///< energy of the hit [GeV]
  ::edm4hep::Vector3f position{}; ///< position of the hit in world coordinates [mm]

  unsigned int contributions_begin{};
  unsigned int contributions_end{};
};

} // namespace edm4hep

#endif
