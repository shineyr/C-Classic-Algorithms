#include <iostream>
#include <cstdlib>

using namespace std;

/************************************************************************/
/*
* 亲密数：如果不等整数a,b 满足a的真因子和等于b ， b的真因子和等于a ，则
* 两者称为亲密数
*/
/************************************************************************/

//求一个数的亲密数
int friendNum(int &a)
{
	//循环处理1~num/2找其真因子和
	int b = 0;
	for (int i = 1; i <= a / 2; ++i)
	{
		if (a % i == 0)
		{
			b += i;
		}
	}//for
	
	//对该因子和进行因式分解
	int sum = 0;
	for (int j = 1; j <= b / 2; ++j)
	{
		if (b % j == 0)
			sum += j;
	}
	//避免重复，用a<b筛选
	if (sum == a && a < b)
		return b;
	else
		return 0;
}

//int main()
//{
//	cout << "找出1~10000内的所有完全数：" << endl;
//	for (int i = 0; i < 10000; i++)
//		if (friendNum(i) != 0)
//			cout << "[ " << i << " , " << friendNum(i) << " ]" << endl;
//	cout << endl;
//	system("pause");
//	return 0;
//}