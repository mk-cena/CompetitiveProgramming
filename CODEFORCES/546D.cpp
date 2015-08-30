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

ll fcount[5000005], value[5000005], ranges[5000005];
void precompute_factors()
{
	for(ll i =0;i<5000005;i++)
	{
		value[i] = 1;
		fcount[i] = 0;
	}

	// distinct factors
	for(ll i =2;i<5000005;i++)
		if(value[i] == 1 && fcount[i] == 0)
		{
			value[i] = i;
			fcount[i]++;
			for(ll j = i+i;j<5000005;j+=i)
			{
				fcount[j]++;
				value[j] *= i;
			}
		}

	// duplicate factors
	for(ll i =2;i<5000005;i++)
		if(value[i]<i)
		{
			fcount[i] += fcount[i/value[i]];
		}

	ranges[0] = ranges[1] = 0;
	for(ll i = 2;i<5000005;i++)
		ranges[i] = ranges[i - 1] + fcount[i];
}

int main()
{
	ll t,a,b;
	scanf("%I64d",&t);
	precompute_factors();
	while(t--)
	{
		scanf("%I64d %I64d",&a,&b);
		printf("%I64d\n", ranges[a] - ranges[b]);
	}
	return 0;
}