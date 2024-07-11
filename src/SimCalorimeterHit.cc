// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MutableSimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/SimCalorimeterHitObj.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

SimCalorimeterHit::SimCalorimeterHit() : m_obj(new SimCalorimeterHitObj{}, podio::utils::MarkOwned) {
}

SimCalorimeterHit::SimCalorimeterHit(std::uint64_t cellID, float energy, edm4hep::Vector3f position) :
    m_obj(new SimCalorimeterHitObj{}, podio::utils::MarkOwned) {
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.position = position;
}

SimCalorimeterHit& SimCalorimeterHit::operator=(SimCalorimeterHit other) {
  swap(*this, other);
  return *this;
}

MutableSimCalorimeterHit SimCalorimeterHit::clone(bool cloneRelations) const {
  auto tmp = new SimCalorimeterHitObj(podio::ObjectID{}, m_obj->data);
  tmp->m_contributions = new std::vector<edm4hep::CaloHitContribution>();
  if (cloneRelations) {
    // If the current object has been read from a file, then the object may only have a slice of the relation vector
    // so this slice has to be copied in case we want to modify it
    tmp->m_contributions->reserve(m_obj->m_contributions->size());
    for (size_t i = m_obj->data.contributions_begin; i < m_obj->data.contributions_end; i++) {
      tmp->m_contributions->emplace_back((*m_obj->m_contributions)[i]);
    }
    tmp->data.contributions_begin = 0;
    tmp->data.contributions_end = tmp->m_contributions->size();
  } else {
    tmp->data.contributions_begin = 0;
    tmp->data.contributions_end = 0;
  }
  return MutableSimCalorimeterHit(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

SimCalorimeterHit::SimCalorimeterHit(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj> obj) : m_obj(std::move(obj)) {
}

SimCalorimeterHit::SimCalorimeterHit(const MutableSimCalorimeterHit& other) : SimCalorimeterHit(other.m_obj) {
}

SimCalorimeterHit::SimCalorimeterHit(SimCalorimeterHitObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<SimCalorimeterHitObj>(obj)) {
}

SimCalorimeterHit SimCalorimeterHit::makeEmpty() {
  return {nullptr};
}

std::uint64_t SimCalorimeterHit::getCellID() const {
  return m_obj->data.cellID;
}
float SimCalorimeterHit::getEnergy() const {
  return m_obj->data.energy;
}
const edm4hep::Vector3f& SimCalorimeterHit::getPosition() const {
  return m_obj->data.position;
}

std::vector<edm4hep::CaloHitContribution>::const_iterator SimCalorimeterHit::contributions_begin() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_begin);
  return ret_value;
}

std::vector<edm4hep::CaloHitContribution>::const_iterator SimCalorimeterHit::contributions_end() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_end);
  return ret_value;
}

std::size_t SimCalorimeterHit::contributions_size() const {
  return m_obj->data.contributions_end - m_obj->data.contributions_begin;
}

edm4hep::CaloHitContribution SimCalorimeterHit::getContributions(std::size_t index) const {
  if (contributions_size() > index) {
    return m_obj->m_contributions->at(m_obj->data.contributions_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::CaloHitContribution> SimCalorimeterHit::getContributions() const {
  auto begin = m_obj->m_contributions->begin();
  std::advance(begin, m_obj->data.contributions_begin);
  auto end = m_obj->m_contributions->begin();
  std::advance(end, m_obj->data.contributions_end);
  return {begin, end};
}

bool SimCalorimeterHit::isAvailable() const {
  return m_obj;
}

const podio::ObjectID SimCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool SimCalorimeterHit::operator==(const MutableSimCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const SimCalorimeterHit& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " position : " << value.getPosition() << '\n';

  o << " contributions : ";
  for (unsigned i = 0; i < value.contributions_size(); ++i) {
    o << value.getContributions(i) << " ";
  }
  o << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const SimCalorimeterHit& value) {
  j = nlohmann::json{{"cellID", value.getCellID()}, {"energy", value.getEnergy()}, {"position", value.getPosition()}};

  j["contributions"] = nlohmann::json::array();
  for (const auto& v : value.getContributions()) {
    j["contributions"].emplace_back(
        nlohmann::json{{"collectionID", v.getObjectID().collectionID}, {"index", v.getObjectID().index}});
  }
}
#endif

} // namespace edm4hep
