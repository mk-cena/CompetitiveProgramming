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

bool bears[1000][1000];
int main()
{
	int n,m,q,x,y,cnt = 0, tmp = 0,tmp2;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		tmp = 0;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&tmp2);
			bears[i][j] = tmp2;
			if(bears[i][j])
				tmp++;
			else
				tmp=0;
			cnt = max(cnt,tmp);
		}
	}

	for(int i=0;i<q;i++)
	{
		cnt = 0;
		scanf("%d %d", &x,&y);
		x--,y--;
		bears[x][y] = !bears[x][y];
		for(int r=0;r<n;r++)
		{
			tmp = 0;
			for(int j=0;j<m;j++)
			{
				if(bears[r][j])
					tmp++;
				else
					tmp = 0;

				cnt = max(cnt,tmp);
			}
		}

		printf("%d\n",cnt);

	}
	return 0;
}