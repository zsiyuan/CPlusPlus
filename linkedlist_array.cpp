#include <iostream>
using namespace std;

int main()
{
	int data[100];
	int right[100];

	int Number = 0;
	cout << "原始数据大小:";
	cin >> Number;

	cout << "读入原始数据:";
	for (int i = 0; i < Number; i++)
	{
		cin >> data[i];
	}

	//初始化right矩阵
	for (int i = 0; i < Number; i++)
	{
		if (i != (Number - 1))
		{
			right[i] = i + 1;
		}
		else
		{
			right[i] = -1;
		}
	}

	int insert_data = 0;
	cout << "输入插入的数:";
	cin >> insert_data;
	data[Number] = insert_data;

	int t = 0;
	while (t != -1)
	{
		if (data[right[t]] > insert_data)
		{
			right[Number] = right[t];
			right[t] = Number;
			break;
		}
		t = right[t];
	}

	t = 0;
	while (t != -1)
	{
		cout << data[t] << " ";
		t = right[t];
	}

	system("pause");
	return 0;
}
