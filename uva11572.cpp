#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<sstream>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

int snows[1000005];
int main()
{
	int k;
	scanf("%d", &k);
	while (k--)
	{
		int n;
		
		scanf("%d", &n);
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &snows[i]);
		}
		int left = 0, right = 0,same = 0;
		for (; right < n; right++)
		{
			m[snows[right]]++;
			if (m[snows[right]] > 1)same++;
			if (same)
			{
				m[snows[left]]--;
				if (m[snows[left]] >= 1)same--;
				left++;
			}
		}
		printf("%d\n", right - left);
	}
	//system("pause");
	return 0;
}