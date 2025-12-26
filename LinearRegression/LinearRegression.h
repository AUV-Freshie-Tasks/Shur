#pragma once

#include<utility>
#include<vector>
using namespace std;




double costFunction(double m, double c, vector<pair<double,double>> data){
	double result = 0;
	double x;
	double y;
	for(int i=0; i < data.size(); i++)
	{
		x = data[i].first;
		y = data[i].second;
		result = result + (y-m*x-c)*(y-m*x-c);
	}
	return result;
}

double interceptGradient(double m, double c, vector<pair<double,double>> data){
        double result = 0;
        double x;
        double y;
        for(int i=0; i < data.size(); i++)
        {
                x = data[i].first;
                y = data[i].second;
                result = result + (y-m*x-c);
        }
	result = result*(-2);
        return result;
}

double slopeGradient(double m, double c, vector<pair<double,double>> data){
        double result = 0;
        double x;
        double y;
        for(int i=0; i < data.size(); i++)
        {
                x = data[i].first;
                y = data[i].second;
                result = result + x*(y-m*x-c);
        }
        result = result*(-2);
        return result;
}


pair<double,double> getLine(vector<pair<double,double>> data, double stepSize, size_t noOfSteps){

	double m = 0;
	double c = 0;

	for(int i=0; i<noOfSteps; i++){
	double cfValue = costFunction(m,c,data);
	double temp= m;
	m = m - slopeGradient(m,c,data)*stepSize;
	c = c - interceptGradient(temp,c,data)*stepSize;
	}
	pair<double,double> result;
	result.first = m;
	result.second = c;

	return result;

}
