#include <iostream>
#include <cstdlib>

using namespace std;

bool isLeapYear(int year)
{
	//闰年两个判断规则：（1）可以整除400 （2）不能整除100但可以整除4
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
	{
		return 1;
	}
	else
		return 0;
}

//int main()
//{
//	int year;
//	cout << "2000 年到3000 年之间所有的闰年如下：" << endl;
//
//	for (int year = 2000; year <= 3000; year++)
//	{
//		if (isLeapYear(year))
//			cout << year << "\t";
//	}
//
//	system("pause");
//	cout << endl;
//	return 0;
//}