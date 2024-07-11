// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorEventParametersOBJ_H
#define EDM4HEP_GeneratorEventParametersOBJ_H

// data model specific includes
#include "edm4hep/GeneratorEventParametersData.h"
#include "edm4hep/MCParticle.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class GeneratorEventParameters;

class GeneratorEventParametersObj {
public:
  /// constructor
  GeneratorEventParametersObj();
  /// copy constructor (does a deep-copy of relation containers)
  GeneratorEventParametersObj(const GeneratorEventParametersObj&);
  /// constructor from ObjectID and GeneratorEventParametersData
  /// does not initialize the internal relation containers
  GeneratorEventParametersObj(const podio::ObjectID id, GeneratorEventParametersData data);
  /// No assignment operator
  GeneratorEventParametersObj& operator=(const GeneratorEventParametersObj&) = delete;
  virtual ~GeneratorEventParametersObj();

public:
  podio::ObjectID id;
  GeneratorEventParametersData data;
  std::vector<edm4hep::MCParticle>* m_signalVertex{nullptr};
  std::vector<double>* m_crossSections{nullptr};
  std::vector<double>* m_crossSectionErrors{nullptr};
};

} // namespace edm4hep

#endif
