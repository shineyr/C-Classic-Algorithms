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

//冒泡排序
void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j>i; j--)
		{
			if (a[j] > a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}//if
		}//for
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
		cout<<a[i]<<"\t";

	BubbleSort(a, N);

	cout << endl << "After sort: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << "\t";

	system("pause");

	return 0;
}