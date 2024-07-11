// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_GeneratorPdfInfo_CollectionData_H
#define EDM4HEP_GeneratorPdfInfo_CollectionData_H

// datamodel specific includes
#include "edm4hep/GeneratorPdfInfoData.h"
#include "edm4hep/GeneratorPdfInfoObj.h"

// schema evolution specific includes

// podio specific includes
#include "podio/CollectionBuffers.h"
#include "podio/ICollectionProvider.h"

#include <deque>
#include <memory>

namespace edm4hep {

using GeneratorPdfInfoObjPointerContainer = std::deque<GeneratorPdfInfoObj*>;
using GeneratorPdfInfoDataContainer = std::vector<GeneratorPdfInfoData>;

/**
 * Class encapsulating everything related to storage of data that is needed by a
 * collection.
 */
class GeneratorPdfInfoCollectionData {
public:
  /**
   * The Objs of this collection
   */
  GeneratorPdfInfoObjPointerContainer entries{};

  /**
   * Default constructor setting up the necessary buffers
   */
  GeneratorPdfInfoCollectionData();

  /**
   * Constructor from existing I/O buffers
   */
  GeneratorPdfInfoCollectionData(podio::CollectionReadBuffers buffers, bool isSubsetColl);

  /**
   * Non copy-able, move-only class
   */
  GeneratorPdfInfoCollectionData(const GeneratorPdfInfoCollectionData&) = delete;
  GeneratorPdfInfoCollectionData& operator=(const GeneratorPdfInfoCollectionData&) = delete;
  GeneratorPdfInfoCollectionData(GeneratorPdfInfoCollectionData&& other) = default;
  GeneratorPdfInfoCollectionData& operator=(GeneratorPdfInfoCollectionData&& other) = default;

  /**
   * Destructor
   */
  ~GeneratorPdfInfoCollectionData() = default;

  void clear(bool isSubsetColl);

  podio::CollectionWriteBuffers getCollectionBuffers(bool isSubsetColl);

  void prepareForWrite(bool isSubsetColl);

  void prepareAfterRead(uint32_t collectionID);

  void makeSubsetCollection();

  bool setReferences(const podio::ICollectionProvider* collectionProvider, bool isSubsetColl);

private:
  // members to handle 1-to-N-relations

  // members to handle vector members

  // I/O related buffers
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  std::unique_ptr<GeneratorPdfInfoDataContainer> m_data{nullptr};
};

} // namespace edm4hep

#endif
