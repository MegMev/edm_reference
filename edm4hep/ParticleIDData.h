// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleIDDATA_H
#define EDM4HEP_ParticleIDDATA_H

#include <cstdint>

namespace edm4hep {

/** @class ParticleIDData
 *  ParticleID
 *  @author: EDM4hep authors
 */
class ParticleIDData {
public:
  std::int32_t type{};          ///< userdefined type
  std::int32_t PDG{};           ///< PDG code of this id - ( 999999 ) if unknown
  std::int32_t algorithmType{}; ///< type of the algorithm/module that created this hypothesis
  float likelihood{};           ///< likelihood of this hypothesis - in a user defined normalization

  unsigned int parameters_begin{};
  unsigned int parameters_end{};
};

} // namespace edm4hep

#endif
