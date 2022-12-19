#include<iostream>
using std::ostream;
using std::istream;
#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
protected:
	int row, list;
	double** HL;
public:
	Matrix(int r_=0 , int l_ =0); //构造函数
	Matrix(int r_, int l_, double** newone);
	Matrix(const Matrix& rhs);
	~Matrix();
	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator = (const Matrix& rhs);
	Matrix operator*(const double m);
	Matrix operator*(const Matrix& rhs);
	Matrix operator/(const double m);
	Matrix operator()(const int j);//提取矩阵的第j列
	double& operator()( int rows,  int cols);//提取矩阵的第i行，第j列元素
	int rows()const;//返回矩阵的行数
	int cols()const;//返回矩阵的列数
	Matrix transporse();//矩阵转置
	friend ostream& operator << (ostream& os, const Matrix& rhs);
	friend istream& operator >> (istream& is, const Matrix& rhs);
};

class col_vector :public Matrix
{
public:
	col_vector(int r_ = 0);
	double& operator()(int i);//提取列向量的第i行
	//~col_vector();
};

class row_vector :public Matrix
{
public:
	
	row_vector(int l_ = 0);
	double& operator()(int j);//提取行向量的第j列
};

class Unit :public Matrix //构造单位矩阵
{
public:
	Unit(int row = 0);
};
#endif