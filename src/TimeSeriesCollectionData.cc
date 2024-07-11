// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TimeSeriesCollection.h"
#include "edm4hep/TimeSeriesCollectionData.h"

#include <numeric>

namespace edm4hep {

TimeSeriesCollectionData::TimeSeriesCollectionData() :
    m_vec_amplitude(new std::vector<float>()), m_data(new TimeSeriesDataContainer()) {
  m_vecmem_info.emplace_back("float", &m_vec_amplitude);
}

TimeSeriesCollectionData::TimeSeriesCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_refCollections(std::move(*buffers.references)), m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::TimeSeriesData>());

    m_vec_amplitude.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[0].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void TimeSeriesCollectionData::clear(bool isSubsetColl) {
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
  if (m_vec_amplitude)
    m_vec_amplitude->clear();
  m_vecs_amplitude.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers TimeSeriesCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_amplitude;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void TimeSeriesCollectionData::prepareForWrite(bool isSubsetColl) {
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

  const auto amplitude_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const TimeSeriesObj* obj) { return sum + obj->m_amplitude->size(); });
  m_vec_amplitude->reserve(amplitude_size);
  int amplitude_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].amplitude_begin = amplitude_index;
    (*m_data)[i].amplitude_end += amplitude_index;
    amplitude_index = (*m_data)[i].amplitude_end;
    for (const auto& it : (*m_vecs_amplitude[i])) {
      m_vec_amplitude->push_back(it);
    }
  }
}

void TimeSeriesCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new TimeSeriesObj({index, collectionID}, data);

    obj->m_amplitude = m_vec_amplitude.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void TimeSeriesCollectionData::createRelations(TimeSeriesObj* obj) {
  // We take ownership of these here
  m_vecs_amplitude.emplace_back(obj->m_amplitude);
}

bool TimeSeriesCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::TimeSeriesObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::TimeSeriesCollection*>(coll);
        obj = tmp_coll->m_storage.entries[id.index];
      }
      entries.push_back(obj);
    }
    return true; // TODO: check success, how?
  }

  // Normal collections have to resolve all relations

  return true; // TODO: check success, how?
}

void TimeSeriesCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_vec_amplitude.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
