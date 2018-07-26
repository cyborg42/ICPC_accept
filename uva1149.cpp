#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<fstream>
using namespace std;

int n, item[100005], picked[100005], l;

bool cmp(int a, int b)
{
	return a > b;
}
int find(int v)
{
	int left = 0, right = n, m;
	while (left < right)
	{
		m = left + (right - left) / 2;
		if (item[m] <= v)right = m;
		else left = m + 1;
	}
	
	while (left<n)
	{
		if (picked[left] == 1)left++;
		else break;
	}
	return left;

}
int main()
{
	//ofstream mycout("temp.txt");
	int Z;
	scanf("%d", &Z);
	while (Z--)
	{
	memset(picked, 0, sizeof picked);
	memset(item, 0, sizeof item);
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &item[i]);
		}
		sort(item, item + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (picked[i] == 1)continue;
			picked[i] = 1;
			ans++;
			int last = l - item[i];
			int temp = find(last);
			picked[temp] = 1;
			//cout << item[i] <<" "<< item[temp]<<endl;
		}
		cout << ans << endl;
		if (Z != 0)cout << endl;
	}
	//mycout.close();
	//cin >> n;
	return 0;
}