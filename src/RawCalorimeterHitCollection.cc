// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "podio/CollectionBufferFactory.h"
#include "podio/SchemaEvolution.h"

#include "edm4hep/DatamodelDefinition.h"
#include "edm4hep/RawCalorimeterHitCollection.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

// standard includes
#include <iomanip>
#include <stdexcept>

namespace edm4hep {

RawCalorimeterHitCollection::RawCalorimeterHitCollection() :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(false),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage() {
}

RawCalorimeterHitCollection::RawCalorimeterHitCollection(RawCalorimeterHitCollectionData&& data, bool isSubsetColl) :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(isSubsetColl),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage(std::move(data)) {
}

RawCalorimeterHitCollection::~RawCalorimeterHitCollection() {
  // Need to tell the storage how to clean-up
  m_storage.clear(m_isSubsetColl);
}

RawCalorimeterHit RawCalorimeterHitCollection::operator[](std::size_t index) const {
  return RawCalorimeterHit(m_storage.entries[index]);
}

RawCalorimeterHit RawCalorimeterHitCollection::at(std::size_t index) const {
  return RawCalorimeterHit(m_storage.entries.at(index));
}

MutableRawCalorimeterHit RawCalorimeterHitCollection::operator[](std::size_t index) {
  return MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr(m_storage.entries[index]));
}

MutableRawCalorimeterHit RawCalorimeterHitCollection::at(std::size_t index) {
  return MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr(m_storage.entries.at(index)));
}

std::size_t RawCalorimeterHitCollection::size() const {
  return m_storage.entries.size();
}

std::size_t RawCalorimeterHitCollection::max_size() const {
  return m_storage.entries.max_size();
}

bool RawCalorimeterHitCollection::empty() const {
  return m_storage.entries.empty();
}

void RawCalorimeterHitCollection::setSubsetCollection(bool setSubset) {
  if (m_isSubsetColl != setSubset && !m_storage.entries.empty()) {
    throw std::logic_error("Cannot change the character of a collection that already contains elements");
  }

  if (setSubset) {
    m_storage.makeSubsetCollection();
  }
  m_isSubsetColl = setSubset;
}

MutableRawCalorimeterHit RawCalorimeterHitCollection::create() {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }

  auto obj = m_storage.entries.emplace_back(new RawCalorimeterHitObj());

  obj->id = {int(m_storage.entries.size() - 1), m_collectionID};
  return MutableRawCalorimeterHit(podio::utils::MaybeSharedPtr(obj));
}

void RawCalorimeterHitCollection::clear() {
  m_storage.clear(m_isSubsetColl);
  m_isPrepared = false;
}

void RawCalorimeterHitCollection::prepareForWrite() const {
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

void RawCalorimeterHitCollection::prepareAfterRead() {
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

bool RawCalorimeterHitCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  return m_storage.setReferences(collectionProvider, m_isSubsetColl);
}

void RawCalorimeterHitCollection::push_back(const MutableRawCalorimeterHit& object) {
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
    } else {
      throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
    }
  } else {

    push_back(RawCalorimeterHit(object));
  }
}

void RawCalorimeterHitCollection::push_back(const RawCalorimeterHit& object) {
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

podio::CollectionWriteBuffers RawCalorimeterHitCollection::getBuffers() {
  return m_storage.getCollectionBuffers(m_isSubsetColl);
}

std::vector<std::uint64_t> RawCalorimeterHitCollection::cellID(const size_t nElem) const {
  std::vector<std::uint64_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.cellID);
  }
  return tmp;
}

std::vector<std::int32_t> RawCalorimeterHitCollection::amplitude(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.amplitude);
  }
  return tmp;
}

std::vector<std::int32_t> RawCalorimeterHitCollection::timeStamp(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.timeStamp);
  }
  return tmp;
}

size_t RawCalorimeterHitCollection::getDatamodelRegistryIndex() const {
  return edm4hep::meta::DatamodelRegistryIndex::value();
}

