#include <iostream>
using namespace std;

int fun(int x)
{
	int sum = 0;
	int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	while (x/10 != 0)
	{
		sum += f[x%10];
		x = x / 10;
	}
	sum += f[x];
	return sum;
}

int main()
{
	int Number = 0;
	int sum = 0;
	int k = 0;
	cout << "输入火柴棒根数:";
	cin >> Number;

	for (int i = 0; i < 1111; i++)
	{
		for (int j = 0; j < 1111; j++)
		{
			k = i + j;
			if (fun(i) + fun(j) + fun(k) == (Number - 4))
			{
				cout << i << "+" << j << "=" << k << endl;
				sum++;
			}
		}
	}


	system("pause");
	return 0;
}
