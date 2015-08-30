#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <fstream>
#include <limits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i,N) for(int i=0;i<N;i++)
#define MAXPRIME 1000000007

bool compare(int a, int b)
{
	return a > b;
}

class Compare
{
	public:
		bool operator()(int a, int b)
		{
			return a > b;
		}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}

int main()
{

	int n, truth[1000009];
	bool all_but_last_2 = true;
	scanf("%d",&n);
	REP(i,n)
	{	
		scanf("%d",&truth[i]);
		if(i < n - 2) all_but_last_2 = all_but_last_2 && truth[i];
	}
	if(truth[n - 1])
	{
		printf("NO\n");
		return 0;
	}
	if(n >= 2 && !truth[n - 1] && !truth[n - 2] && all_but_last_2)
	{
		printf("NO\n");
		return 0;
	}
	if(n == 1 && !truth[0])
	{
		printf("YES\n%d",0);
		return 0;
	}
	if(!truth[n - 1] && truth[n - 2])
	{
		printf("YES\n");
		REP(i, n) 
		{	
			if(i > 0) printf("->");
			printf("%d", truth[i]);
		}
		return 0;
	}
	printf("YES\n(");
	int j;
	for(j = n - 3;j > 0 && truth[j];j--);
	REP(i, j)
	{
		if(i == 0) printf("(");
		if(i > 0) printf("->");
		printf("%d",truth[i]);
		if(i == j - 1) printf(")->");
	}
	printf("(0->(");
	for(int i = j + 1;i < n - 1;i++)
	{
		if(i > j + 1) printf("->");
		printf("%d",truth[i]);
	}
	printf(")))->0");
	return 0;
}