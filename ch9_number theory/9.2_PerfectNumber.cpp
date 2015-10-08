#include <iostream>
#include <cstdlib>

using namespace std;

/************************************************************************/
/* 
* 完全数：等于其所有因子的和
* 与完全数相关的两个概念：
* 亏数：当一个自然数的所有真因子的和小于该自然数，则为亏数
* 盈数：当一个自然数的所有真因子的和大于该自然数，则为盈数
*/
/************************************************************************/

//判断完全数
bool judgePerfect(long &num)
{
	//循环处理1~num/2找其真因子
	long sum = num;
	for (int i = 1; i <= num / 2; ++i)
	{
		if (num % i == 0)
		{
			sum -= i;
		}
	}//for
	if (0 == sum)
		return true;
	else
		return false;
}

//int main()
//{
//	cout << "找出1~1000内的所有完全数：" << endl;
//	for (long i = 0; i < 10000; i++)
//		if (judgePerfect(i))
//			cout << i << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}