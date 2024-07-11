// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit3DCollection_H
#define EDM4HEP_TrackerHit3DCollection_H

// datamodel specific includes
#include "edm4hep/MutableTrackerHit3D.h"
#include "edm4hep/TrackerHit3D.h"
#include "edm4hep/TrackerHit3DCollectionData.h"
#include "edm4hep/TrackerHit3DData.h"
#include "edm4hep/TrackerHit3DObj.h"

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

class TrackerHit3DCollectionIterator {
public:
  TrackerHit3DCollectionIterator(size_t index, const TrackerHit3DObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TrackerHit3DObj>{nullptr}), m_collection(collection) {
  }

  TrackerHit3DCollectionIterator(const TrackerHit3DCollectionIterator&) = delete;
  TrackerHit3DCollectionIterator& operator=(const TrackerHit3DCollectionIterator&) = delete;

  bool operator!=(const TrackerHit3DCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TrackerHit3DCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  TrackerHit3D operator*();
  TrackerHit3D* operator->();
  TrackerHit3DCollectionIterator& operator++();

private:
  size_t m_index;
  TrackerHit3D m_object;
  const TrackerHit3DObjPointerContainer* m_collection;
};

class TrackerHit3DMutableCollectionIterator {
public:
  TrackerHit3DMutableCollectionIterator(size_t index, const TrackerHit3DObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TrackerHit3DObj>{nullptr}), m_collection(collection) {
  }

  TrackerHit3DMutableCollectionIterator(const TrackerHit3DMutableCollectionIterator&) = delete;
  TrackerHit3DMutableCollectionIterator& operator=(const TrackerHit3DMutableCollectionIterator&) = delete;

  bool operator!=(const TrackerHit3DMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TrackerHit3DMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableTrackerHit3D operator*();
  MutableTrackerHit3D* operator->();
  TrackerHit3DMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableTrackerHit3D m_object;
  const TrackerHit3DObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class TrackerHit3DCollection : public podio::CollectionBase {
public:
  using value_type = TrackerHit3D;
  using const_iterator = TrackerHit3DCollectionIterator;
  using iterator = TrackerHit3DMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  TrackerHit3DCollection();
  TrackerHit3DCollection(TrackerHit3DCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  TrackerHit3DCollection(const TrackerHit3DCollection&) = delete;
  TrackerHit3DCollection& operator=(const TrackerHit3DCollection&) = delete;
  TrackerHit3DCollection(TrackerHit3DCollection&&) = default;
  TrackerHit3DCollection& operator=(TrackerHit3DCollection&&) = default;

  //  TrackerHit3DCollection(TrackerHit3DVector* data, uint32_t collectionID);
  ~TrackerHit3DCollection();

  constexpr static auto typeName = "edm4hep::TrackerHit3DCollection";
  constexpr static auto valueTypeName = "edm4hep::TrackerHit3D";
  constexpr static auto dataTypeName = "edm4hep::TrackerHit3DData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  TrackerHit3DCollection* operator->() {
    return (TrackerHit3DCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableTrackerHit3D create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableTrackerHit3D create(Args&&... args);

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
  TrackerHit3D operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableTrackerHit3D operator[](std::size_t index);
  /// Returns the const object of given index
  TrackerHit3D at(std::size_t index) const;
  /// Returns the object of given index
  MutableTrackerHit3D at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableTrackerHit3D& object);
  /// Append an object to the (subset) collection
  void push_back(const TrackerHit3D& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](TrackerHit3DObj* obj) {
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
  std::vector<std::int32_t> type(const size_t nElem = 0) const;
  std::vector<std::int32_t> quality(const size_t nElem = 0) const;
  std::vector<float> time(const size_t nElem = 0) const;
  std::vector<float> eDep(const size_t nElem = 0) const;
  std::vector<float> eDepError(const size_t nElem = 0) const;
  std::vector<edm4hep::Vector3d> position(const size_t nElem = 0) const;
  std::vector<edm4hep::CovMatrix3f> covMatrix(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class TrackerHit3DCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable TrackerHit3DCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const TrackerHit3DCollection& v);

template <typename... Args>
MutableTrackerHit3D TrackerHit3DCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new TrackerHit3DObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  return MutableTrackerHit3D(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerHit3DCollection& collection);
#endif

} // namespace edm4hep

#endif
