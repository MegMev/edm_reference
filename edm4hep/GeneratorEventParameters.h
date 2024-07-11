// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorEventParameters_H
#define EDM4HEP_GeneratorEventParameters_H

#include "edm4hep/GeneratorEventParametersObj.h"

#include "edm4hep/MCParticle.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableGeneratorEventParameters;
class GeneratorEventParametersCollection;
class GeneratorEventParametersCollectionData;

/** @class GeneratorEventParameters
 *  Generator event parameters
 *  @author: EDM4hep authors
 */
class GeneratorEventParameters {

  friend class MutableGeneratorEventParameters;
  friend class GeneratorEventParametersCollection;
  friend class edm4hep::GeneratorEventParametersCollectionData;
  friend class GeneratorEventParametersCollectionIterator;

public:
  using mutable_type = MutableGeneratorEventParameters;
  using collection_type = GeneratorEventParametersCollection;

  /// default constructor
  GeneratorEventParameters();

  /// Constructor initializing all members
  GeneratorEventParameters(double eventScale, double alphaQED, double alphaQCD, int signalProcessId, double sqrts);

  /// copy constructor
  GeneratorEventParameters(const GeneratorEventParameters& other) = default;

  /// copy-assignment operator
  GeneratorEventParameters& operator=(GeneratorEventParameters other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableGeneratorEventParameters clone(bool cloneRelations = true) const;

  /// destructor
  ~GeneratorEventParameters() = default;

  /// converting constructor from mutable object
  GeneratorEventParameters(const MutableGeneratorEventParameters& other);

  static GeneratorEventParameters makeEmpty();

public:
  /// Access the event scale
  double getEventScale() const;

  /// Access the alpha_QED
  double getAlphaQED() const;

  /// Access the alpha_QCD
  double getAlphaQCD() const;

  /// Access the id of signal process
  int getSignalProcessId() const;

  /// Access the sqrt(s) [GeV]
  double getSqrts() const;

  std::size_t signalVertex_size() const;
  edm4hep::MCParticle getSignalVertex(std::size_t) const;
  std::vector<edm4hep::MCParticle>::const_iterator signalVertex_begin() const;
  std::vector<edm4hep::MCParticle>::const_iterator signalVertex_end() const;
  podio::RelationRange<edm4hep::MCParticle> getSignalVertex() const;
  std::size_t crossSections_size() const;
  double getCrossSections(std::size_t) const;
  std::vector<double>::const_iterator crossSections_begin() const;
  std::vector<double>::const_iterator crossSections_end() const;
  podio::RelationRange<double> getCrossSections() const;
  std::size_t crossSectionErrors_size() const;
  double getCrossSectionErrors(std::size_t) const;
  std::vector<double>::const_iterator crossSectionErrors_begin() const;
  std::vector<double>::const_iterator crossSectionErrors_end() const;
  podio::RelationRange<double> getCrossSectionErrors() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from GeneratorEventParametersObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<GeneratorEventParametersObj>{nullptr};
  }

  bool operator==(const GeneratorEventParameters& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableGeneratorEventParameters& other) const;

  bool operator!=(const GeneratorEventParameters& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableGeneratorEventParameters& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const GeneratorEventParameters& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(GeneratorEventParameters& a, GeneratorEventParameters& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing GeneratorEventParametersObj
  explicit GeneratorEventParameters(podio::utils::MaybeSharedPtr<GeneratorEventParametersObj> obj);
  GeneratorEventParameters(GeneratorEventParametersObj* obj);

  podio::utils::MaybeSharedPtr<GeneratorEventParametersObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const GeneratorEventParameters& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const GeneratorEventParameters& value);
#endif

} // namespace edm4hep

#endif
