// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/GeneratorEventParametersObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

GeneratorEventParametersObj::GeneratorEventParametersObj() :
    id(),
    data(),
    m_signalVertex(new std::vector<edm4hep::MCParticle>()),
    m_crossSections(new std::vector<double>()),
    m_crossSectionErrors(new std::vector<double>()) {
}

GeneratorEventParametersObj::GeneratorEventParametersObj(const podio::ObjectID id_,
                                                         GeneratorEventParametersData data_) :
    id(id_), data(data_) {
}

GeneratorEventParametersObj::GeneratorEventParametersObj(const GeneratorEventParametersObj& other) :
    id(),
    data(other.data),
    m_signalVertex(new std::vector<edm4hep::MCParticle>(*(other.m_signalVertex))),
    m_crossSections(new std::vector<double>(*(other.m_crossSections))),
    m_crossSectionErrors(new std::vector<double>(*(other.m_crossSectionErrors))) {
}

GeneratorEventParametersObj::~GeneratorEventParametersObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_signalVertex;
    delete m_crossSections;
    delete m_crossSectionErrors;
  }
}
} // namespace edm4hep
