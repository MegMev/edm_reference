// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ReconstructedParticleCollection.h"
#include "edm4hep/ReconstructedParticleCollectionData.h"

#include "edm4hep/ClusterCollection.h"
#include "edm4hep/TrackCollection.h"
#include "edm4hep/VertexCollection.h"

namespace edm4hep {

ReconstructedParticleCollectionData::ReconstructedParticleCollectionData() :
    m_rel_clusters(new std::vector<edm4hep::Cluster>()),
    m_rel_tracks(new std::vector<edm4hep::Track>()),
    m_rel_particles(new std::vector<edm4hep::ReconstructedParticle>()),
    m_rel_startVertex(new std::vector<edm4hep::Vertex>()),
    m_data(new ReconstructedParticleDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
}

ReconstructedParticleCollectionData::ReconstructedParticleCollectionData(podio::CollectionReadBuffers buffers,
                                                                         bool isSubsetColl) :
    m_rel_clusters(new std::vector<edm4hep::Cluster>()),
    m_rel_tracks(new std::vector<edm4hep::Track>()),
    m_rel_particles(new std::vector<edm4hep::ReconstructedParticle>()),
    m_rel_startVertex(new std::vector<edm4hep::Vertex>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::ReconstructedParticleData>());
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void ReconstructedParticleCollectionData::clear(bool isSubsetColl) {
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

  // clear relations to tracks. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_tracks_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_tracks_tmp.clear();
  if (m_rel_tracks) {
    for (auto& item : (*m_rel_tracks)) {
      item.unlink();
    }
    m_rel_tracks->clear();
  }

  // clear relations to particles. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_particles_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_particles_tmp.clear();
  if (m_rel_particles) {
    for (auto& item : (*m_rel_particles)) {
      item.unlink();
    }
    m_rel_particles->clear();
  }

  if (m_rel_startVertex) {
    for (auto& item : (*m_rel_startVertex)) {
      item.unlink();
    }
    m_rel_startVertex->clear();
  }

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers ReconstructedParticleCollectionData::getCollectionBuffers(bool isSubsetColl) {
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void ReconstructedParticleCollectionData::prepareForWrite(bool isSubsetColl) {
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
  int tracks_index = 0;
  int particles_index = 0;
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

    (*m_data)[i].tracks_begin = tracks_index;
    (*m_data)[i].tracks_end += tracks_index;
    tracks_index = (*m_data)[i].tracks_end;
    for (const auto& it : (*m_rel_tracks_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[1]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].particles_begin = particles_index;
    (*m_data)[i].particles_end += particles_index;
    particles_index = (*m_data)[i].particles_end;
    for (const auto& it : (*m_rel_particles_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[2]->emplace_back(it.getObjectID());
    }
  }
  for (auto& obj : entries) {
    if (obj->m_startVertex) {
      m_refCollections[3]->emplace_back(obj->m_startVertex->getObjectID());
    } else {
      m_refCollections[3]->push_back({podio::ObjectID::invalid, 0});
    }
  }
}

void ReconstructedParticleCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new ReconstructedParticleObj({index, collectionID}, data);

    obj->m_clusters = m_rel_clusters.get();
    obj->m_tracks = m_rel_tracks.get();
    obj->m_particles = m_rel_particles.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void ReconstructedParticleCollectionData::createRelations(ReconstructedParticleObj* obj) {
  // We take ownership of these here
  m_rel_clusters_tmp.emplace_back(obj->m_clusters);
  // We take ownership of these here
  m_rel_tracks_tmp.emplace_back(obj->m_tracks);
  // We take ownership of these here
  m_rel_particles_tmp.emplace_back(obj->m_particles);
}

bool ReconstructedParticleCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider,
                                                        bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::ReconstructedParticleObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::ReconstructedParticleCollection*>(coll);
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
        m_rel_tracks->emplace_back(edm4hep::Track::makeEmpty());
        continue;
      }
      edm4hep::TrackCollection* tmp_coll = static_cast<edm4hep::TrackCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_tracks->emplace_back(tmp);
    } else {
      m_rel_tracks->emplace_back(edm4hep::Track::makeEmpty());
    }
  }

  for (unsigned int i = 0, size = m_refCollections[2]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[2])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        m_rel_particles->emplace_back(edm4hep::ReconstructedParticle::makeEmpty());
        continue;
      }
      edm4hep::ReconstructedParticleCollection* tmp_coll = static_cast<edm4hep::ReconstructedParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_particles->emplace_back(tmp);
    } else {
      m_rel_particles->emplace_back(edm4hep::ReconstructedParticle::makeEmpty());
    }
  }

  for (unsigned int i = 0, size = entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[3])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        entries[i]->m_startVertex = nullptr;
        continue;
      }
      edm4hep::VertexCollection* tmp_coll = static_cast<edm4hep::VertexCollection*>(coll);
      entries[i]->m_startVertex = new edm4hep::Vertex((*tmp_coll)[id.index]);
    } else {
      entries[i]->m_startVertex = nullptr;
    }
  }

  return true; // TODO: check success, how?
}

void ReconstructedParticleCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_clusters.reset(nullptr);
  m_rel_tracks.reset(nullptr);
  m_rel_particles.reset(nullptr);
  m_rel_startVertex.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
