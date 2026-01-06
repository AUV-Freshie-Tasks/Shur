#include "pid.h"
#include <iostream>
using namespace std;

int main(){
	PID c;

	cout<<c.finalValue(2.3)<< "\n";
        cout<<c.finalValue(2.6)<< "\n";
        cout<<c.finalValue(6.7)<< "\n";
        cout<<c.finalValue(4.2)<< "\n";
        cout<<c.finalValue(4.5)<< "\n";
        cout<<c.finalValue(9.9)<< "\n";
        cout<<c.finalValue(4.5)<< "\n";
        cout<<c.finalValue(3.4)<< "\n";
        cout<<c.finalValue(6.5)<< "\n";

	return 0;

}
