// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterCollection_H
#define EDM4HEP_ClusterCollection_H

// datamodel specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterCollectionData.h"
#include "edm4hep/ClusterData.h"
#include "edm4hep/ClusterObj.h"
#include "edm4hep/MutableCluster.h"

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

class ClusterCollectionIterator {
public:
  ClusterCollectionIterator(size_t index, const ClusterObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<ClusterObj>{nullptr}), m_collection(collection) {
  }

  ClusterCollectionIterator(const ClusterCollectionIterator&) = delete;
  ClusterCollectionIterator& operator=(const ClusterCollectionIterator&) = delete;

  bool operator!=(const ClusterCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const ClusterCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  Cluster operator*();
  Cluster* operator->();
  ClusterCollectionIterator& operator++();

private:
  size_t m_index;
  Cluster m_object;
  const ClusterObjPointerContainer* m_collection;
};

class ClusterMutableCollectionIterator {
public:
  ClusterMutableCollectionIterator(size_t index, const ClusterObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<ClusterObj>{nullptr}), m_collection(collection) {
  }

  ClusterMutableCollectionIterator(const ClusterMutableCollectionIterator&) = delete;
  ClusterMutableCollectionIterator& operator=(const ClusterMutableCollectionIterator&) = delete;

  bool operator!=(const ClusterMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const ClusterMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableCluster operator*();
  MutableCluster* operator->();
  ClusterMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableCluster m_object;
  const ClusterObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class ClusterCollection : public podio::CollectionBase {
public:
  using value_type = Cluster;
  using const_iterator = ClusterCollectionIterator;
  using iterator = ClusterMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  ClusterCollection();
  ClusterCollection(ClusterCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  ClusterCollection(const ClusterCollection&) = delete;
  ClusterCollection& operator=(const ClusterCollection&) = delete;
  ClusterCollection(ClusterCollection&&) = default;
  ClusterCollection& operator=(ClusterCollection&&) = default;

  //  ClusterCollection(ClusterVector* data, uint32_t collectionID);
  ~ClusterCollection();

  constexpr static auto typeName = "edm4hep::ClusterCollection";
  constexpr static auto valueTypeName = "edm4hep::Cluster";
  constexpr static auto dataTypeName = "edm4hep::ClusterData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  ClusterCollection* operator->() {
    return (ClusterCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableCluster create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableCluster create(Args&&... args);

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
  Cluster operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableCluster operator[](std::size_t index);
  /// Returns the const object of given index
  Cluster at(std::size_t index) const;
  /// Returns the object of given index
  MutableCluster at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableCluster& object);
  /// Append an object to the (subset) collection
  void push_back(const Cluster& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](ClusterObj* obj) {
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
  std::vector<float> energy(const size_t nElem = 0) const;
  std::vector<float> energyError(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3f> position(const size_t nElem = 0) const;
  std::vector<edm4hep::CovMatrix3f> positionError(const size_t nElem = 0) const;
  std::vector<float> iTheta(const size_t nElem = 0) const;
  std::vector<float> phi(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3f> directionError(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class ClusterCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable ClusterCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const ClusterCollection& v);

template <typename... Args>
MutableCluster ClusterCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new ClusterObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, ClusterData} constructor
  obj->m_clusters = new std::vector<edm4hep::Cluster>();
  obj->m_hits = new std::vector<edm4hep::CalorimeterHit>();
  obj->m_shapeParameters = new std::vector<float>();
  obj->m_subdetectorEnergies = new std::vector<float>();
  m_storage.createRelations(obj);
  return MutableCluster(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const ClusterCollection& collection);
#endif

} // namespace edm4hep

#endif
