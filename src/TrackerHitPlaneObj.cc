// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackerHitPlaneObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

TrackerHitPlaneObj::TrackerHitPlaneObj() : id(), data() {
}

TrackerHitPlaneObj::TrackerHitPlaneObj(const podio::ObjectID id_, TrackerHitPlaneData data_) : id(id_), data(data_) {
}

TrackerHitPlaneObj::TrackerHitPlaneObj(const TrackerHitPlaneObj& other) : id(), data(other.data) {
}

} // namespace edm4hep
