#include <iostream>
using namespace std;

int Number = 0;
int a[10] = {0};
int book[10] = {0};

void DFS(int step)
{
	if (step == Number + 1)
	{
		for (int i = 1; i <= Number; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= Number; i++)
	{
		if (book[i] == 0)
		{
			a[step] = i;
			book[i] = 1;
			DFS(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int main()
{
	cout << "输入1-9之间的整数:";
	cin >> Number;
	DFS(1);

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;
int a[10] = { 0 };
int book[10] = {0};
int sum = 0;

void DFS(int step)
{
	if (step == 10)
	{
		if (100 * a[1] + 10 * a[2] + a[3] + 100 * a[4] + 10 * a[5] + a[6] == 100 * a[7] + 10 * a[8] + a[9])
		{
			sum++;
			for (int i = 1; i <= 9; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (book[i] == 0)
		{
			a[step] = i;
			book[i] = 1;
			DFS(step+1);
			book[i] = 0;
		}
	}

	return;
}

int main()
{
	DFS(1);

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int a[50][50];
int book[50][50] = {0};
int p;
int q;
int min = 10000;

int nrows = 0;
int ncols = 0;

void DFS(int x, int y, int step)
{
	if (x == p && y == q)
	{
		if (step < min)
		{
			min = step;
		}
		return;
	}

	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int tx;
	int ty;
	for (int i = 0; i < 4; i++)
	{
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncols)
			continue;
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}

int main()
{
	int startx, starty;
	cout << "输入起点坐标:";
	cin >> startx >> starty;
	cout << "输入终点坐标:";
	cin >> p >> q;
	cout << "输入地图大小:";
	cin >> nrows >> ncols;

	cout << "输入地图:" << endl;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	DFS(startx, starty, 0);
	cout << "最短距离:" << min << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

struct queue {
	int x;
	int y;
	int s;
	int f;
};

int main()
{
	int a[50][50];
	int book[50][50] = {0};

	struct queue Q[2500];

	int head = 1;
	int tail = 1;

	int rows = 0;
	int cols = 0;
	cout << "输入地图的大小:";
	cin >> rows >> cols;

	int min = 10000;

	int startx = 0;
	int starty = 0;
	cout << "输出起始的坐标:";
	cin >> startx >> starty;

	int p = 0;
	int q = 0;
	cout << "输出目标的坐标:";
	cin >> p >> q;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> a[i][j];
		}
	}

	Q[tail].x = startx;
	Q[tail].y = starty;
	Q[tail].f = 0;
	Q[tail].s = 0;
	tail++;
	book[startx][starty] = 1;

	int flag = 0;

	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int tx;
	int ty;

	while (head < tail)
	{
		for (int i = 0; i < 4; i++)
		{
			tx = Q[head].x + next[i][0];
			ty = Q[head].y + next[i][1];

			if (tx < 0 || tx >= rows || ty < 0 || ty >= cols)
				continue;
			if (a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				Q[tail].x = tx;
				Q[tail].y = ty;
				Q[tail].f = head;
				Q[tail].s = Q[head].s + 1;
				tail++;
			}

			if (tx == p && ty == q)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}

	cout << "最短路径为:" << Q[tail - 1].s << endl;
	system("pause");
	return(0);
}

#include <iostream>
using namespace std;

struct node {
	int x;
	int y;
};

char a[20][20];

int getsum(int x, int y)
{
	int sum = 0;
	int tx = 0;
	int ty = 0;

	//向上搜索
	tx = x;
	ty = y;
	while (a[tx][ty] != '#')
	{
		if (a[tx][ty] == 'G')
		{
			sum++;
		}
		tx--;
	}

	//向下搜索
	tx = x;
	ty = y;
	while (a[tx][ty] != '#')
	{
		if (a[tx][ty] == 'G')
		{
			sum++;
		}
		tx++;
	}

	//向左搜索
	tx = x;
	ty = y;
	while (a[tx][ty] != '#')
	{
		if (a[tx][ty] == 'G')
		{
			sum++;
		}
		ty--;
	}

	//向右搜索
	tx = x;
	ty = y;
	while (a[tx][ty] != '#')
	{
		if (a[tx][ty] == 'G')
		{
			sum++;
		}
		ty++;
	}

	return sum;
}

int main()
{
	int book[20][20] = {0};

	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int nrows = 0;
	int ncosl = 0;
	cout << "数据地图大小:";
	cin >> nrows >> ncosl;

	int startx = 0;
	int starty = 0;
	cout << "输入起始位置:";
	cin >> startx >> starty;

	for (int i = 0; i < nrows; i++)
	{
		cin >> a[i];
	}

	struct node queue[2500];

	int head = 0;
	int tail = 0;

	queue[tail].x = startx;
	queue[tail].y = starty;
	tail++;

	int mx;
	int my;

	book[startx][starty] = 1;
	int max = getsum(startx, starty);
	mx = startx;
	my = starty;
	int sum = 0;

	while (head < tail)
	{
		for (int i = 0; i < 4; i++)
		{
			int tx = queue[head].x + next[i][0];
			int ty = queue[head].y + next[i][1];

			if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncosl)
				continue;
			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				tail++;

				sum = getsum(tx, ty);
				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}

			}
		}
		head++;
	}

	cout << "炸弹应放在(" << mx << "," << my << ")处,最大可消灭敌人:" << max << "人" << endl;

	system("pause");
	return 0;

}

#include <iostream>
using namespace std;

char a[20][20];
int book[20][20] = {0};
int max = 0;
int mx;
int my;
int nrows = 0;
int ncols = 0;

int getsum(int i, int j)
{
	int sum = 0;

	int x;
	int y;

	//向上搜索
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x--;
	}

	//向下搜索
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x++;
	}

	//向左搜索
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y--;
	}

	//向右搜索
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y++;
	}

	return sum;
}

void DFS(int x, int y)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int sum = getsum(x,y);
	if (sum > max)
	{
		max = sum;
		mx = x;
		my = y;
	}


	for (int i = 0; i < 4; i++)
	{
		int tx = x + next[i][0];
		int ty = y + next[i][1];

		if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncols)
			continue;

		if (a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			DFS(tx, ty);
		}
	}
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	int startx;
	int starty;
	cout << "输入起始的位点:";
	cin >> startx >> starty;

	cout << "输入地图:" << endl;
	for (int i = 0; i < nrows; i++)
	{
		cin >> a[i];
	}

	DFS(startx, starty);

	cout << "应该将炸弹放在(" << mx << "," << my << ")处，可最大消灭敌人:" << max << "人" << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

struct node {
	int x;
	int y;
};

int main()
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int a[20][20] = {0};
	int book[20][20] = {0};

	int nrows = 0;
	int ncols = 0;
	int startx = 0;
	int starty = 0;

	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	cout << "输入降落点:";
	cin >> startx >> starty;

	cout << "输入地图:" << endl;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	struct node queue[500];
	int head = 1;
	int tail = 1;
	int sum = 0;

	queue[tail].x = startx;
	queue[tail].y = starty;
	tail++;
	sum++;
	book[startx][starty] = 1;

	while (head < tail)
	{
		for (int i = 0; i < 4; i++)
		{
			int tx = queue[head].x + next[i][0];
			int ty = queue[head].y + next[i][1];

			if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncols)
				continue;
			if (a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				sum++;
				tail++;
			}
		}
		head++;
	}

	cout << "岛屿大小为:" << sum << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int a[20][20] = {0};
