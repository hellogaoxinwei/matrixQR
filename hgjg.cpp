#include"models.h"
using std::cin;
using std::cout;
using std::endl;
extern double ess;
int main()
{
	cout << "Please input a matrix and a col vetor.Please let matrix's col equals vector." << endl;
	cout << "Now Please input matrix's row and col,and let row>=col" << endl;
	int m, n;
	cin >> m >> n;
	if (m < n)
	{
		cout << "error input" << endl;
		return 0;
	}
	cout << "Now please input matrix " << endl;
	Matrix A(m, n);
	cin >> A;
	cout << "Now please input col" << endl;
	Matrix y(m,1);
	cin >> y;
	cout << "Now we solve the least QR-square and its ess's square" << endl;
	Matrix x(n,1);
	x = endsolve(A, y);
	cout << "the least QR-square answer is" << "x=" << endl;
	cout << x;
	cout << "the ess^2=" << endl;
	cout << ess << endl;
	return 0;

}