#pragma once

#ifdef DLL1_LIB_EXPORTS
#define DLL1_LIB_API _declspec(dllexport)
#else
#define DLL1_LIB_API _declspec(dllimport)
#endif

extern "C" DLL1_LIB_API double y(double x);
extern "C" DLL1_LIB_API double HH(double x);
extern "C" DLL1_LIB_API double SH(double x);
extern "C" DLL1_LIB_API double characteristic(double m, double x1, double x2, double y1, double y2);
extern "C" DLL1_LIB_API double shag(double m, double x1, double x2, double y1, double y2);
