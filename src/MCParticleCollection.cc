// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "podio/CollectionBufferFactory.h"
#include "podio/SchemaEvolution.h"

#include "edm4hep/DatamodelDefinition.h"
#include "edm4hep/MCParticleCollection.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

// standard includes
#include <iomanip>
#include <stdexcept>

namespace edm4hep {

MCParticleCollection::MCParticleCollection() :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(false),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage() {
}

MCParticleCollection::MCParticleCollection(MCParticleCollectionData&& data, bool isSubsetColl) :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(isSubsetColl),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage(std::move(data)) {
}

MCParticleCollection::~MCParticleCollection() {
  // Need to tell the storage how to clean-up
  m_storage.clear(m_isSubsetColl);
}

MCParticle MCParticleCollection::operator[](std::size_t index) const {
  return MCParticle(m_storage.entries[index]);
}

MCParticle MCParticleCollection::at(std::size_t index) const {
  return MCParticle(m_storage.entries.at(index));
}

MutableMCParticle MCParticleCollection::operator[](std::size_t index) {
  return MutableMCParticle(podio::utils::MaybeSharedPtr(m_storage.entries[index]));
}

MutableMCParticle MCParticleCollection::at(std::size_t index) {
  return MutableMCParticle(podio::utils::MaybeSharedPtr(m_storage.entries.at(index)));
}

std::size_t MCParticleCollection::size() const {
  return m_storage.entries.size();
}

std::size_t MCParticleCollection::max_size() const {
  return m_storage.entries.max_size();
}

bool MCParticleCollection::empty() const {
  return m_storage.entries.empty();
}

void MCParticleCollection::setSubsetCollection(bool setSubset) {
  if (m_isSubsetColl != setSubset && !m_storage.entries.empty()) {
    throw std::logic_error("Cannot change the character of a collection that already contains elements");
  }

  if (setSubset) {
    m_storage.makeSubsetCollection();
  }
  m_isSubsetColl = setSubset;
}

MutableMCParticle MCParticleCollection::create() {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }

  auto obj = m_storage.entries.emplace_back(new MCParticleObj());
  m_storage.createRelations(obj);

  obj->id = {int(m_storage.entries.size() - 1), m_collectionID};
  return MutableMCParticle(podio::utils::MaybeSharedPtr(obj));
}

void MCParticleCollection::clear() {
  m_storage.clear(m_isSubsetColl);
  m_isPrepared = false;
}

void MCParticleCollection::prepareForWrite() const {
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

void MCParticleCollection::prepareAfterRead() {
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

bool MCParticleCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  return m_storage.setReferences(collectionProvider, m_isSubsetColl);
}

void MCParticleCollection::push_back(const MutableMCParticle& object) {
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

    push_back(MCParticle(object));
  }
}

void MCParticleCollection::push_back(const MCParticle& object) {
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

podio::CollectionWriteBuffers MCParticleCollection::getBuffers() {
  return m_storage.getCollectionBuffers(m_isSubsetColl);
}

std::vector<std::int32_t> MCParticleCollection::PDG(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.PDG);
  }
  return tmp;
}

std::vector<std::int32_t> MCParticleCollection::generatorStatus(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.generatorStatus);
  }
  return tmp;
}

std::vector<std::int32_t> MCParticleCollection::simulatorStatus(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.simulatorStatus);
  }
  return tmp;
}

std::vector<float> MCParticleCollection::charge(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.charge);
  }
  return tmp;
}

std::vector<float> MCParticleCollection::time(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.time);
  }
  return tmp;
}

std::vector<double> MCParticleCollection::mass(const size_t nElem) const {
  std::vector<double> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.mass);
  }
  return tmp;
}

std::vector<edm4hep::Vector3d> MCParticleCollection::vertex(const size_t nElem) const {
  std::vector<edm4hep::Vector3d> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.vertex);
  }
  return tmp;
}

std::vector<edm4hep::Vector3d> MCParticleCollection::endpoint(const size_t nElem) const {
  std::vector<edm4hep::Vector3d> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.endpoint);
  }
  return tmp;
}

std::vector<edm4hep::Vector3d> MCParticleCollection::momentum(const size_t nElem) const {
  std::vector<edm4hep::Vector3d> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.momentum);
  }
  return tmp;
}

std::vector<edm4hep::Vector3d> MCParticleCollection::momentumAtEndpoint(const size_t nElem) const {
  std::vector<edm4hep::Vector3d> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.momentumAtEndpoint);
  }
  return tmp;
}

std::vector<edm4hep::Vector3f> MCParticleCollection::spin(const size_t nElem) const {
  std::vector<edm4hep::Vector3f> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.spin);
  }
  return tmp;
}

std::vector<edm4hep::Vector2i> MCParticleCollection::colorFlow(const size_t nElem) const {
  std::vector<edm4hep::Vector2i> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.colorFlow);
  }
  return tmp;
}

size_t MCParticleCollection::getDatamodelRegistryIndex() const {
  return edm4hep::meta::DatamodelRegistryIndex::value();
}

