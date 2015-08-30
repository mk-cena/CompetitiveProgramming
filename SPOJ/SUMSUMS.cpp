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
#define MOD 98765431LL

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

ll mod(ll a, ll b)
{
	return ((a % b) + b) % b;
}

struct M2
{
	ll a1, a2, b1, b2;
	M2(ll a1, ll a2, ll b1, ll b2):a1(a1), a2(a2), b1(b1), b2(b2) {}
	M2 operator * (const M2 &matrix)
	{
		return M2(mod((a1 * matrix.a1 + a2 * matrix.b1), MOD),
				  mod((a1 * matrix.a2 + a2 * matrix.b2), MOD),
				  mod((b1 * matrix.a1 + b2 * matrix.b1), MOD),
				  mod((b1 * matrix.a2 + b2 * matrix.b2), MOD));
	}
};

void POW(M2 &T, M2 &base, ll e)
{
	if(e == 1) return;
	POW(T, base, e >> 1);
	T = T * T;
	if(e & 1) T = T * base;
}

int main()
{
	ll result, n, t, c[50000], sum = 0;
	scanf("%lld %lld", &n, &t);
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &c[i]);
		sum = mod(sum + c[i], MOD);
	}

	if(n > 2)
	{
		M2 T = M2(-1, 1, 0, n - 1);
		M2 base = M2(-1, 1, 0, n - 1);
		POW(T, base, t);
		for(int i=0;i<n;i++)
		{
			result = mod(c[i] * T.a1 + sum * T.a2, MOD);
			printf("%lld\n", result);
		}
	}
	else
	{
		if(n == 1) printf("%lld", 0LL);
		else printf("%lld\n%lld\n",c[t & 1],c[!(t & 1)]);
	}
	return 0;
}