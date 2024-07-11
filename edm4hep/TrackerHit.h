// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHit_H
#define EDM4HEP_TrackerHit_H

#include "edm4hep/TrackerHit3D.h"
#include "edm4hep/TrackerHitPlane.h"

#include "podio/ObjectID.h"
#include "podio/utilities/TypeHelpers.h"

#include <memory>
#include <ostream>
#include <stdexcept>

namespace edm4hep {

/** @class TrackerHit
 *  Tracker hit interface class
 *  @author: Thomas Madlener, DESY
 */
class TrackerHit {

  /// type alias containing all the types this interface should work for.
  using InterfacedTypes = std::tuple<::edm4hep::TrackerHit3D, ::edm4hep::TrackerHitPlane>;
  /// type alias containing all the mutable types that can be used to initialize
  /// this interface
  using InterfacedMutableTypes = podio::detail::TupleOfMutableTypes<InterfacedTypes>;

  /// template variable for determining whether type T is a valid interface type
  template <typename T>
  constexpr static bool isInterfacedType = podio::detail::isInTuple<T, InterfacedTypes>;

  /// template variable for determining whether type T can be used to initialize
  /// this interface
  template <typename T>
  constexpr static bool isInitializableFrom =
      isInterfacedType<T> || podio::detail::isInTuple<T, InterfacedMutableTypes>;

  struct Concept {
    virtual ~Concept() = default;
    virtual std::unique_ptr<Concept> clone() const = 0;
    virtual void print(std::ostream&) const = 0;

    virtual podio::ObjectID getObjectID() const = 0;
    virtual bool isAvailable() const = 0;
    virtual void unlink() = 0;
    virtual std::uint64_t getCellID() const = 0;

    virtual std::int32_t getType() const = 0;

    virtual std::int32_t getQuality() const = 0;

    virtual float getTime() const = 0;

    virtual float getEDep() const = 0;

    virtual float getEDepError() const = 0;

    virtual const edm4hep::Vector3d& getPosition() const = 0;

    virtual const std::type_info& typeInfo() const = 0;
    virtual bool equal(const Concept* rhs) const = 0;
    virtual const void* objAddress() const = 0;
  };

  template <typename ValueT>
  struct Model final : Concept {
    ~Model() = default;
    Model(ValueT value) : m_value(value) {
    }

    std::unique_ptr<Concept> clone() const final {
      return std::make_unique<Model<ValueT>>(m_value);
    }

    void print(std::ostream& os) const final {
      os << m_value;
    }

    void unlink() final {
      m_value.unlink();
    }
    bool isAvailable() const final {
      return m_value.isAvailable();
    }
    podio::ObjectID getObjectID() const final {
      return m_value.getObjectID();
    }

    const std::type_info& typeInfo() const final {
      return typeid(ValueT);
    }

    bool equal(const Concept* rhs) const final {
      if (typeInfo() == rhs->typeInfo()) {
        return m_value == static_cast<const Model<ValueT>*>(rhs)->m_value;
      }
      return false;
    }

    const void* objAddress() const final {
      return m_value.m_obj.get();
    }

    std::uint64_t getCellID() const final {
      return m_value.getCellID();
    }

    std::int32_t getType() const final {
      return m_value.getType();
    }

    std::int32_t getQuality() const final {
      return m_value.getQuality();
    }

    float getTime() const final {
      return m_value.getTime();
    }

    float getEDep() const final {
      return m_value.getEDep();
    }

    float getEDepError() const final {
      return m_value.getEDepError();
    }

    const edm4hep::Vector3d& getPosition() const final {
      return m_value.getPosition();
    }

    ValueT m_value{};
  };

  std::unique_ptr<Concept> m_self{nullptr};

public:
  template <typename ValueT>
  TrackerHit(ValueT value) : m_self(std::make_unique<Model<podio::detail::GetDefaultHandleType<ValueT>>>(value)) {
    static_assert(isInitializableFrom<ValueT>,
                  "TrackerHit can only be initialized with one of the following types (and their Mutable counter "
                  "parts): ::edm4hep::TrackerHit3D, ::edm4hep::TrackerHitPlane");
  }

  TrackerHit(const TrackerHit& other) : m_self(other.m_self->clone()) {
  }
  TrackerHit& operator=(const TrackerHit& other) {
    TrackerHit tmp{other};
    std::swap(tmp.m_self, this->m_self);
    return *this;
  }

  ~TrackerHit() = default;
  TrackerHit(TrackerHit&&) = default;
  TrackerHit& operator=(TrackerHit&&) = default;

  /// Create an empty handle
  static TrackerHit makeEmpty() {
    // We simply chose the first type of the interfaced types here to initialize
    // an empty handle
    return ::edm4hep::TrackerHit3D::makeEmpty();
  }

  /// check whether the object is actually available
  bool isAvailable() const {
    return m_self->isAvailable();
  }
  /// disconnect from the underlying value
  void unlink() {
    m_self->unlink();
  }

  podio::ObjectID id() const {
    return getObjectID();
  }
  podio::ObjectID getObjectID() const {
    return m_self->getObjectID();
  }

  /// Check if the object currently holds a value of the requested type
  template <typename T>
  bool isA() const {
    static_assert(
        isInterfacedType<T>,
        "TrackerHit can only ever be one of the following types: ::edm4hep::TrackerHit3D, ::edm4hep::TrackerHitPlane");
    return typeid(T) == m_self->typeInfo();
  }

  /// Get the contained value as the concrete type it was put in. This will
  /// throw a std::runtime_error if T is not the type of the currently held
  /// value. Use isA to check beforehand if necessary
  template <typename T>
  T as() const {
    if (!isA<T>()) {
      throw std::runtime_error("Cannot get value as object currently holds another type");
    }
    // We can safely cast here since we check types before
    return static_cast<Model<T>*>(m_self.get())->m_value;
  }

  template <typename T>
  [[deprecated("Use 'as' instead.")]] T getValue() const {
    return as<T>();
  }

  friend bool operator==(const TrackerHit& lhs, const TrackerHit& rhs) {
    return lhs.m_self->equal(rhs.m_self.get());
  }

  friend bool operator!=(const TrackerHit& lhs, const TrackerHit& rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const TrackerHit& lhs, const TrackerHit& rhs) {
    return lhs.m_self->objAddress() < rhs.m_self->objAddress();
  }

  /// Access the ID of the sensor that created this hit
  std::uint64_t getCellID() const {
    return m_self->getCellID();
  }

  /// Access the type of the raw data hit
  std::int32_t getType() const {
    return m_self->getType();
  }

  /// Access the quality bit flag of the hit
  std::int32_t getQuality() const {
    return m_self->getQuality();
  }

  /// Access the time of the hit [ns]
  float getTime() const {
    return m_self->getTime();
  }

  /// Access the energy deposited on the hit [GeV]
  float getEDep() const {
    return m_self->getEDep();
  }

  /// Access the error measured on eDep [GeV]
  float getEDepError() const {
    return m_self->getEDepError();
  }

  /// Access the hit position [mm]
  const edm4hep::Vector3d& getPosition() const {
    return m_self->getPosition();
  }

  friend std::ostream& operator<<(std::ostream& os, const TrackerHit& value) {
    value.m_self->print(os);
    return os;
  }
};

} // namespace edm4hep

#endif
