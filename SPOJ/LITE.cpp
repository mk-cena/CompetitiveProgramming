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
int n, m, tree[500000], lazy[500000];

int query(int node, int b, int e, int i, int j)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] = (e - b + 1) - tree[node];
		if(b != e)
		{
			lazy[left] ^= 1;
			lazy[right] ^= 1;
		}
		lazy[node] = 0;
	}
	if(b > j || e < i) return 0;
	if(b >= i && e <= j) return tree[node];
	int l = query(left, b, mid, i, j);
	int r = query(right, mid + 1, e, i, j);
	return l + r;
}

void update(int node, int b, int e, int i , int j)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;
	if(lazy[node])
	{
		tree[node] = (e - b + 1) - tree[node];
		if(b != e)
		{
			lazy[left] ^= 1;
			lazy[right] ^= 1;
		}
		lazy[node] = 0; 
	}

	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		tree[node] = (e - b + 1) - tree[node];
		lazy[left] ^= 1;
		lazy[right] ^= 1;
		return;
	}
	update(left, b, mid, i, j);
	update(right, mid + 1, e, i, j);
	tree[node] = tree[left] + tree[right];
}

int main()
{
	int s, e, op;
	scanf("%d %d",&n, &m);
	rep(i,m)
	{
		scanf("%d %d %d", &op, &s, &e);
		if(op) printf("%d\n", query(1, 1, n, s, e));
		else update(1, 1, n, s, e);
	}
	return 0;
}