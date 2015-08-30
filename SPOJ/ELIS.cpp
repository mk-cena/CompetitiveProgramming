#include <iostream>
#include <vector>
#include <climits>
#include <stdio.h>

using namespace std;

int length;
vector<int>sequence;
int dp[11];

int DP(int last)
{
	if(dp[last] != -1)
		return dp[last];

	int q = 0;
	for(int i = last - 1;i>=0;i--)
		if(sequence[i] < sequence[last])
			q = max(q, DP(i));

	dp[last] = q + 1;

	return dp[last];
}

int main()
{
	scanf("%d", &length);
	int temp;
	sequence.clear();
	for(int i=0;i<length;i++)
	{
		cin >> temp;
		sequence.push_back(temp);
	}
	sequence.push_back(INT_MAX);
	for(int i=0;i<11;i++)
		dp[i] = -1;
	cout << DP(length)-1 << endl;
}