podio::SchemaVersionT RawCalorimeterHitCollection::getSchemaVersion() const {
  return edm4hep::meta::schemaVersion;
}

// anonymous namespace for registration with the CollectionBufferFactory. This
// ensures that we don't have to make up arbitrary namespace names here, since
// none of this is publicly visible
namespace {

  podio::CollectionReadBuffers createBuffers(bool isSubset) {
    auto readBuffers = podio::CollectionReadBuffers{};
    readBuffers.type = "edm4hep::RawCalorimeterHitCollection";
    readBuffers.schemaVersion = edm4hep::meta::schemaVersion;
    readBuffers.data = isSubset ? nullptr : new RawCalorimeterHitDataContainer;
    // The number of ObjectID vectors is either 1 or the sum of OneToMany and
    // OneToOne relations
    const auto nRefs = isSubset ? 1 : 0 + 0;
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
      RawCalorimeterHitCollectionData data(buffers, isSubsetColl);
      return std::make_unique<RawCalorimeterHitCollection>(std::move(data), isSubsetColl);
    };

    readBuffers.recast = [](podio::CollectionReadBuffers& buffers) {
      // We only have any of these buffers if this is not a subset collection
      if (buffers.data) {
        buffers.data = podio::CollectionWriteBuffers::asVector<edm4hep::RawCalorimeterHitData>(buffers.data);
      }
    };

    readBuffers.deleteBuffers = [](podio::CollectionReadBuffers& buffers) {
      if (buffers.data) {
        // If we have data then we are not a subset collection and we have to
        // clean up all type erased buffers by casting them back to something that
        // we can delete
        delete static_cast<edm4hep::RawCalorimeterHitDataContainer*>(buffers.data);
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
      factory.registerCreationFunc("edm4hep::RawCalorimeterHitCollection", edm4hep::meta::schemaVersion, createBuffers);

      // Make the SchemaEvolution aware of the current version by
      // registering a no-op function for this and all preceding versions
      // will be overridden whenever an explicit action is required
      for (unsigned int schemaVersion = 1; schemaVersion < edm4hep::meta::schemaVersion + 1; ++schemaVersion) {
        podio::SchemaEvolution::mutInstance().registerEvolutionFunc(
            "edm4hep::RawCalorimeterHitCollection", schemaVersion, edm4hep::meta::schemaVersion,
            podio::SchemaEvolution::noOpSchemaEvolution, podio::SchemaEvolution::Priority::AutoGenerated);
      }

      return true;
    }();
    return reg;
  }

  const auto registeredCollection = registerCollection();
} // namespace

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RawCalorimeterHitCollection& collection) {
  j = nlohmann::json::array();
  for (auto&& elem : collection) {
    j.emplace_back(elem);
  }
}
#endif

RawCalorimeterHit RawCalorimeterHitCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>((*m_collection)[m_index]);
  return m_object;
}

RawCalorimeterHit* RawCalorimeterHitCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>((*m_collection)[m_index]);
  return &m_object;
}

RawCalorimeterHitCollectionIterator& RawCalorimeterHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

MutableRawCalorimeterHit RawCalorimeterHitMutableCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>((*m_collection)[m_index]);
  return m_object;
}

MutableRawCalorimeterHit* RawCalorimeterHitMutableCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<RawCalorimeterHitObj>((*m_collection)[m_index]);
  return &m_object;
}

RawCalorimeterHitMutableCollectionIterator& RawCalorimeterHitMutableCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const RawCalorimeterHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:   amplitude:   timeStamp:" << '\n';

  for (const auto&& el : v) {
    o << std::scientific << std::showpos << std::setw(12) << el.id() << " " << std::setw(12) << el.getCellID() << " "
      << std::setw(12) << el.getAmplitude() << " " << std::setw(12) << el.getTimeStamp() << " " << std::endl;
  }

  o.flags(old_flags);
  return o;
}

void RawCalorimeterHitCollection::print(std::ostream& os, bool flush) const {
  os << *this;
  if (flush) {
    os.flush();
  }
}

} // namespace edm4hep
