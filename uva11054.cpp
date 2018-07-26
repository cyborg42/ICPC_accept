#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<sstream>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		long long int carry = 0;
		long long int sum = 0;
		while (n--)
		{
			long long int cur;
			scanf("%lld", &cur);
			carry += cur;
			sum += abs(carry);
		}
		printf("%lld\n", sum);
	}
	// system("pause");
	return 0;
}