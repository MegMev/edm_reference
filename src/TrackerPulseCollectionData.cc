// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackerPulseCollection.h"
#include "edm4hep/TrackerPulseCollectionData.h"

#include "edm4hep/TimeSeriesCollection.h"

namespace edm4hep {

TrackerPulseCollectionData::TrackerPulseCollectionData() :
    m_rel_timeSeries(new std::vector<edm4hep::TimeSeries>()), m_data(new TrackerPulseDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
}

TrackerPulseCollectionData::TrackerPulseCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_rel_timeSeries(new std::vector<edm4hep::TimeSeries>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::TrackerPulseData>());
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void TrackerPulseCollectionData::clear(bool isSubsetColl) {
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
  for (auto& pointer : m_refCollections) {
    pointer->clear();
  }
  if (m_rel_timeSeries) {
    for (auto& item : (*m_rel_timeSeries)) {
      item.unlink();
    }
    m_rel_timeSeries->clear();
  }

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers TrackerPulseCollectionData::getCollectionBuffers(bool isSubsetColl) {
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void TrackerPulseCollectionData::prepareForWrite(bool isSubsetColl) {
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

  for (auto& obj : entries) {
    if (obj->m_timeSeries) {
      m_refCollections[0]->emplace_back(obj->m_timeSeries->getObjectID());
    } else {
      m_refCollections[0]->push_back({podio::ObjectID::invalid, 0});
    }
  }
}

void TrackerPulseCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new TrackerPulseObj({index, collectionID}, data);

    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

bool TrackerPulseCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider,
                                               bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::TrackerPulseObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::TrackerPulseCollection*>(coll);
        obj = tmp_coll->m_storage.entries[id.index];
      }
      entries.push_back(obj);
    }
    return true; // TODO: check success, how?
  }

  // Normal collections have to resolve all relations
  for (unsigned int i = 0, size = entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        entries[i]->m_timeSeries = nullptr;
        continue;
      }
      edm4hep::TimeSeriesCollection* tmp_coll = static_cast<edm4hep::TimeSeriesCollection*>(coll);
      entries[i]->m_timeSeries = new edm4hep::TimeSeries((*tmp_coll)[id.index]);
    } else {
      entries[i]->m_timeSeries = nullptr;
    }
  }

  return true; // TODO: check success, how?
}

void TrackerPulseCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_timeSeries.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
