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

#define MAXPRIME 1000000007
#define REP(i,N) for(int i=0;i<N;i++)
#define MAX 50009
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


struct segnode
{
	int sum, mx, prefix_mx, suffix_mx;
	segnode(){}
	segnode(int a, int b, int c, int d) : sum(a), mx(b), prefix_mx(c), suffix_mx(d) {}
};
segnode tree[6 * MAX];
int a[2 * MAX];
void build(int node, int i, int j)
{
	if(i == j) tree[node] = segnode(a[i], a[i], a[i], a[i]);
	else
	{
		int left = 2 * node, right = 2 * node + 1, mid = (i + j) / 2;
		build(left, i, mid);
		build(right, mid + 1, j);
		tree[node].sum = tree[left].sum + tree[right].sum;
		tree[node].prefix_mx = max(tree[left].prefix_mx, tree[left].sum + tree[right].prefix_mx);
		tree[node].suffix_mx = max(tree[right].suffix_mx, tree[right].sum + tree[left].suffix_mx);
		tree[node].mx = max(tree[left].suffix_mx + tree[right].prefix_mx, max(tree[left].mx, tree[right].mx));
	}
}

segnode query(int node, int i, int j, int b, int e)
{
	int mid = (i + j) / 2, left_id = 2 * node, right_id = 2 * node + 1;
	if(i >= b && j<= e) return tree[node];
	if(e <= mid) return query(left_id, i, mid, b, e);
	if(b > mid) return query(right_id, mid + 1, j, b, e);
	segnode left = query(left_id, i, mid, b, e);
	segnode right = query(right_id, mid + 1, j, b, e);
	int sum = left.sum + right.sum;
	int prefix_mx = max(left.prefix_mx, left.sum + right.prefix_mx);
	int suffix_mx = max(right.suffix_mx, right.sum + left.suffix_mx);
	int mx = max(left.suffix_mx + right.prefix_mx, max(left.mx, right.mx));
	return segnode(sum, mx, prefix_mx, suffix_mx);
}

void update(int node, int i, int j, int x, int y)
{
	if(x >= i && x <= j)
	{
		int left = 2 * node, right = 2 * node + 1, mid = (i + j) / 2;
		if(i == j) tree[node] = segnode(y, y, y, y);
		else
		{
			update(left, i, mid, x, y);
			update(right, mid + 1, j, x, y);
			tree[node].sum = tree[left].sum + tree[right].sum;
			tree[node].prefix_mx = max(tree[left].prefix_mx, tree[left].sum + tree[right].prefix_mx);
			tree[node].suffix_mx = max(tree[right].suffix_mx, tree[right].sum + tree[left].suffix_mx);
			tree[node].mx = max(tree[left].suffix_mx + tree[right].prefix_mx, max(tree[left].mx, tree[right].mx));
		}
	}
}

int main()
{
	int x,y,t,m,n;
	scanf("%d",&n);
	REP(i,n) scanf("%d", &a[i]);
	scanf("%d",&m);
	build(1, 0, n - 1);
	while(m--)
	{
		scanf("%d %d %d", &t, &x, &y);
		if(t) printf("%d\n", query(1, 0, n - 1, x - 1, y - 1).mx);
		else update(1, 0, n - 1, x - 1, y);
	}
	return 0;
}