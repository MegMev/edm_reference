// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecIonizationCluster_H
#define EDM4HEP_RecIonizationCluster_H

#include "edm4hep/RecIonizationClusterObj.h"

#include "edm4hep/TrackerPulse.h"
#include "podio/RelationRange.h"
#include <cstdint>
#include <vector>

#include "podio/utilities/MaybeSharedPtr.h"

#include <cstddef>
#include <ostream>

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json_fwd.hpp"
#endif

namespace edm4hep {

class MutableRecIonizationCluster;
class RecIonizationClusterCollection;
class RecIonizationClusterCollectionData;

/** @class RecIonizationCluster
 *  Reconstructed Ionization Cluster
 *  @author: Wenxing Fang, IHEP
 */
class RecIonizationCluster {

  friend class MutableRecIonizationCluster;
  friend class RecIonizationClusterCollection;
  friend class edm4hep::RecIonizationClusterCollectionData;
  friend class RecIonizationClusterCollectionIterator;

public:
  using mutable_type = MutableRecIonizationCluster;
  using collection_type = RecIonizationClusterCollection;

  /// default constructor
  RecIonizationCluster();

  /// Constructor initializing all members
  RecIonizationCluster(std::uint64_t cellID, float significance, std::int16_t type);

  /// copy constructor
  RecIonizationCluster(const RecIonizationCluster& other) = default;

  /// copy-assignment operator
  RecIonizationCluster& operator=(RecIonizationCluster other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRecIonizationCluster clone(bool cloneRelations = true) const;

  /// destructor
  ~RecIonizationCluster() = default;

  /// converting constructor from mutable object
  RecIonizationCluster(const MutableRecIonizationCluster& other);

  static RecIonizationCluster makeEmpty();

public:
  /// Access the cell id.
  std::uint64_t getCellID() const;

  /// Access the significance.
  float getSignificance() const;

  /// Access the type.
  std::int16_t getType() const;

  std::size_t trackerPulse_size() const;
  edm4hep::TrackerPulse getTrackerPulse(std::size_t) const;
  std::vector<edm4hep::TrackerPulse>::const_iterator trackerPulse_begin() const;
  std::vector<edm4hep::TrackerPulse>::const_iterator trackerPulse_end() const;
  podio::RelationRange<edm4hep::TrackerPulse> getTrackerPulse() const;

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecIonizationClusterObj instance
  void unlink() {
    m_obj = podio::utils::MaybeSharedPtr<RecIonizationClusterObj>{nullptr};
  }

  bool operator==(const RecIonizationCluster& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const MutableRecIonizationCluster& other) const;

  bool operator!=(const RecIonizationCluster& other) const {
    return !(*this == other);
  }
  bool operator!=(const MutableRecIonizationCluster& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RecIonizationCluster& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(RecIonizationCluster& a, RecIonizationCluster& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RecIonizationClusterObj
  explicit RecIonizationCluster(podio::utils::MaybeSharedPtr<RecIonizationClusterObj> obj);
  RecIonizationCluster(RecIonizationClusterObj* obj);

  podio::utils::MaybeSharedPtr<RecIonizationClusterObj> m_obj{nullptr};
};

std::ostream& operator<<(std::ostream& o, const RecIonizationCluster& value);

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const RecIonizationCluster& value);
#endif

} // namespace edm4hep

#endif