int book[20][20] = {0};
int nrows = 0;
int ncols = 0;
int sum = 0;

void DFS(int x, int y)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	for (int i = 0; i < 4; i++)
	{
		int tx = x + next[i][0];
		int ty = y + next[i][1];

		if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncols)
			continue;
		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			sum++;
			DFS(tx,ty);
		}
	}
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	int startx = 0;
	int starty = 0;
	cout << "输入降落点位置:";
	cin >> startx >> starty;

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	book[startx][starty] = 1;
	sum++;
	DFS(startx, starty);
	cout << "岛屿的大小为:" << sum << endl;
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int a[20][20] = {0};
int book[20][20] = {0};

int sum = 0;
int nrows = 0;
int ncols = 0;

void DFS(int x, int y, int color)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	a[x][y] = color;

	for (int i = 0; i < 4; i++)
	{
		int tx = x + next[i][0];
		int ty = y + next[i][1];

		if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncols)
		{
			continue;
		}
		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			sum++;
			book[tx][ty] = 1;
			DFS(tx, ty, color);
		}
	}
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	int startx = 0;
	int starty = 0;
	cout << "输入降落点位置:";
	cin >> startx >> starty;

	cout << "输入地图的大小:" << endl;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	DFS(startx, starty, -1);


	cout << "染色后的地图:" << endl;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "岛屿的大小为:" << sum << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int a[20][20] = {0};
