//============================================================================
// Name        : Matrix.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>

#define FORS(i,s,e) for(int i = int(s); i <= int(e); i++)
#define FOR(i,n) FORS(i,0,n)
#define tr(C,it) \
	for(typeof((C).begin()) it = (C).begin(); it != (C).end();it++)
#define all(C) (C).begin()
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef struct _Dimension{
	int row;
	int col;
}Dimension;

template<typename T>
class Matrix{
private:
	int row;
	int col;
	Dimension dim;
	vector<vector <T> >  mat;
private:
	Matrix<T> Add(Matrix<T>& other,int sign);
	void AddMats(Matrix<T>& M1,Matrix<T>& M2,Matrix<T>& res,int sign);
	void subMatrix(Matrix<T>& M,Matrix<T>& From, int rowStart,int colStart,int rowEnd,int colEnd);
	void Multiply(Matrix<T>& M1,Matrix<T>& M2,Matrix<T>& res);
public:
	Matrix(int row,int col);
	~Matrix();
	int getRow();
	void setRow(int _row);
	int getCol();
	void setCol(int _col);
	vector<vector<T> >& getMat();
	void setMat(vector<vector<T> > _mat);
	Dimension determineDimension(Matrix<T>& M1,Matrix<T>& M2);
	Matrix<T> Multiplication(Matrix<T>& other);
	Matrix<T> Addition(Matrix<T>& other);
	Matrix<T> Subtraction(Matrix<T>& other);
	void printMatrix();
};

template<typename T>
Matrix<T>::Matrix(int _row,int _col){
	row = _row;
	col = _col;
	dim.row = _row;
	dim.col = _col;
	mat = vector<vector<T> >(row,vector<T> (col,(T)NULL));  // r x c matrix initialized zero
}

template<typename T>
vector<vector<T> >& Matrix<T>::getMat(){
	return mat;
}

template<typename T>
void Matrix<T>::setMat(vector<vector<T> > _mat){
	FOR(i,row-1){
		FOR(j,col-1){
			mat[i][j] = _mat[i][j];
		}
	}
}

template<typename T>
int Matrix<T>::getRow(){
	return this->row;
}

template<typename T>
void Matrix<T>::setRow(int _row){
	row =_row;
}

template<typename T>
int Matrix<T>::getCol(){
	return this->col;
}

template<typename T>
void Matrix<T>::setCol(int _col){
	col = _col;
}

