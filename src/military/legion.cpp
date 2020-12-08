#include "legion.h"

#include "application/tiberiusapplication.h"

#include "core/streamio.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "soldier.h"

#include <QDebug>

Legion::Legion(int32_t id)
{
  mType = Type::Legionnaires;
  mId = id;
  mAcademyTrained = false;
  mEmpireService = false;
  mMorale = Morale::Average;
}

Legion::~Legion()
{

}

bool Legion::academyTrained() const
{
  return mAcademyTrained;
}

void Legion::addSolider(std::unique_ptr<Soldier> soldier)
{
  mSoldiers.push_back(std::move(soldier));
}

bool Legion::empireService() const
{
  return mEmpireService;
}

int32_t Legion::id() const
{
  return mId;
}

void Legion::loadFromDataStream(QDataStream &dataStream)
{
  uint8_t value = streamio::readUInt8(dataStream);
  dataStream.skipRawData(127);

  qDebug() << value;

  //for (int32_t i = 0; i < 32; i++) {
  //  int32_t value = streamio::readInt32(dataStream);
  //  qDebug() << value;
  //}
}

Legion::Morale Legion::morale() const
{
  return mMorale;
}

QString Legion::moraleString() const
{
  return moraleString(mMorale);
}

QString Legion::moraleString(Morale morale)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(138, static_cast<int32_t>(morale) + 37);
}

QString Legion::name() const
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(138, static_cast<int32_t>(mId));
}

QPixmap Legion::image() const
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(GROUP_FIGURE_FORT_STANDARD_ICONS);

  int32_t imageId = baseId + static_cast<int32_t>(mId);
  QPixmap pixmap = QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage());
  return pixmap;
}

void Legion::removeSolider(const QString & name)
{
  for (SoldierVector::iterator itr = mSoldiers.begin(); itr != mSoldiers.end(); ++itr) {
    if (itr->get()->name() == name) {
      mSoldiers.erase(itr);
      return;
    }
  }
}

void Legion::saveToDataStream(QDataStream &dataStream) const
{

}

void Legion::setAcademyTrained(bool value)
{
  mAcademyTrained = value;
}

void Legion::setEmpireService(bool value)
{
  mEmpireService = value;
}

void Legion::setMorale(Morale value)
{
  mMorale = value;
}

int32_t Legion::totalSoldiers() const
{
  return static_cast<int32_t>(mSoldiers.size());
}

Legion::Type Legion::type()
{
  return mType;
}

QString Legion::typeString() const
{
  return typeString(mType);
}

QString Legion::typeString(Type type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(138, static_cast<int32_t>(type)+33);
}
