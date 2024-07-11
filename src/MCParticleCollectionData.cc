// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticleCollection.h"
#include "edm4hep/MCParticleCollectionData.h"

namespace edm4hep {

MCParticleCollectionData::MCParticleCollectionData() :
    m_rel_parents(new std::vector<edm4hep::MCParticle>()),
    m_rel_daughters(new std::vector<edm4hep::MCParticle>()),
    m_data(new MCParticleDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
}

MCParticleCollectionData::MCParticleCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_rel_parents(new std::vector<edm4hep::MCParticle>()),
    m_rel_daughters(new std::vector<edm4hep::MCParticle>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::MCParticleData>());
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void MCParticleCollectionData::clear(bool isSubsetColl) {
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
  // clear relations to parents. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_parents_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_parents_tmp.clear();
  if (m_rel_parents) {
    for (auto& item : (*m_rel_parents)) {
      item.unlink();
    }
    m_rel_parents->clear();
  }

  // clear relations to daughters. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_daughters_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_daughters_tmp.clear();
  if (m_rel_daughters) {
    for (auto& item : (*m_rel_daughters)) {
      item.unlink();
    }
    m_rel_daughters->clear();
  }

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers MCParticleCollectionData::getCollectionBuffers(bool isSubsetColl) {
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void MCParticleCollectionData::prepareForWrite(bool isSubsetColl) {
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

  int parents_index = 0;
  int daughters_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].parents_begin = parents_index;
    (*m_data)[i].parents_end += parents_index;
    parents_index = (*m_data)[i].parents_end;
    for (const auto& it : (*m_rel_parents_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[0]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].daughters_begin = daughters_index;
    (*m_data)[i].daughters_end += daughters_index;
    daughters_index = (*m_data)[i].daughters_end;
    for (const auto& it : (*m_rel_daughters_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[1]->emplace_back(it.getObjectID());
    }
  }
}

void MCParticleCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new MCParticleObj({index, collectionID}, data);

    obj->m_parents = m_rel_parents.get();
    obj->m_daughters = m_rel_daughters.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void MCParticleCollectionData::createRelations(MCParticleObj* obj) {
  // We take ownership of these here
  m_rel_parents_tmp.emplace_back(obj->m_parents);
  // We take ownership of these here
  m_rel_daughters_tmp.emplace_back(obj->m_daughters);
}

bool MCParticleCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::MCParticleObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
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
        m_rel_parents->emplace_back(edm4hep::MCParticle::makeEmpty());
        continue;
      }
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_parents->emplace_back(tmp);
    } else {
      m_rel_parents->emplace_back(edm4hep::MCParticle::makeEmpty());
    }
  }

  for (unsigned int i = 0, size = m_refCollections[1]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
      podio::CollectionBase* coll = nullptr;
      if (!collectionProvider->get(id.collectionID, coll)) {
        m_rel_daughters->emplace_back(edm4hep::MCParticle::makeEmpty());
        continue;
      }
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_daughters->emplace_back(tmp);
    } else {
      m_rel_daughters->emplace_back(edm4hep::MCParticle::makeEmpty());
    }
  }

  return true; // TODO: check success, how?
}

void MCParticleCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_parents.reset(nullptr);
  m_rel_daughters.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
