// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/GeneratorEventParametersCollection.h"
#include "edm4hep/GeneratorEventParametersCollectionData.h"

#include "edm4hep/MCParticleCollection.h"
#include <numeric>

namespace edm4hep {

GeneratorEventParametersCollectionData::GeneratorEventParametersCollectionData() :
    m_rel_signalVertex(new std::vector<edm4hep::MCParticle>()),
    m_vec_crossSections(new std::vector<double>()),
    m_vec_crossSectionErrors(new std::vector<double>()),
    m_data(new GeneratorEventParametersDataContainer()) {
  m_refCollections.emplace_back(std::make_unique<std::vector<podio::ObjectID>>());
  m_vecmem_info.emplace_back("double", &m_vec_crossSections);
  m_vecmem_info.emplace_back("double", &m_vec_crossSectionErrors);
}

GeneratorEventParametersCollectionData::GeneratorEventParametersCollectionData(podio::CollectionReadBuffers buffers,
                                                                               bool isSubsetColl) :
    m_rel_signalVertex(new std::vector<edm4hep::MCParticle>()),
    m_refCollections(std::move(*buffers.references)),
    m_vecmem_info(std::move(*buffers.vectorMembers)) {
  // For subset collections we are done, for proper collections we still have to
  // populate the data and vector members
  if (!isSubsetColl) {
    m_data.reset(buffers.dataAsVector<edm4hep::GeneratorEventParametersData>());

    m_vec_crossSections.reset(podio::CollectionReadBuffers::asVector<double>(m_vecmem_info[0].second));
    m_vec_crossSectionErrors.reset(podio::CollectionReadBuffers::asVector<double>(m_vecmem_info[1].second));
  }

  // Cleanup these to avoid leaking them
  delete buffers.references;
  delete buffers.vectorMembers;
}

void GeneratorEventParametersCollectionData::clear(bool isSubsetColl) {
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
  // clear relations to signalVertex. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_signalVertex_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
  }
  m_rel_signalVertex_tmp.clear();
  if (m_rel_signalVertex) {
    for (auto& item : (*m_rel_signalVertex)) {
      item.unlink();
    }
    m_rel_signalVertex->clear();
  }

  if (m_vec_crossSections)
    m_vec_crossSections->clear();
  m_vecs_crossSections.clear();

  if (m_vec_crossSectionErrors)
    m_vec_crossSectionErrors->clear();
  m_vecs_crossSectionErrors.clear();

  for (auto& obj : entries) {
    delete obj;
  }
  entries.clear();
}

podio::CollectionWriteBuffers GeneratorEventParametersCollectionData::getCollectionBuffers(bool isSubsetColl) {
  if (!isSubsetColl) {
    // Make sure these point to the right place, even if a collection has been
    // moved since it has been created
    m_vecmem_info[0].second = &m_vec_crossSections;
    m_vecmem_info[1].second = &m_vec_crossSectionErrors;
  }
  return {isSubsetColl ? nullptr : (void*)&m_data, isSubsetColl ? nullptr : (void*)m_data.get(),
          &m_refCollections, // only need to store the ObjectIDs of the referenced objects
          &m_vecmem_info};
}

void GeneratorEventParametersCollectionData::prepareForWrite(bool isSubsetColl) {
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

  int signalVertex_index = 0;
  const auto crossSections_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const GeneratorEventParametersObj* obj) {
        return sum + obj->m_crossSections->size();
      });
  m_vec_crossSections->reserve(crossSections_size);
  int crossSections_index = 0;
  const auto crossSectionErrors_size =
      std::accumulate(entries.begin(), entries.end(), 0, [](size_t sum, const GeneratorEventParametersObj* obj) {
        return sum + obj->m_crossSectionErrors->size();
      });
  m_vec_crossSectionErrors->reserve(crossSectionErrors_size);
  int crossSectionErrors_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].signalVertex_begin = signalVertex_index;
    (*m_data)[i].signalVertex_end += signalVertex_index;
    signalVertex_index = (*m_data)[i].signalVertex_end;
    for (const auto& it : (*m_rel_signalVertex_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[0]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].crossSections_begin = crossSections_index;
    (*m_data)[i].crossSections_end += crossSections_index;
    crossSections_index = (*m_data)[i].crossSections_end;
    for (const auto& it : (*m_vecs_crossSections[i])) {
      m_vec_crossSections->push_back(it);
    }

    (*m_data)[i].crossSectionErrors_begin = crossSectionErrors_index;
    (*m_data)[i].crossSectionErrors_end += crossSectionErrors_index;
    crossSectionErrors_index = (*m_data)[i].crossSectionErrors_end;
    for (const auto& it : (*m_vecs_crossSectionErrors[i])) {
      m_vec_crossSectionErrors->push_back(it);
    }
  }
}

void GeneratorEventParametersCollectionData::prepareAfterRead(uint32_t collectionID) {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new GeneratorEventParametersObj({index, collectionID}, data);

    obj->m_signalVertex = m_rel_signalVertex.get();
    obj->m_crossSections = m_vec_crossSections.get();
    obj->m_crossSectionErrors = m_vec_crossSectionErrors.get();
    entries.emplace_back(obj);
    ++index;
  }

  // at this point we could clear the I/O data buffer, but we keep them intact
  // because then we can save a call to prepareForWrite
}

void GeneratorEventParametersCollectionData::createRelations(GeneratorEventParametersObj* obj) {
  // We take ownership of these here
  m_rel_signalVertex_tmp.emplace_back(obj->m_signalVertex);
  // We take ownership of these here
  m_vecs_crossSections.emplace_back(obj->m_crossSections);
  // We take ownership of these here
  m_vecs_crossSectionErrors.emplace_back(obj->m_crossSectionErrors);
}

bool GeneratorEventParametersCollectionData::setReferences(const podio::ICollectionProvider* collectionProvider,
                                                           bool isSubsetColl) {
  if (isSubsetColl) {
    for (const auto& id : *m_refCollections[0]) {
      podio::CollectionBase* coll = nullptr;
      edm4hep::GeneratorEventParametersObj* obj = nullptr;
      if (collectionProvider->get(id.collectionID, coll)) {
        auto* tmp_coll = static_cast<edm4hep::GeneratorEventParametersCollection*>(coll);
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
        m_rel_signalVertex->emplace_back(edm4hep::MCParticle::makeEmpty());
        continue;
      }
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_signalVertex->emplace_back(tmp);
    } else {
      m_rel_signalVertex->emplace_back(edm4hep::MCParticle::makeEmpty());
    }
  }

  return true; // TODO: check success, how?
}

void GeneratorEventParametersCollectionData::makeSubsetCollection() {
  // Subset collections do not need all the data buffers that normal
  // collections need, so we can free them here
  m_vecmem_info.clear();

  m_data.reset(nullptr);

  m_rel_signalVertex.reset(nullptr);
  m_vec_crossSections.reset(nullptr);
  m_vec_crossSectionErrors.reset(nullptr);

  // Subset collections need one vector of ObjectIDs for I/O purposes.
  m_refCollections.resize(1);
  m_refCollections[0] = std::make_unique<std::vector<podio::ObjectID>>();
}

} // namespace edm4hep
