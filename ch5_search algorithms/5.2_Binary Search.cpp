#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 12;

/*
* 查找算法的第一种方法—折半，最坏情况下查找次数nlogn ， 查找效率高于顺序查找
*/
int BinarySearch(const vector<int> &nums, const int &x)
{
	if (nums.empty())
		return -1;

	int len = nums.size();

	int lhs = 0, rhs = len - 1;
	while (lhs <= rhs)
	{
		int mid = (lhs + rhs) / 2;
		if (x == nums[mid])
		{
			return mid;
		}else if (nums[mid] < lhs)
		{
			lhs = mid + 1;
		}
		else{
			rhs = mid - 1;
		}
	}//while
	return -1;
}

int main()
{
	vector<int> v;

	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		v.push_back(rand() % 100);
	}//for

	cout << "数据序列：" << endl;
	for (int i = 0; i < N; i++)
		cout << v[i] << "\t";
	cout << endl;

	cout << "排序后：" << endl;
	sort(v.begin(), v.end());
	
	cout << "数据序列：" << endl;
	for (int i = 0; i < N; i++)
		cout << v[i] << "\t";
	cout << endl;

	cout << "查找50 ： ";
	int pos = BinarySearch(v, 50);
	if (-1 == pos)
		cout << "不存在" << endl;
	else
		cout << pos << endl;

	system("pause");
	return 0;

}