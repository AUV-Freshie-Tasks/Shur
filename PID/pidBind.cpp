#include <pybind11/pybind11.h>
#include "pid.h"

namespace py = pybind11;

PYBIND11_MODULE(bindingModule, m){
	py::class_<Proportional>(m, "Proportional")
		.def(py::init<>())
		.def( "proportionalValue", &Proportional::proportionalValue);

	py::class_<Integral>(m, "Integral")
                .def(py::init<>())
                .def( "integralValue", &Integral::integralValue);

	py::class_<Differential>(m, "Differential")
                .def(py::init<>())
                .def( "differentialValue", &Differential::differentialValue);

	py::class_<PID>(m, "PID")
                .def(py::init<>())
                .def( "finalValue", &PID::finalValue);	

}		
