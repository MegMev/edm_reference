// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackOBJ_H
#define EDM4HEP_TrackOBJ_H

// data model specific includes
#include "edm4hep/Quantity.h"
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackState.h"
#include "edm4hep/TrackerHit.h"
#include <vector>

#include "podio/ObjectID.h"
#include <vector>

namespace edm4hep {

class Track;

class TrackObj {
public:
  /// constructor
  TrackObj();
  /// copy constructor (does a deep-copy of relation containers)
  TrackObj(const TrackObj&);
  /// constructor from ObjectID and TrackData
  /// does not initialize the internal relation containers
  TrackObj(const podio::ObjectID id, TrackData data);
  /// No assignment operator
  TrackObj& operator=(const TrackObj&) = delete;
  virtual ~TrackObj();

public:
  podio::ObjectID id;
  TrackData data;
  std::vector<edm4hep::TrackerHit>* m_trackerHits{nullptr};
  std::vector<edm4hep::Track>* m_tracks{nullptr};
  std::vector<std::int32_t>* m_subdetectorHitNumbers{nullptr};
  std::vector<edm4hep::TrackState>* m_trackStates{nullptr};
  std::vector<edm4hep::Quantity>* m_dxQuantities{nullptr};
};

} // namespace edm4hep

#endif
