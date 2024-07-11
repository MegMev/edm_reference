// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleIDCollection_H
#define EDM4HEP_ParticleIDCollection_H

// datamodel specific includes
#include "edm4hep/MutableParticleID.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/ParticleIDCollectionData.h"
#include "edm4hep/ParticleIDData.h"
#include "edm4hep/ParticleIDObj.h"

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

class ParticleIDCollectionIterator {
public:
  ParticleIDCollectionIterator(size_t index, const ParticleIDObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<ParticleIDObj>{nullptr}), m_collection(collection) {
  }

  ParticleIDCollectionIterator(const ParticleIDCollectionIterator&) = delete;
  ParticleIDCollectionIterator& operator=(const ParticleIDCollectionIterator&) = delete;

  bool operator!=(const ParticleIDCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const ParticleIDCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  ParticleID operator*();
  ParticleID* operator->();
  ParticleIDCollectionIterator& operator++();

private:
  size_t m_index;
  ParticleID m_object;
  const ParticleIDObjPointerContainer* m_collection;
};

class ParticleIDMutableCollectionIterator {
public:
  ParticleIDMutableCollectionIterator(size_t index, const ParticleIDObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<ParticleIDObj>{nullptr}), m_collection(collection) {
  }

  ParticleIDMutableCollectionIterator(const ParticleIDMutableCollectionIterator&) = delete;
  ParticleIDMutableCollectionIterator& operator=(const ParticleIDMutableCollectionIterator&) = delete;

  bool operator!=(const ParticleIDMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const ParticleIDMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableParticleID operator*();
  MutableParticleID* operator->();
  ParticleIDMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableParticleID m_object;
  const ParticleIDObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class ParticleIDCollection : public podio::CollectionBase {
public:
  using value_type = ParticleID;
  using const_iterator = ParticleIDCollectionIterator;
  using iterator = ParticleIDMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  ParticleIDCollection();
  ParticleIDCollection(ParticleIDCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  ParticleIDCollection(const ParticleIDCollection&) = delete;
  ParticleIDCollection& operator=(const ParticleIDCollection&) = delete;
  ParticleIDCollection(ParticleIDCollection&&) = default;
  ParticleIDCollection& operator=(ParticleIDCollection&&) = default;

  //  ParticleIDCollection(ParticleIDVector* data, uint32_t collectionID);
  ~ParticleIDCollection();

  constexpr static auto typeName = "edm4hep::ParticleIDCollection";
  constexpr static auto valueTypeName = "edm4hep::ParticleID";
  constexpr static auto dataTypeName = "edm4hep::ParticleIDData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  ParticleIDCollection* operator->() {
    return (ParticleIDCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableParticleID create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableParticleID create(Args&&... args);

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
  ParticleID operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableParticleID operator[](std::size_t index);
  /// Returns the const object of given index
  ParticleID at(std::size_t index) const;
  /// Returns the object of given index
  MutableParticleID at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableParticleID& object);
  /// Append an object to the (subset) collection
  void push_back(const ParticleID& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](ParticleIDObj* obj) {
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

  std::vector<std::int32_t> type(const size_t nElem = 0) const;
  std::vector<std::int32_t> PDG(const size_t nElem = 0) const;
  std::vector<std::int32_t> algorithmType(const size_t nElem = 0) const;
  std::vector<float> likelihood(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class ParticleIDCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable ParticleIDCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const ParticleIDCollection& v);

template <typename... Args>
MutableParticleID ParticleIDCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new ParticleIDObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, ParticleIDData} constructor
  obj->m_parameters = new std::vector<float>();
  m_storage.createRelations(obj);
  return MutableParticleID(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ParticleIDCollection& collection);
#endif

} // namespace edm4hep

#endif
