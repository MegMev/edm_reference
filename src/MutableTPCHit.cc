// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableTPCHit.h"
#include "edm4hep/TPCHit.h"
#include "edm4hep/TPCHitCollection.h"
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHitObj.h"

#include <ostream>

namespace edm4hep {

MutableTPCHit::MutableTPCHit() : m_obj(new TPCHitObj()) {
  if (m_obj)
    m_obj->acquire();
}

MutableTPCHit::MutableTPCHit(std::uint64_t cellID, std::int32_t quality, float time, float charge) :
    m_obj(new TPCHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
}

MutableTPCHit::MutableTPCHit(const MutableTPCHit& other) : m_obj(other.m_obj) {
  if (m_obj)
    m_obj->acquire();
}

MutableTPCHit& MutableTPCHit::operator=(MutableTPCHit other) {
  swap(*this, other);
  return *this;
}

MutableTPCHit::MutableTPCHit(TPCHitObj* obj) : m_obj(obj) {
  if (m_obj) {
    m_obj->acquire();
  }
}

MutableTPCHit MutableTPCHit::clone() const {
  return {new TPCHitObj(*m_obj)};
}

MutableTPCHit::~MutableTPCHit() {
  if (m_obj) {
    m_obj->release();
  }
}
MutableTPCHit::operator TPCHit() const {
  return TPCHit(m_obj);
}

const std::uint64_t& MutableTPCHit::getCellID() const {
  return m_obj->data.cellID;
}
const std::int32_t& MutableTPCHit::getQuality() const {
  return m_obj->data.quality;
}
const float& MutableTPCHit::getTime() const {
  return m_obj->data.time;
}
const float& MutableTPCHit::getCharge() const {
  return m_obj->data.charge;
}

void MutableTPCHit::setCellID(std::uint64_t value) {
  m_obj->data.cellID = value;
}
void MutableTPCHit::setQuality(std::int32_t value) {
  m_obj->data.quality = value;
}
void MutableTPCHit::setTime(float value) {
  m_obj->data.time = value;
}
void MutableTPCHit::setCharge(float value) {
  m_obj->data.charge = value;
}

void MutableTPCHit::addToRawDataWords(std::int32_t component) {
  m_obj->m_rawDataWords->push_back(component);
  m_obj->data.rawDataWords_end++;
}

std::vector<std::int32_t>::const_iterator MutableTPCHit::rawDataWords_begin() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_begin);
  return ret_value;
}

std::vector<std::int32_t>::const_iterator MutableTPCHit::rawDataWords_end() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_end);
  return ret_value;
}

std::size_t MutableTPCHit::rawDataWords_size() const {
  return m_obj->data.rawDataWords_end - m_obj->data.rawDataWords_begin;
}

std::int32_t MutableTPCHit::getRawDataWords(std::size_t index) const {
  if (rawDataWords_size() > index) {
    return m_obj->m_rawDataWords->at(m_obj->data.rawDataWords_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<std::int32_t> MutableTPCHit::getRawDataWords() const {
  auto begin = m_obj->m_rawDataWords->begin();
  std::advance(begin, m_obj->data.rawDataWords_begin);
  auto end = m_obj->m_rawDataWords->begin();
  std::advance(end, m_obj->data.rawDataWords_end);
  return {begin, end};
}

bool MutableTPCHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID MutableTPCHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, 0};
}

bool MutableTPCHit::operator==(const TPCHit& other) const {
  return m_obj == other.m_obj;
}

#ifdef PODIO_JSON_OUTPUT
void to_json(nlohmann::json& j, const MutableTPCHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()},
                     {"quality", value.getQuality()},
                     {"time", value.getTime()},
                     {"charge", value.getCharge()},
                     {"rawDataWords", value.getRawDataWords()}};
}
#endif

} // namespace edm4hep
