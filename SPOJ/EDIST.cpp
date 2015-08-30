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

int m,n,dp[2005][2005];
char a[2005], b[2005];

int DP(int i, int j)
{
	if(j == n)
		return m - i; /* kill */

	if(dp[i][j] != -1)
		return dp[i][j];

	int q = 1 + DP(i, j + 1); /* insert */
	
	if(i < m)
	{
		q = min(q, min(DP(i + 1, j + 1) + (a[i] != b[j]), /* replace/copy */
		 		1 + DP(i + 1, j))); /* delete */
	}
	
	dp[i][j] = q;

	return q;
}

int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s\n%s",a,b);
		m = strlen(a);
		n = strlen(b);
		for(int i=0;i<2001;i++)
			for(int j=0;j<2001;j++)
				dp[i][j] = -1;
		printf("%d\n", DP(0,0));
	}
	return 0;
}