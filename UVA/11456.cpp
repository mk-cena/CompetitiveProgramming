#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

int nCars;
int cars[2001];
int dp1[2001], dp2[2001];

int DP1(int first) //LIS reversed
{	
	if(dp1[first] != -1)
		return dp1[first];

	int q = 1;
	for(int i = (first+1); i<nCars;i++)
		if(cars[first] < cars[i])
			q=max(q, 1+DP1(i));

	dp1[first] = q;
	return q;

}

int DP2(int last) //LDS
{
	if(dp2[last]!=-1)
		return dp2[last];

	int q=1;
	for(int i=last+1;i<nCars;i++)
		if(cars[last] > cars[i])
			q=max(q,1+DP2(i));

	dp2[last] = q;
	return q;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int k=0;k<t;k++)
	{
		scanf("%d",&nCars);
		for(int i=0;i<nCars;i++)
			scanf("%d",&(cars[i]));

		for(int i=0;i<2001;i++)
			dp1[i] = dp2[i] =-1;

		int q = 0;		
		for(int i = 0; i<nCars; i++)
			q=max(q,DP1(i) + DP2(i) - 1);

		cout << q << endl;
	}
}