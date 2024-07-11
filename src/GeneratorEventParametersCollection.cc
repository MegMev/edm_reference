// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "podio/CollectionBufferFactory.h"
#include "podio/SchemaEvolution.h"

#include "edm4hep/DatamodelDefinition.h"
#include "edm4hep/GeneratorEventParametersCollection.h"

#include "edm4hep/MCParticleCollection.h"
#include <numeric>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

// standard includes
#include <iomanip>
#include <stdexcept>

namespace edm4hep {

GeneratorEventParametersCollection::GeneratorEventParametersCollection() :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(false),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage() {
}

GeneratorEventParametersCollection::GeneratorEventParametersCollection(GeneratorEventParametersCollectionData&& data,
                                                                       bool isSubsetColl) :
    m_isValid(false),
    m_isPrepared(false),
    m_isSubsetColl(isSubsetColl),
    m_collectionID(podio::ObjectID::untracked),
    m_storageMtx(std::make_unique<std::mutex>()),
    m_storage(std::move(data)) {
}

GeneratorEventParametersCollection::~GeneratorEventParametersCollection() {
  // Need to tell the storage how to clean-up
  m_storage.clear(m_isSubsetColl);
}

GeneratorEventParameters GeneratorEventParametersCollection::operator[](std::size_t index) const {
  return GeneratorEventParameters(m_storage.entries[index]);
}

GeneratorEventParameters GeneratorEventParametersCollection::at(std::size_t index) const {
  return GeneratorEventParameters(m_storage.entries.at(index));
}

MutableGeneratorEventParameters GeneratorEventParametersCollection::operator[](std::size_t index) {
  return MutableGeneratorEventParameters(podio::utils::MaybeSharedPtr(m_storage.entries[index]));
}

MutableGeneratorEventParameters GeneratorEventParametersCollection::at(std::size_t index) {
  return MutableGeneratorEventParameters(podio::utils::MaybeSharedPtr(m_storage.entries.at(index)));
}

std::size_t GeneratorEventParametersCollection::size() const {
  return m_storage.entries.size();
}

std::size_t GeneratorEventParametersCollection::max_size() const {
  return m_storage.entries.max_size();
}

bool GeneratorEventParametersCollection::empty() const {
  return m_storage.entries.empty();
}

void GeneratorEventParametersCollection::setSubsetCollection(bool setSubset) {
  if (m_isSubsetColl != setSubset && !m_storage.entries.empty()) {
    throw std::logic_error("Cannot change the character of a collection that already contains elements");
  }

  if (setSubset) {
    m_storage.makeSubsetCollection();
  }
  m_isSubsetColl = setSubset;
}

MutableGeneratorEventParameters GeneratorEventParametersCollection::create() {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }

  auto obj = m_storage.entries.emplace_back(new GeneratorEventParametersObj());
  m_storage.createRelations(obj);

  obj->id = {int(m_storage.entries.size() - 1), m_collectionID};
  return MutableGeneratorEventParameters(podio::utils::MaybeSharedPtr(obj));
}

void GeneratorEventParametersCollection::clear() {
  m_storage.clear(m_isSubsetColl);
  m_isPrepared = false;
}

void GeneratorEventParametersCollection::prepareForWrite() const {
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

void GeneratorEventParametersCollection::prepareAfterRead() {
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

bool GeneratorEventParametersCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  return m_storage.setReferences(collectionProvider, m_isSubsetColl);
}

void GeneratorEventParametersCollection::push_back(const MutableGeneratorEventParameters& object) {
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

    push_back(GeneratorEventParameters(object));
  }
}

void GeneratorEventParametersCollection::push_back(const GeneratorEventParameters& object) {
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

podio::CollectionWriteBuffers GeneratorEventParametersCollection::getBuffers() {
  return m_storage.getCollectionBuffers(m_isSubsetColl);
}

std::vector<double> GeneratorEventParametersCollection::eventScale(const size_t nElem) const {
  std::vector<double> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.eventScale);
  }
  return tmp;
}

std::vector<double> GeneratorEventParametersCollection::alphaQED(const size_t nElem) const {
  std::vector<double> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.alphaQED);
  }
  return tmp;
}

std::vector<double> GeneratorEventParametersCollection::alphaQCD(const size_t nElem) const {
  std::vector<double> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.alphaQCD);
  }
  return tmp;
}

std::vector<int> GeneratorEventParametersCollection::signalProcessId(const size_t nElem) const {
  std::vector<int> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.signalProcessId);
  }
  return tmp;
}

std::vector<double> GeneratorEventParametersCollection::sqrts(const size_t nElem) const {
  std::vector<double> tmp;
  const auto valid_size = nElem != 0 ? std::min(nElem, m_storage.entries.size()) : m_storage.entries.size();
  tmp.reserve(valid_size);
  for (size_t i = 0; i < valid_size; ++i) {
    tmp.emplace_back(m_storage.entries[i]->data.sqrts);
  }
  return tmp;
}

size_t GeneratorEventParametersCollection::getDatamodelRegistryIndex() const {
  return edm4hep::meta::DatamodelRegistryIndex::value();
}

podio::SchemaVersionT GeneratorEventParametersCollection::getSchemaVersion() const {
  return edm4hep::meta::schemaVersion;
}

// anonymous namespace for registration with the CollectionBufferFactory. This
// ensures that we don't have to make up arbitrary namespace names here, since
// none of this is publicly visible
namespace {

