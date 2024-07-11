// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vertex_H
#define EDM4HEP_Vertex_H

#include "edm4hep/VertexObj.h"

#include "edm4hep/CovMatrix3f.h"
#include "edm4hep/Vector3f.h"
#include "podio/RelationRange.h"
#include <cstdint>
#include <edm4hep/Constants.h>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class MutableReconstructedParticle;
} // namespace edm4hep

namespace edm4hep {

class MutableVertex;
class VertexCollection;
class VertexCollectionData;

/** @class Vertex
 *  Vertex
 *  @author: EDM4hep authors
 */
class Vertex {

  friend class MutableVertex;
  friend class VertexCollection;
  friend class edm4hep::VertexCollectionData;
  friend class VertexCollectionIterator;

public:
  using mutable_type = MutableVertex;
  using collection_type = VertexCollection;

  /// default constructor
  Vertex();

  /// Constructor initializing all members
  Vertex(std::int32_t primary, float chi2, std::int32_t ndf, edm4hep::Vector3f position, edm4hep::CovMatrix3f covMatrix,
         std::int32_t algorithmType);

  /// copy constructor
  Vertex(const Vertex& other) = default;

  /// copy-assignment operator
  Vertex& operator=(Vertex other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableVertex clone(bool cloneRelations = true) const;

  /// destructor
  ~Vertex() = default;

  /// converting constructor from mutable object
  Vertex(const MutableVertex& other);

  static Vertex makeEmpty();

public:
  /// Access the boolean flag, if vertex is the primary vertex of the event
  std::int32_t getPrimary() const;

  /// Access the chi-squared of the vertex fit
  float getChi2() const;

  /// Access the number of degrees of freedom of the vertex fit
  std::int32_t getNdf() const;

  /// Access the [mm] position of the vertex
  const edm4hep::Vector3f& getPosition() const;

  /// Access the covariance matrix of the position
  const edm4hep::CovMatrix3f& getCovMatrix() const;

  /// Access the type code for the algorithm that has been used to create the vertex
  std::int32_t getAlgorithmType() const;

  /// Access the reconstructed particle associated to this vertex
  const edm4hep::ReconstructedParticle getAssociatedParticle() const;

  std::size_t parameters_size() const;
  float getParameters(std::size_t) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;

  /// Get the position covariance matrix value for the two passed dimensions
  float getCovMatrix(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getCovMatrix().getValue(dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from VertexObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<VertexObj>{nullptr};
  }

  bool operator==(const Vertex& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableVertex& other) const;

  bool operator!=(const Vertex& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableVertex& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const Vertex& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(Vertex& a, Vertex& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing VertexObj
  explicit Vertex(podio::utils::MaybeSharedPtr<VertexObj> obj);
  Vertex(VertexObj* obj);

  podio::utils::MaybeSharedPtr<VertexObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const Vertex& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const Vertex& value);
#endif

} // namespace edm4hep

#endif
