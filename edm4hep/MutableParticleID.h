// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableParticleID_H
#define EDM4HEP_MutableParticleID_H

#include "edm4hep/ParticleIDObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/ParticleID.h"

#include "podio/RelationRange.h"
#include <cstdint>
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

/** @class MutableParticleID
 *  ParticleID
 *  @author: EDM4hep authors
 */
class MutableParticleID {

  friend class ParticleIDCollection;
  friend class ParticleIDMutableCollectionIterator;
  friend class ParticleID;

public:
  using object_type = ParticleID;
  using collection_type = ParticleIDCollection;

  /// default constructor
  MutableParticleID();

  /// Constructor initializing all members
  MutableParticleID(std::int32_t type, std::int32_t PDG, std::int32_t algorithmType, float likelihood);

  /// copy constructor
  MutableParticleID(const MutableParticleID& other) = default;

  /// copy-assignment operator
  MutableParticleID& operator=(MutableParticleID other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableParticleID clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableParticleID() = default;

public:
  /// Access the userdefined type
  std::int32_t getType() const;

  /// Access the PDG code of this id - ( 999999 ) if unknown
  std::int32_t getPDG() const;

  /// Access the type of the algorithm/module that created this hypothesis
  std::int32_t getAlgorithmType() const;

  /// Access the likelihood of this hypothesis - in a user defined normalization
  float getLikelihood() const;

  /// Access the the particle from which this PID has been computed
  const edm4hep::ReconstructedParticle getParticle() const;

  /// Set the userdefined type
  void setType(std::int32_t value);
  /// Get mutable reference to userdefined type
  std::int32_t& getType();
  /// Get reference to userdefined type
  [[deprecated("use getType instead")]] std::int32_t& type();

  /// Set the PDG code of this id - ( 999999 ) if unknown
  void setPDG(std::int32_t value);
  /// Get mutable reference to PDG code of this id - ( 999999 ) if unknown
  std::int32_t& getPDG();
  /// Get reference to PDG code of this id - ( 999999 ) if unknown
  [[deprecated("use getPDG instead")]] std::int32_t& PDG();

  /// Set the type of the algorithm/module that created this hypothesis
  void setAlgorithmType(std::int32_t value);
  /// Get mutable reference to type of the algorithm/module that created this hypothesis
  std::int32_t& getAlgorithmType();
  /// Get reference to type of the algorithm/module that created this hypothesis
  [[deprecated("use getAlgorithmType instead")]] std::int32_t& algorithmType();

  /// Set the likelihood of this hypothesis - in a user defined normalization
  void setLikelihood(float value);
  /// Get mutable reference to likelihood of this hypothesis - in a user defined normalization
  float& getLikelihood();
  /// Get reference to likelihood of this hypothesis - in a user defined normalization
  [[deprecated("use getLikelihood instead")]] float& likelihood();

  /// Set the the particle from which this PID has been computed
  void setParticle(const edm4hep::ReconstructedParticle& value);

  void addToParameters(const float&);
  std::size_t parameters_size() const;
  float getParameters(std::size_t) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ParticleIDObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<ParticleIDObj>{nullptr};
  }

  bool operator==(const MutableParticleID& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const ParticleID& other) const;

  bool operator!=(const MutableParticleID& other) const {
    return !(*this == other);
  }
  bool operator!=(const ParticleID& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableParticleID& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableParticleID& a, MutableParticleID& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing ParticleIDObj
  explicit MutableParticleID(podio::utils::MaybeSharedPtr<ParticleIDObj> obj);

  podio::utils::MaybeSharedPtr<ParticleIDObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableParticleID& value);
#endif

} // namespace edm4hep

#endif
