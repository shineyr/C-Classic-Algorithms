#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double MontePI(int n)
{
	double PI;
	double x, y;
	int sum = 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		x = (double)rand() / RAND_MAX; //产生0~1之间的一个随机数
		y = (double)rand() / RAND_MAX; 

		if (x*x + y*y <= 1)
			sum++;

	}//for

	PI = 4.0 * sum / n;
	return PI;
}

int main()
{
	int n;
	double PI;

	cout << "蒙特卡罗算法求圆周率PI：" << endl;

	cout << "输入点数：" << endl;

	while (cin >> n)
	{	
		PI = MontePI(n);

		cout << PI << endl;
	}
	


	system("pause");
	return 0;
}