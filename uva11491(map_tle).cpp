#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<string>
#include<set>
#include<functional>
#include<map>
using namespace std;



int main()
{
	//ofstream mycout("temp.txt");
	int n, d;

	while (cin>>n>>d,n)
	{
		string str,ans;
		cin >> str;
		map<int, int, greater<int> > m;
		map<int, int, greater<int> >::iterator it;
		for (int i = 0; i < d; i++)
		{
			m[str[i] - '0']++;
		}
		int left = 0, right = d;
		for (; right < n; right++)
		{
			m[str[right] - '0']++;
			int max = (*m.begin()).first;
			while (str[left] != max + '0')
			{
				m[str[left] - '0']--;
				if (m[str[left] - '0'] == 0)
				{
					m.erase(str[left] - '0');
				}
				left++;
			}
			m[str[left] - '0']--;
			if (m[str[left] - '0'] == 0)
			{
				m.erase(str[left] - '0');
			};
			left++;
			ans = ans + (char)(max + '0');
		}
		cout << ans << endl;
	}
	//cin >> n;
	//mycout.close();
	return 0;
}