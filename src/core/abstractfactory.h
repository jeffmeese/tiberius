#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <cstdint>
#include <functional>
#include <memory>
#include <map>
#include <string>
#include <utility>

template <class AbstractProduct, class IdType>
class Factory
{
  using Creator = std::function<AbstractProduct(void)>;

public:
  void registerFactory(IdType type, const Creator & make)
  {
    mFactoryMap.insert(std::make_pair(type, make));
  }

  AbstractProduct create(IdType type) const
  {
    auto itr = mFactoryMap.find(type);
    if (itr != mFactoryMap.end()) {
      return itr->second();
    }
    return nullptr;
  }

private:
  std::map<IdType, Creator> mFactoryMap;
};

template<typename IdType, class AbstractProduct, class DerivedProduct>
class Registrar
{
public:
  Registrar(IdType type)
  {
    AbstractProduct::factory().registerType(type, [](void) -> AbstractProduct * { return new DerivedProduct(); } );
  }
};

#endif // ABSTRACTFACTORY_H
