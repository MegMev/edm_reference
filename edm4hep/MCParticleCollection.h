// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticleCollection_H
#define EDM4HEP_MCParticleCollection_H

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleCollectionData.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticleObj.h"
#include "edm4hep/MutableMCParticle.h"

// podio specific includes
#include "podio/CollectionBase.h"
#include "podio/CollectionIDTable.h"
#include "podio/ICollectionProvider.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

#include <algorithm>
#include <array>
#include <cstddef>
#include <deque>
#include <memory>
#include <mutex>
#include <ostream>
#include <string>
#include <vector>

namespace podio {
struct RelationNames;
}

namespace edm4hep {

class MCParticleCollectionIterator {
public:
  MCParticleCollectionIterator(size_t index, const MCParticleObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<MCParticleObj>{nullptr}), m_collection(collection) {
  }

  MCParticleCollectionIterator(const MCParticleCollectionIterator&) = delete;
  MCParticleCollectionIterator& operator=(const MCParticleCollectionIterator&) = delete;

  bool operator!=(const MCParticleCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const MCParticleCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MCParticle operator*();
  MCParticle* operator->();
  MCParticleCollectionIterator& operator++();

private:
  size_t m_index;
  MCParticle m_object;
  const MCParticleObjPointerContainer* m_collection;
};

class MCParticleMutableCollectionIterator {
public:
  MCParticleMutableCollectionIterator(size_t index, const MCParticleObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<MCParticleObj>{nullptr}), m_collection(collection) {
  }

  MCParticleMutableCollectionIterator(const MCParticleMutableCollectionIterator&) = delete;
  MCParticleMutableCollectionIterator& operator=(const MCParticleMutableCollectionIterator&) = delete;

  bool operator!=(const MCParticleMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const MCParticleMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableMCParticle operator*();
  MutableMCParticle* operator->();
  MCParticleMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableMCParticle m_object;
  const MCParticleObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class MCParticleCollection : public podio::CollectionBase {
public:
  using value_type = MCParticle;
  using const_iterator = MCParticleCollectionIterator;
  using iterator = MCParticleMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  MCParticleCollection();
  MCParticleCollection(MCParticleCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  MCParticleCollection(const MCParticleCollection&) = delete;
  MCParticleCollection& operator=(const MCParticleCollection&) = delete;
  MCParticleCollection(MCParticleCollection&&) = default;
  MCParticleCollection& operator=(MCParticleCollection&&) = default;

  //  MCParticleCollection(MCParticleVector* data, uint32_t collectionID);
  ~MCParticleCollection();

  constexpr static auto typeName = "edm4hep::MCParticleCollection";
  constexpr static auto valueTypeName = "edm4hep::MCParticle";
  constexpr static auto dataTypeName = "edm4hep::MCParticleData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  MCParticleCollection* operator->() {
    return (MCParticleCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableMCParticle create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableMCParticle create(Args&&... args);

  /// number of elements in the collection
  std::size_t size() const final;

  /// maximal number of elements in the collection
  std::size_t max_size() const final;

  /// Is the collection empty
  bool empty() const final;

  /// fully qualified type name
  const std::string_view getTypeName() const final {
    return typeName;
  }
  /// fully qualified type name of elements - with namespace
  const std::string_view getValueTypeName() const final {
    return valueTypeName;
  }
  /// fully qualified type name of stored POD elements - with namespace
  const std::string_view getDataTypeName() const final {
    return dataTypeName;
  }
  /// schema version
  podio::SchemaVersionT getSchemaVersion() const final;

  bool isSubsetCollection() const final {
    return m_isSubsetColl;
  }

  void setSubsetCollection(bool setSubset = true) final;

  /// Returns the const object of given index
  MCParticle operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableMCParticle operator[](std::size_t index);
  /// Returns the const object of given index
  MCParticle at(std::size_t index) const;
  /// Returns the object of given index
  MutableMCParticle at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableMCParticle& object);
  /// Append an object to the (subset) collection
  void push_back(const MCParticle& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](MCParticleObj* obj) {
        obj->id = {obj->id.index, static_cast<uint32_t>(ID)};
      });
    }
    m_isValid = true;
  };

  uint32_t getID() const final {
    return m_collectionID;
  }

  bool isValid() const final {
    return m_isValid;
  }

  size_t getDatamodelRegistryIndex() const final;

  // support for the iterator protocol
  iterator begin() {
    return iterator(0, &m_storage.entries);
  }
  const_iterator begin() const {
    return const_iterator(0, &m_storage.entries);
  }
  const_iterator cbegin() const {
    return begin();
  }
  iterator end() {
    return iterator(m_storage.entries.size(), &m_storage.entries);
  }
  const_iterator end() const {
    return const_iterator(m_storage.entries.size(), &m_storage.entries);
  }
  const_iterator cend() const {
    return end();
  }

  std::vector<std::int32_t> PDG(const size_t nElem = 0) const;
  std::vector<std::int32_t> generatorStatus(const size_t nElem = 0) const;
  std::vector<std::int32_t> simulatorStatus(const size_t nElem = 0) const;
  std::vector<float> charge(const size_t nElem = 0) const;
  std::vector<float> time(const size_t nElem = 0) const;
  std::vector<double> mass(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3d> vertex(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3d> endpoint(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3d> momentum(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3d> momentumAtEndpoint(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3f> spin(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector2i> colorFlow(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class MCParticleCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable MCParticleCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const MCParticleCollection& v);

template <typename... Args>
MutableMCParticle MCParticleCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new MCParticleObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, MCParticleData} constructor
  obj->m_parents = new std::vector<edm4hep::MCParticle>();
  obj->m_daughters = new std::vector<edm4hep::MCParticle>();
  m_storage.createRelations(obj);
  return MutableMCParticle(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCParticleCollection& collection);
#endif

} // namespace edm4hep

#endif
