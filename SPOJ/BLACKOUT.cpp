#include <iostream>
#include <climits>

using namespace std;

int n,m,q,k,v[1003];
long long dp[1003][1003],dp2[2003][2003],w[1003];

long long DP(long long b, long long p)
{
	if(dp[b][p]!=-1)
		return dp[b][p];

	if(b >= q)
		return 0;

	long long t = DP(b+1,p);
	if(p - w[b] >= 0)
		t = max(t, v[b] + DP(b+1,p - w[b]));

	dp[b][p] = t;
	
	return t;
}

void precompute1()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%lli", &dp2[i][j]);
			if(i-1 >= 0)
				dp2[i][j] += dp2[i-1][j];
			if(j-1 >= 0)
				dp2[i][j] += dp2[i][j-1];
			if(i-1 >= 0 && j-1 >= 0)
				dp2[i][j] -= dp2[i-1][j-1];
		}
}

void precompute2(int i, int a, int b, int c, int d)
{
	w[i]=0;
	if(c >= 0 && d >= 0)
		w[i] += dp2[c][d];
	if(c >= 0 && b-1 >= 0)
		w[i] -= dp2[c][b-1];
	if(a-1 >= 0 && d >= 0)
		w[i] -= dp2[a-1][d];
	if(a-1 >= 0 && b-1 >= 0)
		w[i] += dp2[a-1][b-1];
}

int main()
{
	scanf("%d %d %d %d", &n,&m,&q,&k);

	precompute1();

	for(int i=0,a,b,c,d;i<q;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		precompute2(i,a-1,b-1,c-1,d-1);
		v[i] = (c - a + 1) * (d - b + 1);
		for(int j=0;j<=k;j++)
			dp[i][j]=-1;
	}

	printf("%lld\n", DP(0,k));
}