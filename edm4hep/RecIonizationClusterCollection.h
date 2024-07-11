// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecIonizationClusterCollection_H
#define EDM4HEP_RecIonizationClusterCollection_H

// datamodel specific includes
#include "edm4hep/MutableRecIonizationCluster.h"
#include "edm4hep/RecIonizationCluster.h"
#include "edm4hep/RecIonizationClusterCollectionData.h"
#include "edm4hep/RecIonizationClusterData.h"
#include "edm4hep/RecIonizationClusterObj.h"

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

class RecIonizationClusterCollectionIterator {
public:
  RecIonizationClusterCollectionIterator(size_t index, const RecIonizationClusterObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<RecIonizationClusterObj>{nullptr}),
      m_collection(collection) {
  }

  RecIonizationClusterCollectionIterator(const RecIonizationClusterCollectionIterator&) = delete;
  RecIonizationClusterCollectionIterator& operator=(const RecIonizationClusterCollectionIterator&) = delete;

  bool operator!=(const RecIonizationClusterCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const RecIonizationClusterCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  RecIonizationCluster operator*();
  RecIonizationCluster* operator->();
  RecIonizationClusterCollectionIterator& operator++();

private:
  size_t m_index;
  RecIonizationCluster m_object;
  const RecIonizationClusterObjPointerContainer* m_collection;
};

class RecIonizationClusterMutableCollectionIterator {
public:
  RecIonizationClusterMutableCollectionIterator(size_t index,
                                                const RecIonizationClusterObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<RecIonizationClusterObj>{nullptr}),
      m_collection(collection) {
  }

  RecIonizationClusterMutableCollectionIterator(const RecIonizationClusterMutableCollectionIterator&) = delete;
  RecIonizationClusterMutableCollectionIterator&
  operator=(const RecIonizationClusterMutableCollectionIterator&) = delete;

  bool operator!=(const RecIonizationClusterMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const RecIonizationClusterMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableRecIonizationCluster operator*();
  MutableRecIonizationCluster* operator->();
  RecIonizationClusterMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableRecIonizationCluster m_object;
  const RecIonizationClusterObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class RecIonizationClusterCollection : public podio::CollectionBase {
public:
  using value_type = RecIonizationCluster;
  using const_iterator = RecIonizationClusterCollectionIterator;
  using iterator = RecIonizationClusterMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  RecIonizationClusterCollection();
  RecIonizationClusterCollection(RecIonizationClusterCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  RecIonizationClusterCollection(const RecIonizationClusterCollection&) = delete;
  RecIonizationClusterCollection& operator=(const RecIonizationClusterCollection&) = delete;
  RecIonizationClusterCollection(RecIonizationClusterCollection&&) = default;
  RecIonizationClusterCollection& operator=(RecIonizationClusterCollection&&) = default;

  //  RecIonizationClusterCollection(RecIonizationClusterVector* data, uint32_t collectionID);
  ~RecIonizationClusterCollection();

  constexpr static auto typeName = "edm4hep::RecIonizationClusterCollection";
  constexpr static auto valueTypeName = "edm4hep::RecIonizationCluster";
  constexpr static auto dataTypeName = "edm4hep::RecIonizationClusterData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  RecIonizationClusterCollection* operator->() {
    return (RecIonizationClusterCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableRecIonizationCluster create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableRecIonizationCluster create(Args&&... args);

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
  RecIonizationCluster operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableRecIonizationCluster operator[](std::size_t index);
  /// Returns the const object of given index
  RecIonizationCluster at(std::size_t index) const;
  /// Returns the object of given index
  MutableRecIonizationCluster at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableRecIonizationCluster& object);
  /// Append an object to the (subset) collection
  void push_back(const RecIonizationCluster& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](RecIonizationClusterObj* obj) {
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
  std::vector<float> significance(const size_t nElem = 0) const;
  std::vector<std::int16_t> type(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class RecIonizationClusterCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable RecIonizationClusterCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const RecIonizationClusterCollection& v);

template <typename... Args>
MutableRecIonizationCluster RecIonizationClusterCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new RecIonizationClusterObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, RecIonizationClusterData} constructor
  obj->m_trackerPulse = new std::vector<edm4hep::TrackerPulse>();
  m_storage.createRelations(obj);
  return MutableRecIonizationCluster(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecIonizationClusterCollection& collection);
#endif

} // namespace edm4hep

#endif
