#include"matrix.h"
#include<cmath>
#include<iomanip>
const double tot = 1e-6;
using namespace std;
 int i, j;
 Matrix::Matrix(int r_, int l_) :row(r_), list(l_)//　　//构造函数
 {
	     HL = new double* [row];
	     for (i = 0; i < row; i++)
		         HL[i] = new double[list];
		 for (i = 0; i < row; i++)
			 for (j = 0; j < list; j++)
				 HL[i][j] = 0;
	 }

 Matrix::Matrix(int r_, int l_, double** newone) :row(r_), list(l_)//　　//构造函数重载，主要用于加法减法中的return使用
 {
	 for (i = 0; i < row; i++)
		 for (j = 0; j < list; j++)
			 if (abs(newone[i][j]) < tot)
				 newone[i][j] = 0;

	     HL = new double* [row];
	     for (i = 0; i < row; i++)
		         HL[i] = new double[list];
	     for (i = 0; i < row; i++)
		         for (j = 0; j < list; j++)
		             HL[i][j] = newone[i][j];
	 }
 
 Matrix::Matrix(const Matrix & rhs)
 {
	     if (this != &rhs)
		     {
		         this->row = rhs.row;
		        this->list = rhs.list;
		         HL = new double* [row];
		         for (i = 0; i < row; i++)
			            HL[i] = new double[list];
		       for (i = 0; i < row; i++)
			           for (j = 0; j < list; j++)
			                this->HL[i][j] = rhs.HL[i][j];
		     }
	 }

 Matrix::~Matrix()//　　　　//　析构函数，删除开辟的空间
 {
	    
	     for (i = 0; i < row; i++)
		         delete[] HL[i];
	     delete[] HL;
	 }

 int Matrix::rows()const
 {
	 return row;
 }

 int Matrix::cols()const
 {
	 return list;
 }


 Matrix Matrix::operator + (const Matrix& rhs)
 {
	 if ((this->row == rhs.row) && (this->list == rhs.list))
	 {
		 double** newone;
		 int r_, l_;
		 r_ = row; l_ = list;
		 newone = new double* [row];
		 for (i = 0; i < row; i++)
			 newone[i] = new double[list];
		 for (i = 0; i < row; i++)
			 for (j = 0; j < list; j++)
				 newone[i][j] = HL[i][j] + rhs.HL[i][j];
		 return Matrix(r_, l_, newone);
	 }
 }
	

 Matrix Matrix::operator - (const Matrix & rhs)
 {
	     if ((this->row == rhs.row) && (this->list == rhs.list))
		    {
		        double** newone;
		        int r_, l_;
		        r_ = row; l_ = list;
		         newone = new double* [row];
		        for (i = 0; i < row; i++)
			            newone[i] = new double[list];
		         for (i = 0; i < row; i++)
			             for (j = 0; j < list; j++)
			               newone[i][j] = HL[i][j] - rhs.HL[i][j];
		         return Matrix(r_, l_, newone);
		     }
	 
		
 }

 Matrix Matrix::operator * (const double m)
 {
		 double** newone;
		 int r_, l_;
		 r_ = row; l_ = list;
		 newone = new double* [row];
		 for (i = 0; i < row; i++)
			 newone[i] = new double[list];
		 for (i = 0; i < row; i++)
			 for (j = 0; j < list; j++)
				 newone[i][j] = m * HL[i][j];
		 return Matrix(r_, l_, newone);
	 }
	 
 
 Matrix Matrix::operator * (const Matrix&rhs)
 {
	 double** newone;
	 int r_, l_;
	 r_ = row; l_ = rhs.list;
	 newone = new double* [row];
	 for (i = 0; i < row; i++)
		 newone[i] = new double[rhs.list];
	 for (i = 0; i < row; i++)
	  for (j = 0; j < rhs.list; j++)
			 newone[i][j] = 0;

	 for (i = 0; i < row; i++)
		 for (j = 0; j < rhs.list; j++)
			 for (int k = 0; k < list; k++)
				 newone[i][j]+= HL[i][k] * rhs.HL[k][j];
	

	 return Matrix(r_, l_, newone);
 }
 Matrix Matrix::operator / (const double m)
 {
	 double** newone;
	 int r_, l_;
	 r_ = row; l_ = list;
	 newone = new double* [row];
	 for (i = 0; i < row; i++)
		 newone[i] = new double[list];
	 for (i = 0; i < row; i++)
		 for (j = 0; j < list; j++)
			 newone[i][j] =  HL[i][j]/m;
	 return Matrix(r_, l_, newone);
 }

 Matrix Matrix::operator = (const Matrix & rhs)
 {
	     if ((this->row == rhs.row) && (this->list == rhs.list))
		    {
		         for (i = 0; i < row; i++)
			             for (j = 0; j < list; j++)
			                this->HL[i][j] = rhs.HL[i][j];
		      return (*this);
		    }
	 //        cout<<"error ——矩阵类型不符 "<<endl; 
		 }

 Matrix Matrix::operator()(const int m)
 {
	 double** newone;
	 int r_, l_;
	 r_ = row; l_ = 1;
	 newone = new double* [row];
	 for (i = 0; i < row; i++)
		 newone[i] = new double[1];
	 for (i = 0; i < row; i++)
		 newone[i][0] = HL[i][m-1];
	 return Matrix(r_, l_, newone);
 }
 Matrix Matrix::transporse()
 {
	 double** newone;
	 int r_, l_;
	 r_ = list; l_ = row;
	 newone = new double* [list];
	 for (i = 0; i < row; i++)
		 newone[i] = new double[row];
	 for (i = 0; i < list; i++)
		 for (j = 0; j < row; j++)
			 newone[i][j] = HL[j][i];
	 return Matrix(list, row, newone);
	 
 }

 double& Matrix::operator()( int i,  int j)
 {
	 return HL[i-1][j-1];
 }

 ostream & operator << (ostream & os, const Matrix & rhs)
{
	    
	    for (i = 0; i < rhs.row; i++)
		     {
			for (j = 0; j < rhs.list; j++)
			{
				os << setiosflags(ios::fixed) << setprecision(4) << rhs.HL[i][j] << " ";
			}
			os << endl;
		    }
	    return os;
	 }
 
 istream& operator >> (istream& is, const Matrix& rhs)
 {

	 for (i = 0; i < rhs.row; i++)
	 {
		 for (j = 0; j < rhs.list; j++)
			 is >> rhs.HL[i][j];
		 
	 }
	 return is;
 }

 col_vector::col_vector(int r_) :Matrix(r_, 1)
 {
	 
		 HL = new double* [row];
		 for (i = 0; i < row; i++)
			 HL[i] = new double[1];
		 for (i = 0; i < row; i++)
			 HL[i][0] = 0;
	 
 }

 /*col_vector::~col_vector()//　　　　//　析构函数，删除开辟的空间
 {

	 for (i = 0; i < row; i++)
		 delete[] HL[i];
	 delete[] HL;
 }
 */
 double& col_vector::operator()(int i)
 {
	 return HL[i-1][0];
 }

 
 row_vector::row_vector(int l_) :Matrix(1, l_)
 {
	 HL = new double* [1];
		 HL[0] = new double[list];
	 for (j = 0; j < list; j++)
		 HL[0][j] = 0;
 }
 double& row_vector::operator()(int j)
 {
	 return HL[0][j-1];
 }

 Unit::Unit(int rows):Matrix(rows,rows)
 {
		 for (i = 0; i < rows; i++)
			 for (j = 0; j < rows; j++)
				 if (i == j)
					 HL[i][j] = 1;
				 else HL[i][j] = 0;
 }