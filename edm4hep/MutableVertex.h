// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableVertex_H
#define EDM4HEP_MutableVertex_H

#include "edm4hep/VertexObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/Vertex.h"

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

/** @class MutableVertex
 *  Vertex
 *  @author: EDM4hep authors
 */
class MutableVertex {

  friend class VertexCollection;
  friend class VertexMutableCollectionIterator;
  friend class Vertex;

public:
  using object_type = Vertex;
  using collection_type = VertexCollection;

  /// default constructor
  MutableVertex();

  /// Constructor initializing all members
  MutableVertex(std::int32_t primary, float chi2, std::int32_t ndf, edm4hep::Vector3f position,
                edm4hep::CovMatrix3f covMatrix, std::int32_t algorithmType);

  /// copy constructor
  MutableVertex(const MutableVertex& other) = default;

  /// copy-assignment operator
  MutableVertex& operator=(MutableVertex other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableVertex clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableVertex() = default;

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

  /// Set the boolean flag, if vertex is the primary vertex of the event
  void setPrimary(std::int32_t value);
  /// Get mutable reference to boolean flag, if vertex is the primary vertex of the event
  std::int32_t& getPrimary();
  /// Get reference to boolean flag, if vertex is the primary vertex of the event
  [[deprecated("use getPrimary instead")]] std::int32_t& primary();

  /// Set the chi-squared of the vertex fit
  void setChi2(float value);
  /// Get mutable reference to chi-squared of the vertex fit
  float& getChi2();
  /// Get reference to chi-squared of the vertex fit
  [[deprecated("use getChi2 instead")]] float& chi2();

  /// Set the number of degrees of freedom of the vertex fit
  void setNdf(std::int32_t value);
  /// Get mutable reference to number of degrees of freedom of the vertex fit
  std::int32_t& getNdf();
  /// Get reference to number of degrees of freedom of the vertex fit
  [[deprecated("use getNdf instead")]] std::int32_t& ndf();

  /// Set the [mm] position of the vertex
  void setPosition(edm4hep::Vector3f value);
  /// Get mutable reference to [mm] position of the vertex
  edm4hep::Vector3f& getPosition();
  /// Get reference to [mm] position of the vertex
  [[deprecated("use getPosition instead")]] edm4hep::Vector3f& position();

  /// Set the covariance matrix of the position
  void setCovMatrix(edm4hep::CovMatrix3f value);
  /// Get mutable reference to covariance matrix of the position
  edm4hep::CovMatrix3f& getCovMatrix();
  /// Get reference to covariance matrix of the position
  [[deprecated("use getCovMatrix instead")]] edm4hep::CovMatrix3f& covMatrix();

  /// Set the type code for the algorithm that has been used to create the vertex
  void setAlgorithmType(std::int32_t value);
  /// Get mutable reference to type code for the algorithm that has been used to create the vertex
  std::int32_t& getAlgorithmType();
  /// Get reference to type code for the algorithm that has been used to create the vertex
  [[deprecated("use getAlgorithmType instead")]] std::int32_t& algorithmType();

  /// Set the reconstructed particle associated to this vertex
  void setAssociatedParticle(const edm4hep::ReconstructedParticle& value);

  void addToParameters(const float&);
  std::size_t parameters_size() const;
  float getParameters(std::size_t) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;

  /// Get the position covariance matrix value for the two passed dimensions
  float getCovMatrix(edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) const {
    return getCovMatrix().getValue(dimI, dimJ);
  }

  /// Set the position covariance matrix value for the two passed dimensions
  void setCovMatrix(float value, edm4hep::Cartesian dimI, edm4hep::Cartesian dimJ) {
    getCovMatrix().setValue(value, dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from VertexObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<VertexObj>{nullptr};
  }

  bool operator==(const MutableVertex& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const Vertex& other) const;

  bool operator!=(const MutableVertex& other) const {
    return !(*this == other);
  }
  bool operator!=(const Vertex& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableVertex& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableVertex& a, MutableVertex& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing VertexObj
  explicit MutableVertex(podio::utils::MaybeSharedPtr<VertexObj> obj);

  podio::utils::MaybeSharedPtr<VertexObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableVertex& value);
#endif

} // namespace edm4hep

#endif
