// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecDqdxOBJ_H
#define EDM4HEP_RecDqdxOBJ_H

// data model specific includes
#include "edm4hep/RecDqdxData.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class Track;
}

namespace edm4hep {

class RecDqdx;

class RecDqdxObj {
public:
  /// constructor
  RecDqdxObj();
  /// copy constructor (does a deep-copy of relation containers)
  RecDqdxObj(const RecDqdxObj&);
  /// constructor from ObjectID and RecDqdxData
  /// does not initialize the internal relation containers
  RecDqdxObj(const podio::ObjectID id, RecDqdxData data);
  /// No assignment operator
  RecDqdxObj& operator=(const RecDqdxObj&) = delete;
  virtual ~RecDqdxObj();

public:
  podio::ObjectID id;
  RecDqdxData data;
  edm4hep::Track* m_track{nullptr};
};

} // namespace edm4hep

#endif
