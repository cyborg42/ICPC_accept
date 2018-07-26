#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<sstream>
#include<deque>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	deque<int> stack;
	for (string strLine; getline(cin, strLine); cout << "0" << endl)
	{
		stack.clear();
		cout << strLine << endl;
		istringstream ss(strLine);
		for (int tmp; ss >> tmp; stack.push_front(tmp));
		for (deque<int>::iterator i = stack.begin(); i != stack.end(); i++)
		{
			deque<int>::iterator iMax = max_element(i, stack.end());
			if (iMax != i)
			{
				if (iMax != stack.end() - 1)
				{
					reverse(iMax, stack.end());
					cout << distance(stack.begin(), iMax) + 1 << " ";
				}
				reverse(i, stack.end());
				cout << distance(stack.begin(), i) + 1 << " ";
			}
		}
	}
	//system("pause");
	return 0;
}