// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContributionDATA_H
#define EDM4HEP_CaloHitContributionDATA_H

#include "edm4hep/Vector3f.h"
#include <cstdint>

namespace edm4hep {

/** @class CaloHitContributionData
 *  Monte Carlo contribution to SimCalorimeterHit
 *  @author: EDM4hep authors
 */
class CaloHitContributionData {
public:
  std::int32_t PDG{};                 ///< PDG code of the shower particle that caused this contribution
  float energy{};                     ///< energy of the this contribution [G]
  float time{};                       ///< time of this contribution [ns]
  ::edm4hep::Vector3f stepPosition{}; ///< position of this energy deposition (step) [mm]
};

} // namespace edm4hep

#endif
