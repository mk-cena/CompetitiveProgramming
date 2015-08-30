#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

int nPoints;
int points[1002][2];
int dp[1002];

int DP(int last)
{
	if(dp[last]!=-1)
		return dp[last];

	int q = 1;
	int duplicate = 0;
	for(int i = 0;i<nPoints;i++)
		if(last!=i &&
		   points[last][0] >= points[i][0] && 
		   points[last][1] >= points[i][1])
		   if(points[last][0] == points[i][0] && 
		      points[last][1] == points[i][1])
		   		duplicate = 1;
		   	else
				q = max(q, 1 + DP(i));
	dp[last]=q+duplicate;
	return dp[last];
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int i=0;i<t;i++)
	{
		for(int j=0;j<1002;j++)
			dp[j]=-1;
		scanf("%d",&nPoints);

		for(int k=0;k<2;k++)
			for(int j=0;j<nPoints;j++)
				scanf("%d",&(points[j][k]));
		
		points[nPoints][0] = points[nPoints][1] = INT_MAX;

		printf("%d\n",DP(nPoints) - 1);
	}
}