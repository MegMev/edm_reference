// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorPdfInfoDATA_H
#define EDM4HEP_GeneratorPdfInfoDATA_H

#include <array>

namespace edm4hep {

/** @class GeneratorPdfInfoData
 *  Generator pdf information
 *  @author: EDM4hep authors
 */
class GeneratorPdfInfoData {
public:
  std::array<int, 2> partonId{}; ///< Parton PDG id
  std::array<int, 2> lhapdfId{}; ///< LHAPDF PDF id (see https://lhapdf.hepforge.org/pdfsets.html)
  std::array<double, 2> x{};     ///< Parton momentum fraction
  std::array<double, 2> xf{};    ///< PDF value
  double scale{};                ///< Factorisation scale [GeV]
};

} // namespace edm4hep

#endif
