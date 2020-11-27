#ifndef SOUNDDATA_H
#define SOUNDDATA_H

#include "tiberius.h"

#include <map>
#include <memory>
#include <vector>

class Sound;

class SoundData
{
public:
 TIBERIUS_LIB_DECL SoundData();
 TIBERIUS_LIB_DECL ~SoundData();

public:
 TIBERIUS_LIB_DECL void addSound(std::unique_ptr<Sound> sound);
 TIBERIUS_LIB_DECL Sound * findSound(int id);
 TIBERIUS_LIB_DECL const Sound * findSound(int id) const;
 TIBERIUS_LIB_DECL Sound * getSound(int index);
 TIBERIUS_LIB_DECL const Sound * getSound(int index) const;
 TIBERIUS_LIB_DECL int totalSounds() const;

private:
 using SoundPtr = std::unique_ptr<Sound>;
 using SoundVector = std::vector<SoundPtr>;
 using IndexMap = std::map<int, int>;

private:
 SoundVector mSounds;
 IndexMap mIndexMap;
};

#endif // SOUNDDATA_H
