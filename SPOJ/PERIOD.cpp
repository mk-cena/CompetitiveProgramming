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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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


char p[1000020];
int f[1000020], len;

void precompute_failure()
{
	f[0] = f[1] = 0;

	for(int i=2,j;i<=len;i++)
	{
		j = f[i - 1];

		while(true)
		{
			if(p[j] == p[i - 1])
			{
				f[i] = j + 1;
				break;
			}

			if(j == 0)
			{
				f[i] = 0;
				break;
			}

			j = f[j];
		}
	}
}

int main()
{
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;t++)
	{
		scanf("%d\n%s",&len,p);
		precompute_failure();
		printf("Test case #%d\n",t);
		for(int i=2,j;i<=len;i++)
		{
			j = i - f[i];
			if(i != j && i % j == 0)
			{
				printf("%d %d\n",i,i/j);
			}
		}
		printf("\n");
	}
	return 0;
}