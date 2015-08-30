#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define MAXPRIME 1000000007

bool compare(int a, int b)
{
	return a > b;
}

class Compare
{
	public:
		bool operator()(int a, int b)
		{
			return a > b;
		}
};

int main()
{
	ll n,a,coins = 0;
	bool taken[10000];
	scanf("%I64d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&a);
		for(ll j=a;j<10000;j++)
			if(!taken[j])
			{
				taken[j] = true;
				break;
			}
			else coins++;
	}
	printf("%I64d\n",coins);
	return 0;
}