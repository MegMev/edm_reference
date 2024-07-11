// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoParticleAssociationCollection_H
#define EDM4HEP_MCRecoParticleAssociationCollection_H

// datamodel specific includes
#include "edm4hep/MCRecoParticleAssociation.h"
#include "edm4hep/MCRecoParticleAssociationCollectionData.h"
#include "edm4hep/MCRecoParticleAssociationData.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"
#include "edm4hep/MutableMCRecoParticleAssociation.h"

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

class MCRecoParticleAssociationCollectionIterator {
public:
  MCRecoParticleAssociationCollectionIterator(size_t index,
                                              const MCRecoParticleAssociationObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj>{nullptr}),
      m_collection(collection) {
  }

  MCRecoParticleAssociationCollectionIterator(const MCRecoParticleAssociationCollectionIterator&) = delete;
  MCRecoParticleAssociationCollectionIterator& operator=(const MCRecoParticleAssociationCollectionIterator&) = delete;

  bool operator!=(const MCRecoParticleAssociationCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const MCRecoParticleAssociationCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MCRecoParticleAssociation operator*();
  MCRecoParticleAssociation* operator->();
  MCRecoParticleAssociationCollectionIterator& operator++();

private:
  size_t m_index;
  MCRecoParticleAssociation m_object;
  const MCRecoParticleAssociationObjPointerContainer* m_collection;
};

class MCRecoParticleAssociationMutableCollectionIterator {
public:
  MCRecoParticleAssociationMutableCollectionIterator(size_t index,
                                                     const MCRecoParticleAssociationObjPointerContainer* collection) :
      m_index(index),
      m_object(podio::utils::MaybeSharedPtr<MCRecoParticleAssociationObj>{nullptr}),
      m_collection(collection) {
  }

  MCRecoParticleAssociationMutableCollectionIterator(const MCRecoParticleAssociationMutableCollectionIterator&) =
      delete;
  MCRecoParticleAssociationMutableCollectionIterator&
  operator=(const MCRecoParticleAssociationMutableCollectionIterator&) = delete;

  bool operator!=(const MCRecoParticleAssociationMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const MCRecoParticleAssociationMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableMCRecoParticleAssociation operator*();
  MutableMCRecoParticleAssociation* operator->();
  MCRecoParticleAssociationMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableMCRecoParticleAssociation m_object;
  const MCRecoParticleAssociationObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class MCRecoParticleAssociationCollection : public podio::CollectionBase {
public:
  using value_type = MCRecoParticleAssociation;
  using const_iterator = MCRecoParticleAssociationCollectionIterator;
  using iterator = MCRecoParticleAssociationMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  MCRecoParticleAssociationCollection();
  MCRecoParticleAssociationCollection(MCRecoParticleAssociationCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  MCRecoParticleAssociationCollection(const MCRecoParticleAssociationCollection&) = delete;
  MCRecoParticleAssociationCollection& operator=(const MCRecoParticleAssociationCollection&) = delete;
  MCRecoParticleAssociationCollection(MCRecoParticleAssociationCollection&&) = default;
  MCRecoParticleAssociationCollection& operator=(MCRecoParticleAssociationCollection&&) = default;

  //  MCRecoParticleAssociationCollection(MCRecoParticleAssociationVector* data, uint32_t collectionID);
  ~MCRecoParticleAssociationCollection();

  constexpr static auto typeName = "edm4hep::MCRecoParticleAssociationCollection";
  constexpr static auto valueTypeName = "edm4hep::MCRecoParticleAssociation";
  constexpr static auto dataTypeName = "edm4hep::MCRecoParticleAssociationData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  MCRecoParticleAssociationCollection* operator->() {
    return (MCRecoParticleAssociationCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableMCRecoParticleAssociation create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableMCRecoParticleAssociation create(Args&&... args);

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
  MCRecoParticleAssociation operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableMCRecoParticleAssociation operator[](std::size_t index);
  /// Returns the const object of given index
  MCRecoParticleAssociation at(std::size_t index) const;
  /// Returns the object of given index
  MutableMCRecoParticleAssociation at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableMCRecoParticleAssociation& object);
  /// Append an object to the (subset) collection
  void push_back(const MCRecoParticleAssociation& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](MCRecoParticleAssociationObj* obj) {
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
  friend class MCRecoParticleAssociationCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable MCRecoParticleAssociationCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const MCRecoParticleAssociationCollection& v);

template <typename... Args>
MutableMCRecoParticleAssociation MCRecoParticleAssociationCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new MCRecoParticleAssociationObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  return MutableMCRecoParticleAssociation(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MCRecoParticleAssociationCollection& collection);
#endif

} // namespace edm4hep

#endif
