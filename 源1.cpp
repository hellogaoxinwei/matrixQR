#include"models.h"
#include<cmath>
using std::cout;
double ess = 0;//残差
Matrix HouseHolder(Matrix& x1, Matrix& x2,int n) //x1,x2都是列向量，x1是原始列向量
//x2是变化后的列向量，n是行数
{
	Unit I(n);
	Matrix v(n, 1);
	v = x1 - x2;
	Matrix vv(1, n);
	vv = v.transporse();//v的转置
	Matrix cube(1, 1);
	cube = vv * v;
	if (abs(cube(1, 1))>1e-5)
	{
		double beta = 2 / (cube(1, 1));
		Matrix H(n, n);
		H = I - (v * vv) * beta;
		return H;
	}
	else
		return I;
}


Matrix QR(Matrix& A,int m,int n)//A是一个m行n列的矩阵
{
	double guodu;
	Unit I(m);
	Matrix Q2(m, m);
	Q2 = I + Q2;
	Matrix Q1(m, m);
	Matrix new_col(m,1);
	Matrix old(m,1);
	for (int i = 1; i <= n; i++)
	{
		
		guodu = 0;
		for (int k = 1; k <= m; k++)
			old(k,1) = A(k, i);
		for (int j = i; j <= m; j++) //
			guodu += old(j,1) * old(j,1);
		for (int j = 1; j <i; j++)
			new_col(j,1) = old(j,1);
		new_col(i,1) = sqrt(guodu);
		Q1 = HouseHolder(old, new_col, m);
		A = Q1 * A;
		Q2 = Q1 * Q2;
	}
	return Q2.transporse();
}
Matrix solve(Matrix& A, Matrix& y,int n) //A是n*n矩阵，y是n*1列向量
{
	Matrix x(n,1);
	double m = 0;
	x(n,1) = y(n,1) / (A(n, n));

	for (int i = n-1; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
			m = m + A(i, j) * x(j,1);
		x(i,1) = (y(i,1) - m) / A(i, i);
	}
	return x;
}

Matrix endsolve(Matrix& A, Matrix& y)
{
	int m= A.rows();
	int n = A.cols();
	Matrix Q(m, m);
	Matrix x(n,1);
	Q = QR(A,m,n);
	Matrix y_temp(m, 1);
	y_temp = Q.transporse() * y;
	Matrix AA(n, n);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			AA(i, j) = A(i, j);
	Matrix yy(n,1);
	for (int i = 1; i <= n; i++)
		yy(i,1) = y_temp(i,1);
	for (int i = n + 1; i <= m; i++)
		ess = ess + y_temp(i, 1) * y_temp(i, 1);
	x = solve(AA, yy, n);
	return x;
}
