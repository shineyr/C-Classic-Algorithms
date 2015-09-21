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
void InsertionSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}//while
		a[j+1] = temp;
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

	InsertionSort(a, N);

	cout << endl << "After sort: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << "\t";

	system("pause");

	return 0;
}
