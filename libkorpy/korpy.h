#pragma once 
#include <functional>
#include <libkorpy/korpy_export.h>


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	/**
	 * @brief Function load python module, which name is FuncName and execute korsar_mt function in this module
	 * 
	 * @param FuncName: Name of python file, which is launch for run
	 * @param[out] Out: Results
	 * @param Args: Arguments 
	 */
	void LIBKORPY_EXPORT callfunc(const char* FuncName, double* Out, double* const Args);

#ifdef __cplusplus
}
#endif // __cplusplus