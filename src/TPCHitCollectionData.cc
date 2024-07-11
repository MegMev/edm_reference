// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TPCHitCollection.h"
#include "edm4hep/TPCHitCollectionData.h"

#include <numeric>

namespace edm4hep {

TPCHitCollectionData::TPCHitCollectionData() :
    m_vec_rawDataWords(new std::vector<std::int32_t>()), m_data(new TPCHitDataContainer()) {
  m_vecmem_info.emplace_back("std::int32_t", &m_vec_rawDataWords);
}

TPCHitCollectionData::TPCHitCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_refCollections(std::move(*buffers.references)), m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::TPCHitData>());

    m_vec_rawDataWords.reset(podio::CollectionReadBuffers::asVector<std::int32_t>(m_vecmem_info[0].second));
  }
}

void TPCHitCollectionData::clear(bool isSubsetColl) {
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
  if (m_vec_rawDataWords)
    m_vec_rawDataWords->clear();
  m_vecs_rawDataWords.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers TPCHitCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_rawDataWords;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void TPCHitCollectionData::prepareForWrite(bool isSubsetColl) {
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

  const auto rawDataWords_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const TPCHitObj* obj) { return sum + obj->m_rawDataWords->size(); });
  m_vec_rawDataWords->reserve(rawDataWords_size);
  int rawDataWords_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].rawDataWords_begin = rawDataWords_index;
    (*m_data)[i].rawDataWords_end += rawDataWords_index;
    rawDataWords_index = (*m_data)[i].rawDataWords_end;
    for (const auto& it : (*m_vecs_rawDataWords[i])) {
      m_vec_rawDataWords->push_back(it);
    }
  }
}

void TPCHitCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new TPCHitObj({index, collectionID}, data);

    obj->m_rawDataWords = m_vec_rawDataWords.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void TPCHitCollectionData::createRelations(TPCHitObj* obj) {
  // We take ownership of these here
  m_vecs_rawDataWords.emplace_back(obj->m_rawDataWords);
}

bool TPCHitCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::TPCHitObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::TPCHitCollection*>(coll);
        obj = tmp_coll->m_storage.entries[id.index];
      }
      entries.push_back(obj);
    }
    return true; // TODO: check success, how?
  }

  // Normal collections have to resolve all relations

  return true; // TODO: check success, how?
}

void TPCHitCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_vec_rawDataWords.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
