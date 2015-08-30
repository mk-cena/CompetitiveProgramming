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

int h, w, stones[1000][1000], dp[1000][1000];

int DP(int i, int j)
{
	if(i == h || j == w || j == -1)
		return 0;

	if(dp[i][j] !=  -1)
		return dp[i][j];

	int q = stones[i][j] + max(DP(i + 1, j - 1), max(DP(i + 1,j), DP(i + 1, j + 1)));

	dp[i][j] = q;

	return q;
}

int main()
{
	int t,mx;
	scanf("%d\n", &t);
	while(t--)
	{
		scanf("%d %d\n",&h, &w);
		for(int i =0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				dp[i][j] = -1;
				scanf("%d",&stones[i][j]);
			}

		mx = -1;
		
		for(int i=0;i<w;i++)
			mx = max(DP(0,i),mx);

		printf("%d\n",mx);
	}
	return 0;
}