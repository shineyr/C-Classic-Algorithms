#include <iostream>
#include <cstdlib>

using namespace std;

//穷举算法，对鸡兔的数量用引用传递，若存在结果返回true，否则返回false
bool QiongJu(int heads, int foots, int &chicken, int &rabbit)
{
	bool ret = false;
	int c, r;

	for (int c = 0; c < heads; c++)
	{
		r = heads - c;
		if ((2 * c + 4 * r) == foots)
		{
			ret = true;
			chicken = c;
			rabbit = r;
		}//if
	}//for

	return ret;
}

int main()
{
	int chicken, rabbit, heads, foots;

	cout<< "请输入头足的数量：\n";
	while (cin >> heads >> foots)
	{
		bool ret = QiongJu(heads, foots, chicken, rabbit);

		if (ret)
		{
			cout << "鸡有：" << chicken << "只，兔有：" << rabbit << "只。" << endl;
		}
		else{
			cout << "无解！" << endl;
		}
	}//while

	system("pause");
	return 0;
}