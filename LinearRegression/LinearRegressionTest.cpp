

#include "LinearRegression.h"
#include <vector>
#include <utility>
#include <iostream>

int main(){
	vector<pair<double,double>> data = {{1,2},{0,0}};
	pair<double,double> answer = getLine(data, 0.01, 1000);
	cout<< answer.first;
	cout<< answer.second;
	return 0;
}
	
