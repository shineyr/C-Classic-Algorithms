#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXNUM = 30;

int falseCoin(int weight[], int lhs, int rhs)
{
	if (lhs == rhs)
		return lhs + 1;
	//如果只剩下两个银币，则较轻的那个便是假币
	else if (lhs == (rhs - 1))
	{
		return weight[lhs] < weight[rhs] ? lhs + 1 : rhs + 1;
	}
	
	int lsum = 0, rsum = 0;

	//如果偶数个银币，则比较两等份
	if ((rhs - lhs + 1) % 2 == 0)
	{
		for (int i = lhs; i < (lhs + (rhs - lhs + 1) / 2); i++)
		{
			lsum += weight[i];
		}

		for (int j = lhs + (rhs - lhs + 1) / 2; j <= rhs; j++)
		{
			rsum += weight[j];
		}

		//左右两份等重，则无假币
		if (lsum == rsum)
			return -1;
		else
			return (lsum < rsum) ? falseCoin(weight, lhs, lhs + (rhs - lhs) / 2) : falseCoin(weight, lhs + (rhs - lhs) / 2 + 1, rhs);
	}

	//如果奇数个银币，则比较除中间银币外的两等份
	else if ((rhs - lhs + 1) % 2 != 0)
	{
		for (int i = lhs; i < (lhs + (rhs - lhs) / 2); i++)
		{
			lsum += weight[i];
		}

		for (int j = (lhs + (rhs - lhs) / 2 + 1); j <= rhs; j++)
		{
			rsum += weight[j];
		}

		//左右两份等重，则无假币
		if (lsum == rsum && weight[lhs] == weight[lhs + (rhs - lhs) / 2])
			return -1;

		//如果两份等重，中间银币较轻，则中间银币为假币
		else if (lsum == rsum && weight[lhs] > weight[lhs + (rhs - lhs) / 2])
			return lhs + (rhs - lhs) / 2 + 1;
		
		//否则，返回较轻那份中的假币
		else
			return (lsum < rsum) ? falseCoin(weight, lhs, lhs + (rhs - lhs) / 2 - 1) : falseCoin(weight, lhs + (rhs - lhs) / 2 + 1, rhs);
	}
}

int main()
{
	int weight[MAXNUM];

	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> weight[i];

		int falsePos = falseCoin(weight, 0, n - 1);

		if (falsePos != -1)
			cout << "第" << falsePos << "个银币为假币！" << endl;
		else
			cout << "无假币!" << endl;

	}//while

	system("pause");
	return 0;
}