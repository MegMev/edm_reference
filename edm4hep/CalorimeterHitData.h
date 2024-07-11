// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHitDATA_H
#define EDM4HEP_CalorimeterHitDATA_H

#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class CalorimeterHitData
 *  Calorimeter hit
 *  @author: EDM4hep authors
 */
class CalorimeterHitData {
public:
  std::uint64_t cellID{};         ///< detector specific (geometrical) cell id
  float energy{};                 ///< energy of the hit [GeV]
  float energyError{};            ///< error of the hit energy [GeV]
  float time{};                   ///< time of the hit [ns]
  ::edm4hep::Vector3f position{}; ///< position of the hit in world coordinates [mm]
  std::int32_t type{};            ///< type of hit
};

} // namespace edm4hep

#endif
