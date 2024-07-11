// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/GeneratorPdfInfo.h"
#include "edm4hep/GeneratorPdfInfoData.h"
#include "edm4hep/GeneratorPdfInfoObj.h"
#include "edm4hep/MutableGeneratorPdfInfo.h"

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
#include "nlohmann/json.hpp"
#endif

#include <ostream>

namespace edm4hep {

GeneratorPdfInfo::GeneratorPdfInfo() : m_obj(new GeneratorPdfInfoObj{}, podio::utils::MarkOwned) {
}

GeneratorPdfInfo::GeneratorPdfInfo(std::array<int, 2> partonId, std::array<int, 2> lhapdfId, std::array<double, 2> x,
                                   std::array<double, 2> xf, double scale) :
    m_obj(new GeneratorPdfInfoObj{}, podio::utils::MarkOwned) {
  m_obj->data.partonId = partonId;
  m_obj->data.lhapdfId = lhapdfId;
  m_obj->data.x = x;
  m_obj->data.xf = xf;
  m_obj->data.scale = scale;
}

GeneratorPdfInfo& GeneratorPdfInfo::operator=(GeneratorPdfInfo other) {
  swap(*this, other);
  return *this;
}

MutableGeneratorPdfInfo GeneratorPdfInfo::clone(bool cloneRelations) const {
  auto tmp = new GeneratorPdfInfoObj(podio::ObjectID{}, m_obj->data);
  if (cloneRelations) {
  } else {
  }
  return MutableGeneratorPdfInfo(podio::utils::MaybeSharedPtr(tmp, podio::utils::MarkOwned));
}

GeneratorPdfInfo::GeneratorPdfInfo(podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj> obj) : m_obj(std::move(obj)) {
}

GeneratorPdfInfo::GeneratorPdfInfo(const MutableGeneratorPdfInfo& other) : GeneratorPdfInfo(other.m_obj) {
}

GeneratorPdfInfo::GeneratorPdfInfo(GeneratorPdfInfoObj* obj) :
    m_obj(podio::utils::MaybeSharedPtr<GeneratorPdfInfoObj>(obj)) {
}

GeneratorPdfInfo GeneratorPdfInfo::makeEmpty() {
  return {nullptr};
}

const std::array<int, 2>& GeneratorPdfInfo::getPartonId() const {
  return m_obj->data.partonId;
}
int GeneratorPdfInfo::getPartonId(size_t i) const {
  return m_obj->data.partonId.at(i);
}
const std::array<int, 2>& GeneratorPdfInfo::getLhapdfId() const {
  return m_obj->data.lhapdfId;
}
int GeneratorPdfInfo::getLhapdfId(size_t i) const {
  return m_obj->data.lhapdfId.at(i);
}
const std::array<double, 2>& GeneratorPdfInfo::getX() const {
  return m_obj->data.x;
}
double GeneratorPdfInfo::getX(size_t i) const {
  return m_obj->data.x.at(i);
}
const std::array<double, 2>& GeneratorPdfInfo::getXf() const {
  return m_obj->data.xf;
}
double GeneratorPdfInfo::getXf(size_t i) const {
  return m_obj->data.xf.at(i);
}
double GeneratorPdfInfo::getScale() const {
  return m_obj->data.scale;
}

bool GeneratorPdfInfo::isAvailable() const {
  return m_obj;
}

const podio::ObjectID GeneratorPdfInfo::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{};
}

bool GeneratorPdfInfo::operator==(const MutableGeneratorPdfInfo& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const GeneratorPdfInfo& value) {
  if (!value.isAvailable()) {
    return o << "[not available]";
  }
  o << " id: " << value.id() << '\n';
  o << " partonId : ";
  for (size_t i = 0; i < 2; ++i) {
    o << value.getPartonId()[i] << "|";
  }
  o << '\n';
  o << " lhapdfId : ";
  for (size_t i = 0; i < 2; ++i) {
    o << value.getLhapdfId()[i] << "|";
  }
  o << '\n';
  o << " x : ";
  for (size_t i = 0; i < 2; ++i) {
    o << value.getX()[i] << "|";
  }
  o << '\n';
  o << " xf : ";
  for (size_t i = 0; i < 2; ++i) {
    o << value.getXf()[i] << "|";
  }
  o << '\n';
  o << " scale : " << value.getScale() << '\n';

  return o;
}

#if defined(PODIO_JSON_OUTPUT) && !defined(__CLING__)
void to_json(nlohmann::json& j, const GeneratorPdfInfo& value) {
  j = nlohmann::json{{"partonId", value.getPartonId()},
                     {"lhapdfId", value.getLhapdfId()},
                     {"x", value.getX()},
                     {"xf", value.getXf()},
                     {"scale", value.getScale()}};
}
#endif

} // namespace edm4hep
