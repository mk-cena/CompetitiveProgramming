#include <iostream>
#include <climits>
#include <stdio.h>

using namespace std;

int f[255], nodes, dp[255][255], w[255][255];


int DP(int start, int end)
{
	if(start > end)
		return 0;

	if(dp[start][end] != INT_MAX)
		return dp[start][end];

	int q = INT_MAX;
	for(int i=start;i<=end;i++)
		q = min(q, DP(start, i-1) + DP(i+1, end) + w[start][end] - f[i]);

	dp[start][end]=q;

	return q;

}

int main()
{
	
	while(scanf("%d",&nodes) != EOF)
	{
		for(int i=0;i<nodes;i++)
			scanf("%d",&f[i]);

		for(int i=0;i<=nodes+1;i++)
			for(int j=i;j<=nodes+1;j++)
			{
				dp[i][j] = INT_MAX;
				if(i==j)
					w[i][j] = f[i];
				else
					w[i][j] = w[i][j-1] + f[j];
			}

		printf("%d\n",DP(0,nodes-1));
	}
}