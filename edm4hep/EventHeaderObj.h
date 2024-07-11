// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeaderOBJ_H
#define EDM4HEP_EventHeaderOBJ_H

// data model specific includes
#include "edm4hep/EventHeaderData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class EventHeader;

class EventHeaderObj {
public:
  /// constructor
  EventHeaderObj();
  /// copy constructor (does a deep-copy of relation containers)
  EventHeaderObj(const EventHeaderObj&);
  /// constructor from ObjectID and EventHeaderData
  /// does not initialize the internal relation containers
  EventHeaderObj(const podio::ObjectID id, EventHeaderData data);
  /// No assignment operator
  EventHeaderObj& operator=(const EventHeaderObj&) = delete;
  virtual ~EventHeaderObj();

public:
  podio::ObjectID id;
  EventHeaderData data;
  std::vector<double>* m_weights{nullptr};
};

} // namespace edm4hep

#endif
