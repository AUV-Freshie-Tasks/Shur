#include "logistic.h"
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

int main(){
	vector<pair<double, double>> trainingData = {
    {0.5, 0},
    {1.2, 0},
    {1.8, 0},
    {2.1, 0},
    {2.5, 0},
    {2.9, 0},
    {3.0, 0},
    {3.5, 0},
    {4.1, 0},
    {4.4, 0},
    
    {5.0, 1},
    {5.5, 1},
    {6.1, 1},
    {6.4, 1},
    {7.0, 1},
    {7.8, 1},
    {8.2, 1},
    {8.9, 1},
    {9.5, 1},
    {10.0, 1}
};
pair<double,double> result;
logistic l;
l.inputData(trainingData);
result = l.getWeights(0.001,1000000);

return 0;
}
