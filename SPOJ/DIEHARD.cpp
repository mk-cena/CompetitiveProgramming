#include <stdio.h>
#include <iostream>

using namespace std;

int h, a, places[3][2] = {{3,2},{-20,5},{-5,-10}}, dp[1002][1002][3];

#define zone1 {h+=3; a+=2;}
#define zone2 {h-=5; a-=10;}
#define zone3 {h-=20; a+=5;}

int Greedy()
{
	int i;
	for(i=0;h > 0 && a > 0;i++)
	{
		if(i%2 == 0) zone1
		else
			if(a < 11)	zone3
			else 
				if(h < 21)	zone2
				else zone2
	}
	return i - 1;
}


int DP(int x, int y, int c)
{
	if(x <= 0 || y <= 0)
		return -1;

	if(dp[x][y][c] != -2)
		return dp[x][y][c];

	int q = -1;

	for(int i=0;i<3;i++)
		if(i != c)
			q = max(q, 1 + DP(x + places[i][0], y + places[i][1], i));

	dp[x][y][c] = q;
	return q;
}

int main()
{
	int t;
	scanf("%d", &t);

	for(int i=0;i<t;i++)
	{
		scanf("%d %d", &h, &a);
		printf("%d\n", Greedy());
		/*
			****** DP ******
			for(int j = 0;j<1002;j++)
				for(int k = 0;k<1002;k++)
					dp[j][k][0] = dp[j][k][1] = dp[j][k][2] = -2;
			printf("%d\n", DP(h,a,-1));
		*/
	}
}