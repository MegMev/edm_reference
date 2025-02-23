// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/EventHeaderCollection.h"
#include "edm4hep/EventHeaderCollectionData.h"

#include <numeric>

namespace edm4hep {

EventHeaderCollectionData::EventHeaderCollectionData() :
    m_vec_weights(new std::vector<double>()), m_data(new EventHeaderDataContainer()) {
  m_vecmem_info.emplace_back("double", &m_vec_weights);
}

EventHeaderCollectionData::EventHeaderCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_refCollections(std::move(*buffers.references)), m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::EventHeaderData>());

    m_vec_weights.reset(podio::CollectionReadBuffers::asVector<double>(m_vecmem_info[0].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void EventHeaderCollectionData::clear(bool isSubsetColl) {
  if (isSubsetColl) {
    // We don't own the objects so no cleanup to do here
    entries.clear();
    // Clear the ObjectID I/O buffer
    for (auto& pointer : m_refCollections) {
      pointer->clear();
    }
    return;
  }

  // Normal collections manage a bit more and have to clean up a bit more
  if (m_data)
    m_data->clear();
  if (m_vec_weights)
    m_vec_weights->clear();
  m_vecs_weights.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers EventHeaderCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_weights;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void EventHeaderCollectionData::prepareForWrite(bool isSubsetColl) {
  for (auto& pointer : m_refCollections) {
    pointer->clear();
  }

  // If this is a subset collection use the relation storing mechanism to
  // store the ObjectIDs of all referenced objects and nothing else
  if (isSubsetColl) {
    for (const auto* obj : entries) {
      m_refCollections[0]->emplace_back(obj->id);
    }
    return;
  }

  // Normal collections have to store the data and all the relations
  m_data->reserve(entries.size());
  for (auto& obj : entries) {
    m_data->push_back(obj->data);
  }

  const auto weights_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const EventHeaderObj* obj) { return sum + obj->m_weights->size(); });
  m_vec_weights->reserve(weights_size);
  int weights_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].weights_begin = weights_index;
    (*m_data)[i].weights_end += weights_index;
    weights_index = (*m_data)[i].weights_end;
    for (const auto& it : (*m_vecs_weights[i])) {
      m_vec_weights->push_back(it);
    }
  }
}

void EventHeaderCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new EventHeaderObj({index, collectionID}, data);

    obj->m_weights = m_vec_weights.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void EventHeaderCollectionData::createRelations(EventHeaderObj* obj) {
  // We take ownership of these here
  m_vecs_weights.emplace_back(obj->m_weights);
}

bool EventHeaderCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::EventHeaderObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::EventHeaderCollection*>(coll);
        obj = tmp_coll->m_storage.entries[id.index];
      }
      entries.push_back(obj);
    }
    return true; // TODO: check success, how?
  }

  // Normal collections have to resolve all relations

  return true; // TODO: check success, how?
}

void EventHeaderCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_vec_weights.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
