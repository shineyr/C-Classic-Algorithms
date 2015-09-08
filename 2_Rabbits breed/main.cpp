#include <iostream>
#include <cstdlib>

using namespace std;

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	cout << "递推法求兔子产仔问题，请输入月份:" << endl;
	int n;
	while (cin >> n)
	{
		cout << n << "月后，兔子有：" << Fibonacci(n) << "对。" << endl;
	}

	system("pause");
	return 0;
}