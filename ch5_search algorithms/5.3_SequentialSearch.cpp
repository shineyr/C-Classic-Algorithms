#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAXLEN = 100;

//定义节点类型
typedef struct {
	char key[10];
	char name[20];
	int age;
}DATA;

//定义顺序表结构
typedef struct {
	DATA ListData[MAXLEN + 1];
	int listLen; //顺序表已存节点的数量
}SLType;

void SLInit(SLType *SL)
{
	SL->listLen = 0;
}

int SLLength(SLType *SL)
{
	return SL->listLen;
}

//增加元素到顺序表表尾
int SLAdd(SLType *SL, DATA data)
{
	if (SL->listLen >= MAXLEN)
	{
		cout << "顺序表已满，不能再添加节点！" << endl;
		return 0;
	}
	SL->ListData[++SL->listLen] = data;
	return 1;
}

//根据序号返回数据元素
DATA *SLFindByNum(SLType *SL, int n)
{
	if (n < 1 || n > SL->listLen + 1)
	{
		cout << "节点序号错误，不能返回节点！" << endl;
		return NULL;
	}
else
	return &SL->ListData[n];
}

//按关键字查询节点
int SLFindByCont(SLType *SL, char *key)
{
	for (int i = 1; i <= SL->listLen; ++i)
	{
		if (strcmp(SL->ListData[i].key, key) == 0)
			return i;
	}//for
	return 0;
}

//显示顺序表中所有节点
int SLAll(SLType *SL)
{
	for (int i = 1; i <= SL->listLen; i++)
	{
		cout << SL->ListData[i].key << ", " << SL->ListData[i].name << ", " << SL->ListData[i].age << endl;
	}
	return 0;
}

int main()
{
	//定义顺序表变量
	SLType SL;
	//定义节点保存数据类型变量
	DATA data;
	//定义节点保存指针变量
	DATA *pdata;

	cout << "顺序表操作演示" << endl;
	SLInit(&SL);
	cout << "初始化顺序表完成" << endl;

	do{
		cout << "输入添加的节点信息（学号 姓名 年龄）" << endl;
		//清空输入缓冲区
		fflush(stdin);
		cin >> data.key >> data.name >> data.age;
		if (data.age)
		{
			if (!SLAdd(&SL,data))
				break;;
		}
		else{
			break;
		}
	} while (1);

	cout << "顺序表中的节点有：" << endl;

	SLAll(&SL);

	fflush(stdin);
	
	cout << "输入要取出节点的编号" << endl;
	int i;
	cin >> i;
	pdata = SLFindByNum(&SL, i);
	if (pdata)
	{
		cout << "第" << i << "个节点为：" << pdata->key << pdata->name << pdata->age << endl;
	}//fi
	
	system("pause");
	return 0;

}



