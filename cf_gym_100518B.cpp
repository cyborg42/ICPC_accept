#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<string>
#include<functional>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int n;
double a[2][5005];
double aq[2][5005];
double b[2][5005];
double bq[2][5005];
double least[5005];
double most[5005];
double compute(double a, double b, double c, double d)
{
	if (a == 0 && c == 0)
	{
		return b < d ? b : d;
	}
	else
	{
		double k = (c + d - b) / (a + c);
		if (k >= 1)
		{
			return a + b;
		}
		else if (k <= 0)
		{
			return c + d;
		}
		else
		{
			return a * k + b;
		}
	}
}
int main()
{
	freopen("braess.in", "r", stdin);
	freopen("braess.out", "w", stdout);
	//ofstream mycout("temp.txt");
	scanf("%d", &n);
	memset(aq, 0, sizeof aq);
	memset(bq, 0, sizeof bq);
	double ans2 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf%lf", &a[0][i], &b[0][i], &a[1][i], &b[1][i]);
		aq[0][i] = aq[0][i - 1] + a[0][i];
		aq[1][i] = aq[1][i - 1] + a[1][i];
		bq[0][i] = bq[0][i - 1] + b[0][i];
		bq[1][i] = bq[1][i - 1] + b[1][i];

		ans2 += compute(a[0][i], b[0][i], a[1][i], b[1][i]);
	}
	double ans1;

	ans1 = compute(aq[0][n], bq[0][n], aq[1][n], bq[1][n]);
	printf("%.9f\n", ans1);

	printf("%.9f\n", ans2);

	least[0] = 0;
	most[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		double min = 10000000000.0;
		double max = 0;
		for (int j = 0; j < i; j++)
		{
			double tmp = least[j];
			double tmp2 = most[j];
			double aa = 0, bb = 0, cc = 0, dd = 0;

			aa = aq[0][i] - aq[0][j];
			bb = bq[0][i] - bq[0][j];
			cc = aq[1][i] - aq[1][j];
			dd = bq[1][i] - bq[1][j];
			double ans;
			ans = compute(aa, bb, cc, dd);
			tmp += ans;
			tmp2 += ans;
			min = min > tmp ? tmp : min;
			max = max > tmp2 ? max : tmp2;
		}
		least[i] = min;
		most[i] = max;
	}
	printf("%.9f\n", least[n]);
	printf("%.9f\n", most[n]);




	//cin >> n;
	//mycout.close();
	return 0;
} 