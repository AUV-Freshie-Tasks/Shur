#pragma MATRIX_H

#include <vector>;
using namespace std;
template <class T>
class Matrix{
	private:
		T rows;
		T cols;
		vector<vector<T>> data;
	public:
	        //constructor 
		Matrix(size_t r, size_t c) : rows(r), cols(c)
	        {
	

		//resizing the vector of vector	
		data.resize(rows);
		for(int i=0; i<rows; i++)
		{
			data[i].resize(cols);
		};


		//setting initial values to zero
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
			data[i][j] = 0;
			}
		}
	
	
		}

	        //function: getValue
		T getValue(size_t r, size_t c)
		{
			return data[r][c];
		}

		//function: insertValue
		void insertValue(size_t r, size_t c, T value)
		{
			data[r][c] = value;
		}

		//function: print
		void print()
		{
			for(int i=0; i<rows;i++)
			{
				for(int j=0; j<cols; j++)
				{
					cout<<data[i][j]<<"  ";
				}
				cout<<'\n';

			}
			cout<<'\n';
		}

		//overloading the + operator

		Matrix operator+(const Matrix &other)
		{
			Matrix result(rows,cols);
			if(rows==other.rows && cols==other.cols)
			{

				for(int i=0; i< rows; i++)
				{
					for(int j=0; j<cols; j++)
					{
						result.data[i][j] = data[i][j] + other.data[i][j];
					}
				}
			}
		//	else{
			// exception handling will write while writing main.cpp
		//	}
		return result;
		}

};