int book[20][20] = {0};

int nrows = 0;
int ncols = 0;

int num = 0;
void DFS(int x, int y, int color)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	a[x][y] = color;

	for (int i = 0; i < 4; i++)
	{
		int tx = x + next[i][0];
		int ty = y + next[i][1];

		if (tx < 0 || tx >= nrows || ty < 0 || ty >= ncols)
			continue;

		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			DFS(tx, ty, color);
		}
	}
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	cout << "读入地图:" << endl;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			if (a[i][j] > 0)
			{
				num--;
				book[i][j] = 1;
				DFS(i, j , num);
			}
		}
	}

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int a[20][20] = {0};
int book[20][20] = {0};

int flag = 0;
int nrows = 0;
int ncols = 0;

void DFS(int x, int y, int front)
{
	if (x == nrows && y == ncols + 1)
	{
		flag = 1;
		return;
	}

	if (x < 1 || x > nrows || y < 1 || ncols > ncols)
		return;
	if (book[x][y] == 1)
		return;
	book[x][y] = 1;

	if (a[x][y] >= 5 && a[x][y] <= 6)
	{
		if (front == 1)
		{
			DFS(x, y+1, 1);
		}

		if (front == 2)
		{
			DFS(x+1, y, 2);
		}

		if (front == 3)
		{
			DFS(x, y-1, 3);
		}

		if (front == 4)
		{
			DFS(x-1, y, 4);
		}
	}

	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)
		{
			DFS(x+1, y, 2);
			DFS(x-1, y, 4);
		}

		if (front == 2)
		{
			DFS(x, y+1, 1);
			DFS(x, y-1, 3);
		}

		if (front == 3)
		{
			DFS(x-1, y, 4);
			DFS(x+1, y, 2);
		}

		if (front == 4)
		{
			DFS(x, y + 1, 1);
			DFS(x, y - 1, 3);
		}
	}
	book[x][y] = 0;
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	for (int i = 1; i <= nrows; i++)
	{

		for (int j = 1; j <= ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	DFS(1,1,1);
	if (flag == 0)
		cout << "未找到!" << endl;
	else
	{
		cout << "找到铺设方案！" << endl;
	}

	system("pause");
	return 0;

}

#include <iostream>
using namespace std;

int a[20][20] = {0};
int book[20][20] = {0};
int nrows = 0;
int ncols = 0;
int flag = 0;

struct node {
	int x;
	int y;
}s[100];

int top = 0;

void dfs(int x, int y, int front)
{
	if (x == nrows && y == ncols + 1)
	{
		flag = 1;
		for (int i = 1; i <= top; i++)
		{
			cout << "(" << s[i].x << "," << s[i].y << ")" << "--->";
		}
		cout << endl;
		return;
	}

	if (x < 1 || x > nrows || y < 1 || y > ncols)
		return;
	if (book[x][y] == 1)
		return;
	book[x][y] = 1;

	top++;
	s[top].x = x;
	s[top].y = y;

	if (a[x][y] >= 5 && a[x][y] <= 6)
	{
		if (front == 1)
		{
			dfs(x, y+1, 1);
		}

		if (front == 2)
		{
			dfs(x+1, y, 2);
		}

		if (front == 3)
		{
			dfs(x, y-1, 3);
		}

		if (front == 4)
		{
			dfs(x-1, y, 4);
		}
	}

	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)
		{
			dfs(x+1, y, 2);
			dfs(x-1, y, 4);
		}

		if (front == 2)
		{
			dfs(x, y+1, 1);
			dfs(x, y-1, 3);
		}

		if (front == 3)
		{
			dfs(x-1, y, 4);
			dfs(x+1, y, 2);
		}

		if (front == 4)
		{
			dfs(x, y+1, 1);
			dfs(x, y-1, 3);
		}
	}

	book[x][y] = 0;
	top--;
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> nrows >> ncols;

	cout << "输入地图:" << endl;
	for (int i = 1; i <= nrows; i++)
	{
		for (int j = 1; j <= ncols; j++)
		{
			cin >> a[i][j];
		}
	}

	dfs(1,1,1);
	if (flag == 0)
		cout << "没找到!" << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int book[100] = {0};
