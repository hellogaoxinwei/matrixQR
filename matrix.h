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
	Matrix(int r_=0 , int l_ =0); //���캯��
	Matrix(int r_, int l_, double** newone);
	Matrix(const Matrix& rhs);
	~Matrix();
	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator = (const Matrix& rhs);
	Matrix operator*(const double m);
	Matrix operator*(const Matrix& rhs);
	Matrix operator/(const double m);
	Matrix operator()(const int j);//��ȡ����ĵ�j��
	double& operator()( int rows,  int cols);//��ȡ����ĵ�i�У���j��Ԫ��
	int rows()const;//���ؾ��������
	int cols()const;//���ؾ��������
	Matrix transporse();//����ת��
	friend ostream& operator << (ostream& os, const Matrix& rhs);
	friend istream& operator >> (istream& is, const Matrix& rhs);
};

class col_vector :public Matrix
{
public:
	col_vector(int r_ = 0);
	double& operator()(int i);//��ȡ�������ĵ�i��
	//~col_vector();
};

class row_vector :public Matrix
{
public:
	
	row_vector(int l_ = 0);
	double& operator()(int j);//��ȡ�������ĵ�j��
};

class Unit :public Matrix //���쵥λ����
{
public:
	Unit(int row = 0);
};
#endif