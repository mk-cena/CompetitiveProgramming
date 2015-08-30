#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

unsigned int matrices,cases;
unsigned int dp[10][10];
unsigned int backtrack[10][10];
vector<unsigned int> dims;

unsigned int DP(unsigned int start, unsigned int end)
{
	if(dp[start][end] != UINT_MAX)
		return dp[start][end];
	if(start == end)
		return 0;
	else
	{
		unsigned int q = UINT_MAX;
		for(unsigned int i=start;i<end;i++)
		{
			q = DP(start,i) + DP(i+1,end) + (dims[start] * dims[end+1] * dims[i+1]);
			if(q < dp[start][end])
			{
				dp[start][end] = q;
				backtrack[start][end] = i;
			}
		}
		return dp[start][end];
	}
}

void BackTrack(unsigned int start, unsigned end)
{
	if(start == end)
		printf("A%d",start+1);
	else
	{
		cout << "(";
		BackTrack(start, backtrack[start][end]);
		cout << " x ";
		BackTrack(backtrack[start][end] + 1, end);
		cout << ")";
	}
}

void DP_Main()
{
	cases = 1;
	while(true)
	{
		cin >> matrices;
		if(matrices == 0)
			break;
		dims.clear();
		int width,height;
		for(int i=0;i<matrices;i++)
		{
			scanf("%d %d", &width, &height);
			dims.push_back(width);
		}
		dims.push_back(height);
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				dp[i][j] = backtrack[i][j] = UINT_MAX;

		printf("Case %d: ",cases);
		DP(0,matrices-1);
		BackTrack(0,matrices-1);
		cout<<endl;
		cases++;
	}
}

int main()
{
	DP_Main();
}