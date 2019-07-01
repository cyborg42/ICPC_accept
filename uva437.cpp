#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<string>
#include<functional>
#include<queue>
using namespace std;

int n;
int blocks[35][3];
int d[35][3];

int dp(int idx, int k)
{
	if (d[idx][k] != -1)
	{
		return d[idx][k];
	}
	int maxh = 0;



	int a = blocks[idx][k == 0 ? 1 : 0];
	int b = blocks[idx][k == 2 ? 1 : 2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int aa = blocks[i][j == 0 ? 1 : 0];
			int bb = blocks[i][j == 2 ? 1 : 2];
			if (a > aa&&b > bb)
			{
				int t = dp(i, j);
				maxh = t > maxh ? t : maxh;
			}
		}
	}
	return d[idx][k] = maxh + blocks[idx][k];
}

int main()
{
	//ofstream mycout("temp.txt");
	int c = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(blocks, 0, sizeof blocks);
		memset(d, -1, sizeof d);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &blocks[i][0], &blocks[i][1], &blocks[i][2]);
			sort(blocks[i], blocks[i] + 3);
		}
		int maxh = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int t = dp(i, j);
				maxh = t > maxh ? t : maxh;
			}
		}

		printf("Case %d: maximum height = %d\n", c++, maxh);

	}

	//mycout.close();
	return 0;
}