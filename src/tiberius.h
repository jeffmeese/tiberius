#ifndef TIBERIUS_H
#define TIBERIUS_H

#include <QtCore/QtGlobal>

#if defined(TIBERIUS_EXPORT)
#  define TIBERIUS_LIB_DECL Q_DECL_EXPORT
#elif defined(TIBERIUS_IMPORT)
#  define TIBERIUS_LIB_DECL Q_DECL_IMPORT
#else
#  define TIBERIUS_LIB_DECL
#endif

#endif // TIBERIUS_H
