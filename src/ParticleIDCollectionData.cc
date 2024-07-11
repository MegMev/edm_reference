// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ParticleIDCollection.h"
#include "edm4hep/ParticleIDCollectionData.h"

#include "edm4hep/ReconstructedParticleCollection.h"
#include <numeric>

namespace edm4hep {

ParticleIDCollectionData::ParticleIDCollectionData() :
    m_rel_particle(new std::vector<edm4hep::ReconstructedParticle>()),
    m_vec_parameters(new std::vector<float>()),
    m_data(new ParticleIDDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_vecmem_info.emplace_back("float", &m_vec_parameters);
}

ParticleIDCollectionData::ParticleIDCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl) :
    m_rel_particle(new std::vector<edm4hep::ReconstructedParticle>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::ParticleIDData>());

    m_vec_parameters.reset(podio::CollectionReadBuffers::asVector<float>(m_vecmem_info[0].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void ParticleIDCollectionData::clear(bool isSubsetColl) {
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
  if (m_rel_particle) {
    for (auto& item : (*m_rel_particle)) {
      item.unlink();
    }
    m_rel_particle->clear();
  }

  if (m_vec_parameters)
    m_vec_parameters->clear();
  m_vecs_parameters.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers ParticleIDCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_parameters;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void ParticleIDCollectionData::prepareForWrite(bool isSubsetColl) {
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

  const auto parameters_size =
      std::accumulate(entries.begin(), entries.end(), 0,
                      [](size_t sum, const ParticleIDObj* obj) { return sum + obj->m_parameters->size(); });
  m_vec_parameters->reserve(parameters_size);
  int parameters_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].parameters_begin = parameters_index;
    (*m_data)[i].parameters_end += parameters_index;
    parameters_index = (*m_data)[i].parameters_end;
    for (const auto& it : (*m_vecs_parameters[i])) {
      m_vec_parameters->push_back(it);
    }
  }
  for (auto& obj : entries) {
    if (obj->m_particle) {
      m_refCollections[0]->emplace_back(obj->m_particle->getObjectID());
    } else {
      m_refCollections[0]->push_back({podio::ObjectID::invalid, 0});
    }
  }
}

void ParticleIDCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new ParticleIDObj({index, collectionID}, data);

    obj->m_parameters = m_vec_parameters.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void ParticleIDCollectionData::createRelations(ParticleIDObj* obj) {
  // We take ownership of these here
  m_vecs_parameters.emplace_back(obj->m_parameters);
}

bool ParticleIDCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::ParticleIDObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::ParticleIDCollection*>(coll);
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
        entries[i]->m_particle = nullptr;
        continue;
      }
      edm4hep::ReconstructedParticleCollection* tmp_coll = static_cast<edm4hep::ReconstructedParticleCollection*>(coll);
      entries[i]->m_particle = new edm4hep::ReconstructedParticle((*tmp_coll)[id.index]);
    } else {
      entries[i]->m_particle = nullptr;
    }
  }

  return true; // TODO: check success, how?
}

void ParticleIDCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_particle.reset(nullptr);
  m_vec_parameters.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
