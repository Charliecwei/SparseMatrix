#include <iostream>
#include <vector>

template<typename T>
class SparseMatrix
{
	public:
		// === CREATION ==============================================
		SparseMatrix(int n);
		SparseMatrix(int rows, int columns);
		
		SparseMatrix(const SparseMatrix<T> & m); // copy constructor
        SparseMatrix<T> & operator = (const SparseMatrix<T> & m);

        ~SparseMatrix(void);


		// === GETTERS / SETTERS ==============================================
		int getRowCount(void) const;
		int getColumnCount(void) const;
		std::vector<int>* getRow(void) const;
		std::vector<int>* getColum(void) const;
		// === VALUES ==============================================
		T get(int row, int col) const;
		SparseMatrix & set(T val, int row, int col);
		

		// === OPERATIONS ==============================================
		std::vector<T> multiply(const std::vector<T> & x) const;
		std::vector<T> operator * (const std::vector<T> & x) const;
		
		SparseMatrix<T> multiply(const SparseMatrix<T> & m) const;
		SparseMatrix operator * (const SparseMatrix<T> & m) const;

		SparseMatrix<T> add(const SparseMatrix<T> & m) const;
		SparseMatrix<T> operator + (const SparseMatrix<T> & m) const;

		SparseMatrix<T> subtract(const SparseMatrix<T> & m) const;
		SparseMatrix<T> operator - (const SparseMatrix<T> & m) const;

		//=== FRIEND FUNCTIONS =========================================

		template<typename X>
		friend bool operator == (const SparseMatrix<X> & a, const SparseMatrix<X> & b);

		template<typename X>
		friend bool operator != (const SparseMatrix<X> & a, const SparseMatrix<X> & b);

		template<typename X>
		friend std::ostream & operator << (std::ostream & os, const SparseMatrix<X> & matrix);
	
	protected:
		int m, n;
		std::vector<T> * vals;
		std::vector<int> * rows, * cols;

		// === HELPERS / VALIDATORS ==============================================
		 void construct(int m, int n);
		 void destruct(void);
		 void deepCopy(const SparseMatrix<T> & m);
		 void validateCoordinates(int row, int col) const;
		 void insert(int index, int row, int col, T val);
		 void remove(int index, int row);
};

