// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackerHit3DObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

TrackerHit3DObj::TrackerHit3DObj() : id(), data() {
}

TrackerHit3DObj::TrackerHit3DObj(const podio::ObjectID id_, TrackerHit3DData data_) : id(id_), data(data_) {
}

TrackerHit3DObj::TrackerHit3DObj(const TrackerHit3DObj& other) : id(), data(other.data) {
}

} // namespace edm4hep
