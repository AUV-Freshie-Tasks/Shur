#include <pybind11/pybind11.h>
#include "matrix.h"
#include <iostream>

namespace py = pybind11;

PYBIND11_MODULE(bindingModule, m , py::mod_gil_not_used()) {
	py::class_<Matrix<double>>(m, "Matrix")
		.def(py::init<size_t,size_t>())
		.def(py::init<>())
                
	.def("getValue", &Matrix<double>::getValue)
        .def("insertValue", &Matrix<double>::insertValue)
        .def("print", &Matrix<double>::print)
        .def("multiplyScalar", &Matrix<double>::multiplyScalar)
        .def("invertMatrix", &Matrix<double>::invertMatrix)
        .def("getLU", &Matrix<double>::getLU)
        .def("generateKey", &Matrix<double>::generateKey);
}

