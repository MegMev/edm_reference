// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeaderDATA_H
#define EDM4HEP_EventHeaderDATA_H

#include <cstdint>

namespace edm4hep {

/** @class EventHeaderData
 *  Event Header. Additional parameters are assumed to go into the metadata tree.
 *  @author: EDM4hep authors
 */
class EventHeaderData {
public:
  std::int32_t eventNumber{}; ///< event number
  std::int32_t runNumber{};   ///< run number
  std::uint64_t timeStamp{};  ///< time stamp
  double weight{};            ///< event weight

  unsigned int weights_begin{};
  unsigned int weights_end{};
};

} // namespace edm4hep

#endif
