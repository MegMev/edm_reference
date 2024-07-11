// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "podio/CollectionBufferFactory.h"
#include "podio/SchemaEvolution.h"

#include "edm4hep/DatamodelDefinition.h"
#include "edm4hep/ReconstructedParticleCollection.h"

#include "edm4hep/ClusterCollection.h"
#include "edm4hep/TrackCollection.h"
#include "edm4hep/VertexCollection.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

// standard includes
#include <iomanip>
#include <stdexcept>

namespace edm4hep {

ReconstructedParticleCollection::ReconstructedParticleCollection() :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(false),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage() {
}

ReconstructedParticleCollection::ReconstructedParticleCollection(ReconstructedParticleCollectionData&& data,
                                                                 bool isSubsetColl) :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(isSubsetColl),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage(std::move(data)) {
}

ReconstructedParticleCollection::~ReconstructedParticleCollection() {
  // Need to tell the storage how to clean-up
  m_storage.clear(m_isSubsetColl);
}

ReconstructedParticle ReconstructedParticleCollection::operator[](std::size_t index) const {
  return ReconstructedParticle(m_storage.entries[index]);
}

ReconstructedParticle ReconstructedParticleCollection::at(std::size_t index) const {
  return ReconstructedParticle(m_storage.entries.at(index));
}

MutableReconstructedParticle ReconstructedParticleCollection::operator[](std::size_t index) {
  return MutableReconstructedParticle(podio::utils::MaybeSharedPtr(m_storage.entries[index]));
}

MutableReconstructedParticle ReconstructedParticleCollection::at(std::size_t index) {
  return MutableReconstructedParticle(podio::utils::MaybeSharedPtr(m_storage.entries.at(index)));
}

std::size_t ReconstructedParticleCollection::size() const {
  return m_storage.entries.size();
}

std::size_t ReconstructedParticleCollection::max_size() const {
  return m_storage.entries.max_size();
}

bool ReconstructedParticleCollection::empty() const {
  return m_storage.entries.empty();
}

void ReconstructedParticleCollection::setSubsetCollection(bool setSubset) {
  if (m_isSubsetColl != setSubset && !m_storage.entries.empty()) {
    throw std::logic_error("Cannot change the character of a collection that already contains elements");
  }

  if (setSubset) {
    m_storage.makeSubsetCollection();
  }
  m_isSubsetColl = setSubset;
}

MutableReconstructedParticle ReconstructedParticleCollection::create() {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }

  auto obj = m_storage.entries.emplace_back(new ReconstructedParticleObj());
  m_storage.createRelations(obj);

  obj->id = {int(m_storage.entries.size() - 1), m_collectionID};
  return MutableReconstructedParticle(podio::utils::MaybeSharedPtr(obj));
}

void ReconstructedParticleCollection::clear() {
  m_storage.clear(m_isSubsetColl);
  m_isPrepared = false;
}

void ReconstructedParticleCollection::prepareForWrite() const {
  // TODO: Replace this double locking pattern here with an atomic and only one
  // lock. Problem: std::atomic is not default movable.
  {
    std::lock_guard lock{*m_storageMtx};
    // If the collection has been prepared already there is nothing to do
    if (m_isPrepared) {
      return;
    }
  }

  std::lock_guard lock{*m_storageMtx};
  // by the time we acquire the lock another thread might have already
  // succeeded, so we need to check again now
  if (m_isPrepared) {
    return;
  }
  m_storage.prepareForWrite(m_isSubsetColl);
  m_isPrepared = true;
}

void ReconstructedParticleCollection::prepareAfterRead() {
  // No need to go through this again if we have already done it
  if (m_isPrepared) {
    return;
  }

  if (!m_isSubsetColl) {
    // Subset collections do not store any data that would require post-processing
    m_storage.prepareAfterRead(m_collectionID);
  }
  // Preparing a collection doesn't affect the underlying I/O buffers, so this
  // collection is still prepared
  m_isPrepared = true;
}

bool ReconstructedParticleCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  return m_storage.setReferences(collectionProvider, m_isSubsetColl);
}

