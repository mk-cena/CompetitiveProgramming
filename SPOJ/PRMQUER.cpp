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

bool prime[10000009];
char type;
int n, q, x, y, v, array[100005],lazy[1000000],tree[1000000];
void build_primes()
{
	rep(i, 10000009) prime[i] = true;
	prime[0] = prime[1] = false;
	rep(i, 3165)
		if(prime[i])
			for(int j = i * i;j <= 10000009; j += i) prime[j] = false;
}
void build(int node, int b, int e)
{
	lazy[node] = 0;
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(b == e) tree[node] = array[e] <= 10000000 && prime[array[e]];
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
		tree[node] = (lazy[node] <= 10000000 && prime[lazy[node]]) * (e - b + 1);
		if(b != e)
			lazy[left] = lazy[right] = lazy[node];
		else array[e] = lazy[node];
		lazy[node] = 0;
	}
	if(b > j || e < i) return 0;
	if(b >= i && e <= j) return tree[node];
	int l = query(left, b, mid, i, j);
	int r = query(right, mid + 1, e, i, j);

	return l + r;
}
void update_add(int node, int b, int e, int i, int v)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] = (lazy[node] <= 10000000 && prime[lazy[node]]) * (e - b + 1);
		if(b != e)
			lazy[left] = lazy[right] = lazy[node];
		else array[e] = lazy[node];
		lazy[node] = 0;
	}

	if(b > i || e < i) return;
	if(b == e)
	{
		array[e] += v;
		tree[node] = array[e] <= 10000000 && prime[array[e]];
	}
	else
	{
		update_add(left, b, mid, i, v);
		update_add(right, mid + 1, e, i, v);
		tree[node] = tree[left] + tree[right];
	}
}
void update_replace(int node, int b, int e, int i, int j, int v)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] = (lazy[node] <= 10000000 && prime[lazy[node]]) * (e - b + 1);
		if(b != e)
			lazy[left] = lazy[right] = lazy[node];
		else array[e] = lazy[node];
		lazy[node] = 0;
	}

	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		tree[node] = (v <= 10000000 && prime[v]) * (e - b + 1);
		if(b != e)
			lazy[left] = lazy[right] = v;
		else array[e] = v;
		return;
	}
	update_replace(left, b, mid, i, j, v);
	update_replace(right, mid + 1, e, i, j, v);
	tree[node] = tree[left] + tree[right];
}
int main()
{
	build_primes();
	scanf("%d %d\n", &n, &q);
	rep(i, n)
	{
		if(i != 0) scanf(" "); 
		scanf("%d", array + i);
	}
	build(1, 0, n - 1);
	while(q--)
	{
		scanf("\n");
		scanf("%c ", &type);
		if(type == 'A') scanf("%d %d", &v, &x), update_add(1, 0, n - 1, x - 1, v);
		else if(type == 'R') scanf("%d %d %d", &v, &x, &y), update_replace(1, 0, n - 1, x - 1, y - 1, v);
		else if(type == 'Q') scanf("%d %d", &x, &y), printf("%d\n", query(1, 0, n - 1, x - 1, y - 1));
	}
	return 0;
}