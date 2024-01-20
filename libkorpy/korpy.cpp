#include <libkorpy/korpy.h>
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;

void LIBKORPY_EXPORT alib()
{
	alienfunc(foo, "foo", 1, 2);
}

void LIBKORPY_EXPORT afuncinfo(const char *FuncName, int *const ValNum, int *const ArgNum)
{
    alienfuncinfo(FuncName, ValNum, ArgNum);
    return void();
}

void LIBKORPY_EXPORT callfunc(const char* FuncName, double Out[], double* const Args)
{
	callalien(FuncName, Out, Args);
	return void();
}

double *foo(double *const args)
{
	static double out[1];
	// out[0] = args[0] + args[1];

    
    py::scoped_interpreter guard{};

    py::module_ calc = py::module_::import("calc");

    py::object result = calc.attr("add")(args[0], args[1]);
    out[0] = result.cast<double>();
    
    std::cout << out[0] << std::endl;

	return out;
}