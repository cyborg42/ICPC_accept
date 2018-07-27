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
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		int ans = 0;
		string a, b;
		cin >> a >> b;
		int one_zero = 0, zero_one = 0, que_one = 0, que_zero = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '0'&&b[i] == '1')zero_one++;
			if (a[i] == '1'&&b[i] == '0')one_zero++;
			if (a[i] == '?'&&b[i] == '1')que_one++;
			if (a[i] == '?'&&b[i] == '0')que_zero++;
		}
		ans = min(zero_one, one_zero);
		zero_one -= ans;
		one_zero -= ans;
		if (one_zero > que_one)
		{
			cout << "Case " << j << ": " << -1 << endl;
			continue;
		}
		ans += one_zero * 2;
		que_one -= one_zero;
		one_zero = 0;
		ans += zero_one + que_one + que_zero;
		cout << "Case " << j << ": " << ans << endl;
	}
	//cin >> n;
	//mycout.close();
	return 0;
}