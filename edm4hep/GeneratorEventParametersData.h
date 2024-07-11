// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorEventParametersDATA_H
#define EDM4HEP_GeneratorEventParametersDATA_H

namespace edm4hep {

/** @class GeneratorEventParametersData
 *  Generator event parameters
 *  @author: EDM4hep authors
 */
class GeneratorEventParametersData {
public:
  double eventScale{};   ///< event scale
  double alphaQED{};     ///< alpha_QED
  double alphaQCD{};     ///< alpha_QCD
  int signalProcessId{}; ///< id of signal process
  double sqrts{};        ///< sqrt(s) [GeV]

  unsigned int crossSections_begin{};
  unsigned int crossSections_end{};
  unsigned int crossSectionErrors_begin{};
  unsigned int crossSectionErrors_end{};
  unsigned int signalVertex_begin{};
  unsigned int signalVertex_end{};
};

} // namespace edm4hep

#endif
