#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*
* 平方回文数是一个回文数，这个回文数可以表示成一个自然数的平方
*/

//判断 自然数n平方是否是平方回文数
bool SquarePalindromic(int n)
{
	long ret = n * n;

	vector<int> v;
	while (ret / 10 != 0)
	{
		v.push_back(ret % 10);
		ret /= 10;
	}//while

	int lhs = 0, rhs = v.size() - 1;
	while (lhs < rhs)
	{
		if (v[lhs] != v[rhs])
			return false;
		++lhs;
		--rhs;
	}
	return true;
}

bool isSquarePalindromic(int n)
{
	int ret = sqrt(n);
	//满足是某个自然数的平方这一条件
	if (ret != 0 && n == ret * ret)
	{
		vector<int> v;
		while (n != 0)
		{
			v.push_back(n % 10);
			n /= 10;
		}//while

		int lhs = 0, rhs = v.size() - 1;
		while (lhs < rhs)
		{
			if (v[lhs] != v[rhs])
				return false;
			++lhs;
			--rhs;
		}
		return true;
	}
	else
		return false;	
}


//int  main()
//{
//	cout << "找出1~1000内的所有平方回文数" << endl;
//	for (int i = 1; i < 1000; ++i)
//		if (isSquarePalindromic(i))
//			cout << i << '\t';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}