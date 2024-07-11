// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoClusterParticleAssociationCollection_H
#define EDM4HEP_MCRecoClusterParticleAssociationCollection_H

// datamodel specific includes
#include "edm4hep/MCRecoClusterParticleAssociation.h"
#include "edm4hep/MCRecoClusterParticleAssociationCollectionData.h"
#include "edm4hep/MCRecoClusterParticleAssociationData.h"
#include "edm4hep/MCRecoClusterParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoClusterParticleAssociation.h"

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

class MCRecoClusterParticleAssociationCollectionIterator {
public:
  MCRecoClusterParticleAssociationCollectionIterator(
      size_t index, const MCRecoClusterParticleAssociationObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj>{nullptr}),
      m_collection(collection) {
  }

  MCRecoClusterParticleAssociationCollectionIterator(const MCRecoClusterParticleAssociationCollectionIterator&) =
      delete;
  MCRecoClusterParticleAssociationCollectionIterator&
  operator=(const MCRecoClusterParticleAssociationCollectionIterator&) = delete;

  bool operator!=(const MCRecoClusterParticleAssociationCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const MCRecoClusterParticleAssociationCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MCRecoClusterParticleAssociation operator*();
  MCRecoClusterParticleAssociation* operator->();
  MCRecoClusterParticleAssociationCollectionIterator& operator++();

private:
  size_t m_index;
  MCRecoClusterParticleAssociation m_object;
  const MCRecoClusterParticleAssociationObjPointerContainer* m_collection;
};

class MCRecoClusterParticleAssociationMutableCollectionIterator {
public:
  MCRecoClusterParticleAssociationMutableCollectionIterator(
      size_t index, const MCRecoClusterParticleAssociationObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<MCRecoClusterParticleAssociationObj>{nullptr}),
      m_collection(collection) {
  }

  MCRecoClusterParticleAssociationMutableCollectionIterator(
      const MCRecoClusterParticleAssociationMutableCollectionIterator&) = delete;
  MCRecoClusterParticleAssociationMutableCollectionIterator&
  operator=(const MCRecoClusterParticleAssociationMutableCollectionIterator&) = delete;

  bool operator!=(const MCRecoClusterParticleAssociationMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const MCRecoClusterParticleAssociationMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableMCRecoClusterParticleAssociation operator*();
  MutableMCRecoClusterParticleAssociation* operator->();
  MCRecoClusterParticleAssociationMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableMCRecoClusterParticleAssociation m_object;
  const MCRecoClusterParticleAssociationObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class MCRecoClusterParticleAssociationCollection : public podio::CollectionBase {
public:
  using value_type = MCRecoClusterParticleAssociation;
  using const_iterator = MCRecoClusterParticleAssociationCollectionIterator;
  using iterator = MCRecoClusterParticleAssociationMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  MCRecoClusterParticleAssociationCollection();
  MCRecoClusterParticleAssociationCollection(MCRecoClusterParticleAssociationCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  MCRecoClusterParticleAssociationCollection(const MCRecoClusterParticleAssociationCollection&) = delete;
  MCRecoClusterParticleAssociationCollection& operator=(const MCRecoClusterParticleAssociationCollection&) = delete;
  MCRecoClusterParticleAssociationCollection(MCRecoClusterParticleAssociationCollection&&) = default;
  MCRecoClusterParticleAssociationCollection& operator=(MCRecoClusterParticleAssociationCollection&&) = default;

  //  MCRecoClusterParticleAssociationCollection(MCRecoClusterParticleAssociationVector* data, uint32_t collectionID);
  ~MCRecoClusterParticleAssociationCollection();

  constexpr static auto typeName = "edm4hep::MCRecoClusterParticleAssociationCollection";
  constexpr static auto valueTypeName = "edm4hep::MCRecoClusterParticleAssociation";
  constexpr static auto dataTypeName = "edm4hep::MCRecoClusterParticleAssociationData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  MCRecoClusterParticleAssociationCollection* operator->() {
    return (MCRecoClusterParticleAssociationCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableMCRecoClusterParticleAssociation create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableMCRecoClusterParticleAssociation create(Args&&... args);

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
  MCRecoClusterParticleAssociation operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableMCRecoClusterParticleAssociation operator[](std::size_t index);
  /// Returns the const object of given index
  MCRecoClusterParticleAssociation at(std::size_t index) const;
  /// Returns the object of given index
  MutableMCRecoClusterParticleAssociation at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableMCRecoClusterParticleAssociation& object);
  /// Append an object to the (subset) collection
  void push_back(const MCRecoClusterParticleAssociation& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](MCRecoClusterParticleAssociationObj* obj) {
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

  std::vector<float> weight(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class MCRecoClusterParticleAssociationCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable MCRecoClusterParticleAssociationCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const MCRecoClusterParticleAssociationCollection& v);

template <typename... Args>
MutableMCRecoClusterParticleAssociation MCRecoClusterParticleAssociationCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new MCRecoClusterParticleAssociationObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  return MutableMCRecoClusterParticleAssociation(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoClusterParticleAssociationCollection& collection);
#endif

} // namespace edm4hep

#endif
