// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "podio/CollectionBufferFactory.h"
#include "podio/SchemaEvolution.h"

#include "edm4hep/ClusterCollection.h"
#include "edm4hep/DatamodelDefinition.h"

#include "edm4hep/CalorimeterHitCollection.h"
#include <numeric>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

// standard includes
#include <iomanip>
#include <stdexcept>

namespace edm4hep {

ClusterCollection::ClusterCollection() :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(false),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage() {
}

ClusterCollection::ClusterCollection(ClusterCollectionData&& data, bool isSubsetColl) :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(isSubsetColl),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage(std::move(data)) {
}

ClusterCollection::~ClusterCollection() {
  // Need to tell the storage how to clean-up
  m_storage.clear(m_isSubsetColl);
}

Cluster ClusterCollection::operator[](std::size_t index) const {
  return Cluster(m_storage.entries[index]);
}

Cluster ClusterCollection::at(std::size_t index) const {
  return Cluster(m_storage.entries.at(index));
}

MutableCluster ClusterCollection::operator[](std::size_t index) {
  return MutableCluster(podio::utils::MaybeSharedPtr(m_storage.entries[index]));
}

MutableCluster ClusterCollection::at(std::size_t index) {
  return MutableCluster(podio::utils::MaybeSharedPtr(m_storage.entries.at(index)));
}

std::size_t ClusterCollection::size() const {
  return m_storage.entries.size();
}

std::size_t ClusterCollection::max_size() const {
  return m_storage.entries.max_size();
}

bool ClusterCollection::empty() const {
  return m_storage.entries.empty();
}

void ClusterCollection::setSubsetCollection(bool setSubset) {
  if (m_isSubsetColl != setSubset && !m_storage.entries.empty()) {
    throw std::logic_error("Cannot change the character of a collection that already contains elements");
  }

  if (setSubset) {
    m_storage.makeSubsetCollection();
  }
  m_isSubsetColl = setSubset;
}

MutableCluster ClusterCollection::create() {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }

  auto obj = m_storage.entries.emplace_back(new ClusterObj());
  m_storage.createRelations(obj);

  obj->id = {int(m_storage.entries.size() - 1), m_collectionID};
  return MutableCluster(podio::utils::MaybeSharedPtr(obj));
}

void ClusterCollection::clear() {
  m_storage.clear(m_isSubsetColl);
  m_isPrepared = false;
}

void ClusterCollection::prepareForWrite() const {
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

void ClusterCollection::prepareAfterRead() {
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

bool ClusterCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  return m_storage.setReferences(collectionProvider, m_isSubsetColl);
}

void ClusterCollection::push_back(const MutableCluster& object) {
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

    push_back(Cluster(object));
  }
}

void ClusterCollection::push_back(const Cluster& object) {
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

podio::CollectionWriteBuffers ClusterCollection::getBuffers() {
  return m_storage.getCollectionBuffers(m_isSubsetColl);
}

std::vector<std::int32_t> ClusterCollection::type(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.type);
  }
  return tmp;
}

std::vector<float> ClusterCollection::energy(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.energy);
  }
  return tmp;
}

std::vector<float> ClusterCollection::energyError(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.energyError);
  }
  return tmp;
}

std::vector<edm4hep::Vector3f> ClusterCollection::position(const size_t nElem) const {
  std::vector<edm4hep::Vector3f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.position);
  }
  return tmp;
}

std::vector<edm4hep::CovMatrix3f> ClusterCollection::positionError(const size_t nElem) const {
  std::vector<edm4hep::CovMatrix3f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.positionError);
  }
  return tmp;
}

std::vector<float> ClusterCollection::iTheta(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.iTheta);
  }
  return tmp;
}

std::vector<float> ClusterCollection::phi(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.phi);
  }
  return tmp;
}

std::vector<edm4hep::Vector3f> ClusterCollection::directionError(const size_t nElem) const {
  std::vector<edm4hep::Vector3f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.directionError);
  }
  return tmp;
}

size_t ClusterCollection::getDatamodelRegistryIndex() const {
  return edm4hep::meta::DatamodelRegistryIndex::value();
}

podio::SchemaVersionT ClusterCollection::getSchemaVersion() const {
  return edm4hep::meta::schemaVersion;
}

// anonymous namespace for registration with the CollectionBufferFactory. This
// ensures that we don't have to make up arbitrary namespace names here, since
// none of this is publicly visible
namespace {

