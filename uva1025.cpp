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
const int INF = 0x3f3f3f3f;
int n, T, t[55], m1, m2, r[255], l[255],tl[55],tr[55];
int lft[205][55];

int main()
{
	//ofstream mycout("temp.txt");
	int Case = 1;

	while (scanf("%d", &n), n)
	{
		memset(lft, -1, sizeof lft);
		memset(tl, 0, sizeof tl);
		memset(tr, 0, sizeof tr);
		scanf("%d", &T);
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &t[i]);
		}
		for (int i = 2; i <= n; i++)
		{
			tl[i] = tl[i - 1] + t[i - 1];
		}
		for (int i = n - 1; i >= 1; i--)
		{
			tr[i] = tr[i + 1] + t[i];
		}

		scanf("%d", &m1);
		memset(r, 0, sizeof r);
		memset(l, 0, sizeof l);
		for (int i = 0; i < m1; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			l[tmp] = 1;
		}
		scanf("%d", &m2);
		for (int i = 0; i < m2; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			r[tmp] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			lft[T][i] = INF;
		}
		lft[T][n] = 0;
		for (int i = T - 1; i >= 0; i--)
		{
			for (int j = 1; j <= n; j++)
			{
				lft[i][j] = lft[i + 1][j] + 1;
				if (j < n && i - tl[j] >= 0 && l[i - tl[j]] && i + t[j] <= T && lft[i][j] > lft[i + t[j]][j + 1])
				{
					lft[i][j] = lft[i + t[j]][j + 1];
				}
				if (j > 1 && i - tr[j] >= 0 && r[i - tr[j]] && i + t[j - 1] <= T && lft[i][j] > lft[i + t[j - 1]][j - 1])
				{
					lft[i][j] = lft[i + t[j - 1]][j - 1];
				}
			}
		}
		
		cout << "Case Number " << Case++ << ": ";
		if (lft[0][1] >= INF)cout << "impossible\n";
		else cout << lft[0][1] << "\n";
	}
	
	//mycout.close();
	return 0;
}