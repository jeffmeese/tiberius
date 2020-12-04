#include "resourcedata.h"

#include <algorithm>

ResourceData::ResourceData()
{
  mResources[0].reset(new Resource(Resource::Type::Wheat));
  mResources[1].reset(new Resource(Resource::Type::Vegetables));
  mResources[2].reset(new Resource(Resource::Type::Fruit));
  mResources[3].reset(new Resource(Resource::Type::Olives));
  mResources[4].reset(new Resource(Resource::Type::Vines));
  mResources[5].reset(new Resource(Resource::Type::Meat));
  mResources[6].reset(new Resource(Resource::Type::Wine));
  mResources[7].reset(new Resource(Resource::Type::Oil));
  mResources[8].reset(new Resource(Resource::Type::Iron));
  mResources[9].reset(new Resource(Resource::Type::Timber));
  mResources[10].reset(new Resource(Resource::Type::Clay));
  mResources[11].reset(new Resource(Resource::Type::Marble));
  mResources[12].reset(new Resource(Resource::Type::Weapons));
  mResources[13].reset(new Resource(Resource::Type::Furniture));
  mResources[14].reset(new Resource(Resource::Type::Pottery));

  mResourceToIndex[Resource::Type::Wheat] = 0;
  mResourceToIndex[Resource::Type::Vegetables] = 1;
  mResourceToIndex[Resource::Type::Fruit] = 2;
  mResourceToIndex[Resource::Type::Olives] = 3;
  mResourceToIndex[Resource::Type::Vines] = 4;
  mResourceToIndex[Resource::Type::Meat] = 5;
  mResourceToIndex[Resource::Type::Wine] = 6;
  mResourceToIndex[Resource::Type::Oil] = 7;
  mResourceToIndex[Resource::Type::Iron] = 8;
  mResourceToIndex[Resource::Type::Timber] = 9;
  mResourceToIndex[Resource::Type::Clay] = 10;
  mResourceToIndex[Resource::Type::Marble] = 11;
  mResourceToIndex[Resource::Type::Weapons] = 12;
  mResourceToIndex[Resource::Type::Furniture] = 13;
  mResourceToIndex[Resource::Type::Pottery] = 14;
}

ResourceData::~ResourceData()
{

}

void ResourceData::addAvailableResource(Resource::Type type)
{
  if (isResourceAvailable(type))
    return;

  mAvailableResources.push_back(type);
  emit changed();
}

std::vector<Resource::Type> & ResourceData::availableResources()
{
  return mAvailableResources;
}

const std::vector<Resource::Type> & ResourceData::availableResources() const
{
  return mAvailableResources;
}

Resource * ResourceData::getResource(Resource::Type type)
{
  std::map<Resource::Type, int>::iterator itr = mResourceToIndex.find(type);
  return mResources[itr->second].get();
}

const Resource * ResourceData::getResource(Resource::Type type) const
{
  std::map<Resource::Type, int>::const_iterator itr = mResourceToIndex.find(type);
  return mResources[itr->second].get();
}

bool ResourceData::isResourceAvailable(Resource::Type type) const
{
  return std::find(mAvailableResources.begin(), mAvailableResources.end(), type) != mAvailableResources.end();
}

void ResourceData::removeAvailableResource(Resource::Type type)
{
  if (!isResourceAvailable(type))
    return;

  std::vector<Resource::Type>::const_iterator itr = std::find(mAvailableResources.begin(), mAvailableResources.end(), type);
  mAvailableResources.erase(itr);
}

void ResourceData::setAvailableResources(const std::vector<Resource::Type> & resources)
{
  mAvailableResources = resources;
  emit changed();
}
