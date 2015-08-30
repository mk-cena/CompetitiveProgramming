#include <stdio.h>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

unsigned int numberElements;
vector<int> board;
int dp[101][101];

int DP(unsigned int start,unsigned int end)
{

	if(dp[start][end]!=INT_MIN)
		return dp[start][end];

	if(start > end || end < 0)
		return 0;

	int q = INT_MIN;
	int sum = 0;
	for(unsigned int i = start;i<=end;i++)
	{
		sum += board[i];
		q = max(q,sum - DP(i + 1, end));
	}
	sum = 0;
	for(unsigned int i = end; i>start; i--)
	{
		sum += board[i];
		q = max(q,sum - DP(start, i - 1));
	}

	dp[start][end] = q;

	return dp[start][end];
}

int main()
{
	int element;
	while(true)
	{
		cin >> numberElements;

		if(numberElements == 0)
			break;
		board.clear();
		for(unsigned int i=0;i<101;i++)
			for(unsigned int j=0;j<101;j++)
				dp[i][j]=INT_MIN;
		for(unsigned int i=0;i<numberElements;i++)
		{
			cin >> element;
			board.push_back(element);
		}

		printf("%d\n",DP(0,numberElements-1));
	}
}