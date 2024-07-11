// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoTrackerHitPlaneAssociationCollection.h"
#include "edm4hep/MCRecoTrackerHitPlaneAssociationCollectionData.h"

#include "edm4hep/SimTrackerHitCollection.h"
#include "edm4hep/TrackerHitPlaneCollection.h"

namespace edm4hep {

MCRecoTrackerHitPlaneAssociationCollectionData::MCRecoTrackerHitPlaneAssociationCollectionData() :
    m_rel_rec(new std::vector<edm4hep::TrackerHitPlane>()),
    m_rel_sim(new std::vector<edm4hep::SimTrackerHit>()),
    m_data(new MCRecoTrackerHitPlaneAssociationDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
}

MCRecoTrackerHitPlaneAssociationCollectionData::MCRecoTrackerHitPlaneAssociationCollectionData(
    podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_rel_rec(new std::vector<edm4hep::TrackerHitPlane>()),
    m_rel_sim(new std::vector<edm4hep::SimTrackerHit>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::MCRecoTrackerHitPlaneAssociationData>());
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void MCRecoTrackerHitPlaneAssociationCollectionData::clear(bool isSubsetColl) {
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
  if (m_rel_rec) {
    for (auto& item : (*m_rel_rec)) {
      item.unlink();
    }
    m_rel_rec->clear();
  }

  if (m_rel_sim) {
    for (auto& item : (*m_rel_sim)) {
      item.unlink();
    }
    m_rel_sim->clear();
  }

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers MCRecoTrackerHitPlaneAssociationCollectionData::getCollectionBuffers(bool isSubsetColl) {
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void MCRecoTrackerHitPlaneAssociationCollectionData::prepareForWrite(bool isSubsetColl) {
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
    if (obj->m_rec) {
      m_refCollections[0]->emplace_back(obj->m_rec->getObjectID());
    } else {
      m_refCollections[0]->push_back({podio::ObjectID::invalid, 0});
    }
  }

  for (auto& obj : entries) {
    if (obj->m_sim) {
      m_refCollections[1]->emplace_back(obj->m_sim->getObjectID());
    } else {
      m_refCollections[1]->push_back({podio::ObjectID::invalid, 0});
    }
  }
}

void MCRecoTrackerHitPlaneAssociationCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new MCRecoTrackerHitPlaneAssociationObj({index, collectionID}, data);

    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

bool MCRecoTrackerHitPlaneAssociationCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider,
                                                                   bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::MCRecoTrackerHitPlaneAssociationObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::MCRecoTrackerHitPlaneAssociationCollection*>(coll);
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
        entries[i]->m_rec = nullptr;
        continue;
      }
      edm4hep::TrackerHitPlaneCollection* tmp_coll = static_cast<edm4hep::TrackerHitPlaneCollection*>(coll);
      entries[i]->m_rec = new edm4hep::TrackerHitPlane((*tmp_coll)[id.index]);
    } else {
      entries[i]->m_rec = nullptr;
    }
  }

  for (unsigned int i = 0, size = entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        entries[i]->m_sim = nullptr;
        continue;
      }
      edm4hep::SimTrackerHitCollection* tmp_coll = static_cast<edm4hep::SimTrackerHitCollection*>(coll);
      entries[i]->m_sim = new edm4hep::SimTrackerHit((*tmp_coll)[id.index]);
    } else {
      entries[i]->m_sim = nullptr;
    }
  }

  return true; // TODO: check success, how?
}

void MCRecoTrackerHitPlaneAssociationCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_rec.reset(nullptr);
  m_rel_sim.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
