// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CalorimeterHitObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

CalorimeterHitObj::CalorimeterHitObj() : id(), data() {
}

CalorimeterHitObj::CalorimeterHitObj(const podio::ObjectID id_, CalorimeterHitData data_) : id(id_), data(data_) {
}

CalorimeterHitObj::CalorimeterHitObj(const CalorimeterHitObj& other) : id(), data(other.data) {
}

} // namespace edm4hep
