// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimPrimaryIonizationClusterCollection.h"
#include "edm4hep/SimPrimaryIonizationClusterCollectionData.h"

#include "edm4hep/MCParticleCollection.h"
#include <numeric>

namespace edm4hep {

SimPrimaryIonizationClusterCollectionData::SimPrimaryIonizationClusterCollectionData() :
    m_rel_MCParticle(new std::vector<edm4hep::MCParticle>()),
    m_vec_electronCellID(new std::vector<std::uint64_t>()),
    m_vec_electronTime(new std::vector<float>()),
    m_vec_electronPosition(new std::vector<edm4hep::Vector3d>()),
    m_vec_pulseTime(new std::vector<float>()),
    m_vec_pulseAmplitude(new std::vector<float>()),
    m_data(new SimPrimaryIonizationClusterDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_vecmem_info.emplace_back("std::uint64_t", &m_vec_electronCellID);
  m_vecmem_info.emplace_back("float", &m_vec_electronTime);
  m_vecmem_info.emplace_back("edm4hep::Vector3d", &m_vec_electronPosition);
  m_vecmem_info.emplace_back("float", &m_vec_pulseTime);
  m_vecmem_info.emplace_back("float", &m_vec_pulseAmplitude);
}

SimPrimaryIonizationClusterCollectionData::SimPrimaryIonizationClusterCollectionData(
    podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_rel_MCParticle(new std::vector<edm4hep::MCParticle>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::SimPrimaryIonizationClusterData>());

    m_vec_electronCellID.reset(podio::CollectionReadBuffers::asVector<std::uint64_t>(m_vecmem_info[0].second));
    m_vec_electronTime.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[1].second));
    m_vec_electronPosition.reset(podio::CollectionReadBuffers::asVector<edm4hep::Vector3d>(m_vecmem_info[2].second));
    m_vec_pulseTime.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[3].second));
    m_vec_pulseAmplitude.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[4].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void SimPrimaryIonizationClusterCollectionData::clear(bool isSubsetColl) {
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
  if (m_rel_MCParticle) {
    for (auto& item : (*m_rel_MCParticle)) {
      item.unlink();
    }
    m_rel_MCParticle->clear();
  }

  if (m_vec_electronCellID)
    m_vec_electronCellID->clear();
  m_vecs_electronCellID.clear();

  if (m_vec_electronTime)
    m_vec_electronTime->clear();
  m_vecs_electronTime.clear();

  if (m_vec_electronPosition)
    m_vec_electronPosition->clear();
  m_vecs_electronPosition.clear();

  if (m_vec_pulseTime)
    m_vec_pulseTime->clear();
  m_vecs_pulseTime.clear();

  if (m_vec_pulseAmplitude)
    m_vec_pulseAmplitude->clear();
  m_vecs_pulseAmplitude.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers SimPrimaryIonizationClusterCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_electronCellID;
    m_vecmem_info[1].second = &m_vec_electronTime;
    m_vecmem_info[2].second = &m_vec_electronPosition;
    m_vecmem_info[3].second = &m_vec_pulseTime;
    m_vecmem_info[4].second = &m_vec_pulseAmplitude;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void SimPrimaryIonizationClusterCollectionData::prepareForWrite(bool isSubsetColl) {
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

  const auto electronCellID_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const SimPrimaryIonizationClusterObj* obj) {
        return sum + obj->m_electronCellID->size();
      });
  m_vec_electronCellID->reserve(electronCellID_size);
  int electronCellID_index = 0;
  const auto electronTime_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const SimPrimaryIonizationClusterObj* obj) {
        return sum + obj->m_electronTime->size();
      });
  m_vec_electronTime->reserve(electronTime_size);
  int electronTime_index = 0;
  const auto electronPosition_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const SimPrimaryIonizationClusterObj* obj) {
        return sum + obj->m_electronPosition->size();
      });
  m_vec_electronPosition->reserve(electronPosition_size);
  int electronPosition_index = 0;
  const auto pulseTime_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const SimPrimaryIonizationClusterObj* obj) {
        return sum + obj->m_pulseTime->size();
      });
  m_vec_pulseTime->reserve(pulseTime_size);
  int pulseTime_index = 0;
  const auto pulseAmplitude_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const SimPrimaryIonizationClusterObj* obj) {
        return sum + obj->m_pulseAmplitude->size();
      });
  m_vec_pulseAmplitude->reserve(pulseAmplitude_size);
  int pulseAmplitude_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].electronCellID_begin = electronCellID_index;
    (*m_data)[i].electronCellID_end += electronCellID_index;
    electronCellID_index = (*m_data)[i].electronCellID_end;
    for (const auto& it : (*m_vecs_electronCellID[i])) {
      m_vec_electronCellID->push_back(it);
    }

    (*m_data)[i].electronTime_begin = electronTime_index;
    (*m_data)[i].electronTime_end += electronTime_index;
    electronTime_index = (*m_data)[i].electronTime_end;
    for (const auto& it : (*m_vecs_electronTime[i])) {
      m_vec_electronTime->push_back(it);
    }

    (*m_data)[i].electronPosition_begin = electronPosition_index;
    (*m_data)[i].electronPosition_end += electronPosition_index;
    electronPosition_index = (*m_data)[i].electronPosition_end;
    for (const auto& it : (*m_vecs_electronPosition[i])) {
      m_vec_electronPosition->push_back(it);
    }

    (*m_data)[i].pulseTime_begin = pulseTime_index;
    (*m_data)[i].pulseTime_end += pulseTime_index;
    pulseTime_index = (*m_data)[i].pulseTime_end;
    for (const auto& it : (*m_vecs_pulseTime[i])) {
      m_vec_pulseTime->push_back(it);
    }

    (*m_data)[i].pulseAmplitude_begin = pulseAmplitude_index;
    (*m_data)[i].pulseAmplitude_end += pulseAmplitude_index;
    pulseAmplitude_index = (*m_data)[i].pulseAmplitude_end;
    for (const auto& it : (*m_vecs_pulseAmplitude[i])) {
      m_vec_pulseAmplitude->push_back(it);
    }
  }
  for (auto& obj : entries) {
    if (obj->m_MCParticle) {
      m_refCollections[0]->emplace_back(obj->m_MCParticle->getObjectID());
    } else {
      m_refCollections[0]->push_back({podio::ObjectID::invalid, 0});
    }
  }
}

void SimPrimaryIonizationClusterCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new SimPrimaryIonizationClusterObj({index, collectionID}, data);

    obj->m_electronCellID = m_vec_electronCellID.get();
    obj->m_electronTime = m_vec_electronTime.get();
    obj->m_electronPosition = m_vec_electronPosition.get();
    obj->m_pulseTime = m_vec_pulseTime.get();
    obj->m_pulseAmplitude = m_vec_pulseAmplitude.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void SimPrimaryIonizationClusterCollectionData::createRelations(SimPrimaryIonizationClusterObj* obj) {
  // We take ownership of these here
  m_vecs_electronCellID.emplace_back(obj->m_electronCellID);
  // We take ownership of these here
  m_vecs_electronTime.emplace_back(obj->m_electronTime);
  // We take ownership of these here
  m_vecs_electronPosition.emplace_back(obj->m_electronPosition);
  // We take ownership of these here
  m_vecs_pulseTime.emplace_back(obj->m_pulseTime);
  // We take ownership of these here
  m_vecs_pulseAmplitude.emplace_back(obj->m_pulseAmplitude);
}

bool SimPrimaryIonizationClusterCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider,
                                                              bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::SimPrimaryIonizationClusterObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::SimPrimaryIonizationClusterCollection*>(coll);
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
        entries[i]->m_MCParticle = nullptr;
        continue;
      }
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      entries[i]->m_MCParticle = new edm4hep::MCParticle((*tmp_coll)[id.index]);
    } else {
      entries[i]->m_MCParticle = nullptr;
    }
  }

  return true; // TODO: check success, how?
}

void SimPrimaryIonizationClusterCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_MCParticle.reset(nullptr);
  m_vec_electronCellID.reset(nullptr);
  m_vec_electronTime.reset(nullptr);
  m_vec_electronPosition.reset(nullptr);
  m_vec_pulseTime.reset(nullptr);
  m_vec_pulseAmplitude.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
