#include "resource.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

Resource::Resource()
{
  mType = Type::Wheat;
}

Resource::Type Resource::type() const
{
  return mType;
}

QPixmap Resource::getImage(Type type)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(GROUP_RESOURCE_ICONS);

  int32_t imageOffset = 0;
  switch (type) {
  case Type::Wheat:
    imageOffset += 1;
    break;
  case Type::Vegetables:
    imageOffset += 2;
    break;
  case Type::Fruit:
    imageOffset += 3;
    break;
  default:
    break;
  }

  QPixmap pixmap = QPixmap::fromImage(imageData->getImageRecord(baseId+imageOffset)->createImage());
  return pixmap;
}

QString Resource::getString(Type type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  QString textString;

  switch (type) {
  case Type::Wheat:
    textString = stringData->getString(23, 1);
    break;
  case Type::Vegetables:
    textString = stringData->getString(23, 2);
    break;
  case Type::Fruit:
    textString = stringData->getString(23, 3);
    break;
  default:
    textString = stringData->getString(23, 0);
  }

  return textString;
}
