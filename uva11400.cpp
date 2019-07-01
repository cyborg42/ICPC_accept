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
class Light
{
public:
	int v, k, c, l;
	friend bool operator < (Light a, Light b)
	{
		return a.v < b.v;
	}
private:

}light[1005];
int n;
int d[1005];
int s[1005];
int main()
{
	while (scanf("%d",&n),n)
	{
		s[0] = 0;
		d[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d%d", &light[i].v, &light[i].k, &light[i].c, &light[i].l);
		}
		sort(light + 1, light + n + 1);
		for (int i = 1; i <= n; i++)
		{
			s[i] = s[i - 1] + light[i].l;
		}
		for (int i = 1; i <= n; i++)
		{
			d[i] = 0x3f3f3f3f;
			for (int j = 0; j < i; j++)
			{
				d[i] = min(d[i], d[j] + (s[i] - s[j])*light[i].c + light[i].k);
			}
		}
		printf("%d\n", d[n]);
	}
	
	return 0;
} 