#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct {
	char key[10];
	char name[20];
	int age;
}Data;

typedef struct Node{
	Data data;
	struct Node *next;
}ListNode;

//追加节点
ListNode *Add(ListNode *head, Data data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	if (!node)
	{
		cout << "节点内存申请失败" << endl;
		return NULL;
	}
	else{
		node->data = data;
		node->next = NULL;
		if (head == NULL)
		{
			head = node;
			return head;
		}
		else{
			ListNode *tmp = head;
			while (tmp->next)
			{
				tmp = tmp->next;
			}//找到尾节点
			tmp->next = node;
			return head;
		}//else
	}//else
}

ListNode *searchNode(ListNode *head, char *key)
{
	if (head == NULL)
		return NULL;

	ListNode *tmp = head;
	while (tmp)
	{
		if (strcmp(tmp->data.key, key) == 0)
			return tmp;
		tmp = tmp->next;
	}//while
	return NULL;
}

int length(ListNode *head)
{
	if (!head)
		return 0;

	int len = 0;
	ListNode *tmp = head;
	while (tmp)
	{
		++len;
		tmp = tmp->next;
	}//while
	return len;
}

void display(ListNode *head)
{
	if (!head)
		cout << "当前链表为空！" << endl;
	
	cout << "当前链表中有" << length(head) << "个元素" << endl;

	ListNode *tmp = head;
	while (tmp)
	{
		cout << tmp->data.key << ", " << tmp->data.name << ", " << tmp->data.age << endl;
		tmp = tmp->next;
	}
}

int main()
{
	
	ListNode *node, *head = NULL;
	Data data;

	do{
		cout << "输入添加的节点信息（学号 姓名 年龄）" << endl;
		//清空输入缓冲区
		fflush(stdin);
		cin >> data.key >> data.name >> data.age;
		if (data.age)
		{
			head = Add(head, data);
		}
		else{
			break;
		}
	} while (1);

	display(head);

	fflush(stdin);
	
	cout << "输入要取出节点的编号" << endl;

	char key[10];
	cin >> key;

	node = searchNode(head , key);
	if (node)
	{
		cout << "关键字" << key << "对应的节点为：" << node->data.key << node->data.name << node->data.age << endl;
	}//fi
	
	system("pause");
	return 0;

}