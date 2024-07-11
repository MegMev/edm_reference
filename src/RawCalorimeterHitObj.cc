// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RawCalorimeterHitObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

RawCalorimeterHitObj::RawCalorimeterHitObj() : id(), data() {
}

RawCalorimeterHitObj::RawCalorimeterHitObj(const podio::ObjectID id_, RawCalorimeterHitData data_) :
    id(id_), data(data_) {
}

RawCalorimeterHitObj::RawCalorimeterHitObj(const RawCalorimeterHitObj& other) : id(), data(other.data) {
}

} // namespace edm4hep
