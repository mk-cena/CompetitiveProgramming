#include <stdio.h>

using namespace std;

#define E 0
#define P 1
#define W 2

int n,m,grid[12][12];

void Greedy()
{
	int count = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(grid[i][j] == P)
			{
				if(grid[i - 1][j] == W)
					grid[i - 1][j] = grid[i][j] = E, count++;
				else if(grid[i][j - 1] == W)
					grid[i][j - 1] = grid[i][j] = E, count++;
				else if(grid[i][j + 1] == W)
					grid[i][j + 1] = grid[i][j] = E, count++;
				else if(grid[i + 1][j] == W)
					grid[i + 1][j] = grid[i][j] = E, count++;
			}
	printf("%d",count);
}

int main()
{
	char str[100];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		for(int j=1;j<=m;j++)
		{
			
			switch(str[j - 1])
			{
				case '.': grid[i][j] = E;break;
				case 'P': grid[i][j] = P;break;
				case 'W': grid[i][j] = W;break;
			}
		}	
	}
	Greedy();
}