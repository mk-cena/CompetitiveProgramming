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
#include <set>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}

ll n;
map<ll,ll>dp;

ll DP(ll i)
{
	if(i == 0)
		return 0;
	if(dp[i] != 0)
		return dp[i];
	ll q = max(i, DP(i/2) + DP(i/3) + DP(i/4));
	dp[i] = q;
	return q;
}

int main()
{
	while(scanf("%lld",&n) != EOF)
		printf("%lld\n",DP(n));
	return 0;
}