// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimPrimaryIonizationClusterCollection_H
#define EDM4HEP_SimPrimaryIonizationClusterCollection_H

// datamodel specific includes
#include "edm4hep/MutableSimPrimaryIonizationCluster.h"
#include "edm4hep/SimPrimaryIonizationCluster.h"
#include "edm4hep/SimPrimaryIonizationClusterCollectionData.h"
#include "edm4hep/SimPrimaryIonizationClusterData.h"
#include "edm4hep/SimPrimaryIonizationClusterObj.h"

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

class SimPrimaryIonizationClusterCollectionIterator {
public:
  SimPrimaryIonizationClusterCollectionIterator(size_t index,
                                                const SimPrimaryIonizationClusterObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj>{nullptr}),
      m_collection(collection) {
  }

  SimPrimaryIonizationClusterCollectionIterator(const SimPrimaryIonizationClusterCollectionIterator&) = delete;
  SimPrimaryIonizationClusterCollectionIterator&
  operator=(const SimPrimaryIonizationClusterCollectionIterator&) = delete;

  bool operator!=(const SimPrimaryIonizationClusterCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const SimPrimaryIonizationClusterCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  SimPrimaryIonizationCluster operator*();
  SimPrimaryIonizationCluster* operator->();
  SimPrimaryIonizationClusterCollectionIterator& operator++();

private:
  size_t m_index;
  SimPrimaryIonizationCluster m_object;
  const SimPrimaryIonizationClusterObjPointerContainer* m_collection;
};

class SimPrimaryIonizationClusterMutableCollectionIterator {
public:
  SimPrimaryIonizationClusterMutableCollectionIterator(
      size_t index, const SimPrimaryIonizationClusterObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<SimPrimaryIonizationClusterObj>{nullptr}),
      m_collection(collection) {
  }

  SimPrimaryIonizationClusterMutableCollectionIterator(const SimPrimaryIonizationClusterMutableCollectionIterator&) =
      delete;
  SimPrimaryIonizationClusterMutableCollectionIterator&
  operator=(const SimPrimaryIonizationClusterMutableCollectionIterator&) = delete;

  bool operator!=(const SimPrimaryIonizationClusterMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const SimPrimaryIonizationClusterMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableSimPrimaryIonizationCluster operator*();
  MutableSimPrimaryIonizationCluster* operator->();
  SimPrimaryIonizationClusterMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableSimPrimaryIonizationCluster m_object;
  const SimPrimaryIonizationClusterObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class SimPrimaryIonizationClusterCollection : public podio::CollectionBase {
public:
  using value_type = SimPrimaryIonizationCluster;
  using const_iterator = SimPrimaryIonizationClusterCollectionIterator;
  using iterator = SimPrimaryIonizationClusterMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  SimPrimaryIonizationClusterCollection();
  SimPrimaryIonizationClusterCollection(SimPrimaryIonizationClusterCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  SimPrimaryIonizationClusterCollection(const SimPrimaryIonizationClusterCollection&) = delete;
  SimPrimaryIonizationClusterCollection& operator=(const SimPrimaryIonizationClusterCollection&) = delete;
  SimPrimaryIonizationClusterCollection(SimPrimaryIonizationClusterCollection&&) = default;
  SimPrimaryIonizationClusterCollection& operator=(SimPrimaryIonizationClusterCollection&&) = default;

  //  SimPrimaryIonizationClusterCollection(SimPrimaryIonizationClusterVector* data, uint32_t collectionID);
  ~SimPrimaryIonizationClusterCollection();

  constexpr static auto typeName = "edm4hep::SimPrimaryIonizationClusterCollection";
  constexpr static auto valueTypeName = "edm4hep::SimPrimaryIonizationCluster";
  constexpr static auto dataTypeName = "edm4hep::SimPrimaryIonizationClusterData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  SimPrimaryIonizationClusterCollection* operator->() {
    return (SimPrimaryIonizationClusterCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableSimPrimaryIonizationCluster create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableSimPrimaryIonizationCluster create(Args&&... args);

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
  SimPrimaryIonizationCluster operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableSimPrimaryIonizationCluster operator[](std::size_t index);
  /// Returns the const object of given index
  SimPrimaryIonizationCluster at(std::size_t index) const;
  /// Returns the object of given index
  MutableSimPrimaryIonizationCluster at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableSimPrimaryIonizationCluster& object);
  /// Append an object to the (subset) collection
  void push_back(const SimPrimaryIonizationCluster& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](SimPrimaryIonizationClusterObj* obj) {
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
  std::vector<float> time(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3d> position(const size_t nElem = 0) const;
  std::vector<std::int16_t> type(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class SimPrimaryIonizationClusterCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable SimPrimaryIonizationClusterCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const SimPrimaryIonizationClusterCollection& v);

template <typename... Args>
MutableSimPrimaryIonizationCluster SimPrimaryIonizationClusterCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new SimPrimaryIonizationClusterObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, SimPrimaryIonizationClusterData} constructor
  obj->m_electronCellID = new std::vector<std::uint64_t>();
  obj->m_electronTime = new std::vector<float>();
  obj->m_electronPosition = new std::vector<edm4hep::Vector3d>();
  obj->m_pulseTime = new std::vector<float>();
  obj->m_pulseAmplitude = new std::vector<float>();
  m_storage.createRelations(obj);
  return MutableSimPrimaryIonizationCluster(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimPrimaryIonizationClusterCollection& collection);
#endif

} // namespace edm4hep

#endif
