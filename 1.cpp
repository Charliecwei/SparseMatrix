#include <iostream>
#include "SparseMatrix.h"
#include "SparseMatrix.cpp"

int main()
{	

	SparseMatrix<int> matrix(3, 4);
	matrix.set(2, 1, 1);
	matrix.set(7, 1, 3);
	matrix.set(4, 2, 2);
	matrix.set(1, 3, 4);
	std::vector<int> x(4,1);

	SparseMatrix<int> matrix2(4,3);
	matrix2.set(2,2,1);
	matrix2.set(1,1,2);
	matrix2.set(3,4,1);
	matrix2.set(10,1,3);
	
	std::vector<int> y = matrix.multiply(x);
	std::vector<int> z = matrix*x;
	std::cout << y[0] << std::endl;

	SparseMatrix<int> matrix3(matrix*matrix2);
	SparseMatrix<int> matrix4(matrix+matrix);
	SparseMatrix<int> matrix5(matrix4-matrix);


	std::cout<<matrix<<std::endl; 

	return 0;
}
