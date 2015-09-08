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

#define rep(i,N) for(int i=0;i<N;i++)
#define memclr(ARRAY) memset(ARRAY,0,sizeof(ARRAY))
#define MAXPRIME 1000000007
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745

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

char tmp;
set <ull> paths;
int t, n, ans, board[8][8];

inline void dfs(int collected, int i, int j, ull visited)
{
	if(collected == 8) 
	{
		if(paths.find(visited) == paths.end()) ans++, paths.insert(visited);
		return;
	}

	if(collected < 8)
	{
		if(i > 0 && board[i - 1][j])
		{
			int shift = (i - 1) * n + j;
			bool flag = (visited >> shift) & 1ULL;
			if(!flag) dfs(collected + 1, i - 1, j, visited | 1ULL << shift);
		}

		if(i < n - 1 && board[i + 1][j])
		{
			int shift = (i + 1) * n + j;
			bool flag = (visited >> shift) & 1ULL;
			if(!flag) dfs(collected + 1, i + 1, j, visited | 1ULL << shift);
		}

		if(j > 0 && board[i][j - 1])
		{
			int shift = i * n + j - 1ULL;
			bool flag = (visited >> shift) & 1ULL;
			if(!flag) dfs(collected + 1, i, j - 1, visited | 1ULL << shift);
		}

		if(j < n - 1 && board[i][j + 1])
		{
			int shift = i * n + j + 1;
			bool flag = (visited >> shift) & 1ULL;
			if(!flag) dfs(collected + 1, i, j + 1, visited | 1ULL << shift);
		}
	}

}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans = 0, paths = set<ull>();
		scanf("%d", &n);
		rep(i, n) 
			rep(j, n)
			{
				tmp = ';';
				while(tmp != 'X' && tmp != '.') scanf("%c", &tmp);
				board[i][j] = tmp == 'X'?1:0;
			}
		rep(i, n) rep(j, n) dfs(0, i, j, 0ULL);
		printf("%d\n", ans);
	}
	return 0;
}