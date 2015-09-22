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
#include <bitset>

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
int n,m,k,rules[1000][1000],sat[1000],z,y,x;
ll dp[900009][20];
bool v[900009][20];
ll DP(unsigned int mask, int p, int c)
{
	if(c == m) return 0;
	if(v[mask][p]) return dp[mask][p];

	ll q = 0;
	rep(i, n)
	{
		if((mask >> i) & 1) continue;
		q = max(q,  sat[i] + rules[p][i] + DP(mask | 1 << i, i, c + 1));
	}
	dp[mask][p] = q, v[mask][p] = true;
	return q;
}

int main()
{
	rep(i, 1000) rep(j, 1000) rules[i][j] = 0;
	rep(i, 900009) rep(j, 20) v[i][j] = false;
	scanf("%d %d %d", &n, &m, &k);
	rep(i, n) scanf("%d",&sat[i]);
	rep(i, k) scanf("%d %d %d", &x, &y, &z), rules[x - 1][y - 1] = z;
	printf("%I64d\n", DP(0,19,0));
	return 0;
}