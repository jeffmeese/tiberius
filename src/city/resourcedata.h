#ifndef RESOURCEDATA_H
#define RESOURCEDATA_H

#include "datamodel.h"

#include "resource/resource.h"

#include <map>
#include <memory>
#include <vector>

class ResourceData
    : public DataModel
{
public:
  TIBERIUS_LIB_DECL ResourceData();
  TIBERIUS_LIB_DECL ~ResourceData();

public:
  TIBERIUS_LIB_DECL std::vector<Resource::Type> & availableResources();
  TIBERIUS_LIB_DECL const std::vector<Resource::Type> & availableResources() const;
  TIBERIUS_LIB_DECL void setAvailableResources(const std::vector<Resource::Type> & resources);

public:
  TIBERIUS_LIB_DECL void addAvailableResource(Resource::Type type);
  TIBERIUS_LIB_DECL Resource * getResource(Resource::Type type);
  TIBERIUS_LIB_DECL const Resource * getResource(Resource::Type type) const;
  TIBERIUS_LIB_DECL bool isResourceAvailable(Resource::Type type) const;
  TIBERIUS_LIB_DECL void removeAvailableResource(Resource::Type);

private:
  using ResourcePtr = std::unique_ptr<Resource>;

private:
  ResourcePtr mResources[Resource::MAX_RESOURCES];
  std::vector<Resource::Type> mAvailableResources;
  std::map<Resource::Type, int> mResourceToIndex;
  std::map<Resource::Type, QString> mResourceStrings;
};

#endif // RESOURCEDATA_H
