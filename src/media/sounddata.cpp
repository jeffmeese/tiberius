#include "sounddata.h"
#include "sound.h"

SoundData::SoundData()
{
}

void SoundData::addSound(std::unique_ptr<Sound> sound)
{
  mIndexMap[sound->id()] = static_cast<int>(mSounds.size());
  mSounds.push_back(std::move(sound));
}

Sound * SoundData::findSound(int id)
{
  IndexMap::iterator itr = mIndexMap.find(id);
  if (itr == mIndexMap.end()) {
    return nullptr;
  }

  return mSounds[itr->second].get();
}

const Sound * SoundData::findSound(int id) const
{
  IndexMap::const_iterator itr = mIndexMap.find(id);
  if (itr == mIndexMap.end()) {
    return nullptr;
  }

  return mSounds.at(itr->second).get();
}

Sound * SoundData::getSound(int index)
{
  return mSounds[index].get();
}

const Sound * SoundData::getSound(int index) const
{
  return mSounds[index].get();
}

int SoundData::totalSounds() const
{
  return static_cast<int>(mSounds.size());
}
