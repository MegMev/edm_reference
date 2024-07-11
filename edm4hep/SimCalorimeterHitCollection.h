// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHitCollection_H
#define EDM4HEP_SimCalorimeterHitCollection_H

// datamodel specific includes
#include "edm4hep/MutableSimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHitCollectionData.h"
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/SimCalorimeterHitObj.h"

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

class SimCalorimeterHitCollectionIterator {
public:
  SimCalorimeterHitCollectionIterator(size_t index, const SimCalorimeterHitObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj>{nullptr}), m_collection(collection) {
  }

  SimCalorimeterHitCollectionIterator(const SimCalorimeterHitCollectionIterator&) = delete;
  SimCalorimeterHitCollectionIterator& operator=(const SimCalorimeterHitCollectionIterator&) = delete;

  bool operator!=(const SimCalorimeterHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const SimCalorimeterHitCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  SimCalorimeterHit operator*();
  SimCalorimeterHit* operator->();
  SimCalorimeterHitCollectionIterator& operator++();

private:
  size_t m_index;
  SimCalorimeterHit m_object;
  const SimCalorimeterHitObjPointerContainer* m_collection;
};

class SimCalorimeterHitMutableCollectionIterator {
public:
  SimCalorimeterHitMutableCollectionIterator(size_t index, const SimCalorimeterHitObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj>{nullptr}), m_collection(collection) {
  }

  SimCalorimeterHitMutableCollectionIterator(const SimCalorimeterHitMutableCollectionIterator&) = delete;
  SimCalorimeterHitMutableCollectionIterator& operator=(const SimCalorimeterHitMutableCollectionIterator&) = delete;

  bool operator!=(const SimCalorimeterHitMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const SimCalorimeterHitMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableSimCalorimeterHit operator*();
  MutableSimCalorimeterHit* operator->();
  SimCalorimeterHitMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableSimCalorimeterHit m_object;
  const SimCalorimeterHitObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class SimCalorimeterHitCollection : public podio::CollectionBase {
public:
  using value_type = SimCalorimeterHit;
  using const_iterator = SimCalorimeterHitCollectionIterator;
  using iterator = SimCalorimeterHitMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  SimCalorimeterHitCollection();
  SimCalorimeterHitCollection(SimCalorimeterHitCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  SimCalorimeterHitCollection(const SimCalorimeterHitCollection&) = delete;
  SimCalorimeterHitCollection& operator=(const SimCalorimeterHitCollection&) = delete;
  SimCalorimeterHitCollection(SimCalorimeterHitCollection&&) = default;
  SimCalorimeterHitCollection& operator=(SimCalorimeterHitCollection&&) = default;

  //  SimCalorimeterHitCollection(SimCalorimeterHitVector* data, uint32_t collectionID);
  ~SimCalorimeterHitCollection();

  constexpr static auto typeName = "edm4hep::SimCalorimeterHitCollection";
  constexpr static auto valueTypeName = "edm4hep::SimCalorimeterHit";
  constexpr static auto dataTypeName = "edm4hep::SimCalorimeterHitData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  SimCalorimeterHitCollection* operator->() {
    return (SimCalorimeterHitCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableSimCalorimeterHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableSimCalorimeterHit create(Args&&... args);

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
  SimCalorimeterHit operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableSimCalorimeterHit operator[](std::size_t index);
  /// Returns the const object of given index
  SimCalorimeterHit at(std::size_t index) const;
  /// Returns the object of given index
  MutableSimCalorimeterHit at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableSimCalorimeterHit& object);
  /// Append an object to the (subset) collection
  void push_back(const SimCalorimeterHit& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](SimCalorimeterHitObj* obj) {
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
  std::vector<edm4hep::Vector3f> position(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class SimCalorimeterHitCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable SimCalorimeterHitCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const SimCalorimeterHitCollection& v);

template <typename... Args>
MutableSimCalorimeterHit SimCalorimeterHitCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new SimCalorimeterHitObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, SimCalorimeterHitData} constructor
  obj->m_contributions = new std::vector<edm4hep::CaloHitContribution>();
  m_storage.createRelations(obj);
  return MutableSimCalorimeterHit(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimCalorimeterHitCollection& collection);
#endif

} // namespace edm4hep

#endif
