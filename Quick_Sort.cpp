#include <iostream>
using namespace std;

int Array[100] = { 0 };
int Input_Number = 0;

void QuickSort(int left, int right)
{
	if (left > right)
	{
		return;
	}

	int Temp = Array[left];
	int i = left;
	int j = right;
	int t = 0;

	while (i != j)
	{
		while (Array[j] >= Temp && i < j)
		{
			j--;
		}

		while (Array[i] <= Temp && i < j)
		{
			i++;
		}

		if (i < j)
		{
			t = Array[i];
			Array[i] = Array[j];
			Array[j] = t;
		}
	}
	Array[left] = Array[i];
	Array[i] = Temp;

	QuickSort(left, i-1);
	QuickSort(i+1, right);
}

void main()
{
	cout << "输入要排序的个数:";
	cin >> Input_Number;

	cout << "输入排序的数:";
	for (int i = 0; i < Input_Number; i++)
	{
		cin >> Array[i];
	}

	QuickSort(0, Input_Number-1);

	//print results
	for (int i = 0; i < Input_Number; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;

	system("pause");
}