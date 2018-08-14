#include <iostream>
#include <string>
using namespace std;

int main()
{
	char a[100];
	cout << "输入比配字符串:";
	gets_s(a);
	cout << "字符串长度为:" << strlen(a) << endl;
	int mid = strlen(a) / 2 - 1;

	char s[100];
	int top = 0;
	for (int i = 0; i <= mid; i++)
	{
		s[++top] = a[i];
	}

	int next = 0;

	if (strlen(a) % 2 == 0)
	{
		next = mid + 1;
	}
	else
	{
		next = mid + 2;
	}

	for (int i = next; i < strlen(a); i++)
	{
		if (a[i] != s[top])
		{
			break;
		}
		top--;
	}

	if (top == 0)
	{
		cout << "Yes!" << endl;
	}
	else
	{
		cout << "No!" << endl;
	}

	system("pause");
	return 0;
}