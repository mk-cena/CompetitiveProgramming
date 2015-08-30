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
char p[100005];
int f[100005], m;

void precompute_failure()
{
	f[0] = f[1] = 0;
	for(int i=2,j;i<=m;i++)
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
	while(true)
	{
		scanf("%s",p);
		
		m = strlen(p);

		if(p[0] == '*' && m == 1)
			break;

		precompute_failure();

		int j = m - f[m];
		
		if(m != j && m % j == 0)
			printf("%d\n", m / j);
		else
			printf("1\n");
	}
	return 0;
}