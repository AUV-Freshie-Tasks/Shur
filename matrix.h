#pragma once

#include <vector>
#include <utility>
#include "LRUcache.h"

using namespace std;
template <class T>
class Matrix{
	private:
		T rows;
		T cols;
		vector<vector<T>> data;
		LRUcache<pair<Matrix<T>,Matrix<T>>> cache;
	public:


	        //constructor 
		Matrix() : rows(0),cols(0){};
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

		//function: multiplyScalar
		void multiplyScalar(double value)
		{
			for(int i=0; i< rows; i++)
                                {
                                        for(int j=0; j<cols; j++)
                                        {
						data[i][j] = data[i][j]*value;
                                        }
                                }
		}

		//Overloading * operator
		//To perform Matrix multiplication
                Matrix operator*(const Matrix &other)
		{
			Matrix result(rows, other.cols);
			if(cols == other.rows)
			{
				for(int i=0; i< rows; i++)
                                {
                                        for(int j=0; j<other.cols; j++)
                                        {
						T value =0;
						for(int k=0; k<cols; k++)
						{
							value = data[i][k]*other.data[k][j] + value;
						}
						result.data[i][j] = value;
                                        }
                                }
	
			}
		//	else{}

			return result;

		}

		//function: invertMatrix
		Matrix invertMatrix()
		{
			Matrix result(rows,cols);
			Matrix joined(rows,2*cols);
			for(int i=0; i<rows; i++)
			{
				for(int j=0; j<cols; j++)
				{
					joined.data[i][j] = data[i][j];
				}
				joined.data[i][i+cols] = 1;
			}

			for(int i=0; i<rows; i++)
			{
				T temp = joined.data[i][i];
				for(int j=0; j<2*rows; j++)
				{
					joined.data[i][j] = joined.data[i][j] / temp;
				}
				for(int k=0; k< rows; k++)
				{
					if(k!=i){
					T value = joined.data[k][i];
					for(int l=0;l<2*rows; l++)
					{
						joined.data[k][l] = joined.data[k][l] - joined.data[i][l]*value;
					}}
				}
			}
			for(int i=0; i<rows; i++)
			{
				for(int j=rows; j<2*rows; j++)
				{
					result.data[i][j-rows]= joined.data[i][j];
				}
			}
			return result;
		}


		//LU Decomposition
		pair<Matrix,Matrix> getLU()
		{
			Matrix L(rows,cols);
			Matrix tmp(rows, cols);

			for(int i=0; i<rows; i++)
                        {
                                for(int j=0; j<cols;j++)
                                {
                                        tmp.data[i][j] = data[i][j];
                                }
                        }
			size_t key = tmp.generateKey();
			pair<Matrix,Matrix> temp = cache.get(key);
			if(temp.first.rows !=0)
			{
				return temp;
			}

			for(int i=0;i<rows; i++)
			{
				L.data[i][i] = 1;
			}

			for(int i=0; i<rows; i++)
			{
				for(int j=i+1; j<rows; j++)
				{
					T temp = tmp.data[j][i]/tmp.data[i][i];
					for(int k=0; k<rows; k++)
					{
						tmp.data[j][k] = tmp.data[j][k] - temp*tmp.data[i][k];
					}
					L.data[j][i] = temp;
				}
			}
			cache.put(key, make_pair(L,tmp));
			return make_pair(L,tmp);
		}


		//Overloading the == operator
		bool operator==(const Matrix &other)
		{
			if(data==other.data)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		//Generate key from matrix
		//basic and prone to collsions, to be changed later
		size_t generateKey()
		{
			hash<T> h;
			size_t temp =0;
			for(int i=0; i<rows;i++)
			{
				for(int j=0; j<cols; j++)\
				{
					temp = temp + h(data[i][j]);
				}
			}
			return temp;

		}	

};