podio::SchemaVersionT MCParticleCollection::getSchemaVersion() const {
  return edm4hep::meta::schemaVersion;
}

// anonymous namespace for registration with the CollectionBufferFactory. This
// ensures that we don't have to make up arbitrary namespace names here, since
// none of this is publicly visible
namespace {

  podio::CollectionReadBuffers createBuffers(bool isSubset) {
    auto readBuffers = podio::CollectionReadBuffers{};
    readBuffers.type = "edm4hep::MCParticleCollection";
    readBuffers.schemaVersion = edm4hep::meta::schemaVersion;
    readBuffers.data = isSubset ? nullptr : new MCParticleDataContainer;
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
      readBuffers.vectorMembers->reserve(0);
    }

    readBuffers.createCollection = [](const podio::CollectionReadBuffers& buffers, bool isSubsetColl) {
      MCParticleCollectionData data(buffers, isSubsetColl);
      return std::make_unique<MCParticleCollection>(std::move(data), isSubsetColl);
    };

    readBuffers.recast = [](podio::CollectionReadBuffers& buffers) {
      // We only have any of these buffers if this is not a subset collection
      if (buffers.data) {
        buffers.data = podio::CollectionWriteBuffers::asVector<edm4hep::MCParticleData>(buffers.data);
      }
    };

    readBuffers.deleteBuffers = [](podio::CollectionReadBuffers& buffers) {
      if (buffers.data) {
        // If we have data then we are not a subset collection and we have to
        // clean up all type erased buffers by casting them back to something that
        // we can delete
        delete static_cast<edm4hep::MCParticleDataContainer*>(buffers.data);
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
      factory.registerCreationFunc("edm4hep::MCParticleCollection", edm4hep::meta::schemaVersion, createBuffers);

      // Make the SchemaEvolution aware of the current version by
      // registering a no-op function for this and all preceding versions
      // will be overridden whenever an explicit action is required
      for (unsigned int schemaVersion = 1; schemaVersion < edm4hep::meta::schemaVersion + 1; ++schemaVersion) {
        podio::SchemaEvolution::mutInstance().registerEvolutionFunc(
            "edm4hep::MCParticleCollection", schemaVersion, edm4hep::meta::schemaVersion,
            podio::SchemaEvolution::noOpSchemaEvolution, podio::SchemaEvolution::Priority::AutoGenerated);
      }

      return true;
    }();
    return reg;
  }

  const auto registeredCollection = registerCollection();
} // namespace

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCParticleCollection& collection) {
  j = nlohmann::json::array();
  for (auto&& elem : collection) {
    j.emplace_back(elem);
  }
}
#endif

MCParticle MCParticleCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<MCParticleObj>((*m_collection)[m_index]);
  return m_object;
}

MCParticle* MCParticleCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<MCParticleObj>((*m_collection)[m_index]);
  return &m_object;
}

MCParticleCollectionIterator& MCParticleCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

MutableMCParticle MCParticleMutableCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<MCParticleObj>((*m_collection)[m_index]);
  return m_object;
}

MutableMCParticle* MCParticleMutableCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<MCParticleObj>((*m_collection)[m_index]);
  return &m_object;
}

MCParticleMutableCollectionIterator& MCParticleMutableCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const MCParticleCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:         PDG:generatorStatus:simulatorStatus:      charge:        time:        mass:              "
       "     vertex [ x, y, z]:                 endpoint [ x, y, z]:                 momentum [ x, y, z]:       "
       "momentumAtEndpoint [ x, y, z]:                     spin [ x, y, z]:       colorFlow [ a, b]:"
    << '\n';

  for (const auto&& el : v) {
    o << std::scientific << std::showpos << std::setw(12) << el.id() << " " << std::setw(12) << el.getPDG() << " "
      << std::setw(12) << el.getGeneratorStatus() << " " << std::setw(12) << el.getSimulatorStatus() << " "
      << std::setw(12) << el.getCharge() << " " << std::setw(12) << el.getTime() << " " << std::setw(12) << el.getMass()
      << " " << std::setw(12) << el.getVertex() << " " << std::setw(12) << el.getEndpoint() << " " << std::setw(12)
      << el.getMomentum() << " " << std::setw(12) << el.getMomentumAtEndpoint() << " " << std::setw(12) << el.getSpin()
      << " " << std::setw(12) << el.getColorFlow() << " " << std::endl;

    o << "      parents : ";
    for (unsigned j = 0, N = el.parents_size(); j < N; ++j) {
      o << el.getParents(j).id() << " ";
    }
    o << std::endl;
    o << "      daughters : ";
    for (unsigned j = 0, N = el.daughters_size(); j < N; ++j) {
      o << el.getDaughters(j).id() << " ";
    }
    o << std::endl;
  }

  o.flags(old_flags);
  return o;
}

void MCParticleCollection::print(std::ostream& os, bool flush) const {
  os << *this;
  if (flush) {
    os.flush();
  }
}

} // namespace edm4hep
