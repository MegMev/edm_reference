// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorPdfInfo_H
#define EDM4HEP_GeneratorPdfInfo_H

#include "edm4hep/GeneratorPdfInfoObj.h"

#include <array>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableGeneratorPdfInfo;
class GeneratorPdfInfoCollection;
class GeneratorPdfInfoCollectionData;

/** @class GeneratorPdfInfo
 *  Generator pdf information
 *  @author: EDM4hep authors
 */
class GeneratorPdfInfo {

  friend class MutableGeneratorPdfInfo;
  friend class GeneratorPdfInfoCollection;
  friend class edm4hep::GeneratorPdfInfoCollectionData;
  friend class GeneratorPdfInfoCollectionIterator;

public:
  using mutable_type = MutableGeneratorPdfInfo;
  using collection_type = GeneratorPdfInfoCollection;

  /// default constructor
  GeneratorPdfInfo();

  /// Constructor initializing all members
  GeneratorPdfInfo(std::array<int, 2> partonId, std::array<int, 2> lhapdfId, std::array<double, 2> x,
                   std::array<double, 2> xf, double scale);

  /// copy constructor
  GeneratorPdfInfo(const GeneratorPdfInfo& other) = default;

  /// copy-assignment operator
  GeneratorPdfInfo& operator=(GeneratorPdfInfo other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableGeneratorPdfInfo clone(bool cloneRelations = true) const;

  /// destructor
  ~GeneratorPdfInfo() = default;

  /// converting constructor from mutable object
  GeneratorPdfInfo(const MutableGeneratorPdfInfo& other);

  static GeneratorPdfInfo makeEmpty();

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

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from GeneratorPdfInfoObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj>{nullptr};
  }

  bool operator==(const GeneratorPdfInfo& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableGeneratorPdfInfo& other) const;

  bool operator!=(const GeneratorPdfInfo& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableGeneratorPdfInfo& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const GeneratorPdfInfo& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(GeneratorPdfInfo& a, GeneratorPdfInfo& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing GeneratorPdfInfoObj
  explicit GeneratorPdfInfo(podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj> obj);
  GeneratorPdfInfo(GeneratorPdfInfoObj* obj);

  podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const GeneratorPdfInfo& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const GeneratorPdfInfo& value);
#endif

} // namespace edm4hep

#endif