void ReconstructedParticleCollection::push_back(const MutableReconstructedParticle& object) {
  // We have to do different things here depending on whether this is a
  // subset collection or not. A normal collection cannot collect objects
  // that are already part of another collection, while a subset collection
  // can only collect such objects
  if (!m_isSubsetColl) {
    auto obj = object.m_obj;
    if (obj->id.index == podio::ObjectID::untracked) {
      const auto size = m_storage.entries.size();
      obj->id = {(int)size, m_collectionID};
      m_storage.entries.push_back(obj.release());
      m_storage.createRelations(obj.get());
    } else {
      throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
    }
  } else {

    push_back(ReconstructedParticle(object));
  }
}

void ReconstructedParticleCollection::push_back(const ReconstructedParticle& object) {
  if (!m_isSubsetColl) {
    throw std::invalid_argument("Immutable objects can only be added to subset collections");
  }
  auto obj = object.m_obj;
  if (obj->id.index < 0) {
    // This path is only possible if we arrive here from an untracked Mutable object
    throw std::invalid_argument(
        "Object needs to be tracked by another collection in order for it to be storable in a subset collection");
  }
  m_storage.entries.push_back(obj.release());
}

podio::CollectionWriteBuffers ReconstructedParticleCollection::getBuffers() {
  return m_storage.getCollectionBuffers(m_isSubsetColl);
}

std::vector<std::int32_t> ReconstructedParticleCollection::PDG(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.PDG);
  }
  return tmp;
}

std::vector<float> ReconstructedParticleCollection::energy(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.energy);
  }
  return tmp;
}

std::vector<edm4hep::Vector3f> ReconstructedParticleCollection::momentum(const size_t nElem) const {
  std::vector<edm4hep::Vector3f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.momentum);
  }
  return tmp;
}

std::vector<edm4hep::Vector3f> ReconstructedParticleCollection::referencePoint(const size_t nElem) const {
  std::vector<edm4hep::Vector3f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.referencePoint);
  }
  return tmp;
}

std::vector<float> ReconstructedParticleCollection::charge(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.charge);
  }
  return tmp;
}

std::vector<float> ReconstructedParticleCollection::mass(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.mass);
  }
  return tmp;
}

std::vector<float> ReconstructedParticleCollection::goodnessOfPID(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.goodnessOfPID);
  }
  return tmp;
}

std::vector<edm4hep::CovMatrix4f> ReconstructedParticleCollection::covMatrix(const size_t nElem) const {
  std::vector<edm4hep::CovMatrix4f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.covMatrix);
  }
  return tmp;
}

size_t ReconstructedParticleCollection::getDatamodelRegistryIndex() const {
  return edm4hep::meta::DatamodelRegistryIndex::value();
}

podio::SchemaVersionT ReconstructedParticleCollection::getSchemaVersion() const {
  return edm4hep::meta::schemaVersion;
}

// anonymous namespace for registration with the CollectionBufferFactory. This
// ensures that we don't have to make up arbitrary namespace names here, since
// none of this is publicly visible
namespace {

  podio::CollectionReadBuffers createBuffers(bool isSubset) {
    auto readBuffers = podio::CollectionReadBuffers{};
    readBuffers.type = "edm4hep::ReconstructedParticleCollection";
    readBuffers.schemaVersion = edm4hep::meta::schemaVersion;
    readBuffers.data = isSubset ? nullptr : new ReconstructedParticleDataContainer;
    // The number of ObjectID vectors is either 1 or the sum of OneToMany and
    // OneToOne relations
    const auto nRefs = isSubset ? 1 : 3 + 1;
    readBuffers.references = new podio::CollRefCollection(nRefs);
    for (auto& ref : *readBuffers.references) {
      // Make sure to place usable buffer pointers here
      ref = std::make_unique<std::vector<podio::ObjectID>>();
    }

    readBuffers.vectorMembers = new podio::VectorMembersInfo();
    if (!isSubset) {
      readBuffers.vectorMembers->reserve(0);
    }

    readBuffers.createCollection = [](const podio::CollectionReadBuffers& buffers, bool isSubsetColl) {
      ReconstructedParticleCollectionData data(buffers, isSubsetColl);
      return std::make_unique<ReconstructedParticleCollection>(std::move(data), isSubsetColl);
    };

    readBuffers.recast = [](podio::CollectionReadBuffers& buffers) {
      // We only have any of these buffers if this is not a subset collection
      if (buffers.data) {
        buffers.data = podio::CollectionWriteBuffers::asVector<edm4hep::ReconstructedParticleData>(buffers.data);
      }
    };

    readBuffers.deleteBuffers = [](podio::CollectionReadBuffers& buffers) {
      if (buffers.data) {
        // If we have data then we are not a subset collection and we have to
        // clean up all type erased buffers by casting them back to something that
        // we can delete
        delete static_cast<edm4hep::ReconstructedParticleDataContainer*>(buffers.data);
      }
      delete buffers.references;
      delete buffers.vectorMembers;
    };

    return readBuffers;
  }

