// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_VertexOBJ_H
#define EDM4HEP_VertexOBJ_H

// data model specific includes
#include "edm4hep/VertexData.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>
// forward declarations
namespace edm4hep {
class ReconstructedParticle;
}

namespace edm4hep {

class Vertex;

class VertexObj {
public:
  /// constructor
  VertexObj();
  /// copy constructor (does a deep-copy of relation containers)
  VertexObj(const VertexObj&);
  /// constructor from ObjectID and VertexData
  /// does not initialize the internal relation containers
  VertexObj(const podio::ObjectID id, VertexData data);
  /// No assignment operator
  VertexObj& operator=(const VertexObj&) = delete;
  virtual ~VertexObj();

public:
  podio::ObjectID id;
  VertexData data;
  edm4hep::ReconstructedParticle* m_associatedParticle{nullptr};
  std::vector<float>* m_parameters{nullptr};
};

} // namespace edm4hep

#endif
