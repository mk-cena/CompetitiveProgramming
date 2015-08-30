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

int coin[1000][2],n,w,dp[200000];

int DP(int weight)
{
	if(weight == w)
		return 0;

	if(weight > w)
		return 1000000000;

	if(dp[weight] != -1)
		return dp[weight];

	int q = 1000000000;
	for(int i=0;i<n;i++)
		q = min(q, coin[i][0] + DP(weight + coin[i][1]));

	dp[weight] = q;

	return q;
}

int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		w = y - x;
		scanf("%d",&n);

		for(int i =0;i<n;i++)
			scanf("%d %d",&coin[i][0],&coin[i][1]);
		for(int i =0;i<w;i++)
			dp[i] = -1;

		x = DP(0);

		if(x >= 1000000000)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",x);
	}
	return 0;
}