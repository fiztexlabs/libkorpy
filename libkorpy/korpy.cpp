#include <libkorpy/korpy.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <iostream>
#include <vector>

namespace py = pybind11;
using namespace py::literals;

py::scoped_interpreter guard{};

void LIBKORPY_EXPORT callfunc(const char* FuncName, double* Out, double* const Args)
{
	static std::vector<double> out;

    py::module extern_module_ = py::module::import(FuncName);

	py::object obj = extern_module_.attr("KorsarMT")();
	py::object result = obj.attr("getResult")(std::vector<double>(Args + 1, Args + 1 + size_t(Args[0])));
	
    out = result.cast<std::vector<double>>();

	for (size_t i = 0; i < out.size(); ++i)
	{
		Out[i] = out.at(i);
	}

	return void();
}