// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticle_H
#define EDM4HEP_ReconstructedParticle_H

#include "edm4hep/ReconstructedParticleObj.h"

#include "edm4hep/Cluster.h"
#include "edm4hep/CovMatrix4f.h"
#include "edm4hep/Track.h"
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
class Vertex;
class MutableVertex;
} // namespace edm4hep

namespace edm4hep {

class MutableReconstructedParticle;
class ReconstructedParticleCollection;
class ReconstructedParticleCollectionData;

/** @class ReconstructedParticle
 *  Reconstructed Particle
 *  @author: EDM4hep authors
 */
class ReconstructedParticle {

  friend class MutableReconstructedParticle;
  friend class ReconstructedParticleCollection;
  friend class edm4hep::ReconstructedParticleCollectionData;
  friend class ReconstructedParticleCollectionIterator;

public:
  using mutable_type = MutableReconstructedParticle;
  using collection_type = ReconstructedParticleCollection;

  /// default constructor
  ReconstructedParticle();

  /// Constructor initializing all members
  ReconstructedParticle(std::int32_t PDG, float energy, edm4hep::Vector3f momentum, edm4hep::Vector3f referencePoint,
                        float charge, float mass, float goodnessOfPID, edm4hep::CovMatrix4f covMatrix);

  /// copy constructor
  ReconstructedParticle(const ReconstructedParticle& other) = default;

  /// copy-assignment operator
  ReconstructedParticle& operator=(ReconstructedParticle other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableReconstructedParticle clone(bool cloneRelations = true) const;

  /// destructor
  ~ReconstructedParticle() = default;

  /// converting constructor from mutable object
  ReconstructedParticle(const MutableReconstructedParticle& other);

  static ReconstructedParticle makeEmpty();

public:
  /// Access the PDG of the reconstructed particle.
  std::int32_t getPDG() const;

  /// Access the energy of the reconstructed particle. Four momentum state is not kept consistent internally [GeV]
  float getEnergy() const;

  /// Access the particle momentum. Four momentum state is not kept consistent internally [GeV]
  const edm4hep::Vector3f& getMomentum() const;

  /// Access the reference, i.e. where the particle has been measured [mm]
  const edm4hep::Vector3f& getReferencePoint() const;

  /// Access the charge of the reconstructed particle
  float getCharge() const;

  /// Access the mass of the reconstructed particle, set independently from four vector. Four momentum state is not kept
  /// consistent internally [GeV]
  float getMass() const;

  /// Access the overall goodness of the PID on a scale of [0;1]
  float getGoodnessOfPID() const;

  /// Access the covariance matrix of the reconstructed particle 4vector
  const edm4hep::CovMatrix4f& getCovMatrix() const;

  /// Access the start vertex associated to this particle
  const edm4hep::Vertex getStartVertex() const;

  std::size_t clusters_size() const;
  edm4hep::Cluster getClusters(std::size_t) const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_begin() const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_end() const;
  podio::RelationRange<edm4hep::Cluster> getClusters() const;
  std::size_t tracks_size() const;
  edm4hep::Track getTracks(std::size_t) const;
  std::vector<edm4hep::Track>::const_iterator tracks_begin() const;
  std::vector<edm4hep::Track>::const_iterator tracks_end() const;
  podio::RelationRange<edm4hep::Track> getTracks() const;
  std::size_t particles_size() const;
  edm4hep::ReconstructedParticle getParticles(std::size_t) const;
  std::vector<edm4hep::ReconstructedParticle>::const_iterator particles_begin() const;
  std::vector<edm4hep::ReconstructedParticle>::const_iterator particles_end() const;
  podio::RelationRange<edm4hep::ReconstructedParticle> getParticles() const;

  bool isCompound() const {
    return particles_size() > 0;
  }
  [[deprecated("use setPDG instead")]] int32_t getType() const {
    return getPDG();
  }
  /// Get the four momentum covariance matrix value for the two passed dimensions
  float getCovMatrix(edm4hep::FourMomCoords dimI, edm4hep::FourMomCoords dimJ) const {
    return getCovMatrix().getValue(dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ReconstructedParticleObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<ReconstructedParticleObj>{nullptr};
  }

  bool operator==(const ReconstructedParticle& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableReconstructedParticle& other) const;

  bool operator!=(const ReconstructedParticle& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableReconstructedParticle& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ReconstructedParticle& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(ReconstructedParticle& a, ReconstructedParticle& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing ReconstructedParticleObj
  explicit ReconstructedParticle(podio::utils::MaybeSharedPtr<ReconstructedParticleObj> obj);
  ReconstructedParticle(ReconstructedParticleObj* obj);

  podio::utils::MaybeSharedPtr<ReconstructedParticleObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const ReconstructedParticle& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ReconstructedParticle& value);
#endif

} // namespace edm4hep

#endif
