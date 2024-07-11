// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableGeneratorPdfInfo_H
#define EDM4HEP_MutableGeneratorPdfInfo_H

#include "edm4hep/GeneratorPdfInfoObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/GeneratorPdfInfo.h"

#include <array>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

/** @class MutableGeneratorPdfInfo
 *  Generator pdf information
 *  @author: EDM4hep authors
 */
class MutableGeneratorPdfInfo {

  friend class GeneratorPdfInfoCollection;
  friend class GeneratorPdfInfoMutableCollectionIterator;
  friend class GeneratorPdfInfo;

public:
  using object_type = GeneratorPdfInfo;
  using collection_type = GeneratorPdfInfoCollection;

  /// default constructor
  MutableGeneratorPdfInfo();

  /// Constructor initializing all members
  MutableGeneratorPdfInfo(std::array<int, 2> partonId, std::array<int, 2> lhapdfId, std::array<double, 2> x,
                          std::array<double, 2> xf, double scale);

  /// copy constructor
  MutableGeneratorPdfInfo(const MutableGeneratorPdfInfo& other) = default;

  /// copy-assignment operator
  MutableGeneratorPdfInfo& operator=(MutableGeneratorPdfInfo other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableGeneratorPdfInfo clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableGeneratorPdfInfo() = default;

public:
  /// Access the Parton PDG id
  const std::array<int, 2>& getPartonId() const;
  /// Access item i of the Parton PDG id
  int getPartonId(size_t i) const;
  /// Access the LHAPDF PDF id (see https://lhapdf.hepforge.org/pdfsets.html)
  const std::array<int, 2>& getLhapdfId() const;
  /// Access item i of the LHAPDF PDF id (see https://lhapdf.hepforge.org/pdfsets.html)
  int getLhapdfId(size_t i) const;
  /// Access the Parton momentum fraction
  const std::array<double, 2>& getX() const;
  /// Access item i of the Parton momentum fraction
  double getX(size_t i) const;
  /// Access the PDF value
  const std::array<double, 2>& getXf() const;
  /// Access item i of the PDF value
  double getXf(size_t i) const;
  /// Access the Factorisation scale [GeV]
  double getScale() const;

  /// Set the Parton PDG id
  void setPartonId(std::array<int, 2> value);
  void setPartonId(size_t i, int value);
  /// Get mutable reference to Parton PDG id
  std::array<int, 2>& getPartonId();
  /// Get reference to Parton PDG id
  [[deprecated("use getPartonId instead")]] std::array<int, 2>& partonId();

  /// Set the LHAPDF PDF id (see https://lhapdf.hepforge.org/pdfsets.html)
  void setLhapdfId(std::array<int, 2> value);
  void setLhapdfId(size_t i, int value);
  /// Get mutable reference to LHAPDF PDF id (see https://lhapdf.hepforge.org/pdfsets.html)
  std::array<int, 2>& getLhapdfId();
  /// Get reference to LHAPDF PDF id (see https://lhapdf.hepforge.org/pdfsets.html)
  [[deprecated("use getLhapdfId instead")]] std::array<int, 2>& lhapdfId();

  /// Set the Parton momentum fraction
  void setX(std::array<double, 2> value);
  void setX(size_t i, double value);
  /// Get mutable reference to Parton momentum fraction
  std::array<double, 2>& getX();
  /// Get reference to Parton momentum fraction
  [[deprecated("use getX instead")]] std::array<double, 2>& x();

  /// Set the PDF value
  void setXf(std::array<double, 2> value);
  void setXf(size_t i, double value);
  /// Get mutable reference to PDF value
  std::array<double, 2>& getXf();
  /// Get reference to PDF value
  [[deprecated("use getXf instead")]] std::array<double, 2>& xf();

  /// Set the Factorisation scale [GeV]
  void setScale(double value);
  /// Get mutable reference to Factorisation scale [GeV]
  double& getScale();
  /// Get reference to Factorisation scale [GeV]
  [[deprecated("use getScale instead")]] double& scale();

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from GeneratorPdfInfoObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj>{nullptr};
  }

  bool operator==(const MutableGeneratorPdfInfo& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const GeneratorPdfInfo& other) const;

  bool operator!=(const MutableGeneratorPdfInfo& other) const {
    return !(*this == other);
  }
  bool operator!=(const GeneratorPdfInfo& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableGeneratorPdfInfo& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableGeneratorPdfInfo& a, MutableGeneratorPdfInfo& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing GeneratorPdfInfoObj
  explicit MutableGeneratorPdfInfo(podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj> obj);

  podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableGeneratorPdfInfo& value);
#endif

} // namespace edm4hep

#endif
