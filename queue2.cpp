#include <iostream>
using namespace std;

struct queue
{
	int data[100];
	int head;
	int tail;
};

int main()
{
	int Number = 0;
	cout << "输入数据的个数:";
	cin >> Number;

	struct queue q;
	q.head = 1;
	q.tail = 1;

	cout << "输入数据:";
	for (int i = 0; i < Number; i++)
	{
		cin >> q.data[q.tail];
		q.tail++;
	}

	while (q.head < q.tail)
	{
		cout << q.data[q.head] << " ";
		q.head++;
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		q.head++;
	}

	cout << endl;
	system("pause");
	return 0;
}