#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>

class Property
{
public:
  Property();
  Property(const QString & name, const QString & value);

public:
  QString name() const;
  QString value() const;
  void setName(const QString & name);
  void setValue(const QString & value);

private:
  QString mName;
  QString mValue;
};

inline QString Property::name() const
{
  return mName;
}

inline QString Property::value() const
{
  return mValue;
}

inline void Property::setName(const QString & name)
{
  mName = name;
}

inline void Property::setValue(const QString & value)
{
  mValue = value;
}

#endif // PROPERTY_H
