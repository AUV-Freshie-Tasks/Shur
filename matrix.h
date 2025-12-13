#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
template <typename Temp>
class Matrix {
	private: 
		size_t rows;
		size_t cols;
		std::vector<std::vector<Temp>> data;

	public:
		Matrix() : rows(0), cols(0) {}

		Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) 
						   {

				data.resize(rows, std::vector<Temp>(cols));}
		Temp& operator()(size_t row, size_t col) {
			if (row > rows-1 || col > cols-1) {
				throw std::invalid_argument("Index does not exist");
			}
			return data[row][col];}
		const Temp& operator()(size_t row, size_t col) const {
                        if (row > rows-1 || col > cols-1) {
                                throw std::invalid_argument("Index does not exist");
                        }
                        return data[row][col];}

		size_t numberOfRows() { return rows;}
		size_t numberOfColumns() { return cols;}
		void print() const {
                        for (size_t i = 0; i < rows; i++){
				for (size_t j=0; j< cols; j++){
					std::cout << data[i][j] << "  ";
				}
				std::cout << "\n";
			}}


    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Cannot add matrices");
     }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j]; }}
        return result; 
    }


    Matrix operator*(Temp scalar) const {
        Matrix result(rows, cols);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] * scalar; }}
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix multiplication dimension mismatch");
        }

        Matrix result(rows, other.cols);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < other.cols; j++) {
                Temp temp = 0;
                for (size_t k = 0; k < cols; k++) {
                    temp = temp + data[i][k]*other.data[k][j];
                }
                result(i, j) = temp;}}
        return result;}

    Matrix inverse() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square");
        }

        size_t n = rows;
        Matrix augmented(n, 2*n);

        for (size_t i = 0; i<n; i++) {
            for (size_t j = 0; j<n; j++) {
                augmented(i,j) = data[i][j];
            }
            augmented(i,i+n) = 1;}

        for (size_t i=0;i<n; i++) {
            Temp pivot = augmented(i,i);

            for (size_t j =0; j<2*n; j++) {
                augmented(i,j) /= pivot;
            }

            for (size_t k=0; k<n; k++) {
                if (k != i) {
                    Temp factor = augmented(k,i);
                    for (size_t j = 0; j < 2*n; j++) {
                        augmented(k, j) -= factor*augmented(i, j);}}}}

        Matrix result(n, n);
        for (size_t i=0;i<n; i++) {
            for (size_t j = 0; j < n; j++) {
                result(i, j) = augmented(i, j + n);}}

        return result;}


    std::pair<Matrix, Matrix> lhDecomposition() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square");
        }

        size_t n = rows;
        Matrix L(n, n);
        Matrix H = *this;

        for (size_t i =0;i<n; i++) {
            L(i, i) =1;
        }
	for (size_t i =0;i<n; i++) {
            for (size_t k = i + 1; k<n; k++) {
                Temp factor = H(k, i) / H(i, i);
                L(k, i) = factor;
                for (size_t j =i; j<n; j++) {
                    H(k, j) -= factor * H(i, j);}}}

        return {L, H};}


};
#endif
