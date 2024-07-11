// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTPCHit.h"
#include "edm4hep/TPCHit.h"
#include "edm4hep/TPCHitCollection.h"
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHitObj.h"

#include <ostream>

namespace edm4hep {

TPCHit::TPCHit() : m_obj(new TPCHitObj()) {
  if (m_obj)
    m_obj->acquire();
}

TPCHit::TPCHit(std::uint64_t cellID, std::int32_t quality, float time, float charge) : m_obj(new TPCHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
}

TPCHit::TPCHit(const TPCHit& other) : m_obj(other.m_obj) {
  if (m_obj)
    m_obj->acquire();
}

TPCHit& TPCHit::operator=(TPCHit other) {
  swap(*this, other);
  return *this;
}

TPCHit::TPCHit(TPCHitObj* obj) : m_obj(obj) {
  if (m_obj) {
    m_obj->acquire();
  }
}

MutableTPCHit TPCHit::clone() const {
  return {new TPCHitObj(*m_obj)};
}

TPCHit::~TPCHit() {
  if (m_obj) {
    m_obj->release();
  }
}

const std::uint64_t& TPCHit::getCellID() const {
  return m_obj->data.cellID;
}
const std::int32_t& TPCHit::getQuality() const {
  return m_obj->data.quality;
}
const float& TPCHit::getTime() const {
  return m_obj->data.time;
}
const float& TPCHit::getCharge() const {
  return m_obj->data.charge;
}

std::vector<std::int32_t>::const_iterator TPCHit::rawDataWords_begin() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_begin);
  return ret_value;
}

std::vector<std::int32_t>::const_iterator TPCHit::rawDataWords_end() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_end);
  return ret_value;
}

std::size_t TPCHit::rawDataWords_size() const {
  return m_obj->data.rawDataWords_end - m_obj->data.rawDataWords_begin;
}

std::int32_t TPCHit::getRawDataWords(std::size_t index) const {
  if (rawDataWords_size() > index) {
    return m_obj->m_rawDataWords->at(m_obj->data.rawDataWords_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::int32_t> TPCHit::getRawDataWords() const {
  auto begin = m_obj->m_rawDataWords->begin();
  std::advance(begin, m_obj->data.rawDataWords_begin);
  auto end = m_obj->m_rawDataWords->begin();
  std::advance(end, m_obj->data.rawDataWords_end);
  return {begin, end};
}

bool TPCHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID TPCHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, 0};
}

bool TPCHit::operator==(const MutableTPCHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const TPCHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " charge : " << value.getCharge() << '\n';

  o << " rawDataWords : ";
  for (unsigned i = 0; i < value.rawDataWords_size(); ++i) {
    o << value.getRawDataWords(i) << " ";
  }
  o << '\n';

  return o;
}

#ifdef PODIO_JSON_OUTPUT
void to_json(nlohmann::json& j, const TPCHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"quality", value.getQuality()},
                     {"time", value.getTime()},
                     {"charge", value.getCharge()},
                     {"rawDataWords", value.getRawDataWords()}};
}
#endif

} // namespace edm4hep
