#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/************************************************************************/
/* C语言中提供了两个随机数生成函数                               
 * (1)伪随机函数—rand ， 用于返回一个0~32767 之间的随机数
 * (2)随机种子函数—srand ， 用来初始化随机数发生器的随机种子
/************************************************************************/

// 产生[0 , 1] 之间的均匀分布的随机数，
// 首先设定一个基数 base=256.0 以及两个常数 u=17.0 v=139.0 其中基数base一般取2的整数倍，常数a和b根据经验取值
// 按照递推公式 Ri = mod(u*Ri-1 + v , base); Pi = Ri/base
double Rand01(double &r)
{
	double base, u, v, p, tmp1, tmp2, tmp3;
	base = 256.0;
	u = 17.0;
	v = 139.0;

	tmp1 = u * r + v; //计算总值
	tmp2 = (int)(tmp1 / base);  //计算商
	tmp3 = tmp1 - tmp2*base; //计算余数

	r = tmp3;
	p = r / base;

	return p;
}

//u是均值，t是方差
double RandZT(double u, double t, double &r)
{
	double total = 0.0;
	double result;

	for (int i = 0; i < 12; ++i)
	{
		total += Rand01(r);
	}

	result = u + t*(total - 6.0);
	return result;
}

//int main()
//{
//	//(1) 不限制范围的随机数
//
//	// 随机种子由时间函数time(0)来获得
//	srand((int)time(0));
//	cout << "5个随机数：" << endl;
//	for (int i = 0; i < 5; i++)
//		cout << rand() << "\t";
//	cout << endl << endl;
//
//	//(2) 限制100以内的随机数
//	cout << "5个100以内的随机数" << endl;
//	for (int i = 0; i < 5; i++)
//		cout << rand() % 100 << "\t";
//	cout << endl << endl;
//
//	//(3) 产生[0 , 1]之间均匀分布的随机数
//	double r = 5.0;
//	cout << "5个[0,1]之间的随机数：" << endl;
//	for (int i = 0; i < 5; i++)
//		cout << Rand01(r) << "\t";
//	cout << endl << endl;
//
//	//(4) 产生任意范围[m , n ]的随机数
//	// 利用公式 m + (n - m)*Rand01(r)
//	double m = 10.0, n = 20.0;
//	cout << "5个[m=10.0,n=20.0]之间的随机数：" << endl;
//	for (int i = 0; i < 5; i++)
//		cout << m + (n - m)*Rand01(r) << "\t";
//	cout << endl << endl;
//
//	//(5) 产生[m , n]间均匀分布的整数
//	// 利用公式 m + (int)(n - m)*Rand01(r)
//	int mm = 10, nn = 20;
//	cout << "5个[mm=10,nn=20]之间的随机整数：" << endl;
//	for (int i = 0; i < 5; i++)
//		cout << mm + (int)((nn - mm)*Rand01(r)) << "\t";
//	cout << endl << endl;
//
//	//(6) 正态分布的随机数
//	double u = 2.0, t = 3.5; r = 5.0;
//	cout << "5个正态分布的随机数：" << endl;
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << RandZT(u, t, r) << "\t";
//	}
//	cout << endl << endl;
//	system("pause");
//	return 0;
//}