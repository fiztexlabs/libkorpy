#include <pybind11/embed.h>
#include <iostream>
#include <libkorpy/korpy.h>

namespace py = pybind11;
using namespace py::literals;

int main()
{
    py::scoped_interpreter guard{};

    py::module_ calc = py::module_::import("calc");
    py::object result = calc.attr("add")(1, 2);
    int n = result.cast<int>();
    
    std::cout << n << std::endl;

    // auto kwargs = py::dict("name"_a="World", "number"_a=42);
    // auto message = "Hello, {name}! The answer is {number}"_s.format(**kwargs);
    // py::print(message);
}