#include "pid.h"
#include <iostream>
using namespace std;

int main(){
	PID c;
	double setpoint = 1000000;
	double var=2;
	double error;


	for(int i = 0; i <1000; i++){
	
		error = var - setpoint;
		var = var - c.finalValue(error);
		cout<<var<<"\n";
	}


	return 0;

}
