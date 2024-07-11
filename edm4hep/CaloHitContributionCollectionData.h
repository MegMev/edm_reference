// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContribution_CollectionData_H
#define EDM4HEP_CaloHitContribution_CollectionData_H

// datamodel specific includes
#include "edm4hep/CaloHitContributionData.h"
#include "edm4hep/CaloHitContributionObj.h"
#include "edm4hep/MCParticle.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using CaloHitContributionObjPointerContainer = std::deque<CaloHitContributionObj*>;
using CaloHitContributionDataContainer = std::vector<CaloHitContributionData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class CaloHitContributionCollectionData {
public:
  /**
   * The Objs of this collection
   */
  CaloHitContributionObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  CaloHitContributionCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  CaloHitContributionCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  CaloHitContributionCollectionData(const CaloHitContributionCollectionData&) = delete;
  CaloHitContributionCollectionData& operator=(const CaloHitContributionCollectionData&) = delete;
  CaloHitContributionCollectionData(CaloHitContributionCollectionData&& other) = default;
  CaloHitContributionCollectionData& operator=(CaloHitContributionCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~CaloHitContributionCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations
  podio::UVecPtr<edm4hep::MCParticle> m_rel_particle{nullptr}; ///< Relation buffer for read / write

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<CaloHitContributionDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
