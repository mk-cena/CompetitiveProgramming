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

#define REP(i,N) for(ll i=0;i<N;i++)
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

#define MAX 300000

ll tree[MAX], lazy[MAX], n,c,p,q,v,type;

ll query(ll node, ll b, ll e, ll i, ll j)
{
	ll mid = (b + e) / 2, left = 2 * node, right = left + 1;

	if(lazy[node])
	{
		tree[node] += lazy[node] * (e - b + 1);
		if(b != e)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(b > j || e < i) return 0;
	if (b >= i && e <= j) return tree[node];
	ll l = query(left, b, mid, i, j);
	ll r = query(right, mid + 1, e, i, j);
	return l + r;
}

void update(ll node, ll b, ll e, ll i, ll j, ll m)
{
	ll mid = (b + e)/2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] += lazy[node] * (e - b + 1);
		if(b != e)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(b > j || e < i) return;
	if(b >= i &&  e <= j) 
	{
		tree[node] += m * (e - b + 1);
		if(b != e)
		{
			lazy[left] += m; 
			lazy[right] += m;
		}
		return;
	}
	
	update(left, b, mid, i, j, m);
	update(right, mid + 1, e, i, j, m);
	tree[node] = tree[left] + tree[right];
}

int main()
{
	ll t;
	scanf("%lld",&t);
	REP(i,t)
	{
		memset(lazy,0,MAX * sizeof(ll));
		memset(tree,0,MAX * sizeof(ll));
		scanf("%lld %lld\n",&n,&c);
		REP(j, c)
		{
			scanf("%lld %lld %lld", &type, &p, &q);
			if(type)
				printf("%lld\n", query(1, 1, n, p, q));
			else
			{

				scanf("%lld", &v);
				update(1, 1, n, p, q, v);
			}
		}
	}
	return 0;
}