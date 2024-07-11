// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorPdfInfoOBJ_H
#define EDM4HEP_GeneratorPdfInfoOBJ_H

// data model specific includes
#include "edm4hep/GeneratorPdfInfoData.h"

#include "podio/ObjectID.h"

namespace edm4hep {

class GeneratorPdfInfo;

class GeneratorPdfInfoObj {
public:
  /// constructor
  GeneratorPdfInfoObj();
  /// copy constructor (does a deep-copy of relation containers)
  GeneratorPdfInfoObj(const GeneratorPdfInfoObj&);
  /// constructor from ObjectID and GeneratorPdfInfoData
  /// does not initialize the internal relation containers
  GeneratorPdfInfoObj(const podio::ObjectID id, GeneratorPdfInfoData data);
  /// No assignment operator
  GeneratorPdfInfoObj& operator=(const GeneratorPdfInfoObj&) = delete;
  virtual ~GeneratorPdfInfoObj() = default;

public:
  podio::ObjectID id;
  GeneratorPdfInfoData data;
};

} // namespace edm4hep

#endif