  podio::CollectionReadBuffers createBuffers(bool isSubset) {
    auto readBuffers = podio::CollectionReadBuffers{};
    readBuffers.type = "edm4hep::GeneratorEventParametersCollection";
    readBuffers.schemaVersion = edm4hep::meta::schemaVersion;
    readBuffers.data = isSubset ? nullptr : new GeneratorEventParametersDataContainer;
    // The number of ObjectID vectors is either 1 or the sum of OneToMany and
    // OneToOne relations
    const auto nRefs = isSubset ? 1 : 1 + 0;
    readBuffers.references = new podio::CollRefCollection(nRefs);
    for (auto& ref : *readBuffers.references) {
      // Make sure to place usable buffer pointers here
      ref = std::make_unique<std::vector<podio::ObjectID>>();
    }

    readBuffers.vectorMembers = new podio::VectorMembersInfo();
    if (!isSubset) {
      readBuffers.vectorMembers->reserve(2);
      readBuffers.vectorMembers->emplace_back("double", new std::vector<double>);
      readBuffers.vectorMembers->emplace_back("double", new std::vector<double>);
    }

    readBuffers.createCollection = [](const podio::CollectionReadBuffers& buffers, bool isSubsetColl) {
      GeneratorEventParametersCollectionData data(buffers, isSubsetColl);
      return std::make_unique<GeneratorEventParametersCollection>(std::move(data), isSubsetColl);
    };

    readBuffers.recast = [](podio::CollectionReadBuffers& buffers) {
      // We only have any of these buffers if this is not a subset collection
      if (buffers.data) {
        buffers.data = podio::CollectionWriteBuffers::asVector<edm4hep::GeneratorEventParametersData>(buffers.data);
        (*buffers.vectorMembers)[0].second =
            podio::CollectionWriteBuffers::asVector<double>((*buffers.vectorMembers)[0].second);
        (*buffers.vectorMembers)[1].second =
            podio::CollectionWriteBuffers::asVector<double>((*buffers.vectorMembers)[1].second);
      }
    };

    readBuffers.deleteBuffers = [](podio::CollectionReadBuffers& buffers) {
      if (buffers.data) {
        // If we have data then we are not a subset collection and we have to
        // clean up all type erased buffers by casting them back to something that
        // we can delete
        delete static_cast<edm4hep::GeneratorEventParametersDataContainer*>(buffers.data);
        delete static_cast<std::vector<double>*>((*buffers.vectorMembers)[0].second);
        delete static_cast<std::vector<double>*>((*buffers.vectorMembers)[1].second);
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
      factory.registerCreationFunc("edm4hep::GeneratorEventParametersCollection", edm4hep::meta::schemaVersion,
                                   createBuffers);

      // Make the SchemaEvolution aware of the current version by
      // registering a no-op function for this and all preceding versions
      // will be overridden whenever an explicit action is required
      for (unsigned int schemaVersion = 1; schemaVersion < edm4hep::meta::schemaVersion + 1; ++schemaVersion) {
        podio::SchemaEvolution::mutInstance().registerEvolutionFunc(
            "edm4hep::GeneratorEventParametersCollection", schemaVersion, edm4hep::meta::schemaVersion,
            podio::SchemaEvolution::noOpSchemaEvolution, podio::SchemaEvolution::Priority::AutoGenerated);
      }

      return true;
    }();
    return reg;
  }

  const auto registeredCollection = registerCollection();
} // namespace

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const GeneratorEventParametersCollection& collection) {
  j = nlohmann::json::array();
  for (auto&& elem : collection) {
    j.emplace_back(elem);
  }
}
#endif

GeneratorEventParameters GeneratorEventParametersCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<GeneratorEventParametersObj>((*m_collection)[m_index]);
  return m_object;
}

GeneratorEventParameters* GeneratorEventParametersCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<GeneratorEventParametersObj>((*m_collection)[m_index]);
  return &m_object;
}

GeneratorEventParametersCollectionIterator& GeneratorEventParametersCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

MutableGeneratorEventParameters GeneratorEventParametersMutableCollectionIterator::operator*() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<GeneratorEventParametersObj>((*m_collection)[m_index]);
  return m_object;
}

MutableGeneratorEventParameters* GeneratorEventParametersMutableCollectionIterator::operator->() {
  m_object.m_obj = podio::utils::MaybeSharedPtr<GeneratorEventParametersObj>((*m_collection)[m_index]);
  return &m_object;
}

GeneratorEventParametersMutableCollectionIterator& GeneratorEventParametersMutableCollectionIterator::operator++() {
  ++m_index;
  return *this;
}

std::ostream& operator<<(std::ostream& o, const GeneratorEventParametersCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:  eventScale:    alphaQED:    alphaQCD:signalProcessId:       sqrts:" << '\n';

  for (const auto&& el : v) {
    o << std::scientific << std::showpos << std::setw(12) << el.id() << " " << std::setw(12) << el.getEventScale()
      << " " << std::setw(12) << el.getAlphaQED() << " " << std::setw(12) << el.getAlphaQCD() << " " << std::setw(12)
      << el.getSignalProcessId() << " " << std::setw(12) << el.getSqrts() << " " << std::endl;

    o << "      signalVertex : ";
    for (unsigned j = 0, N = el.signalVertex_size(); j < N; ++j) {
      o << el.getSignalVertex(j).id() << " ";
    }
    o << std::endl;

    o << "      crossSections : ";
    for (unsigned j = 0, N = el.crossSections_size(); j < N; ++j) {
      o << el.getCrossSections(j) << " ";
    }
    o << std::endl;
    o << "      crossSectionErrors : ";
    for (unsigned j = 0, N = el.crossSectionErrors_size(); j < N; ++j) {
      o << el.getCrossSectionErrors(j) << " ";
    }
    o << std::endl;
  }

  o.flags(old_flags);
  return o;
}

void GeneratorEventParametersCollection::print(std::ostream& os, bool flush) const {
  os << *this;
  if (flush) {
    os.flush();
  }
}

} // namespace edm4hep
