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
  mState = 0;
  mLegionId = 0;
  mType = Type::Legionnaires;
  mId = id;
  mAcademyTrained = false;
  mEmpireService = false;
  mMorale = Morale::Average;
  mNumSoliders = 0;
  mMaxSoliders = 16;
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
  mFields.push_back(streamio::readUInt8(dataStream)); mState = mFields[0];
  mFields.push_back(streamio::readUInt8(dataStream)); mFriendly = mFields[1];
  mFields.push_back(streamio::readUInt8(dataStream)); mLegionId = mFields[2];
  mFields.push_back(streamio::readUInt8(dataStream)); mAtFort = mFields[3];
  mFields.push_back(streamio::readInt16(dataStream)); mType = Type(mFields[4]);
  mFields.push_back(streamio::readInt16(dataStream)); mBuildingId = mFields[5];
  for (int i = 0; i < 16; i++) {
    mFields.push_back(streamio::readInt16(dataStream));
    mFigures[i] = mFields[6+i];
  }

  mFields.push_back(streamio::readUInt8(dataStream)); mNumSoliders = mFields[22];
  mFields.push_back(streamio::readUInt8(dataStream)); mMaxSoliders = mFields[23];
  mFields.push_back(streamio::readInt16(dataStream)); mDefense = mFields[24];
  mFields.push_back(streamio::readInt16(dataStream)); mMorale = Morale(mFields[25]);
  mFields.push_back(streamio::readUInt8(dataStream)); mXFort = mFields[26];
  mFields.push_back(streamio::readUInt8(dataStream)); mYFort = mFields[27];
  mFields.push_back(streamio::readUInt8(dataStream)); mXStandard = mFields[28];
  mFields.push_back(streamio::readUInt8(dataStream)); mYStandard = mFields[29];
  mFields.push_back(streamio::readUInt8(dataStream)); mX = mFields[30];
  mFields.push_back(streamio::readUInt8(dataStream)); mY = mFields[31];
  mFields.push_back(streamio::readUInt8(dataStream)); mDestX = mFields[32];
  mFields.push_back(streamio::readUInt8(dataStream)); mDestY = mFields[33];
  mFields.push_back(streamio::readInt16(dataStream)); mDestBuildingId = mFields[34];
  mFields.push_back(streamio::readInt16(dataStream)); mFigureId = mFields[35];
  mFields.push_back(streamio::readUInt8(dataStream)); mIsLegion = mFields[36];
  mFields.push_back(streamio::readUInt8(dataStream));
  mFields.push_back(streamio::readInt16(dataStream)); mAttack = mFields[38];
  dataStream.skipRawData(66);

//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream)); //mTotalSoliders = mFields[39];
//  mFields.push_back(streamio::readUInt8(dataStream)); //mSolderCapacity = mFields[40];
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream)); //mMorale = Morale(mFields[43]);
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream)); // Fort x
//  mFields.push_back(streamio::readUInt8(dataStream)); // Fort y
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));  //mAcademyTrained = mFields[63];
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));
//  mFields.push_back(streamio::readUInt8(dataStream));

  //for (int i = 0; i < 128; i++)
  //  mFields.push_back(streamio::readUInt8(dataStream));
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
