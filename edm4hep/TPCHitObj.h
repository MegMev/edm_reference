// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHitOBJ_H
#define EDM4HEP_TPCHitOBJ_H

// data model specific includes
#include "edm4hep/TPCHitData.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>

namespace edm4hep {

class TPCHit;

class TPCHitObj : public podio::ObjBase {
public:
  /// constructor
  TPCHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  TPCHitObj(const TPCHitObj&);
  /// constructor from ObjectID and TPCHitData
  /// does not initialize the internal relation containers
  TPCHitObj(const podio::ObjectID id, TPCHitData data);
  /// No assignment operator
  TPCHitObj& operator=(const TPCHitObj&) = delete;
  virtual ~TPCHitObj();

public:
  TPCHitData data;
  std::vector<std::int32_t>* m_rawDataWords{nullptr};
};

} // namespace edm4hep

#endif
