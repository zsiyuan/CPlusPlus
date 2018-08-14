#include <iostream>
using namespace std;

int main()
{
	int queue[101] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
	int head = 0;
	int tail = 9;

	while (head < tail)
	{
		cout << queue[head] << " ";
		head++;
		queue[tail] = queue[head];
		tail++;
		head++;
	}
	cout << endl;
	system("pause");
	return 0;
}