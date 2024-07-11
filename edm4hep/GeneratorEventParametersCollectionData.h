// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorEventParameters_CollectionData_H
#define EDM4HEP_GeneratorEventParameters_CollectionData_H

// datamodel specific includes
#include "edm4hep/GeneratorEventParametersData.h"
#include "edm4hep/GeneratorEventParametersObj.h"
#include "edm4hep/MCParticle.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using GeneratorEventParametersObjPointerContainer = std::deque<GeneratorEventParametersObj*>;
using GeneratorEventParametersDataContainer = std::vector<GeneratorEventParametersData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class GeneratorEventParametersCollectionData {
public:
  /**
   * The Objs of this collection
   */
  GeneratorEventParametersObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  GeneratorEventParametersCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  GeneratorEventParametersCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  GeneratorEventParametersCollectionData(const GeneratorEventParametersCollectionData&) = delete;
  GeneratorEventParametersCollectionData& operator=(const GeneratorEventParametersCollectionData&) = delete;
  GeneratorEventParametersCollectionData(GeneratorEventParametersCollectionData&& other) = default;
  GeneratorEventParametersCollectionData& operator=(GeneratorEventParametersCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~GeneratorEventParametersCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  void createRelations(GeneratorEventParametersObj* obj);

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::MCParticle> m_rel_signalVertex;                    ///< Relation buffer for read / write
  std::vector<podio::UVecPtr<edm4hep::MCParticle>> m_rel_signalVertex_tmp{}; ///< Relation buffer for internal
                                                                             ///< book-keeping

  // members to handle vector members
  podio::UVecPtr<double> m_vec_crossSections{nullptr};             /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<double>> m_vecs_crossSections{};      /// pointers to individual member vectors
  podio::UVecPtr<double> m_vec_crossSectionErrors{nullptr};        /// combined vector of all objects in collection
  std::vector<podio::UVecPtr<double>> m_vecs_crossSectionErrors{}; /// pointers to individual member vectors

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<GeneratorEventParametersDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
