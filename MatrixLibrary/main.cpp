#include <iostream>
#include "matrix.h"
#include <stdlib.h>
#include <utility>

using namespace std;


int main(){
	//Test for Addition
	size_t numberOfRows;
	size_t numberOfCols;
	size_t dataA;
	size_t dataB;
	size_t temp;
	cout<<"Test for Addition of Matrices\n";
	cout<<"Type number of rows:\n";
	cin>> numberOfRows;
	cout<<"Type number of columns:\n";
	cin>> numberOfCols;

	cout<<"The Matrix will contain "<< numberOfRows*numberOfCols <<" elements\n";
	cout<<"Type a number containing "<< numberOfRows*numberOfCols <<" digits, the digits of the number will be stored in the matrixA\n";
	cin>> dataA;
	cout<<"Type a number containing "<< numberOfRows*numberOfCols <<"digits, the digits of the number will be stored in the matrixB\n";
        cin>> dataB;

	system("clear");
	Matrix<double> matrixA(numberOfRows, numberOfCols);
	for(int i=0; i<numberOfRows; i++)
	{
		for(int j=0; j< numberOfCols; j++)
		{
			matrixA.insertValue(i,j,dataA%10);
			dataA = (dataA/10) - ((dataA%10)/10);
		}
	}	

	Matrix<double> matrixB(numberOfRows, numberOfCols);
        for(int i=0; i<numberOfRows; i++)
        {
                for(int j=0; j< numberOfCols; j++)
                {
                        matrixB.insertValue(i,j,dataB%10);
                        dataB = (dataB/10) - ((dataB%10)/10);
                }
        }

	Matrix<double> matrixC(numberOfRows, numberOfCols);
	matrixC = matrixA + matrixB;
	
	cout<<"matrixA:\n";	
	matrixA.print();
	cout<<"matrixB:\n";
        matrixB.print();
	cout<<"matrixA + matrixB:\n";
        matrixC.print();
//	cout<<"Type any number to continue:\n";
//	cin>>temp;
//	system("clear");

	//Test for Multiplication of Matrices
	//incomplete
	matrixC = matrixA*matrixB;
	cout<<"matrixA*matrixB:\n";
	matrixC.print();

	//Test for Inversion
	//incomplete
	matrixC= matrixA.invertMatrix();
	cout<<"matrixA inverse:\n";
	matrixC.print();

	//Test for LU Decomposition
	pair<Matrix<double>,Matrix<double>> LU = matrixA.getLU();
	matrixB = LU.first;
	matrixC = LU.second;
	matrixB.print();
	matrixC.print();


	cout<<"\n The key for matrixA is:\n";
	cout<<matrixA.generateKey();
	return 0;
};


