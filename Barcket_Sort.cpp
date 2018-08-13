#include<iostream>
using namespace std;

int main()
{
	int Array[10] = { 0 };
	int Input_number = 0;
	int Input_data = 0;
	cout << "请输入要排序的数字个数:";
	cin >> Input_number;

	cout << "请输入数据:";
	for (int i = 0; i < Input_number; i++)
	{
		cin >> Input_data;
		Array[Input_data - 1] += 1;
	}
	//输出排序结果
	for (int j = 10 - 1; j >= 0; j--)
	{
		if (Array[j] != 0)
		{
			for (int i = 0; i < Array[j]; i++)
			{
				cout << (j+1) << " ";
			}
		}
	}
	cout << endl;

	system("pause");
	return 0;
}