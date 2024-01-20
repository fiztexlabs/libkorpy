#pragma once 
#include <alien_export.h>
#include <functional>
#include <libkorpy/korpy_export.h>


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	extern void ALIEN_EXPORT alienfunc(std::function<double *(double *)>, const char *, const int, const int);
	extern void ALIEN_EXPORT alienfuncinfo(const char *, int *const, int *const);
	extern void ALIEN_EXPORT callalien(const char *, double[], double *const);

	void LIBKORPY_EXPORT alib();
	void LIBKORPY_EXPORT afuncinfo(const char *, int *const, int *const);
	void LIBKORPY_EXPORT callfunc(const char *, double[], double *const);

	double *foo(double *const args);

#ifdef __cplusplus
}
#endif // __cplusplus