#ifndef LOGISTIC

#define LOGISTIC
#include <cmath>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class logistic{
	private:
		vector<pair<double,double>> data;

	public:	

	logistic(){};	
	void inputData(vector<pair<double,double>> temp){
		data.resize(temp.size());
		for(int i = 0; i < temp.size(); i++){
			data[i] = temp[i];
		}
	}

	double sig(double sig){
		if(sig >= 0){return (1/(1+exp(-1*sig)));}else{
			return exp(sig)/(1+exp(sig));}
	}


	double cfm(double m, double c){
		                double sum = 0;
                for(int i = 0; i < data.size(); i++){
                        double x = data[i].first;
                        double y = data[i].second;
			sum = sum + (sig(m*x+c)-y)*x;

		}
                return sum;
        }


	double cfc(double m, double c){
                                double sum = 0;
                for(int i = 0; i < data.size(); i++){
                        double x = data[i].first;
                        double y = data[i].second;
                        sum = sum + (sig(m*x+c)-y);
		}

                return sum;
        }

	pair<double,double> getWeights(double stepSize, size_t noOfIterations){
	double m = 1;
	double c = 1;
	double mp,cp;
	int i = 0;
	while(abs(m-mp) > 0.0000001 && abs(c-cp) > 0.0000001){
	i++;	
	mp = m;
	cp = c;
	m = m - cfm(m,c)*stepSize;
	c = c - cfc(mp,c)*stepSize;
	if(i%1000 == 0){cout<<m<<","<<c<<"\n";}
	}
	pair<double,double> result;
	result.first = m;
	result.second = c;
	return result;
	}

	double predictProbablity(double m, double x, double c){
		return sig(m*x+c);
	}
	};

#endif
