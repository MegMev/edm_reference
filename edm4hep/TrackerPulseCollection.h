// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerPulseCollection_H
#define EDM4HEP_TrackerPulseCollection_H

// datamodel specific includes
#include "edm4hep/MutableTrackerPulse.h"
#include "edm4hep/TrackerPulse.h"
#include "edm4hep/TrackerPulseCollectionData.h"
#include "edm4hep/TrackerPulseData.h"
#include "edm4hep/TrackerPulseObj.h"

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

class TrackerPulseCollectionIterator {
public:
  TrackerPulseCollectionIterator(size_t index, const TrackerPulseObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TrackerPulseObj>{nullptr}), m_collection(collection) {
  }

  TrackerPulseCollectionIterator(const TrackerPulseCollectionIterator&) = delete;
  TrackerPulseCollectionIterator& operator=(const TrackerPulseCollectionIterator&) = delete;

  bool operator!=(const TrackerPulseCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TrackerPulseCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  TrackerPulse operator*();
  TrackerPulse* operator->();
  TrackerPulseCollectionIterator& operator++();

private:
  size_t m_index;
  TrackerPulse m_object;
  const TrackerPulseObjPointerContainer* m_collection;
};

class TrackerPulseMutableCollectionIterator {
public:
  TrackerPulseMutableCollectionIterator(size_t index, const TrackerPulseObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TrackerPulseObj>{nullptr}), m_collection(collection) {
  }

  TrackerPulseMutableCollectionIterator(const TrackerPulseMutableCollectionIterator&) = delete;
  TrackerPulseMutableCollectionIterator& operator=(const TrackerPulseMutableCollectionIterator&) = delete;

  bool operator!=(const TrackerPulseMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TrackerPulseMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableTrackerPulse operator*();
  MutableTrackerPulse* operator->();
  TrackerPulseMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableTrackerPulse m_object;
  const TrackerPulseObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class TrackerPulseCollection : public podio::CollectionBase {
public:
  using value_type = TrackerPulse;
  using const_iterator = TrackerPulseCollectionIterator;
  using iterator = TrackerPulseMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  TrackerPulseCollection();
  TrackerPulseCollection(TrackerPulseCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  TrackerPulseCollection(const TrackerPulseCollection&) = delete;
  TrackerPulseCollection& operator=(const TrackerPulseCollection&) = delete;
  TrackerPulseCollection(TrackerPulseCollection&&) = default;
  TrackerPulseCollection& operator=(TrackerPulseCollection&&) = default;

  //  TrackerPulseCollection(TrackerPulseVector* data, uint32_t collectionID);
  ~TrackerPulseCollection();

  constexpr static auto typeName = "edm4hep::TrackerPulseCollection";
  constexpr static auto valueTypeName = "edm4hep::TrackerPulse";
  constexpr static auto dataTypeName = "edm4hep::TrackerPulseData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  TrackerPulseCollection* operator->() {
    return (TrackerPulseCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableTrackerPulse create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableTrackerPulse create(Args&&... args);

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
  TrackerPulse operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableTrackerPulse operator[](std::size_t index);
  /// Returns the const object of given index
  TrackerPulse at(std::size_t index) const;
  /// Returns the object of given index
  MutableTrackerPulse at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableTrackerPulse& object);
  /// Append an object to the (subset) collection
  void push_back(const TrackerPulse& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](TrackerPulseObj* obj) {
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
  std::vector<float> charge(const size_t nElem = 0) const;
  std::vector<std::int16_t> quality(const size_t nElem = 0) const;
  std::vector<std::array<float, 3>> covMatrix(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class TrackerPulseCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable TrackerPulseCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const TrackerPulseCollection& v);

template <typename... Args>
MutableTrackerPulse TrackerPulseCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new TrackerPulseObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  return MutableTrackerPulse(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackerPulseCollection& collection);
#endif

} // namespace edm4hep

#endif
