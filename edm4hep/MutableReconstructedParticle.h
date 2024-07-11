// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableReconstructedParticle_H
#define EDM4HEP_MutableReconstructedParticle_H

#include "edm4hep/ReconstructedParticleObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/ReconstructedParticle.h"

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

/** @class MutableReconstructedParticle
 *  Reconstructed Particle
 *  @author: EDM4hep authors
 */
class MutableReconstructedParticle {

  friend class ReconstructedParticleCollection;
  friend class ReconstructedParticleMutableCollectionIterator;
  friend class ReconstructedParticle;

public:
  using object_type = ReconstructedParticle;
  using collection_type = ReconstructedParticleCollection;

  /// default constructor
  MutableReconstructedParticle();

  /// Constructor initializing all members
  MutableReconstructedParticle(std::int32_t PDG, float energy, edm4hep::Vector3f momentum,
                               edm4hep::Vector3f referencePoint, float charge, float mass, float goodnessOfPID,
                               edm4hep::CovMatrix4f covMatrix);

  /// copy constructor
  MutableReconstructedParticle(const MutableReconstructedParticle& other) = default;

  /// copy-assignment operator
  MutableReconstructedParticle& operator=(MutableReconstructedParticle other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableReconstructedParticle clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableReconstructedParticle() = default;

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

  /// Set the PDG of the reconstructed particle.
  void setPDG(std::int32_t value);
  /// Get mutable reference to PDG of the reconstructed particle.
  std::int32_t& getPDG();
  /// Get reference to PDG of the reconstructed particle.
  [[deprecated("use getPDG instead")]] std::int32_t& PDG();

  /// Set the energy of the reconstructed particle. Four momentum state is not kept consistent internally [GeV]
  void setEnergy(float value);
  /// Get mutable reference to energy of the reconstructed particle. Four momentum state is not kept consistent
  /// internally [GeV]
  float& getEnergy();
  /// Get reference to energy of the reconstructed particle. Four momentum state is not kept consistent internally [GeV]
  [[deprecated("use getEnergy instead")]] float& energy();

  /// Set the particle momentum. Four momentum state is not kept consistent internally [GeV]
  void setMomentum(edm4hep::Vector3f value);
  /// Get mutable reference to particle momentum. Four momentum state is not kept consistent internally [GeV]
  edm4hep::Vector3f& getMomentum();
  /// Get reference to particle momentum. Four momentum state is not kept consistent internally [GeV]
  [[deprecated("use getMomentum instead")]] edm4hep::Vector3f& momentum();

  /// Set the reference, i.e. where the particle has been measured [mm]
  void setReferencePoint(edm4hep::Vector3f value);
  /// Get mutable reference to reference, i.e. where the particle has been measured [mm]
  edm4hep::Vector3f& getReferencePoint();
  /// Get reference to reference, i.e. where the particle has been measured [mm]
  [[deprecated("use getReferencePoint instead")]] edm4hep::Vector3f& referencePoint();

  /// Set the charge of the reconstructed particle
  void setCharge(float value);
  /// Get mutable reference to charge of the reconstructed particle
  float& getCharge();
  /// Get reference to charge of the reconstructed particle
  [[deprecated("use getCharge instead")]] float& charge();

  /// Set the mass of the reconstructed particle, set independently from four vector. Four momentum state is not kept
  /// consistent internally [GeV]
  void setMass(float value);
  /// Get mutable reference to mass of the reconstructed particle, set independently from four vector. Four momentum
  /// state is not kept consistent internally [GeV]
  float& getMass();
  /// Get reference to mass of the reconstructed particle, set independently from four vector. Four momentum state is
  /// not kept consistent internally [GeV]
  [[deprecated("use getMass instead")]] float& mass();

  /// Set the overall goodness of the PID on a scale of [0;1]
  void setGoodnessOfPID(float value);
  /// Get mutable reference to overall goodness of the PID on a scale of [0;1]
  float& getGoodnessOfPID();
  /// Get reference to overall goodness of the PID on a scale of [0;1]
  [[deprecated("use getGoodnessOfPID instead")]] float& goodnessOfPID();

  /// Set the covariance matrix of the reconstructed particle 4vector
  void setCovMatrix(edm4hep::CovMatrix4f value);
  /// Get mutable reference to covariance matrix of the reconstructed particle 4vector
  edm4hep::CovMatrix4f& getCovMatrix();
  /// Get reference to covariance matrix of the reconstructed particle 4vector
  [[deprecated("use getCovMatrix instead")]] edm4hep::CovMatrix4f& covMatrix();

  /// Set the start vertex associated to this particle
  void setStartVertex(const edm4hep::Vertex& value);

  void addToClusters(const edm4hep::Cluster&);
  std::size_t clusters_size() const;
  edm4hep::Cluster getClusters(std::size_t) const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_begin() const;
  std::vector<edm4hep::Cluster>::const_iterator clusters_end() const;
  podio::RelationRange<edm4hep::Cluster> getClusters() const;
  void addToTracks(const edm4hep::Track&);
  std::size_t tracks_size() const;
  edm4hep::Track getTracks(std::size_t) const;
  std::vector<edm4hep::Track>::const_iterator tracks_begin() const;
  std::vector<edm4hep::Track>::const_iterator tracks_end() const;
  podio::RelationRange<edm4hep::Track> getTracks() const;
  void addToParticles(const edm4hep::ReconstructedParticle&);
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

  // vertex where the particle decays. This method actually returns the start vertex from the first daughter particle
  // found.
  // TODO: edm4hep::Vertex  getEndVertex() { return  edm4hep::Vertex(  (getParticles(0).isAvailable() ?
  // getParticles(0).getStartVertex() :  edm4hep::Vertex(0,0) ) ) ; }
  [[deprecated("use setPDG instead")]] void setType(int32_t pdg) {
    setPDG(pdg);
  }
  /// Set the four momentum covariance matrix value for the two passed dimensions
  void setCovMatrix(float value, edm4hep::FourMomCoords dimI, edm4hep::FourMomCoords dimJ) {
    getCovMatrix().setValue(value, dimI, dimJ);
  }

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ReconstructedParticleObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<ReconstructedParticleObj>{nullptr};
  }

  bool operator==(const MutableReconstructedParticle& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const ReconstructedParticle& other) const;

  bool operator!=(const MutableReconstructedParticle& other) const {
    return !(*this == other);
  }
  bool operator!=(const ReconstructedParticle& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableReconstructedParticle& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableReconstructedParticle& a, MutableReconstructedParticle& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing ReconstructedParticleObj
  explicit MutableReconstructedParticle(podio::utils::MaybeSharedPtr<ReconstructedParticleObj> obj);

  podio::utils::MaybeSharedPtr<ReconstructedParticleObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableReconstructedParticle& value);
#endif

} // namespace edm4hep

#endif
