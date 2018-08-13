#include <iostream>
using namespace std;

int main()
{
	int Array[100] = {0};
	
	int Input_Number = 0;

	//the number of input data
	cout << "输入排序数据的大小:";
	cin >> Input_Number;

	//输入要排序的数
	for (int i = 0; i < Input_Number; i++)
	{
		cin >> Array[i];
	}

	int Temp = 0;

	for (int i = 1; i <= Input_Number - 1; i++)
	{
		for (int j = 0; j < Input_Number - i; j++)
		{
			if (Array[j] < Array[j + 1])
			{
				Temp = Array[j];
				Array[j] = Array[j+1];
				Array[j + 1] = Temp;
			}
		}
	}

	//print sorted number
	for (int i = 0; i < Input_Number; i++)
	{
		cout << Array[i] << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}