#include<iostream>
#include<algorithm>
#include<cstdlib>

int N;
int x[355][355];
int ans[355];

void init()
{
	::std::cin >> N;
	memset(x, 0, sizeof x);
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			::std::cin >> x[i][j];
		}
	}
}



int main()
{
	init();
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			ans[j] = x[i][j] + (ans[j] > ans[j + 1] ? ans[j] : ans[j + 1]);
		}
	}
	::std::cout << ans[0] << ::std::endl;
	//system("pause");
	return 0;
	
}