// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ClusterCollection.h"
#include "edm4hep/ClusterCollectionData.h"

#include "edm4hep/CalorimeterHitCollection.h"
#include <numeric>

namespace edm4hep {

ClusterCollectionData::ClusterCollectionData() :
    m_rel_clusters(new std::vector<edm4hep::Cluster>()),
    m_rel_hits(new std::vector<edm4hep::CalorimeterHit>()),
    m_vec_shapeParameters(new std::vector<float>()),
    m_vec_subdetectorEnergies(new std::vector<float>()),
    m_data(new ClusterDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_vecmem_info.emplace_back("float", &m_vec_shapeParameters);
  m_vecmem_info.emplace_back("float", &m_vec_subdetectorEnergies);
}

ClusterCollectionData::ClusterCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_rel_clusters(new std::vector<edm4hep::Cluster>()),
    m_rel_hits(new std::vector<edm4hep::CalorimeterHit>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::ClusterData>());

    m_vec_shapeParameters.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[0].second));
    m_vec_subdetectorEnergies.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[1].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void ClusterCollectionData::clear(bool isSubsetColl) {
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
  // clear relations to clusters. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_clusters_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_clusters_tmp.clear();
  if (m_rel_clusters) {
    for (auto& item : (*m_rel_clusters)) {
      item.unlink();
    }
    m_rel_clusters->clear();
  }

  // clear relations to hits. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_hits_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_hits_tmp.clear();
  if (m_rel_hits) {
    for (auto& item : (*m_rel_hits)) {
      item.unlink();
    }
    m_rel_hits->clear();
  }

  if (m_vec_shapeParameters)
    m_vec_shapeParameters->clear();
  m_vecs_shapeParameters.clear();

  if (m_vec_subdetectorEnergies)
    m_vec_subdetectorEnergies->clear();
  m_vecs_subdetectorEnergies.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers ClusterCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_shapeParameters;
    m_vecmem_info[1].second = &m_vec_subdetectorEnergies;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void ClusterCollectionData::prepareForWrite(bool isSubsetColl) {
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

  int clusters_index = 0;
  int hits_index = 0;
  const auto shapeParameters_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const ClusterObj* obj) { return sum + obj->m_shapeParameters->size(); });
  m_vec_shapeParameters->reserve(shapeParameters_size);
  int shapeParameters_index = 0;
  const auto subdetectorEnergies_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const ClusterObj* obj) { return sum + obj->m_subdetectorEnergies->size(); });
  m_vec_subdetectorEnergies->reserve(subdetectorEnergies_size);
  int subdetectorEnergies_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].clusters_begin = clusters_index;
    (*m_data)[i].clusters_end += clusters_index;
    clusters_index = (*m_data)[i].clusters_end;
    for (const auto& it : (*m_rel_clusters_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[0]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].hits_begin = hits_index;
    (*m_data)[i].hits_end += hits_index;
    hits_index = (*m_data)[i].hits_end;
    for (const auto& it : (*m_rel_hits_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[1]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].shapeParameters_begin = shapeParameters_index;
    (*m_data)[i].shapeParameters_end += shapeParameters_index;
    shapeParameters_index = (*m_data)[i].shapeParameters_end;
    for (const auto& it : (*m_vecs_shapeParameters[i])) {
      m_vec_shapeParameters->push_back(it);
    }

    (*m_data)[i].subdetectorEnergies_begin = subdetectorEnergies_index;
    (*m_data)[i].subdetectorEnergies_end += subdetectorEnergies_index;
    subdetectorEnergies_index = (*m_data)[i].subdetectorEnergies_end;
    for (const auto& it : (*m_vecs_subdetectorEnergies[i])) {
      m_vec_subdetectorEnergies->push_back(it);
    }
  }
}

void ClusterCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new ClusterObj({index, collectionID}, data);

    obj->m_clusters = m_rel_clusters.get();
    obj->m_hits = m_rel_hits.get();
    obj->m_shapeParameters = m_vec_shapeParameters.get();
    obj->m_subdetectorEnergies = m_vec_subdetectorEnergies.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void ClusterCollectionData::createRelations(ClusterObj* obj) {
  // We take ownership of these here
  m_rel_clusters_tmp.emplace_back(obj->m_clusters);
  // We take ownership of these here
  m_rel_hits_tmp.emplace_back(obj->m_hits);
  // We take ownership of these here
  m_vecs_shapeParameters.emplace_back(obj->m_shapeParameters);
  // We take ownership of these here
  m_vecs_subdetectorEnergies.emplace_back(obj->m_subdetectorEnergies);
}

bool ClusterCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::ClusterObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::ClusterCollection*>(coll);
        obj = tmp_coll->m_storage.entries[id.index];
      }
      entries.push_back(obj);
    }
    return true; // TODO: check success, how?
  }

  // Normal collections have to resolve all relations
  for (unsigned int i = 0, size = m_refCollections[0]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        m_rel_clusters->emplace_back(edm4hep::Cluster::makeEmpty());
        continue;
      }
      edm4hep::ClusterCollection* tmp_coll = static_cast<edm4hep::ClusterCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_clusters->emplace_back(tmp);
    } else {
      m_rel_clusters->emplace_back(edm4hep::Cluster::makeEmpty());
    }
  }

  for (unsigned int i = 0, size = m_refCollections[1]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        m_rel_hits->emplace_back(edm4hep::CalorimeterHit::makeEmpty());
        continue;
      }
      edm4hep::CalorimeterHitCollection* tmp_coll = static_cast<edm4hep::CalorimeterHitCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_hits->emplace_back(tmp);
    } else {
      m_rel_hits->emplace_back(edm4hep::CalorimeterHit::makeEmpty());
    }
  }

  return true; // TODO: check success, how?
}

void ClusterCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_clusters.reset(nullptr);
  m_rel_hits.reset(nullptr);
  m_vec_shapeParameters.reset(nullptr);
  m_vec_subdetectorEnergies.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
