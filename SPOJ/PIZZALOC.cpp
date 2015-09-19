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

int k,r,m,n,x_m[100],y_m[100],s[100],x,y,dp[1048579];
bitset<100> reachable[20];

inline int dfs(int mask, int i, int j, int c)
{
	if(c == k)
	{
		int sum = 0;
		bitset<100> v;
		rep(i, m) if((mask >> i) & 1) v |= reachable[i];
		rep(i, n) if(v[i]) sum += s[i]; 
		return sum;
	}

	int q = -1;
	for(int p = i; p <= j; p++) q = max(q, dfs(mask | (1 << p), p + 1, m - k + c + 1, c + 1));
	return q;
}


int main()
{
	scanf("%d %d %d", &k, &r, &m);
	r *= r;
	rep(i, m) scanf("%d %d", &x_m[i], &y_m[i]);
	scanf("%d", &n);
	rep(i, n)
	{
		scanf("%d %d %d", &x, &y, &s[i]);
		rep(j, m)
		{
			int dx = x_m[j] - x, dy = y_m[j] - y;			
			reachable[j][i] = dx * dx + dy * dy <= r;
		}
	}
	printf("%d\n", dfs(0, 0, m - k, 0));
	return 0;
}