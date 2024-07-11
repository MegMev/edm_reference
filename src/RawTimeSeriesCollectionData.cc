// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RawTimeSeriesCollection.h"
#include "edm4hep/RawTimeSeriesCollectionData.h"

#include <numeric>

namespace edm4hep {

RawTimeSeriesCollectionData::RawTimeSeriesCollectionData() :
    m_vec_adcCounts(new std::vector<std::int32_t>()), m_data(new RawTimeSeriesDataContainer()) {
  m_vecmem_info.emplace_back("std::int32_t", &m_vec_adcCounts);
}

RawTimeSeriesCollectionData::RawTimeSeriesCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_refCollections(std::move(*buffers.references)), m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::RawTimeSeriesData>());

    m_vec_adcCounts.reset(podio::CollectionReadBuffers::asVector<std::int32_t>(m_vecmem_info[0].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void RawTimeSeriesCollectionData::clear(bool isSubsetColl) {
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
  if (m_vec_adcCounts)
    m_vec_adcCounts->clear();
  m_vecs_adcCounts.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers RawTimeSeriesCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_adcCounts;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void RawTimeSeriesCollectionData::prepareForWrite(bool isSubsetColl) {
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

  const auto adcCounts_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const RawTimeSeriesObj* obj) { return sum + obj->m_adcCounts->size(); });
  m_vec_adcCounts->reserve(adcCounts_size);
  int adcCounts_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].adcCounts_begin = adcCounts_index;
    (*m_data)[i].adcCounts_end += adcCounts_index;
    adcCounts_index = (*m_data)[i].adcCounts_end;
    for (const auto& it : (*m_vecs_adcCounts[i])) {
      m_vec_adcCounts->push_back(it);
    }
  }
}

void RawTimeSeriesCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new RawTimeSeriesObj({index, collectionID}, data);

    obj->m_adcCounts = m_vec_adcCounts.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void RawTimeSeriesCollectionData::createRelations(RawTimeSeriesObj* obj) {
  // We take ownership of these here
  m_vecs_adcCounts.emplace_back(obj->m_adcCounts);
}

bool RawTimeSeriesCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider,
                                                bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::RawTimeSeriesObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::RawTimeSeriesCollection*>(coll);
        obj = tmp_coll->m_storage.entries[id.index];
      }
      entries.push_back(obj);
    }
    return true; // TODO: check success, how?
  }

  // Normal collections have to resolve all relations

  return true; // TODO: check success, how?
}

void RawTimeSeriesCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_vec_adcCounts.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
