// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackCollection_H
#define EDM4HEP_TrackCollection_H

// datamodel specific includes
#include "edm4hep/MutableTrack.h"
#include "edm4hep/Track.h"
#include "edm4hep/TrackCollectionData.h"
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackObj.h"

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

class TrackCollectionIterator {
public:
  TrackCollectionIterator(size_t index, const TrackObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TrackObj>{nullptr}), m_collection(collection) {
  }

  TrackCollectionIterator(const TrackCollectionIterator&) = delete;
  TrackCollectionIterator& operator=(const TrackCollectionIterator&) = delete;

  bool operator!=(const TrackCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TrackCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  Track operator*();
  Track* operator->();
  TrackCollectionIterator& operator++();

private:
  size_t m_index;
  Track m_object;
  const TrackObjPointerContainer* m_collection;
};

class TrackMutableCollectionIterator {
public:
  TrackMutableCollectionIterator(size_t index, const TrackObjPointerContainer* collection) :
      m_index(index), m_object(podio::utils::MaybeSharedPtr<TrackObj>{nullptr}), m_collection(collection) {
  }

  TrackMutableCollectionIterator(const TrackMutableCollectionIterator&) = delete;
  TrackMutableCollectionIterator& operator=(const TrackMutableCollectionIterator&) = delete;

  bool operator!=(const TrackMutableCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  bool operator==(const TrackMutableCollectionIterator& x) const {
    return m_index == x.m_index; // TODO: may not be complete
  }

  MutableTrack operator*();
  MutableTrack* operator->();
  TrackMutableCollectionIterator& operator++();

private:
  size_t m_index;
  MutableTrack m_object;
  const TrackObjPointerContainer* m_collection;
};

/**
A Collection is identified by an ID.
*/
class TrackCollection : public podio::CollectionBase {
public:
  using value_type = Track;
  using const_iterator = TrackCollectionIterator;
  using iterator = TrackMutableCollectionIterator;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

  TrackCollection();
  TrackCollection(TrackCollectionData&& data, bool isSubsetColl);
  // This is a move-only type
  TrackCollection(const TrackCollection&) = delete;
  TrackCollection& operator=(const TrackCollection&) = delete;
  TrackCollection(TrackCollection&&) = default;
  TrackCollection& operator=(TrackCollection&&) = default;

  //  TrackCollection(TrackVector* data, uint32_t collectionID);
  ~TrackCollection();

  constexpr static auto typeName = "edm4hep::TrackCollection";
  constexpr static auto valueTypeName = "edm4hep::Track";
  constexpr static auto dataTypeName = "edm4hep::TrackData";

  void clear() final;

  /// Print this collection to the passed stream
  void print(std::ostream& os = std::cout, bool flush = true) const final;

  /// operator to allow pointer like calling of members a la LCIO
  TrackCollection* operator->() {
    return (TrackCollection*)this;
  }

  /// Append a new object to the collection, and return this object.
  MutableTrack create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template <typename... Args>
  MutableTrack create(Args&&... args);

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
  Track operator[](std::size_t index) const;
  /// Returns the object of a given index
  MutableTrack operator[](std::size_t index);
  /// Returns the const object of given index
  Track at(std::size_t index) const;
  /// Returns the object of given index
  MutableTrack at(std::size_t index);

  /// Append object to the collection
  void push_back(const MutableTrack& object);
  /// Append an object to the (subset) collection
  void push_back(const Track& object);

  void prepareForWrite() const final;
  void prepareAfterRead() final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) final;

  /// Get the collection buffers for this collection
  podio::CollectionWriteBuffers getBuffers() final;

  void setID(uint32_t ID) final {
    m_collectionID = ID;
    if (!m_isSubsetColl) {
      std::for_each(m_storage.entries.begin(), m_storage.entries.end(), [ID](TrackObj* obj) {
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
  std::vector<float> chi2(const size_t nElem = 0) const;
  std::vector<std::int32_t> ndf(const size_t nElem = 0) const;
  std::vector<float> dEdx(const size_t nElem = 0) const;
  std::vector<float> dEdxError(const size_t nElem = 0) const;
  std::vector<float> radiusOfInnermostHit(const size_t nElem = 0) const;

private:
  // For setReferences, we need to give our own CollectionData access to our
  // private entries. Otherwise we would need to expose a public member function
  // that gives access to the Obj* which is definitely not what we want
  friend class TrackCollectionData;

  bool m_isValid{false};
  mutable bool m_isPrepared{false};
  bool m_isSubsetColl{false};
  uint32_t m_collectionID{0};
  mutable std::unique_ptr<std::mutex> m_storageMtx{nullptr};
  mutable TrackCollectionData m_storage{};
};

std::ostream& operator<<(std::ostream& o, const TrackCollection& v);

template <typename... Args>
MutableTrack TrackCollection::create(Args&&... args) {
  if (m_isSubsetColl) {
    throw std::logic_error("Cannot create new elements on a subset collection");
  }
  const int size = m_storage.entries.size();
  auto obj = new TrackObj({size, m_collectionID}, {std::forward<Args>(args)...});
  m_storage.entries.push_back(obj);

  // Need to initialize the relation vectors manually for the {ObjectID, TrackData} constructor
  obj->m_trackerHits = new std::vector<edm4hep::TrackerHit>();
  obj->m_tracks = new std::vector<edm4hep::Track>();
  obj->m_subdetectorHitNumbers = new std::vector<std::int32_t>();
  obj->m_trackStates = new std::vector<edm4hep::TrackState>();
  obj->m_dxQuantities = new std::vector<edm4hep::Quantity>();
  m_storage.createRelations(obj);
  return MutableTrack(podio::utils::MaybeSharedPtr(obj));
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const TrackCollection& collection);
#endif

} // namespace edm4hep

#endif
