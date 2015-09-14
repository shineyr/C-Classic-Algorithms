#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//不用+-*/ 不用第三个变量，交换两个数的值
void swap(int &a, int &b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}

//选择排序
void SelectionSort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		//在k~n-1位置选择最小数
		for (int j = k + 1; j<n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}//if
		}//for

		if (k != i)
			swap(a[i], a[k]);
	}//for
}

const int N = 10;
int main()
{
	int a[N];

	srand(time(NULL));

	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;

	cout << "Before sort: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << "\t";

	SelectionSort(a, N);

	cout << endl << "After sort: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << "\t";

	system("pause");

	return 0;
}