template<typename T>
void Matrix<T>::printMatrix(){
	FOR(i,row-1){
		FOR(j,col-1){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
void printMat(Matrix<T>& M){
	int r = M.getRow();
	int c = M.getCol();
	vector<vector<T> > A = M.getMat();

	FOR(i,r-1){
		FOR(j,c-1){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>
void Matrix<T>::subMatrix(Matrix<T>& M,Matrix<T>& From,int rS,int rE,int cS,int cE){
	for(int i = rS,m =0;i <=rE; i++,m++){
		for(int j = cS,n = 0; j <= cE;j++,n++){
//			cout << mat[i][j] << " ";
			 M.getMat()[m][n]= From.getMat()[i][j];
		}
//		cout << endl;
	}
}




template<typename T>
void Matrix<T>::Multiply(Matrix<T>& M1,Matrix<T>& M2,Matrix<T>& res){
	cout << endl;
	FOR(i,M1.getRow()-1){
		FOR(j,M2.getCol()-1){
			FOR(k,M1.getCol()-1){
				res.getMat()[i][j] += M1.getMat()[i][k] * M2.getMat()[k][j];
			}
		}
	}
}

template<typename T>
Dimension Matrix<T>::determineDimension(Matrix<T>& M1,Matrix<T>& M2){
	Dimension dim;
	dim.row = M1.getRow();
	dim.col = M2.getCol();

	return dim;
}

template<typename T>
Matrix<T> Matrix<T>::Multiplication(Matrix<T>& other)
{
	Matrix<T> res(row,col);

	int fr,fc,cr,cc;

	//generating submatrix a,b,c,d
	if(row % 2 != 0){
		fr = floor(row/2.0);
		cr = ceil(row /2.0);
	}else{
		fr = row / 2;
		cr = fr + 1;
	}

	if(col % 2 != 0){
		fc = floor(col/2.0);
		cc = ceil(col/2.0);
	}else{
		fc = col / 2;
		cc = fc;
	}

	Matrix<T> a(floor(row/2.0),floor(col/2.0));
	subMatrix(a,*this,0,fr-1,0,fc-1);
	a.printMatrix();

	Matrix<T> b(floor(row/2.0),ceil(col/2.0));
	subMatrix(b,*this,0,fr-1,cc-1,col-1);
	b.printMatrix();

	Matrix<T> c(ceil(row/2.0),floor(col/2.0));
	subMatrix(c,*this,cr-1,row-1,0,fc-1);
	c.printMatrix();

	Matrix<T> d(ceil(row/2.0),ceil(col/2.0));
	subMatrix(d,*this,cr-1,row-1,cc-1,col-1);
	d.printMatrix();

	//generating submatrix e,f,g,h
	cout << "efgh" << endl;

	int R = other.getRow();
	int C = other.getCol();

	if(R % 2 != 0){
		fr = floor(R/2.0);
		cr = ceil(R/2.0);
	}else{
		fr = R / 2;
		cr = fr + 1;
	}

	if(C % 2 != 0){
		fc = floor(C / 2.0);
		cc = ceil(C / 2.0);
	}else{
		fc = C / 2 ;
		cc = fc + 1;
	}

	Matrix<T> e(floor(R/2.0),floor(C/2.0));
	subMatrix(e,other,0,fr-1,0,fc-1);
	e.printMatrix();


	Matrix<T> f(floor(R/2.0),ceil(C/2.0));
	subMatrix(f,other,0,fr-1,cc-1,C-1);
	f.printMatrix();

	Matrix<T> g(ceil(R/2.0),floor(C/2.0));
	subMatrix(g,other,cr-1,R-1,0,fc-1);
	g.printMatrix();

	Matrix<T> h(ceil(R/2.0),ceil(C/2.0));
	subMatrix(h,other,cr-1,R-1,cc-1,C-1);
	h.printMatrix();

	Dimension dimP = determineDimension(a,e);
	Matrix<T> matP(dimP.row,dimP.col);
	cout << endl;
	Matrix<T> matP1(dimP.row,dimP.col),matP2(dimP.row,dimP.col);

	//Multiplication of a*e
	Multiply(a,e,matP1);
	cout << "ae" << endl;
	a.printMatrix();
	cout << endl;
	e.printMatrix();
	cout << endl;
	matP1.printMatrix();

	cout << endl;
	//Multiplication of b*g
	Multiply(b,g,matP2);
	matP2.printMatrix();
	cout << endl;

	//Addition of a*e + b*g
	AddMats(matP1,matP2,matP, +1);

	cout << "matP" << endl;
	matP.printMatrix();

	Dimension dimQ = determineDimension(a,f);
	Matrix<T> matQ(dimQ.row,dimQ.col);
	Matrix<T> matQ1(dimQ.row,dimQ.col),matQ2(dimQ.row,dimQ.col);

	//Multiplication of a*f
	Multiply(a,f,matQ1);
	cout << "matQ" << endl;
	matQ.printMatrix();



//	Dimension dimR = determineDimension(c,e);
//	Matrix<T> matR(dimR.row,dimR.col);
//	matR.setMat( (AddMats(Multiply(c,e),Multiply(d,g),+1)).getMat());
//
//	cout << "matR" << endl;
//	matR.printMatrix();
//
//	Dimension dimS = determineDimension(c,f);
//	Matrix<T> matS(dimS.row,dimS.col);
//	matS.setMat( (AddMats(Multiply(c,f),Multiply(d,h),+1)).getMat());
//
//	cout << "matS" << endl;
//	matS.printMatrix();

	return res;
}

/*
 A = | a | b |    B = | e | f |
 	 | c | d |        | g | h |

 R = A * B = | ae + bg | af + bh |
 	 	 	 | ce + dg | cf + dh |

 	 	 	 P = ae + bg
 	 	 	 Q = af + bh
 	 	 	 R = ce + da
 	 	 	 S = cf + dh

 T(n) = 8 * T(n/2) + theta(n^2)

 */
template<typename T>
Matrix<T> Matrix<T>::Add(Matrix<T>& other,int sign){
	Matrix<T> res(row,col);
	FOR(i,row-1){
		FOR(j,col-1){
			res.getMat()[i][j] = mat[i][j] + sign * other.getMat()[i][j];
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::Addition(Matrix<T>& other){
	return this->Add(other,+1);
}

template<typename T>
void Matrix<T>::AddMats(Matrix<T>& M1,Matrix<T>& M2,Matrix<T>& res,int sign){
	FOR(i,M1.getRow()-1){
		FOR(j,M1.getCol()-1){
			res.getMat()[i][j] = M1.getMat()[i][j] + sign * M2.getMat()[i][j];
		}
	}

}

template<typename T>
Matrix<T> Matrix<T>::Subtraction(Matrix& other){
	return this->Add(other.mat,-1);
}


template<typename T>
Matrix<T>::~Matrix(){

}

int main() {
	int N;
	N = 5;


	int A[5][5] = {{ 5, 6, 7, 4, 3},
				   { 4, 3, 6, 8 ,2},
				   { 2, 1, 7, 9, 3},
				   { 1, 6, 2, 3, 4},
				   { 2, 7, 8, 9, 3}
	};


	Matrix<int> matrix(5,5);

	vector<vector<int> > matA(5);
	FOR(i,5-1){
		matA[i] = vector<int> (A[i],A[i] + sizeof(A[i])/sizeof(A[i][0]));
	}

	matrix.setMat(matA);

	matrix.printMatrix();
	cout << endl;

	cout << "Addition" << endl;
	Matrix<int> addRes = matrix.Addition(matrix);
	addRes.printMatrix();

	cout << endl << "Multiplication" << endl;

	int B[5][4] = {{ 4, 3, 2, 1 },
				   { 2, 1, 6, 3 },
				   { 6, 8, 1, 9 },
				   { 4, 2, 9, 7 },
				   { 2, 5, 7, 3 }
	};


	FOR(i,5-1){
		matA[i] = vector<int> (B[i],A[i] + sizeof(B[i])/sizeof(B[i][0]));
	}

	Matrix<int> other(5,4);
	other.setMat(matA);

	other.printMatrix();
	matrix.Multiplication(other);

	return 0;
}
