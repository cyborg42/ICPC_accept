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

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	return (a.first.second < b.first.second || (a.first.second == b.first.second&&a.first.first > b.first.first));
}


int main()
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		int pos[5002][2];
		bool had[5002];
		bool success = true;
		pair<pair<int, int>, int> range[2][5002];
		for (int i = 0; i < n; i++)
		{
			int xl, yl, xr, yr;
			scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
			range[0][i] = make_pair(make_pair(xl, xr), i);
			range[1][i] = make_pair(make_pair(yl, yr), i);
		}
		sort(range[0], range[0] + n, cmp);
		sort(range[1], range[1] + n, cmp);
		for (int k = 0; k <= 1; k++)
		{
			memset(had, false, sizeof(had));
			for (int i = 0; i < n; i++)
			{
				int j;
				for (j = range[k][i].first.first; j <= range[k][i].first.second; j++)
				{
					if (had[j] == false)
					{
						had[j] = true;
						break;
					}
				}
				if (j > range[k][i].first.second)
				{
					success = false;
					break;
				}
				pos[range[k][i].second][k] = j;
			}
			if (success == false)break;
		}
		if (success == false)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d %d\n", pos[i][0], pos[i][1]);
		}
	}
	//system("pause");
	return 0;
}