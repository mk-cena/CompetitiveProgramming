#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

int length, numberCuts;
unsigned int temp;
unsigned int dp[51][51];
vector<unsigned int> cuts;

bool consecutive(vector<unsigned int> &v, unsigned int e1, unsigned int e2)
{
	if(e1 >= e2)
		return true;
	for(int i=0;i<v.size() - 1;i++)
		if(v[i] == e1 && v[i+1] == e2)
			return true;
	return false;	
}

unsigned int DP(unsigned int start, unsigned int end)
{
	if(dp[start][end] != UINT_MAX)
		return dp[start][end];
	if(consecutive(cuts,cuts[start],cuts[end]))
		return 0;
	else
	{
		unsigned int cost = UINT_MAX;
		for(int i=1;i<=numberCuts;i++)
			if(cuts[end] > cuts[i] && cuts[start] < cuts[i])
				cost = min(cost, cuts[end] - cuts[start] + DP(start,i) + DP(i,end));
		dp[start][end] = cost;
		return cost; 
	}
}

void DPMain()
{
	while(true)
	{
		scanf("%d",&length);
		if(length == 0)
			break;
		cuts.clear();
		scanf("%d",&numberCuts);
		cuts.push_back(0);
		for(int i=0;i<numberCuts;i++)
		{
			cin >> temp;
			cuts.push_back(temp);
		}
		cuts.push_back(length);

		for(int i=0;i<51;i++)
			for(int j=0;j<51;j++)
				dp[i][j] = UINT_MAX;	
		
		printf("The minimum cutting is %d.\n", DP(0,cuts.size()-1));
	}		
}

int main()
{
	DPMain();
}