// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RecIonizationClusterObj.h"
#include "podio/ObjectID.h"

namespace edm4hep {

RecIonizationClusterObj::RecIonizationClusterObj() :
    id(), data(), m_trackerPulse(new std::vector<edm4hep::TrackerPulse>()) {
}

RecIonizationClusterObj::RecIonizationClusterObj(const podio::ObjectID id_, RecIonizationClusterData data_) :
    id(id_), data(data_) {
}

RecIonizationClusterObj::RecIonizationClusterObj(const RecIonizationClusterObj& other) :
    id(), data(other.data), m_trackerPulse(new std::vector<edm4hep::TrackerPulse>(*(other.m_trackerPulse))) {
}

RecIonizationClusterObj::~RecIonizationClusterObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_trackerPulse;
  }
}
} // namespace edm4hep
