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

int f[301][301],n1,n2,m1,m2;
bool matches[2001][2001][301];
char p[301][301], t[2001][2001];
 
void precompute_failure(int k)
{
	f[k][0] = f[k][1] = 0;
	for(int i = 2,j;i<=n2;i++)
	{
		j = f[k][i - 1];
		while(true)
		{
			if(p[k][j] == p[k][i - 1])
			{
				f[k][i] = j + 1;
				break;
			}
			else
			{
				if(j == 0)
				{
					f[k][i] = 0;
					break;
				}
			}
			j = f[k][j];
		}
	}
}

int main()
{
	scanf("%d %d\n",&n1, &n2);
	for(int i=0;i<n1;i++)
	{
		scanf("%s\n",p[i]);
		precompute_failure(i);
	}

	scanf("%d %d\n", &m1, &m2);
	for(int i=0;i<m1;i++)
	{
		scanf("%s", t[i]);
	}

	bool found = false;

	for(int kj=0,ki,j,i;kj<n1;kj++)
	{
		i = j = 0;
		ki = kj;

		while(true)
		{

			if(i == m2) i = j = 0, ki++;

			if(ki - kj == m1) break;

			if(p[kj][j] == t[ki][i])
			{
				i++,j++;
				if(j == n2)
				{
					if(kj == 0) matches[ki][i - n2][kj] = true;
					else
						if(matches[ki - 1][i - n2][kj - 1])
							if(kj != n1 - 1) matches[ki][i - n2][kj] = true;
							else
							{
								found = true;
								matches[ki][i - n2][kj] = true;
								printf("(%d,%d)\n", ki - n1 + 2, i - n2 + 1);
							}
					j = f[kj][j];
				}
			}
			else
			{
				if(j > 0) j = f[kj][j];
				else i++;
			}
		}
	}

	if(!found)
	{
		printf("NO MATCH FOUND...\n");
	}
	
	return 0;
}