int e[100][100] = {0};

int sum = 0;
int n;

void DFS(int Cur)
{
	cout << Cur << " ";

	sum++;
	if (sum == n)
	{
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (e[Cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			DFS(i);
		}
	}
	return;
}

int main()
{
	int m;
	cout << "输入图的大小:";
	cin >> n >> m;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999999;
			}
		}
	}

	cout << "读入顶点之间的边:" << endl;
	int a, b;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[1] = 1;
	DFS(1);

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int book[100] = {0};
	int e[100][100] = {0};
	int n, m;
	int queuqe[10001];
	int head = 1;
	int tail = 1;

	cout << "输出图的大小:";
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 9999;
			}
		}
	}

	int a, b;
	for (int j = 0; j < m; j++)
	{
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	queuqe[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail && tail <= n)
	{
		int cur = queuqe[head];
		for (int i = 1; i <= n; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				book[i] = 1;
				queuqe[tail] = i;
				tail++;
			}
			if (tail > n)
			{
				break;
			}
		}
		head++;
	}

	for (int i = 1; i < tail; i++)
	{
		cout << queuqe[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int e[100][100] = {0};
int book[100] = {0};
int n, m;
int min = 999999;

void DFS(int cur, int dis)
{
	if (dis > min)
	{
		return;
	}

	if (cur == n)
	{
		if (dis < min)
		{
			min = dis;
		}
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (e[cur][i] != 9999 && book[i] == 0)
		{
			book[i] = 1;
			DFS(i, dis + e[cur][i]);
			book[i] = 0;
		}
	}
	return;
}

int main()
{
	cout << "输入地图的大小:";
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 9999;
			}
		}
	}

	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		e[a][b] = c;
	}

	book[1] = 0;
	DFS(1, 0);

	cout << "最短路径为:" << min << endl;

	system("pause");
	return 0;

}

#include <iostream>
using namespace std;

struct node {
	int x;
	int s;
};

