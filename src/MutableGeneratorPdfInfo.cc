// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/GeneratorPdfInfo.h"
#include "edm4hep/GeneratorPdfInfoData.h"
#include "edm4hep/GeneratorPdfInfoObj.h"
#include "edm4hep/MutableGeneratorPdfInfo.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

namespace edm4hep {

MutableGeneratorPdfInfo::MutableGeneratorPdfInfo() : m_obj(new GeneratorPdfInfoObj{}, podio::utils::MarkOwned) {
}

MutableGeneratorPdfInfo::MutableGeneratorPdfInfo(std::array<int, 2> partonId, std::array<int, 2> lhapdfId,
                                                 std::array<double, 2> x, std::array<double, 2> xf, double scale) :
    m_obj(new GeneratorPdfInfoObj{}, podio::utils::MarkOwned) {
  m_obj->data.partonId = partonId;
  m_obj->data.lhapdfId = lhapdfId;
  m_obj->data.x = x;
  m_obj->data.xf = xf;
  m_obj->data.scale = scale;
}

MutableGeneratorPdfInfo& MutableGeneratorPdfInfo::operator=(MutableGeneratorPdfInfo other) {
  swap(*this, other);
  return *this;
}

MutableGeneratorPdfInfo MutableGeneratorPdfInfo::clone(bool cloneRelations) const {
  if (!cloneRelations) {
    auto tmp = new GeneratorPdfInfoObj(podio::ObjectID{}, m_obj->data);
    return MutableGeneratorPdfInfo(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
  }
  return MutableGeneratorPdfInfo(
      podio::utils::MaybeSharedPtr(new GeneratorPdfInfoObj(*m_obj), podio::utils::MarkOwned));
}

MutableGeneratorPdfInfo::MutableGeneratorPdfInfo(podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj> obj) :
    m_obj(std::move(obj)) {
}

const std::array<int, 2>& MutableGeneratorPdfInfo::getPartonId() const {
  return m_obj->data.partonId;
}
int MutableGeneratorPdfInfo::getPartonId(size_t i) const {
  return m_obj->data.partonId.at(i);
}
const std::array<int, 2>& MutableGeneratorPdfInfo::getLhapdfId() const {
  return m_obj->data.lhapdfId;
}
int MutableGeneratorPdfInfo::getLhapdfId(size_t i) const {
  return m_obj->data.lhapdfId.at(i);
}
const std::array<double, 2>& MutableGeneratorPdfInfo::getX() const {
  return m_obj->data.x;
}
double MutableGeneratorPdfInfo::getX(size_t i) const {
  return m_obj->data.x.at(i);
}
const std::array<double, 2>& MutableGeneratorPdfInfo::getXf() const {
  return m_obj->data.xf;
}
double MutableGeneratorPdfInfo::getXf(size_t i) const {
  return m_obj->data.xf.at(i);
}
double MutableGeneratorPdfInfo::getScale() const {
  return m_obj->data.scale;
}

void MutableGeneratorPdfInfo::setPartonId(std::array<int, 2> value) {
  m_obj->data.partonId = value;
}
void MutableGeneratorPdfInfo::setPartonId(size_t i, int value) {
  m_obj->data.partonId.at(i) = value;
}
std::array<int, 2>& MutableGeneratorPdfInfo::getPartonId() {
  return m_obj->data.partonId;
}
std::array<int, 2>& MutableGeneratorPdfInfo::partonId() {
  return m_obj->data.partonId;
}
void MutableGeneratorPdfInfo::setLhapdfId(std::array<int, 2> value) {
  m_obj->data.lhapdfId = value;
}
void MutableGeneratorPdfInfo::setLhapdfId(size_t i, int value) {
  m_obj->data.lhapdfId.at(i) = value;
}
std::array<int, 2>& MutableGeneratorPdfInfo::getLhapdfId() {
  return m_obj->data.lhapdfId;
}
std::array<int, 2>& MutableGeneratorPdfInfo::lhapdfId() {
  return m_obj->data.lhapdfId;
}
void MutableGeneratorPdfInfo::setX(std::array<double, 2> value) {
  m_obj->data.x = value;
}
void MutableGeneratorPdfInfo::setX(size_t i, double value) {
  m_obj->data.x.at(i) = value;
}
std::array<double, 2>& MutableGeneratorPdfInfo::getX() {
  return m_obj->data.x;
}
std::array<double, 2>& MutableGeneratorPdfInfo::x() {
  return m_obj->data.x;
}
void MutableGeneratorPdfInfo::setXf(std::array<double, 2> value) {
  m_obj->data.xf = value;
}
void MutableGeneratorPdfInfo::setXf(size_t i, double value) {
  m_obj->data.xf.at(i) = value;
}
std::array<double, 2>& MutableGeneratorPdfInfo::getXf() {
  return m_obj->data.xf;
}
std::array<double, 2>& MutableGeneratorPdfInfo::xf() {
  return m_obj->data.xf;
}
void MutableGeneratorPdfInfo::setScale(double value) {
  m_obj->data.scale = value;
}
double& MutableGeneratorPdfInfo::getScale() {
  return m_obj->data.scale;
}
double& MutableGeneratorPdfInfo::scale() {
  return m_obj->data.scale;
}

bool MutableGeneratorPdfInfo::isAvailable() const {
  return m_obj;
}

const podio::ObjectID MutableGeneratorPdfInfo::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool MutableGeneratorPdfInfo::operator==(const GeneratorPdfInfo& other) const {
  return m_obj == other.m_obj;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const MutableGeneratorPdfInfo& value) {
  j = nlohmann::json{{"partonId", value.getPartonId()},
                     {"lhapdfId", value.getLhapdfId()},
                     {"x", value.getX()},
                     {"xf", value.getXf()},
                     {"scale", value.getScale()}};
}
#endif

} // namespace edm4hep
