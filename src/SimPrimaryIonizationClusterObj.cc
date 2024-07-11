// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticle.h"
#include "edm4hep/SimPrimaryIonizationClusterObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

SimPrimaryIonizationClusterObj::SimPrimaryIonizationClusterObj() :
    id(),
    data(),
    m_MCParticle(nullptr),
    m_electronCellID(new std::vector<std::uint64_t>()),
    m_electronTime(new std::vector<float>()),
    m_electronPosition(new std::vector<edm4hep::Vector3d>()),
    m_pulseTime(new std::vector<float>()),
    m_pulseAmplitude(new std::vector<float>()) {
}

SimPrimaryIonizationClusterObj::SimPrimaryIonizationClusterObj(const podio::ObjectID id_,
                                                               SimPrimaryIonizationClusterData data_) :
    id(id_), data(data_) {
}

SimPrimaryIonizationClusterObj::SimPrimaryIonizationClusterObj(const SimPrimaryIonizationClusterObj& other) :
    id(),
    data(other.data),
    m_MCParticle(nullptr),
    m_electronCellID(new std::vector<std::uint64_t>(*(other.m_electronCellID))),
    m_electronTime(new std::vector<float>(*(other.m_electronTime))),
    m_electronPosition(new std::vector<edm4hep::Vector3d>(*(other.m_electronPosition))),
    m_pulseTime(new std::vector<float>(*(other.m_pulseTime))),
    m_pulseAmplitude(new std::vector<float>(*(other.m_pulseAmplitude))) {
  if (other.m_MCParticle) {
    m_MCParticle = new edm4hep::MCParticle(*(other.m_MCParticle));
  }
}

SimPrimaryIonizationClusterObj::~SimPrimaryIonizationClusterObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_electronCellID;
    delete m_electronTime;
    delete m_electronPosition;
    delete m_pulseTime;
    delete m_pulseAmplitude;
  }

  delete m_MCParticle;
}
} // namespace edm4hep