int main()
{
	int n, m;
	cout << "输入地图的大小:";
	cin >> n >> m;

	int flag = 0;

	int start;
	int end;
	cout << "输入起始和终止位置:";
	cin >> start >> end;

	int e[100][100] = { 0 };
	int book[100] = {0};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 9999;
			}
		}
	}

	int a;
	int b;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	int head = 1;
	int tail = 1;
	struct node queue[100];
	queue[tail].x = start;
	queue[tail].s = 0;
	book[start] = 1;
	tail++;

	while (head < tail)
	{
		int cur = queue[head].x;
		for (int i = 1; i <= n; i++)
		{
			if (e[cur][i] != 9999 && book[i] == 0)
			{
				book[i] = 1;
				queue[tail].x = i;
				queue[tail].s = queue[head].s + 1;
				tail++;
			}

			if (queue[tail - 1].x == end)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}

		head++;
	}

	cout << "最少转机次数为:" << queue[tail - 1].s << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cout << "输入图的大小:";
	cin >> n >> m;

	int e[10][10] = {100};
	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 9999;
			}
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		e[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << e[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int e[10][10] = {0};
	int book[10] = {0};

	int inf = 99999;

	//初始化地图
	int n, m;
	cout << "输入图的大小:";
	cin >> n >> m;

	//初始化图
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = inf;
			}
		}
	}

	int a, b, c;
	cout << "输入边:" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		e[a][b] = c;
	}

	int dis[10] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}

	book[1] = 1;

	int u;

	for (int i = 1; i <= n - 1; i++)
	{
		int min = inf;
		for (int j = 1; j <= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				u = j;
				min = dis[j];
			}
		}

		book[u] = 1;

		for (int v = 1; v <= n; v++)
		{
			if (dis[v] > dis[u] + e[u][v])
			{
				dis[v] = dis[u] + e[u][v];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}


#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cout << "输入图的大小:";
	cin >> n >> m;

	int u[10], v[10], w[10];
	int dis[10] = {0};
	int inf = 99999;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}

	dis[1] = 0;

	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}

	for (int k = 1; k <= n - 1; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int dis[10], bak[10];
	int n, m;
	int u[10], v[10], w[10];

	cout << "输入图的大小:";
	cin >> n >> m;

	int inf = 9999;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	int check;
	int flag;

	for (int k = 1; k <= n - 1; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			bak[i] = dis[i];
		}

		for (int i = 1; i <= m; i++)
		{
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
			}
		}

		check = 0;
		for (int i = 1; i <= n; i++)
		{
			if (bak[i] != dis[i])
			{
				check = 1;
				break;
			}
		}

		if (check == 0)
			break;
	}

	flag = 0;
	for (int i = 1; i <= m; i++)
	{
		if (dis[v[i]] > dis[u[i]] + w[i])
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		cout << "存在这环路!" << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << dis[i] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cout << "输入图的大小:";
	cin >> n >> m;

	int dis[6] = { 0 };
	int book[6] = { 0 };

	int inf = 9999;

	int queue[300] = { 0 };

	int u[8], v[8], w[8];

	int first[6], next[8];

	int head = 1;
	int tail = 1;

	for (int i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	for (int i = 1; i <= n; i++)
		first[i] = -1;

	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	queue[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{
		int k = first[queue[head]];
		while (k != -1)
		{
			if (dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]] + w[k];
				if (book[v[k]] == 0)
				{
					queue[tail] = v[k];
					tail++;
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		book[queue[head]] = 0;
		head++;
 	}

	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
int h[101] = { 0 };
int n = 0;

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

void siftdown(int i)
{
	int t;
	int flag = 0;
	while (i*2 <= n && flag == 0)
	{
		if (h[i] > h[i * 2])
			t = i * 2;
		else
		{
			t = i;
		}

		if (i * 2 + 1 <= n)
		{
			if (h[t] > h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}

		if (t != i)
		{
			swap(t,i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}

void creat()
{
	for (int i = n / 2; i >= 1; i--)
		siftdown(i);
}

int deletemax()
{
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}

int main()
{
	int num;
	cout << "输入要排序数据的个数:";
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> h[i];
	}
	n = num;

	creat();

	for (int i = 1; i <= num; i++)
	{
		cout << deletemax() << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int h[101] = { 0 };
int n = 0;

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

void siftdown(int i)
{
	int t;
	int flag = 0;
	while (i*2 <= n && flag == 0)
	{
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}

		if (i * 2 + 1 <= n)
		{
			if (h[t] > h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}

		if (t != i)
		{
			swap(t,i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}

void create()
{
	for (int i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

void heapsort()
{
	while (n>1)
	{
		swap(1,n);
		n--;
		siftdown(1);

	}
}

int main()
{
	int num;
	cout << "输入排序数据的个数:";
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> h[i];
	}

	n = num;

	create();

	heapsort();

	for (int i = 1; i <= num; i++)
	{
		cout << h[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int h[101] = { 0 };
int n = 0;

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

void siftdown(int i)
{
	int t;
	int flag = 0;
	while (i*2 <= n && flag == 0)
	{
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}

		if (i * 2 + 1 <= n)
		{
			if (h[t] > h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}

		if (t != i)
		{
			swap(t,i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}

void create()
{
	for (int i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

void heapsort()
{
	while (n>1)
	{
		swap(1,n);
		n--;
		siftdown(1);

	}
}

int main()
{
	int num;
	cout << "输入排序数据的个数:";
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> h[i];
	}

	n = num;

	create();

	heapsort();

	for (int i = 1; i <= num; i++)
	{
		cout << h[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int f[1000] = {0};
int n;
int m;
int sum = 0;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
}

int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}
}

void merge(int v, int u)
{
	int t1 = getf(v);
	int t2 = getf(u);

	if (t1 != t2)
	{
		f[t2] = t1;
	}
}

int main()
{
	cin >> n >> m;
	init();

	int x, y;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		merge(x, y);
	}

	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			sum++;
		}
	}

	cout << "共有" << sum << "个犯罪团伙!" << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

struct edge {
	int u;
	int v;
	int w;
};

struct edge e[10];
int n;
int m;
int f[7] = { 0 };
int sum = 0;
int Count = 0;

void quicksort(int left, int right)
{
	if (left > right)
	{
		return;
	}

	struct edge t;

	int i = left;
	int j = right;

	while (i != j)
	{
		if (e[j].w >= e[left].w && i < j)
			j--;
		if (e[i].w <= e[left].w && i < j)
			i++;

		if (i < j)
		{
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}

	t = e[left];
	e[left] = e[i];
	e[i] = t;

	quicksort(left,i-1);
	quicksort(i+1,right);
}

int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}
}

int merge(int v, int u)
{
	int t1 = getf(v);
	int t2 = getf(u);

	if (t1 != t2)
	{
		f[t2] = t1;
		return 1;
	}
	return 0;
}

int main()
{
	cout << "输入图的大小:";
	cin >> n >> m;

	cout << "读入地图:";
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}

	quicksort(1,m);

	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		if (merge(e[i].u, e[i].v))
		{
			Count++;
			sum = sum + e[i].w;
		}

		if (Count == n - 1)
		{
			break;
		}

	}

	cout << "最小树的大小为:" << sum << endl;

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int e[10][10];
	int book[10] = {0};

	int dis[10] = {0};

	int min = 0;
	int inf = 99999;

	int n, m;
	cout << "输入地图的大小:";
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = inf;
			}
		}
	}

	int a, b, c;
	cout << "输入地图:" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		e[a][b] = c;
		e[b][a] = c;
	}

	int Count = 0;
	int sum = 0;
	
	book[1] = 1;
	Count++;

	int j = 0;

	for (int i = 1; i <= n; i++)
	{
		dis[i] = e[i][1];
	}

	while (Count < n)
	{
		min = inf;
		for (int i = 1; i <= n; i++)
		{
			if (book[i] == 0 && dis[i] < min)
			{
				j = i;
				min = dis[i];
			}
		}

		book[j] = 1;
		Count++;
		sum = sum + dis[j];

		for (int i = 1; i <= n; i++)
		{
			if (book[i] == 0 && dis[i] > e[j][i])
			{
				dis[i] = e[j][i];
			}
		}
	}

	cout << "最小树的大小为:" << sum << endl;
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int dis[7] = {0};
int book[7] = {0};
int h[7] = {0};
int pos[7] = {0};
int Size = 0;

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;

	t = pos[h[x]];
	pos[h[x]] = pos[h[y]];
	pos[h[y]] = t;
}

void siftdown(int i)
{
	int t;
	int flag = 0;

	while (i*2 <= Size && flag == 0)
	{
		if (dis[h[i]] > dis[h[i * 2]])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}


		if (i * 2 + 1 <= Size)
		{
			if (dis[h[t]] > dis[h[i * 2 + 1]])
			{
				t = i * 2 + 1;
			}
		}

		if (t != i)
		{
			swap(t,i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}

void siftup(int i)
{
	int flag = 0;
	if (i == 1) return;
	while (i != 1 && flag == 0)
	{
		if (dis[h[i]] < dis[h[i / 2]])
		{
			swap(i, i/2);
		}
		else
		{
			flag = 1;
		}

		i = i / 2;
	}
}

int pop()
{
	int t;
	t = h[1];
	pos[t] = 0;
	h[1] = h[Size];
	pos[h[1]] = 1;
	Size--;
	siftdown(1);
	return t;
}

int main()
{
	int n, m;
	int u[19], v[19], w[19];
	int first[7] = {0};
	int next[19] = {0};
	int inf = 99999;
	int Count = 0;
	int sum = 0;

	cout << "读入地图的大小:";
	cin >> n >> m;

	cout << "读入地图:" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}

	for (int i = m + 1; i <= 2 * m; i++)
	{
		u[i] = v[i-m];
		v[i] = u[i-m];
		w[i] = w[i-m];
	}

	for (int i = 1; i <= n; i++)
	{
		first[i] = -1;
	}

	for (int i = 1; i <= 2 * m; i++)
	{
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	book[1] = 1;
	Count++;

	dis[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dis[i] = inf;
	}
	
	int k = first[1];
	while (k != -1)
	{
		dis[v[k]] = w[k];
		k = next[k];

	}

	Size = n;
	for (int i = 1; i <= Size; i++)
	{
		h[i] = i;
		pos[i] = i;
	}

	for (int i = Size / 2; i >= 1; i--)
	{
		siftdown(i);
	}

	pop();

	int j = 0;

	while (Count < n)
	{
		j = pop();
		book[j] = 1;
		Count++;
		sum = sum + dis[j];

		k = first[j];
		while (k != -1)
		{
			if (book[v[k]] == 0 && dis[v[k]] > w[k])
			{
				dis[v[k]] = w[k];
				siftup(pos[v[k]]);
			}
			k = next[k];
		}
	}

	cout << "最小树的大小为:" << sum << endl;
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int n, m, e[9][9], root;
int num[9], low[9], flag[9], index;

int min(int a, int b)
{
	return a < b ? a : b;
}

void DFS(int cur, int father)
{
	int child = 0;
	index++;
	num[cur] = index;
	low[cur] = index;

	for (int i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1)
		{
			if (num[i] == 0)
			{
				child++;
				DFS(i, cur);
				low[cur] = min(low[cur], low[i]);
				if (cur != root && low[i] >= num[cur])
				{
					flag[cur] = 1;
				}
				if (cur == root && child == 2)
				{
					flag[cur] = 1;
				}
			}
			else if (i != father)
			{
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
	return;
}

int main()
{
	int i, j, x, y;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			e[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		e[x][y] = 1;
		e[y][x] = 1;
	}

	root = 1;
	DFS(1,root);

	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 1)
		{
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int n, m, e[9][9], root;
int num[9], low[9], index;

int min(int a, int b)
{
	return a < b ? a : b;
}

void DFS(int cur, int father)
{
	index++;
	num[cur] = index;
	low[cur] = index;

	for (int i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1)
		{
			if (num[i] == 0)
			{
				DFS(i, cur);
				low[cur] = min(low[i], low[cur]);
				if (low[i] > num[cur])
				{
					cout << cur << "-" << i << endl;
				}
			}
			else if (i != father)
			{
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			e[i][j] = 0;
		}
	}

	int x;
	int y;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		e[x][y] = 1;
		e[y][x] = 1;
	}

	root = 1;
	DFS(1, root);

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int e[101][101];
int match[101];
int book[101];
int n, m;

int DFS(int u)
{
	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0 && e[u][i] == 1)
		{
			book[i] = 1;
			if (match[i] == 0 || DFS(match[i]))
			{
				match[i] = u;
				match[u] = i;
				return 1;
			}
		}
	}
	return 0;
}


int main()
{
	int sum = 0;
	cin >> n >> m;

	int t1, t2;

	for (int i = 1; i <= m; i++)
	{
		cin >> t1 >> t2;
		e[t1][t2] = 1;
		e[t2][t1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		match[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			book[j] = 0;
		}
		if (DFS(i))
		{
			sum++;
		}
	}

	cout << "匹配成功:" << sum << endl;

	system("pause");
	return 0;
}