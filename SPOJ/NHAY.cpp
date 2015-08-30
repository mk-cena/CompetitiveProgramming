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

void precompute_failure(int *f, char *p, int m)
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
	bool end = false;
	char c;
	int m;

	while(true)
	{
		scanf("%d\n",&m);
		
		int *f = (int *) malloc((m + 1) * sizeof(int));
		char *p = (char *) malloc((m + 1) * sizeof(char));

		scanf("%s\n", p);
		
		scanf("%c", &c);

		precompute_failure(f,p,m);

		int i = 0;
		int j = 0;

		while(true)
		{	
			if(p[j] == c)
			{
				j++;
				i++;
				if(j == m)
				{
					j = f[j];
					printf("%d\n", i - m);
				}
				if(scanf("%c",&c) == EOF)
				{
					return 0;
				}
				if(c == '\n')
				{
					printf("\n");
					break;
				}
			}
			else
			{
				if(j > 0)
				{
					j = f[j];
				}
				else
				{
					i++;
					if(scanf("%c",&c) == EOF)
					{
						return 0;
					}
					if(c == '\n')
					{
						printf("\n");
						break;
					}
				}
			}
		}
	}
	return 0;
}