// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableGeneratorEventParameters_H
#define EDM4HEP_MutableGeneratorEventParameters_H

#include "edm4hep/GeneratorEventParametersObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/GeneratorEventParameters.h"

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

/** @class MutableGeneratorEventParameters
 *  Generator event parameters
 *  @author: EDM4hep authors
 */
class MutableGeneratorEventParameters {

  friend class GeneratorEventParametersCollection;
  friend class GeneratorEventParametersMutableCollectionIterator;
  friend class GeneratorEventParameters;

public:
  using object_type = GeneratorEventParameters;
  using collection_type = GeneratorEventParametersCollection;

  /// default constructor
  MutableGeneratorEventParameters();

  /// Constructor initializing all members
  MutableGeneratorEventParameters(double eventScale, double alphaQED, double alphaQCD, int signalProcessId,
                                  double sqrts);

  /// copy constructor
  MutableGeneratorEventParameters(const MutableGeneratorEventParameters& other) = default;

  /// copy-assignment operator
  MutableGeneratorEventParameters& operator=(MutableGeneratorEventParameters other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableGeneratorEventParameters clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableGeneratorEventParameters() = default;

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

  /// Set the event scale
  void setEventScale(double value);
  /// Get mutable reference to event scale
  double& getEventScale();
  /// Get reference to event scale
  [[deprecated("use getEventScale instead")]] double& eventScale();

  /// Set the alpha_QED
  void setAlphaQED(double value);
  /// Get mutable reference to alpha_QED
  double& getAlphaQED();
  /// Get reference to alpha_QED
  [[deprecated("use getAlphaQED instead")]] double& alphaQED();

  /// Set the alpha_QCD
  void setAlphaQCD(double value);
  /// Get mutable reference to alpha_QCD
  double& getAlphaQCD();
  /// Get reference to alpha_QCD
  [[deprecated("use getAlphaQCD instead")]] double& alphaQCD();

  /// Set the id of signal process
  void setSignalProcessId(int value);
  /// Get mutable reference to id of signal process
  int& getSignalProcessId();
  /// Get reference to id of signal process
  [[deprecated("use getSignalProcessId instead")]] int& signalProcessId();

  /// Set the sqrt(s) [GeV]
  void setSqrts(double value);
  /// Get mutable reference to sqrt(s) [GeV]
  double& getSqrts();
  /// Get reference to sqrt(s) [GeV]
  [[deprecated("use getSqrts instead")]] double& sqrts();

  void addToSignalVertex(const edm4hep::MCParticle&);
  std::size_t signalVertex_size() const;
  edm4hep::MCParticle getSignalVertex(std::size_t) const;
  std::vector<edm4hep::MCParticle>::const_iterator signalVertex_begin() const;
  std::vector<edm4hep::MCParticle>::const_iterator signalVertex_end() const;
  podio::RelationRange<edm4hep::MCParticle> getSignalVertex() const;
  void addToCrossSections(const double&);
  std::size_t crossSections_size() const;
  double getCrossSections(std::size_t) const;
  std::vector<double>::const_iterator crossSections_begin() const;
  std::vector<double>::const_iterator crossSections_end() const;
  podio::RelationRange<double> getCrossSections() const;
  void addToCrossSectionErrors(const double&);
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

  bool operator==(const MutableGeneratorEventParameters& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const GeneratorEventParameters& other) const;

  bool operator!=(const MutableGeneratorEventParameters& other) const {
    return !(*this == other);
  }
  bool operator!=(const GeneratorEventParameters& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableGeneratorEventParameters& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableGeneratorEventParameters& a, MutableGeneratorEventParameters& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing GeneratorEventParametersObj
  explicit MutableGeneratorEventParameters(podio::utils::MaybeSharedPtr<GeneratorEventParametersObj> obj);

  podio::utils::MaybeSharedPtr<GeneratorEventParametersObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableGeneratorEventParameters& value);
#endif

} // namespace edm4hep

#endif
