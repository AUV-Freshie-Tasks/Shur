#pragma PID_H
#include <list>
using namespace std;

static list<double> cache;
double timeStep = 0.1;
size_t maxSize = 50;
double Kp = 1;
double Ki = 1;
double Kd = 1;
class Proportional{
	public:
		Proportional() {};
		double Kp = 1;
		void setKp(double temp){
			Kp = temp;
		}

		double proportionalValue(double error){
			return Kp*error;
		}
};

class Integral{
        public:
		Integral() {};
	       double Ki = 1;

	       void setKi(double temp) {
	       Ki = temp;
	       };

	       double integralValue(double error){
		       size_t l = cache.size();
		       cache.push_front(error);
		       if(l > maxSize)
		       {
			       cache.pop_back();
		       }



		       double sum = 0;
		       for(double temp : cache)
		       {
			       //not multiplying timestep as it is constant for now
			       sum = sum + temp;
		       }
		       return Ki*sum/l;
	       }
};

class Differential{
	public:
		Differential() {};
		double Kd = 1;
		double prevError;
		void setKd(double temp){
			Kd = temp;
		}
		size_t l = cache.size();


		double differentialValue(double error){
			if(l = 0)
                {
                        prevError = 0;
                }

			prevError = cache.front();
			double dE = error - prevError;

			return Kd*dE/timeStep;
		}
};

class PID{
	public:
		Proportional p;
		Differential d;
		Integral i;
		PID(){};
		double finalValue(double error){
			return  p.proportionalValue(error) + d.differentialValue(error) + i.integralValue(error);
		}
};








