#ifndef TIBERIUS_H
#define TIBERIUS_H

#if defined(TIBERIUS_EXPORT)
#  define TIBERIUS_LIB_DECL __declspec(dllexport)
#elif defined(JCAESAR_IMPORT)
#  define TIBERIUS_LIB_DECL __declspec(dllimport)
#else
#  define TIBERIUS_LIB_DECL
#endif

#endif // TIBERIUS_H
