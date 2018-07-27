#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;



int main()
{
	//ofstream mycout("temp.txt");
	int n;
	while (scanf("%d", &n), n)
	{
		string str[1005];
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		sort(str, str + n);
		string a = str[n / 2 - 1], b = str[n / 2], ans;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == 'Z')
			{
				ans = ans + 'Z';
				continue;
			}
			if ((a[i] != b[i] || i >= b.length()) && i != a.length() - 1 && ans + (char)(a[i] + 1) != b)
			{
				ans = ans + (char)(a[i] + 1);
				break;
			}
			else ans = ans + (char)(a[i]);
		}
		cout << ans << endl;
	}
	//cin >> n;
	//mycout.close();
	return 0;
}