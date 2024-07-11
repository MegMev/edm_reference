// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "podio/CollectionBufferFactory.h"
#include "podio/SchemaEvolution.h"

#include "edm4hep/DatamodelDefinition.h"
#include "edm4hep/TPCHitCollection.h"

#include <numeric>

// standard includes
#include <iomanip>
#include <stdexcept>

namespace edm4hep {

TPCHitCollection::TPCHitCollection() :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(false),
    m_collectionID(0),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage() {
}

TPCHitCollection::TPCHitCollection(TPCHitCollectionData&& data, bool isSubsetColl) :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(isSubsetColl),
    m_collectionID(0),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage(std::move(data)) {
}

TPCHitCollection::~TPCHitCollection() {
  // Need to tell the storage how to clean-up
  m_storage.clear(m_isSubsetColl);
}

TPCHit TPCHitCollection::operator[](std::size_t index) const {
  return TPCHit(m_storage.entries[index]);
}

TPCHit TPCHitCollection::at(std::size_t index) const {
  return TPCHit(m_storage.entries.at(index));
}

MutableTPCHit TPCHitCollection::operator[](std::size_t index) {
  return MutableTPCHit(m_storage.entries[index]);
}

MutableTPCHit TPCHitCollection::at(std::size_t index) {
  return MutableTPCHit(m_storage.entries.at(index));
}

std::size_t TPCHitCollection::size() const {
  return m_storage.entries.size();
}

void TPCHitCollection::setSubsetCollection(bool setSubset) {
  if (m_isSubsetColl != setSubset && !m_storage.entries.empty()) {
    throw std::logic_error("Cannot change the character of a collection that already contains elements");
  }

  if (setSubset) {
    m_storage.makeSubsetCollection();
  }
  m_isSubsetColl = setSubset;
}

MutableTPCHit TPCHitCollection::create() {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }

  auto obj = m_storage.entries.emplace_back(new TPCHitObj());
  m_storage.createRelations(obj);

  obj->id = {int(m_storage.entries.size() - 1), m_collectionID};
  return MutableTPCHit(obj);
}

void TPCHitCollection::clear() {
  m_storage.clear(m_isSubsetColl);
  m_isPrepared = false;
}

void TPCHitCollection::prepareForWrite() const {
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

void TPCHitCollection::prepareAfterRead() {
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

bool TPCHitCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  return m_storage.setReferences(collectionProvider, m_isSubsetColl);
}

void TPCHitCollection::push_back(TPCHit object) {
  // We have to do different things here depending on whether this is a
  // subset collection or not. A normal collection cannot collect objects
  // that are already part of another collection, while a subset collection
  // can only collect such objects
  if (!m_isSubsetColl) {
    auto obj = object.m_obj;
    if (obj->id.index == podio::ObjectID::untracked) {
      const auto size = m_storage.entries.size();
      obj->id = {(int)size, m_collectionID};
      m_storage.entries.push_back(obj);
      m_storage.createRelations(obj);
    } else {
      throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
    }
  } else {
    const auto obj = object.m_obj;
    if (obj->id.index < 0) {
      throw std::invalid_argument(
          "Objects can only be stored in a subset collection if they are already elements of a collection");
    }
    m_storage.entries.push_back(obj);
    // No need to handle any relations here, since this is already done by the
    // "owning" collection
  }
}

podio::CollectionWriteBuffers TPCHitCollection::getBuffers() {
  return m_storage.getCollectionBuffers(m_isSubsetColl);
}

std::vector<std::uint64_t> TPCHitCollection::cellID(const size_t nElem) const {
  std::vector<std::uint64_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.cellID);
  }
  return tmp;
}

std::vector<std::int32_t> TPCHitCollection::quality(const size_t nElem) const {
  std::vector<std::int32_t> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.quality);
  }
  return tmp;
}

std::vector<float> TPCHitCollection::time(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.time);
  }
  return tmp;
}

std::vector<float> TPCHitCollection::charge(const size_t nElem) const {
  std::vector<float> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.charge);
  }
  return tmp;
}

size_t TPCHitCollection::getDatamodelRegistryIndex() const {
  return edm4hep::meta::DatamodelRegistryIndex::value();
}

podio::SchemaVersionT TPCHitCollection::getSchemaVersion() const {
  return edm4hep::meta::schemaVersion;
}

// anonymous namespace for registration with the CollectionBufferFactory. This
// ensures that we don't have to make up arbitrary namespace names here, since
// none of this is publicly visible
namespace {
  podio::CollectionReadBuffers createBuffers(bool isSubset) {
    auto readBuffers = podio::CollectionReadBuffers{};
    readBuffers.type = "edm4hep::TPCHitCollection";
    readBuffers.schemaVersion = edm4hep::meta::schemaVersion;
    readBuffers.data = isSubset ? nullptr : new TPCHitDataContainer;

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
      readBuffers.vectorMembers->reserve(1);
      readBuffers.vectorMembers->emplace_back("std::int32_t", new std::vector<std::int32_t>);
    }

    readBuffers.createCollection = [](podio::CollectionReadBuffers buffers, bool isSubsetColl) {
      TPCHitCollectionData data(buffers, isSubsetColl);
      return std::make_unique<TPCHitCollection>(std::move(data), isSubsetColl);
    };

    readBuffers.recast = [](podio::CollectionReadBuffers& buffers) {
      // We only have any of these buffers if this is not a subset collection
      if (buffers.data) {
        buffers.data = podio::CollectionWriteBuffers::asVector<edm4hep::TPCHitData>(buffers.data);
        (*buffers.vectorMembers)[0].second =
            podio::CollectionWriteBuffers::asVector<std::int32_t>((*buffers.vectorMembers)[0].second);
      }
    };

    return readBuffers;
  }

  // The usual trick with an IIFE and a static variable inside a funtion and then
  // making sure to call that function during shared library loading
  bool registerCollection() {
    const static auto reg = []() {
      auto& factory = podio::CollectionBufferFactory::mutInstance();
      factory.registerCreationFunc("edm4hep::TPCHitCollection", edm4hep::meta::schemaVersion, createBuffers);

      return true;
    }();
    return reg;
  }

  const auto registeredCollection = registerCollection();
} // namespace

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TPCHitCollection& collection) {
  j = nlohmann::json::array();
  for (auto&& elem : collection) {
    j.emplace_back(elem);
  }
}
#endif

TPCHit TPCHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

TPCHit* TPCHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TPCHitCollectionIterator& TPCHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

MutableTPCHit TPCHitMutableCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

MutableTPCHit* TPCHitMutableCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TPCHitMutableCollectionIterator& TPCHitMutableCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const TPCHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:     quality:        time:      charge:" << '\n';

  for (const auto&& el : v) {
    o << std::scientific << std::showpos << std::setw(12) << el.id() << " " << std::setw(12) << el.getCellID() << " "
      << std::setw(12) << el.getQuality() << " " << std::setw(12) << el.getTime() << " " << std::setw(12)
      << el.getCharge() << " " << std::endl;

    o << "      rawDataWords : ";
    for (unsigned j = 0, N = el.rawDataWords_size(); j < N; ++j) {
      o << el.getRawDataWords(j) << " ";
    }
    o << std::endl;
  }

  o.flags(old_flags);
  return o;
}

void TPCHitCollection::print(std::ostream& os, bool flush) const {
  os << *this;
  if (flush) {
    os.flush();
  }
}

} // namespace edm4hep
