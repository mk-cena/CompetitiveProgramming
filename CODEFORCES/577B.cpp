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

int n,m,a[1000009], dp[1001][1001][2];

int DP(int rem, int i, bool flag)
{
	if(i == n) return rem == 0 && flag;
	if(dp[rem][i][flag] != -1) return dp[rem][i][flag];
	int q = max(DP(((rem + (a[i] % m)) % m), i + 1, flag || true), DP(rem, i + 1, flag || false));
	dp[rem][i][flag] = q;
	return q;
}

int main()
{
	rep(i, 1001) rep(j, 1001) dp[i][j][0] = dp[i][j][1] = -1;
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	if(n > m || DP(0, 0, 0)) printf("YES\n");
	else printf("NO\n");
	return 0;
}