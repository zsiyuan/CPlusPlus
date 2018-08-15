#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

int main()
{
	struct node *head, *p, *q;
	int Number = 0;
	cout << "数据个数:";
	cin >> Number;

	head = NULL;
	q = NULL;

	int input_data = 0;
	for (int i = 0; i < Number; i++)
	{
		cin >> input_data;
		p = (struct node *)malloc(sizeof(struct node));
		p->data = input_data;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}

	//打印输出
	struct node * t = head;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}

	system("pause");
	return 0;
}