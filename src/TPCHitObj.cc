// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TPCHitObj.h"
namespace edm4hep {

TPCHitObj::TPCHitObj() :
    ObjBase{{podio::ObjectID::untracked, 0}, 0}, data(), m_rawDataWords(new std::vector<std::int32_t>()) {
}

TPCHitObj::TPCHitObj(const podio::ObjectID id_, TPCHitData data_) : ObjBase{id_, 0}, data(data_) {
}

TPCHitObj::TPCHitObj(const TPCHitObj& other) :
    ObjBase{{podio::ObjectID::untracked, 0}, 0},
    data(other.data),
    m_rawDataWords(new std::vector<std::int32_t>(*(other.m_rawDataWords))) {
}

TPCHitObj::~TPCHitObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_rawDataWords;
  }
}
} // namespace edm4hep
