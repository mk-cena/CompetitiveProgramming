#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int k, dp[1005][1005],len1,len2, dp2[1005][1005]; //Longest Segment
string str1,str2;

int DP()
{
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
		{
			dp[i][j]=dp2[i][j]=0;
			if((str1[i-1] == str2[j-1]))
				dp2[i][j] = dp2[i-1][j-1]+1;
			for(int l=dp2[i][j];l>=k;l--)
				dp[i][j] = max(dp[i][j],l + dp[i-l][j-l]);
			dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
		}
	return dp[len1][len2];
}

int main()
{
	while(true)
	{
		cin>>k;
		if(k==0)
			return 0;
		cin >> str1 >> str2;
		len1 = str1.length();
		len2 = str2.length();
		for(int i=0;i<1005;i++)
			dp[i][0]=dp[0][i]=dp2[i][0]=dp2[0][i]=0;
		cout << DP() << endl;
	}
}