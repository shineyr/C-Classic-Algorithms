#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int N = 12;

/*
 * 查找算法的第一种方法—顺序查找， 平均查找次数
 * 为n/2 ，时间复杂度为O(n) 
*/
int SeqSearch(const vector<int> &nums, const int &x)
{
    if (nums.empty())
        return -1;

    int len = nums.size();

    for (int i = 0; i < len; i++)
    {
        if (x == nums[i])
        {
            return i;
            break;
        }//if
    }//for
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

    cout << "查找50 ： ";
    if (-1 == SeqSearch(v, 50))
        cout << "不存在" << endl;
    else
        cout << SeqSearch(v, 50) << endl;

    system("pause");
    return 0;

}