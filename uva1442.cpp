#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>

using namespace std;

int n, p[1000005], s[1000005], l[1000005], r[1000005];

int main()
{
	int Z;
	scanf("%d", &Z);
	while (Z--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &s[i]);
		}
		int level = s[0];
		for (int i = 0; i < n; i++)
		{
			if (p[i] > level)level = p[i];
			if (s[i] < level) level = s[i];
			l[i] = level;
		}
		level = s[n - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			if (p[i] > level)level = p[i];
			if (s[i] < level) level = s[i];
			r[i] = level;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += ((l[i] < r[i]) ? l[i] : r[i]) - p[i];
		}
		printf("%d\n", ans);

	}
	return 0;
}