#include<pybind11/pybind11.h>
#include "logistic.h"
namespace py = pybind11;

PYBIND11_MODULE(bindingModule, m){
           py::class_<logistic>(m, "logistic")
		.def(py::init<>())
		
		.def("inputData", &logistic::inputData)
		.def("sig", &logistic::sig)
		.def("cfm", &logistic::cfm)
		.def("cfc", &logistic::cfc)
		.def("getWeights", &logistic::getWeights)
		.def("predictProbablity", &logistic::predictProbablity);
}