  // The usual trick with an IIFE and a static variable inside a function and then
  // making sure to call that function during shared library loading
  bool registerCollection() {
    const static auto reg = []() {
      auto& factory = podio::CollectionBufferFactory::mutInstance();
      factory.registerCreationFunc("edm4hep::ReconstructedParticleCollection", edm4hep::meta::schemaVersion,
                                   createBuffers);

      // Make the SchemaEvolution aware of the current version by
      // registering a no-op function for this and all preceding versions
      // will be overridden whenever an explicit action is required
      for (unsigned int schemaVersion = 1; schemaVersion < edm4hep::meta::schemaVersion + 1; ++schemaVersion) {
        podio::SchemaEvolution::mutInstance().registerEvolutionFunc(
            "edm4hep::ReconstructedParticleCollection", schemaVersion, edm4hep::meta::schemaVersion,
            podio::SchemaEvolution::noOpSchemaEvolution, podio::SchemaEvolution::Priority::AutoGenerated);
      }

      return true;
    }();
    return reg;
  }

  const auto registeredCollection = registerCollection();
} // namespace

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ReconstructedParticleCollection& collection) {
  j = nlohmann::json::array();
  for (auto&& elem : collection) {
    j.emplace_back(elem);
  }
}
#endif

ReconstructedParticle ReconstructedParticleCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ReconstructedParticleObj>((*m_collection)[m_index]);
  return m_object;
}

ReconstructedParticle* ReconstructedParticleCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ReconstructedParticleObj>((*m_collection)[m_index]);
  return &m_object;
}

ReconstructedParticleCollectionIterator& ReconstructedParticleCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

MutableReconstructedParticle ReconstructedParticleMutableCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ReconstructedParticleObj>((*m_collection)[m_index]);
  return m_object;
}

MutableReconstructedParticle* ReconstructedParticleMutableCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ReconstructedParticleObj>((*m_collection)[m_index]);
  return &m_object;
}

ReconstructedParticleMutableCollectionIterator& ReconstructedParticleMutableCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const ReconstructedParticleCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:         PDG:      energy:                 momentum [ x, y, z]:           referencePoint [ x, y, "
       "z]:      charge:        mass:goodnessOfPID:covMatrix [ values]:"
    << '\n';

  for (const auto&& el : v) {
    o << std::scientific << std::showpos << std::setw(12) << el.id() << " " << std::setw(12) << el.getPDG() << " "
      << std::setw(12) << el.getEnergy() << " " << std::setw(12) << el.getMomentum() << " " << std::setw(12)
      << el.getReferencePoint() << " " << std::setw(12) << el.getCharge() << " " << std::setw(12) << el.getMass() << " "
      << std::setw(12) << el.getGoodnessOfPID() << " " << std::setw(12) << el.getCovMatrix() << " " << std::endl;

    o << "      clusters : ";
    for (unsigned j = 0, N = el.clusters_size(); j < N; ++j) {
      o << el.getClusters(j).id() << " ";
    }
    o << std::endl;
    o << "      tracks : ";
    for (unsigned j = 0, N = el.tracks_size(); j < N; ++j) {
      o << el.getTracks(j).id() << " ";
    }
    o << std::endl;
    o << "      particles : ";
    for (unsigned j = 0, N = el.particles_size(); j < N; ++j) {
      o << el.getParticles(j).id() << " ";
    }
    o << std::endl;

    o << "      startVertex : ";
    o << el.getStartVertex().id() << std::endl;
  }

  o.flags(old_flags);
  return o;
}

void ReconstructedParticleCollection::print(std::ostream& os, bool flush) const {
  os << *this;
  if (flush) {
    os.flush();
  }
}

} // namespace edm4hep
