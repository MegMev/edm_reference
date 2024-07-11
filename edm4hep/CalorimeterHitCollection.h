// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHitCollection_H
#define EDM4HEP_CalorimeterHitCollection_H

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CalorimeterHitCollectionData.h"
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHitObj.h"
#include "edm4hep/MutableCalorimeterHit.h"

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

class CalorimeterHitCollectionIterator {
public:
  CalorimeterHitCollectionIterator(size_t index, const CalorimeterHitObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<CalorimeterHitObj>{nullptr}), m_collection(collection) {
  }

  CalorimeterHitCollectionIterator(const CalorimeterHitCollectionIterator&) = delete;
  CalorimeterHitCollectionIterator& operator=(const CalorimeterHitCollectionIterator&) = delete;

  bool operator!=(const CalorimeterHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const CalorimeterHitCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  CalorimeterHit operator*();
  CalorimeterHit* operator->();
  CalorimeterHitCollectionIterator& operator++();

private:
  size_t m_index;
  CalorimeterHit m_object;
  const CalorimeterHitObjPointerContainer* m_collection;
};

class CalorimeterHitMutableCollectionIterator {
public:
  CalorimeterHitMutableCollectionIterator(size_t index, const CalorimeterHitObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<CalorimeterHitObj>{nullptr}), m_collection(collection) {
  }

  CalorimeterHitMutableCollectionIterator(const CalorimeterHitMutableCollectionIterator&) = delete;
  CalorimeterHitMutableCollectionIterator& operator=(const CalorimeterHitMutableCollectionIterator&) = delete;

  bool operator!=(const CalorimeterHitMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const CalorimeterHitMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableCalorimeterHit operator*();
  MutableCalorimeterHit* operator->();
  CalorimeterHitMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableCalorimeterHit m_object;
  const CalorimeterHitObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class CalorimeterHitCollection : public podio::CollectionBase {
public:
  using value_type = CalorimeterHit;
  using const_iterator = CalorimeterHitCollectionIterator;
  using iterator = CalorimeterHitMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  CalorimeterHitCollection();
  CalorimeterHitCollection(CalorimeterHitCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  CalorimeterHitCollection(const CalorimeterHitCollection&) = delete;
  CalorimeterHitCollection& operator=(const CalorimeterHitCollection&) = delete;
  CalorimeterHitCollection(CalorimeterHitCollection&&) = default;
  CalorimeterHitCollection& operator=(CalorimeterHitCollection&&) = default;

  //  CalorimeterHitCollection(CalorimeterHitVector* data, uint32_t collectionID);
  ~CalorimeterHitCollection();

  constexpr static auto typeName = "edm4hep::CalorimeterHitCollection";
  constexpr static auto valueTypeName = "edm4hep::CalorimeterHit";
  constexpr static auto dataTypeName = "edm4hep::CalorimeterHitData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  CalorimeterHitCollection* operator->() {
    return (CalorimeterHitCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableCalorimeterHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableCalorimeterHit create(Args&&... args);

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
  CalorimeterHit operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableCalorimeterHit operator[](std::size_t index);
  /// Returns the const object of given index
  CalorimeterHit at(std::size_t index) const;
  /// Returns the object of given index
  MutableCalorimeterHit at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableCalorimeterHit& object);
  /// Append an object to the (subset) collection
  void push_back(const CalorimeterHit& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](CalorimeterHitObj* obj) {
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

  std::vector<std::uint64_t> cellID(const size_t nElem = 0) const;
  std::vector<float> energy(const size_t nElem = 0) const;
  std::vector<float> energyError(const size_t nElem = 0) const;
  std::vector<float> time(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3f> position(const size_t nElem = 0) const;
  std::vector<std::int32_t> type(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class CalorimeterHitCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable CalorimeterHitCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const CalorimeterHitCollection& v);

template <typename... Args>
MutableCalorimeterHit CalorimeterHitCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new CalorimeterHitObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  return MutableCalorimeterHit(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const CalorimeterHitCollection& collection);
#endif

} // namespace edm4hep

#endif
