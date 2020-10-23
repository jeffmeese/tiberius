#ifndef EMPEROR_REQUEST_H
#define EMPEROR_REQUEST_H

#include "tiberius.h"
#include "event.h"

//#include "resources/resourcetypes.h"

#include <QDataStream>

class EmperorRequest
    : public Event
{
public:
  TIBERIUS_LIB_DECL EmperorRequest();

public:
  TIBERIUS_LIB_DECL bool canComply() const;
  TIBERIUS_LIB_DECL bool dialogShown() const;
  TIBERIUS_LIB_DECL bool visible() const;
  TIBERIUS_LIB_DECL int32_t amount();
  TIBERIUS_LIB_DECL int32_t deadline();
  TIBERIUS_LIB_DECL int32_t favor() const;
  TIBERIUS_LIB_DECL int32_t monthsLeft() const;
  TIBERIUS_LIB_DECL int32_t resourceId() const;
  TIBERIUS_LIB_DECL int32_t state() const;
  TIBERIUS_LIB_DECL void setCanComply(bool value);
  TIBERIUS_LIB_DECL void setDialogShown(bool value);
  TIBERIUS_LIB_DECL void setVisible(bool value);
  TIBERIUS_LIB_DECL void setAmount(int32_t value);
  TIBERIUS_LIB_DECL void setDeadline(int32_t value);
  TIBERIUS_LIB_DECL void setFavor(int32_t value);
  TIBERIUS_LIB_DECL void setMonthsLeft(int32_t value);
  TIBERIUS_LIB_DECL void setResourceId(int32_t value);
  TIBERIUS_LIB_DECL void setState(int32_t value);

private:
  bool mCanComply;
  bool mDialogShown;
  bool mVisible;
  int32_t mAmount;
  int32_t mDeadline;
  int32_t mFavor;
  int32_t mMonthsLeft;
  int32_t mResourceId;
  int32_t mState;
};

inline bool EmperorRequest::canComply() const
{
  return mCanComply;
}

inline bool EmperorRequest::dialogShown() const
{
  return mDialogShown;
}

inline bool EmperorRequest::visible() const
{
  return mVisible;
}

inline int32_t EmperorRequest::amount()
{
  return mAmount;
}

inline int32_t EmperorRequest::deadline()
{
  return mDeadline;
}

inline int32_t EmperorRequest::favor() const
{
  return mFavor;
}

inline int32_t EmperorRequest::monthsLeft() const
{
  return mMonthsLeft;
}

inline int32_t EmperorRequest::resourceId() const
{
  return mResourceId;
}

inline int32_t EmperorRequest::state() const
{
  return mState;
}

inline void EmperorRequest::setCanComply(bool value)
{
  mCanComply = value;
}

inline void EmperorRequest::setDialogShown(bool value)
{
  mDialogShown = value;
}

inline void EmperorRequest::setVisible(bool value)
{
  mVisible = value;
}

inline void EmperorRequest::setAmount(int32_t value)
{
  mAmount = value;
}

inline void EmperorRequest::setDeadline(int32_t value)
{
  mDeadline = value;
}

inline void EmperorRequest::setFavor(int32_t value)
{
  mFavor = value;
}

inline void EmperorRequest::setMonthsLeft(int32_t value)
{
  mMonthsLeft = value;
}

inline void EmperorRequest::setResourceId(int32_t value)
{
  mResourceId = value;
}

inline void EmperorRequest::setState(int32_t value)
{
  mState = value;
}

#endif // EMPEROR_REQUEST_H
