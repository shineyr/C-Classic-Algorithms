#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


/*
* 任何一个合数都可以写成几个质数相乘的形式，这几个质数都称为这个合数的质因数
* 下面实现分解质因数算法
*/

//判断素数
bool isPrime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			return false;
	}//for
	return true;
}

//分解质因数
vector<int> PrimeFactor(int n)
{
	//质数的质因数是其本身
	if (isPrime(n))
	{
		return vector<int>(1, n);
	}

	vector<int> ret;
	for (int i = 2; i <= n; ++i)
	{
		if (n % i == 0 && isPrime(i))
		{
			ret.push_back(i);
			n /= i;
		}
	}//for

	return ret;
}

//int main()
//{
//	vector<int> ret = PrimeFactor(1155);
//	for (size_t i = 0; i < ret.size(); ++i)
//		cout << ret[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}