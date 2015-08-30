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

#define MOD 1000000007

struct M3
{
	ll a1,a2,a3,b1,b2,b3,c1,c2,c3;
	M3(ll a1,ll a2,ll a3,ll b1,ll b2,ll b3,ll c1,ll c2,ll c3):
	a1(a1),a2(a2),a3(a3),
	b1(b1),b2(b2),b3(b3),
	c1(c1),c2(c2),c3(c3){}
	M3 operator * (M3 &matrix)
	{
		return M3((a1 * matrix.a1 + a2 * matrix.b1 + a3 * matrix.c1) % MOD,
				  (a1 * matrix.a2 + a2 * matrix.b2 + a3 * matrix.c2) % MOD,
				  (a1 * matrix.a3 + a2 * matrix.b3 + a3 * matrix.c3) % MOD,

				  (b1 * matrix.a1 + b2 * matrix.b1 + b3 * matrix.c1) % MOD,
				  (b1 * matrix.a2 + b2 * matrix.b2 + b3 * matrix.c2) % MOD,
				  (b1 * matrix.a3 + b2 * matrix.b3 + b3 * matrix.c3) % MOD,

				  (c1 * matrix.a1 + c2 * matrix.b1 + c3 * matrix.c1) % MOD,
				  (c1 * matrix.a2 + c2 * matrix.b2 + c3 * matrix.c2) % MOD,
				  (c1 * matrix.a3 + c2 * matrix.b3 + c3 * matrix.c3) % MOD);
	}
};

inline int POW(ll e)
{
	M3 R = M3(1,0,0,0,1,0,0,0,1);
	M3 T = M3(1,1,1,0,5,3,0,3,2);
	while(e > 0)
	{
		if(e & 1) R = T * R;
		T = T * T;
		e >>= 1;
	}
	return (R.a2 + R.a3) % 1000000007;
}

int main()
{
	ll n;
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%lld",&n);
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n", POW(n));
	}
	return 0;
}