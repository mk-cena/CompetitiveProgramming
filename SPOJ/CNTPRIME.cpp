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

bool prime[1000009];
int x,y,v,t,n,q,type,array[100005],tree[900000],lazy[900000];
void build_primes()
{
	rep(i,1000009) prime[i] = true;
	prime[0] = prime[1] = false;

	rep(i, 1005)
		if(prime[i])
			for(int j = i * i; j <= 1000009; j += i) prime[j] = false;
}

void build(int node, int b, int e)
{
	lazy[node] =  0;
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(b == e) tree[node] = prime[array[e]];
	else
	{
		build(left, b, mid);
		build(right, mid + 1, e);
		tree[node] = tree[left] + tree[right];
	}
}

int query(int node, int b, int e, int i, int j)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] = prime[lazy[node]] * (e - b + 1);
		if(b != e) lazy[left] = lazy[right] = lazy[node];
		lazy[node] = 0;
	}
	if(b > j || e < i) return 0;
	if(b >= i && e <= j) return tree[node];

	int l = query(left, b, mid, i, j);
	int r = query(right, mid + 1, e, i, j);

	return l + r;
}

void update(int node, int b, int e, int i, int j, int v)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] = prime[lazy[node]] * (e - b + 1);
		if(b != e) lazy[left] = lazy[right] = lazy[node];
		lazy[node] = 0;
	}
	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		tree[node] = prime[v] * (e - b + 1);
		lazy[left] = lazy[right] = v;
		return;
	}
	update(left, b, mid, i, j, v);
	update(right, mid + 1, e, i, j, v);
	tree[node] = tree[left] + tree[right];
}

int main()
{
	scanf("%d", &t);
	build_primes();
	for(int tc = 1; tc<=t; tc++)
	{
		scanf("%d %d", &n, &q);
		rep(i,n) scanf("%d", &array[i]);
		build(1, 0, n - 1);
		printf("Case %d:\n", tc);
		rep(i,q)
		{
			scanf("%d %d %d", &type, &x, &y);
			if(type) printf("%d\n", query(1, 0, n - 1, x - 1, y - 1));
			else scanf("%d",&v), update(1, 0, n - 1, x - 1, y - 1, v);
		}
	}
	return 0;
}