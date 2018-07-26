#pragma warning(disable:4996)
#include<iostream>
#include<cstdlib>
#include<cstdio>
int n;
int C[21][21];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &C[i][j]);
		}
	}
}

int main()
{
	init();
	int ans = 0;
	int state;
	int end = 1 << (n - 1);				//n»»³Én-1,¼ôÖ¦Ò»°ë
	for (state = 1; state < end; state++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if ((1 << i)&state)
			{
				continue;
			}
			for (int j = 0; j < n; j++)
			{
				if ((1 << j)&state)
				{
					sum += C[i][j];
				}
			}
		}
		ans = ans > sum ? ans : sum;
	}
	printf("%d", ans);
//	system("pause");
}