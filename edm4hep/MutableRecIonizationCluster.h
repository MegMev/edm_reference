// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MutableRecIonizationCluster_H
#define EDM4HEP_MutableRecIonizationCluster_H

#include "edm4hep/RecIonizationClusterObj.h"
// Make the immutable class available from its mutable version but not vice versa
#include "edm4hep/RecIonizationCluster.h"

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

/** @class MutableRecIonizationCluster
 *  Reconstructed Ionization Cluster
 *  @author: Wenxing Fang, IHEP
 */
class MutableRecIonizationCluster {

  friend class RecIonizationClusterCollection;
  friend class RecIonizationClusterMutableCollectionIterator;
  friend class RecIonizationCluster;

public:
  using object_type = RecIonizationCluster;
  using collection_type = RecIonizationClusterCollection;

  /// default constructor
  MutableRecIonizationCluster();

  /// Constructor initializing all members
  MutableRecIonizationCluster(std::uint64_t cellID, float significance, std::int16_t type);

  /// copy constructor
  MutableRecIonizationCluster(const MutableRecIonizationCluster& other) = default;

  /// copy-assignment operator
  MutableRecIonizationCluster& operator=(MutableRecIonizationCluster other);

  /// create a mutable deep-copy of the object with identical relations
  /// if cloneRelations=false, the relations are not cloned and will be empty
  MutableRecIonizationCluster clone(bool cloneRelations = true) const;

  /// destructor
  ~MutableRecIonizationCluster() = default;

public:
  /// Access the cell id.
  std::uint64_t getCellID() const;

  /// Access the significance.
  float getSignificance() const;

  /// Access the type.
  std::int16_t getType() const;

  /// Set the cell id.
  void setCellID(std::uint64_t value);
  /// Get mutable reference to cell id.
  std::uint64_t& getCellID();
  /// Get reference to cell id.
  [[deprecated("use getCellID instead")]] std::uint64_t& cellID();

  /// Set the significance.
  void setSignificance(float value);
  /// Get mutable reference to significance.
  float& getSignificance();
  /// Get reference to significance.
  [[deprecated("use getSignificance instead")]] float& significance();

  /// Set the type.
  void setType(std::int16_t value);
  /// Get mutable reference to type.
  std::int16_t& getType();
  /// Get reference to type.
  [[deprecated("use getType instead")]] std::int16_t& type();

  void addToTrackerPulse(const edm4hep::TrackerPulse&);
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

  bool operator==(const MutableRecIonizationCluster& other) const {
    return m_obj == other.m_obj;
  }
  bool operator==(const RecIonizationCluster& other) const;

  bool operator!=(const MutableRecIonizationCluster& other) const {
    return !(*this == other);
  }
  bool operator!=(const RecIonizationCluster& other) const {
    return !(*this == other);
  }

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MutableRecIonizationCluster& other) const {
    return m_obj < other.m_obj;
  }

  podio::ObjectID id() const {
    return getObjectID();
  }

  const podio::ObjectID getObjectID() const;

  friend void swap(MutableRecIonizationCluster& a, MutableRecIonizationCluster& b) {
    using std::swap;
    swap(a.m_obj, b.m_obj); // swap out the internal pointers
  }

private:
  /// constructor from existing RecIonizationClusterObj
  explicit MutableRecIonizationCluster(podio::utils::MaybeSharedPtr<RecIonizationClusterObj> obj);

  podio::utils::MaybeSharedPtr<RecIonizationClusterObj> m_obj{nullptr};
};

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableRecIonizationCluster& value);
#endif

} // namespace edm4hep

#endif
