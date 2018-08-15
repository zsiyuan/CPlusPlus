#include <iostream>
using namespace std;

int main()
{
	char a[20][21];
	int cols = 0;
	int rows = 0;
	cout << "输入地图的行数:";
	cin >> rows;
	cout << "输入地图的列数:";
	cin >> cols;

	//输入地图
	cout << "输入地图:";
	for (int i = 0; i < rows; i++)
	{
		cin >> a[i];
	}

	int max = 0;
	int sum = 0;
	int x = 0;
	int y = 0;
	int max_x = 0;
	int max_y = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] == '2')
			{
				sum = 0;

				//向上搜索
				x = i;
				y = j;
				while (a[x][y] != '0')
				{
					if (a[x][y] == '1')
					{
						sum++;
					}
					x--;
				}

				//向下搜索
				x = i;
				y = j;
				while (a[x][y] != '0')
				{
					if (a[x][y] == '1')
					{
						sum++;
					}
					x++;
				}

				//向左搜索
				x = i;
				y = j;
				while (a[x][y] != '0')
				{
					if (a[x][y] == '1')
					{
						sum++;
					}
					y--;
				}

				//向右搜索
				x = i;
				y = j;
				while (a[x][y] != '0')
				{
					if (a[x][y] == '1')
					{
						sum++;
					}
					y++;
				}

				if (sum > max)
				{
					max = sum;
					max_x = x;
					max_y = y;
				}
			}
		}
	}

	//输出结果
	cout << "炸弹应该放置在:" << "(" << max_x << "," << max_y << ")" << endl;
	cout << "最大可消灭敌人数:" << max << endl;

	system("pause");
	return 0;
}