  podio::CollectionReadBuffers createBuffers(bool isSubset) {
    auto readBuffers = podio::CollectionReadBuffers{};
    readBuffers.type = "edm4hep::ClusterCollection";
    readBuffers.schemaVersion = edm4hep::meta::schemaVersion;
    readBuffers.data = isSubset ? nullptr : new ClusterDataContainer;
    // The number of ObjectID vectors is either 1 or the sum of OneToMany and
    // OneToOne relations
    const auto nRefs = isSubset ? 1 : 2 + 0;
    readBuffers.references = new podio::CollRefCollection(nRefs);
    for (auto& ref : *readBuffers.references) {
      // Make sure to place usable buffer pointers here
      ref = std::make_unique<std::vector<podio::ObjectID>>();
    }

    readBuffers.vectorMembers = new podio::VectorMembersInfo();
    if (!isSubset) {
      readBuffers.vectorMembers->reserve(2);
      readBuffers.vectorMembers->emplace_back("float", new std::vector<float>);
      readBuffers.vectorMembers->emplace_back("float", new std::vector<float>);
    }

    readBuffers.createCollection = [](const podio::CollectionReadBuffers& buffers, bool isSubsetColl) {
      ClusterCollectionData data(buffers, isSubsetColl);
      return std::make_unique<ClusterCollection>(std::move(data), isSubsetColl);
    };

    readBuffers.recast = [](podio::CollectionReadBuffers& buffers) {
      // We only have any of these buffers if this is not a subset collection
      if (buffers.data) {
        buffers.data = podio::CollectionWriteBuffers::asVector<edm4hep::ClusterData>(buffers.data);
        (*buffers.vectorMembers)[0].second =
            podio::CollectionWriteBuffers::asVector<float>((*buffers.vectorMembers)[0].second);
        (*buffers.vectorMembers)[1].second =
            podio::CollectionWriteBuffers::asVector<float>((*buffers.vectorMembers)[1].second);
      }
    };

    readBuffers.deleteBuffers = [](podio::CollectionReadBuffers& buffers) {
      if (buffers.data) {
        // If we have data then we are not a subset collection and we have to
        // clean up all type erased buffers by casting them back to something that
        // we can delete
        delete static_cast<edm4hep::ClusterDataContainer*>(buffers.data);
        delete static_cast<std::vector<float>*>((*buffers.vectorMembers)[0].second);
        delete static_cast<std::vector<float>*>((*buffers.vectorMembers)[1].second);
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
      factory.registerCreationFunc("edm4hep::ClusterCollection", edm4hep::meta::schemaVersion, createBuffers);

      // Make the SchemaEvolution aware of the current version by
      // registering a no-op function for this and all preceding versions
      // will be overridden whenever an explicit action is required
      for (unsigned int schemaVersion = 1; schemaVersion < edm4hep::meta::schemaVersion + 1; ++schemaVersion) {
        podio::SchemaEvolution::mutInstance().registerEvolutionFunc(
            "edm4hep::ClusterCollection", schemaVersion, edm4hep::meta::schemaVersion,
            podio::SchemaEvolution::noOpSchemaEvolution, podio::SchemaEvolution::Priority::AutoGenerated);
      }

      return true;
    }();
    return reg;
  }

  const auto registeredCollection = registerCollection();
} // namespace

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ClusterCollection& collection) {
  j = nlohmann::json::array();
  for (auto&& elem : collection) {
    j.emplace_back(elem);
  }
}
#endif

Cluster ClusterCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ClusterObj>((*m_collection)[m_index]);
  return m_object;
}

Cluster* ClusterCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ClusterObj>((*m_collection)[m_index]);
  return &m_object;
}

ClusterCollectionIterator& ClusterCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

MutableCluster ClusterMutableCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ClusterObj>((*m_collection)[m_index]);
  return m_object;
}

MutableCluster* ClusterMutableCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<ClusterObj>((*m_collection)[m_index]);
  return &m_object;
}

ClusterMutableCollectionIterator& ClusterMutableCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const ClusterCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:        type:      energy: energyError:                 position [ x, y, z]:positionError [ "
       "values]:      iTheta:         phi:           directionError [ x, y, z]:"
    << '\n';

  for (const auto&& el : v) {
    o << std::scientific << std::showpos << std::setw(12) << el.id() << " " << std::setw(12) << el.getType() << " "
      << std::setw(12) << el.getEnergy() << " " << std::setw(12) << el.getEnergyError() << " " << std::setw(12)
      << el.getPosition() << " " << std::setw(12) << el.getPositionError() << " " << std::setw(12) << el.getITheta()
      << " " << std::setw(12) << el.getPhi() << " " << std::setw(12) << el.getDirectionError() << " " << std::endl;

    o << "      clusters : ";
    for (unsigned j = 0, N = el.clusters_size(); j < N; ++j) {
      o << el.getClusters(j).id() << " ";
    }
    o << std::endl;
    o << "      hits : ";
    for (unsigned j = 0, N = el.hits_size(); j < N; ++j) {
      o << el.getHits(j).id() << " ";
    }
    o << std::endl;

    o << "      shapeParameters : ";
    for (unsigned j = 0, N = el.shapeParameters_size(); j < N; ++j) {
      o << el.getShapeParameters(j) << " ";
    }
    o << std::endl;
    o << "      subdetectorEnergies : ";
    for (unsigned j = 0, N = el.subdetectorEnergies_size(); j < N; ++j) {
      o << el.getSubdetectorEnergies(j) << " ";
    }
    o << std::endl;
  }

  o.flags(old_flags);
  return o;
}

void ClusterCollection::print(std::ostream& os, bool flush) const {
  os << *this;
  if (flush) {
    os.flush();
  }
}

} // namespace edm4hep
