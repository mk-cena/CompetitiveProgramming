#include <iostream>
#include <stdio.h>

using namespace std;

int w[1001],s[1001],dp[1001],backtrack[1001],nElephants;

int DP(int elephant)
{
	if(dp[elephant]!=-1)
		return dp[elephant];

	int q=1;
	for(int i=0;i<nElephants;i++)
		if(w[i] > w[elephant] && s[i] < s[elephant])
		{
			int temp = 1+DP(i);
			if(q < temp)
			{
				q=temp;
				backtrack[elephant]=i;
			}
		}
	dp[elephant] = q;
	return q;
}

void BackTrack(int elephant)
{
	if(elephant == -1)
		return;
	cout<<elephant + 1<<endl;
	BackTrack(backtrack[elephant]);
}

int main()
{
	for(nElephants=0; cin >> w[nElephants] >> s[nElephants]; nElephants++);
	
	for(int i=0;i<1001;i++)
		dp[i]=backtrack[i]=-1;
	
	int q=0,elephant=0;
	for(int i=0;i<nElephants;i++)
	{
		int temp = DP(i);
		if(q < temp)
		{
			q=temp;
			elephant=i;
		}
	}

	cout<<q<<endl;
	BackTrack(elephant);
}