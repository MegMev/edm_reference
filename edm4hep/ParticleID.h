// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleID_H
#define EDM4HEP_ParticleID_H

#include "edm4hep/ParticleIDObj.h"

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

class MutableParticleID;
class ParticleIDCollection;
class ParticleIDCollectionData;

/** @class ParticleID
 *  ParticleID
 *  @author: EDM4hep authors
 */
class ParticleID {

  friend class MutableParticleID;
  friend class ParticleIDCollection;
  friend class edm4hep::ParticleIDCollectionData;
  friend class ParticleIDCollectionIterator;

public:
  using mutable_type = MutableParticleID;
  using collection_type = ParticleIDCollection;

  /// default constructor
  ParticleID();

  /// Constructor initializing all members
  ParticleID(std::int32_t type, std::int32_t PDG, std::int32_t algorithmType, float likelihood);

  /// copy constructor
  ParticleID(const ParticleID& other) = default;

  /// copy-assignment operator
  ParticleID& operator=(ParticleID other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableParticleID clone(bool cloneRelations = true) const;

  /// destructor
  ~ParticleID() = default;

  /// converting constructor from mutable object
  ParticleID(const MutableParticleID& other);

  static ParticleID makeEmpty();

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

  bool operator==(const ParticleID& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableParticleID& other) const;

  bool operator!=(const ParticleID& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableParticleID& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ParticleID& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(ParticleID& a, ParticleID& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing ParticleIDObj
  explicit ParticleID(podio::utils::MaybeSharedPtr<ParticleIDObj> obj);
  ParticleID(ParticleIDObj* obj);

  podio::utils::MaybeSharedPtr<ParticleIDObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const ParticleID& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ParticleID& value);
#endif

} // namespace edm4hep

#endif
