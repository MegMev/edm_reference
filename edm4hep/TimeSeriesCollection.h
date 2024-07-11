// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TimeSeriesCollection_H
#define EDM4HEP_TimeSeriesCollection_H

// datamodel specific includes
#include "edm4hep/MutableTimeSeries.h"
#include "edm4hep/TimeSeries.h"
#include "edm4hep/TimeSeriesCollectionData.h"
#include "edm4hep/TimeSeriesData.h"
#include "edm4hep/TimeSeriesObj.h"

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

class TimeSeriesCollectionIterator {
public:
  TimeSeriesCollectionIterator(size_t index, const TimeSeriesObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TimeSeriesObj>{nullptr}), m_collection(collection) {
  }

  TimeSeriesCollectionIterator(const TimeSeriesCollectionIterator&) = delete;
  TimeSeriesCollectionIterator& operator=(const TimeSeriesCollectionIterator&) = delete;

  bool operator!=(const TimeSeriesCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TimeSeriesCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  TimeSeries operator*();
  TimeSeries* operator->();
  TimeSeriesCollectionIterator& operator++();

private:
  size_t m_index;
  TimeSeries m_object;
  const TimeSeriesObjPointerContainer* m_collection;
};

class TimeSeriesMutableCollectionIterator {
public:
  TimeSeriesMutableCollectionIterator(size_t index, const TimeSeriesObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TimeSeriesObj>{nullptr}), m_collection(collection) {
  }

  TimeSeriesMutableCollectionIterator(const TimeSeriesMutableCollectionIterator&) = delete;
  TimeSeriesMutableCollectionIterator& operator=(const TimeSeriesMutableCollectionIterator&) = delete;

  bool operator!=(const TimeSeriesMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TimeSeriesMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableTimeSeries operator*();
  MutableTimeSeries* operator->();
  TimeSeriesMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableTimeSeries m_object;
  const TimeSeriesObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class TimeSeriesCollection : public podio::CollectionBase {
public:
  using value_type = TimeSeries;
  using const_iterator = TimeSeriesCollectionIterator;
  using iterator = TimeSeriesMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  TimeSeriesCollection();
  TimeSeriesCollection(TimeSeriesCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  TimeSeriesCollection(const TimeSeriesCollection&) = delete;
  TimeSeriesCollection& operator=(const TimeSeriesCollection&) = delete;
  TimeSeriesCollection(TimeSeriesCollection&&) = default;
  TimeSeriesCollection& operator=(TimeSeriesCollection&&) = default;

  //  TimeSeriesCollection(TimeSeriesVector* data, uint32_t collectionID);
  ~TimeSeriesCollection();

  constexpr static auto typeName = "edm4hep::TimeSeriesCollection";
  constexpr static auto valueTypeName = "edm4hep::TimeSeries";
  constexpr static auto dataTypeName = "edm4hep::TimeSeriesData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  TimeSeriesCollection* operator->() {
    return (TimeSeriesCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableTimeSeries create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableTimeSeries create(Args&&... args);

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
  TimeSeries operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableTimeSeries operator[](std::size_t index);
  /// Returns the const object of given index
  TimeSeries at(std::size_t index) const;
  /// Returns the object of given index
  MutableTimeSeries at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableTimeSeries& object);
  /// Append an object to the (subset) collection
  void push_back(const TimeSeries& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](TimeSeriesObj* obj) {
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
  std::vector<float> interval(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class TimeSeriesCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable TimeSeriesCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const TimeSeriesCollection& v);

template <typename... Args>
MutableTimeSeries TimeSeriesCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new TimeSeriesObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, TimeSeriesData} constructor
  obj->m_amplitude = new std::vector<float>();
  m_storage.createRelations(obj);
  return MutableTimeSeries(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TimeSeriesCollection& collection);
#endif

} // namespace edm4hep

#endif
