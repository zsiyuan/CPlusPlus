#include<iostream>
using namespace std;

struct queue {
	int data[1000];
	int head;
	int tail;
};

struct stack {
	int data[10];
	int top;
};

int main()
{
	struct queue q1, q2;
	struct stack s;
	int book[10];
	q1.head = 0;
	q1.tail = 0;
	q2.head = 0;
	q2.tail = 0;
	s.top = 0;

	for (int i = 0; i < 10; i++)
	{
		book[i] = 0;
	}

	//小哼读入数据
	cout << "读入小哼的数据:";
	for (int i = 0; i < 6; i++)
	{
		cin >> q1.data[q1.tail];
		q1.tail++;
	}

	cout << endl;

	//小哈读入数据
	cout << "小哈读入数据:";
	for (int i = 0; i < 6; i++)
	{
		cin >> q2.data[q2.tail];
		q2.tail++;
	}

	cout << endl;

	int temp = 0;

	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		//小哼先出牌
		temp = q1.data[q1.head];
		if (book[temp - 1] == 0)
		{
			q1.head++;
			s.top++;
			s.data[s.top] = temp;
			book[temp - 1] = 1;
		}
		else
		{
			q1.head++;
			q1.data[q1.tail] = temp;
			q1.tail++;
			while (s.data[s.top] != temp)
			{
				book[s.data[s.top] - 1] = 0;
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}

			book[s.data[s.top] - 1] = 0;
			q1.data[q1.tail] = s.data[s.top];
			q1.tail++;
			s.top--;
		}

		if (q1.head == q1.tail)
		{
			break;
		}

		//小哈出牌
		temp = q2.data[q2.head];
		if (book[temp - 1] == 0)
		{
			q2.head++;
			s.top++;
			s.data[s.top] = temp;
			book[temp - 1] = 1;
		}
		else
		{
			q2.head++;
			q2.data[q2.tail] = temp;
			q2.tail++;
			while (s.data[s.top] != temp)
			{
				book[s.data[s.top] - 1] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
			book[s.data[s.top] - 1] = 0;
			q2.data[q2.tail] = s.data[s.top];
			q2.tail++;
			s.top--;
		}
	}

	if (q2.head == q2.tail)
	{
		cout << "小哼赢了!" << endl;
		cout << "小哼剩余牌为:";
		for (int i = q1.head; i < q1.tail; i++)
		{
			cout << q1.data[i] << " ";
		}
		cout << endl;
		if (s.top > 0)
		{
			cout << "桌上的牌为:";
			for (int i = 1; i <= s.top; i++)
			{
				cout << s.data[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "桌上已没有牌了!" << endl;
		}
	}
	else
	{
		cout << "小哈赢了！" << endl;
		cout << "小哈剩余牌为:";
		for (int i = q2.head; i < q2.tail; i++)
		{
			cout << q2.data[i] << " ";
		}
		cout << endl;
		if (s.top > 0)
		{
			cout << "桌上剩余牌为:";
			for (int i = 1; i <= s.top; i++)
			{
				cout << s.data[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "桌上已经没有牌了!" << endl;
		}
	}

	system("pause");
	return 0;
}