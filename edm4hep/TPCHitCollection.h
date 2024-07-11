// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHitCollection_H
#define EDM4HEP_TPCHitCollection_H

// datamodel specific includes
#include "edm4hep/MutableTPCHit.h"
#include "edm4hep/TPCHit.h"
#include "edm4hep/TPCHitCollectionData.h"
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHitObj.h"

// podio specific includes
#include "podio/CollectionBase.h"
#include "podio/CollectionIDTable.h"
#include "podio/ICollectionProvider.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
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

class TPCHitCollectionIterator {
public:
  TPCHitCollectionIterator(size_t index, const TPCHitObjPointerContainer* collection) :
      m_index(index), m_object(nullptr), m_collection(collection) {
  }

  TPCHitCollectionIterator(const TPCHitCollectionIterator&) = delete;
  TPCHitCollectionIterator& operator=(const TPCHitCollectionIterator&) = delete;

  bool operator!=(const TPCHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  TPCHit operator*();
  TPCHit* operator->();
  TPCHitCollectionIterator& operator++();

private:
  size_t m_index;
  TPCHit m_object;
  const TPCHitObjPointerContainer* m_collection;
};

class TPCHitMutableCollectionIterator {
public:
  TPCHitMutableCollectionIterator(size_t index, const TPCHitObjPointerContainer* collection) :
      m_index(index), m_object(nullptr), m_collection(collection) {
  }

  TPCHitMutableCollectionIterator(const TPCHitMutableCollectionIterator&) = delete;
  TPCHitMutableCollectionIterator& operator=(const TPCHitMutableCollectionIterator&) = delete;

  bool operator!=(const TPCHitMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  MutableTPCHit operator*();
  MutableTPCHit* operator->();
  TPCHitMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableTPCHit m_object;
  const TPCHitObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class TPCHitCollection : public podio::CollectionBase {
public:
  using const_iterator = TPCHitCollectionIterator;
  using iterator = TPCHitMutableCollectionIterator;

  TPCHitCollection();
  TPCHitCollection(TPCHitCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  TPCHitCollection(const TPCHitCollection&) = delete;
  TPCHitCollection& operator=(const TPCHitCollection&) = delete;
  TPCHitCollection(TPCHitCollection&&) = default;
  TPCHitCollection& operator=(TPCHitCollection&&) = default;

  //  TPCHitCollection(TPCHitVector* data, uint32_t collectionID);
  ~TPCHitCollection();

  constexpr static auto typeName = "edm4hep::TPCHitCollection";
  constexpr static auto valueTypeName = "edm4hep::TPCHit";
  constexpr static auto dataTypeName = "edm4hep::TPCHitData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  TPCHitCollection* operator->() {
    return (TPCHitCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableTPCHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableTPCHit create(Args&&... args);

  /// number of elements in the collection
  std::size_t size() const final;

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
  TPCHit operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableTPCHit operator[](std::size_t index);
  /// Returns the const object of given index
  TPCHit at(std::size_t index) const;
  /// Returns the object of given index
  MutableTPCHit at(std::size_t index);

  /// Append object to the collection
  void push_back(TPCHit object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](TPCHitObj* obj) {
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
  iterator end() {
    return iterator(m_storage.entries.size(), &m_storage.entries);
  }
  const_iterator end() const {
    return const_iterator(m_storage.entries.size(), &m_storage.entries);
  }

  std::vector<std::uint64_t> cellID(const size_t nElem = 0) const;
  std::vector<std::int32_t> quality(const size_t nElem = 0) const;
  std::vector<float> time(const size_t nElem = 0) const;
  std::vector<float> charge(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class TPCHitCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable TPCHitCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const TPCHitCollection& v);

template <typename... Args>
MutableTPCHit TPCHitCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new TPCHitObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, TPCHitData} constructor
  obj->m_rawDataWords = new std::vector<std::int32_t>();
  m_storage.createRelations(obj);
  return MutableTPCHit(obj);
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TPCHitCollection& collection);
#endif

} // namespace edm4hep

#endif
