#include <iostream>
#include <stdio.h>

using namespace std;

int numberCubes, cases;
int cubes[501][6];
int dp[501][6];
int backtrack[501][6][2];

int DP(int last, int orientation)
{
	if(last !=-1 && dp[last][orientation] != -1)
		return dp[last][orientation];

	int q = 1;
	int bottom = orientation - (orientation%2) + ((orientation + 1)%2);
	for(int i=last + 1;i<numberCubes;i++)
		for(int j=0;j<6;j++)
			if(last==-1 || cubes[last][bottom] == cubes[i][j])
			{
				int tmp = 1 + DP(i, j);
				if(q < tmp)
				{
					q = tmp;
					backtrack[last==-1?500:last][orientation][0] = i;
					backtrack[last==-1?500:last][orientation][1] = j;
				}
			}

	dp[last==-1?500:last][orientation] = q;

	return q;
}

void BackTrack(int i, int j)
{
	if(backtrack[i][j][0] == -2)
		return;
	else
	{
		printf("%d",backtrack[i][j][0] + 1);
		switch(backtrack[i][j][1])
		{
			case 0:
				printf(" front");break;
			case 1:
				printf(" back");break;
			case 2:
				printf(" left");break;
			case 3:
				printf(" right");break;
			case 4:
				printf(" top");break;
			case 5:
				printf(" bottom");break;
		}
		if(backtrack[backtrack[i][j][0]][backtrack[i][j][1]][0] != -2)
			printf("\n");
		BackTrack(backtrack[i][j][0],backtrack[i][j][1]);
	}	
}

int main()
{
	cases = 1;
	while(true)
	{	
		scanf("%d",&numberCubes);
		if(numberCubes == 0)
			return 0;

		for(int i=0;i<numberCubes;i++)
			for(int j=0;j<6;j++)
				scanf("%d",&(cubes[i][j]));

		for(int i=0;i<501;i++)
		{
			for(int j=0;j<6;j++)
			{
				backtrack[i][j][0] = backtrack[i][j][1] = -2;
				dp[i][j]=-1;
			}
		}

		if(cases!=1)
			printf("\n\n");
		printf("Case #%d\n%d\n", cases++, DP(-1, 5) -1);
		BackTrack(500,5);
	}
}