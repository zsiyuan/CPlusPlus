#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	struct node * next;
};

int main()
{
	struct node *head, *p, *q;
	int Number = 0;
	cout << "输入数据的个数:";
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

	int insert_data = 0;
	cout << "输入要插入的数:";
	cin >> insert_data;

	struct node * t = head;
	while (t != NULL)
	{
		if (t->next == NULL || t->next->data > insert_data)
		{
			p = (struct node *)malloc(sizeof(struct node));
			p->data = insert_data;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}

	t = head;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}


	system("pause");
	return 0;
}