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

#define REP(i,N) for(int i=0;i<N;i++)
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

struct segnode
{
	int sum, prefix_mx, suffix_mx, mx;
	segnode(){}
	segnode(int a, int b, int c, int d) : sum(a), prefix_mx(b), suffix_mx(c), mx(d) {}
};

#define MAX 10009
int a[MAX];
segnode tree[4 * MAX];

void build(int node, int i, int j)
{
	if(i == j) tree[node] = segnode(a[i], a[i], a[i], a[i]);
	else
	{
		int mid = (i + j) / 2, left = 2 * node, right = left + 1;
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
	int mid = (i + j) / 2, left_id = 2 * node, right_id = left_id + 1;
	if(b > e) return segnode(0,0,0,0);
	if(i >= b && j <= e) return tree[node];
	if(mid < b) return query(right_id, mid + 1, j, b, e);
	if(mid >= e) return query(left_id, i, mid, b, e);
	segnode left = query(left_id, i, mid, b, e);
	segnode right = query(right_id, mid + 1, j, b, e);
	segnode current;
	current.sum = left.sum + right.sum;
	current.prefix_mx = max(left.prefix_mx, left.sum + right.prefix_mx);
	current.suffix_mx = max(right.suffix_mx, right.sum + left.suffix_mx);
	current.mx = max(left.suffix_mx + right.prefix_mx, max(left.mx, right.mx));
	return current;
}

int main()
{
	int t, n, m, x1, x2, y1, y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		REP(i, n) scanf("%d",&a[i]);
		build(1, 0, n - 1);
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--, x2--, y1--, y2--;
			if(y1 < x2)
			{
				printf("%d\n", query(1, 0, n - 1, x1, y1).suffix_mx + 
							   query(1, 0, n - 1, y1 + 1, x2 - 1).sum + 
							   query(1, 0, n - 1, x2, y2).prefix_mx);
			}
			else
			{
				printf("%d\n", max(query(1, 0, n - 1, x2, y1).mx, 
							   max(query(1, 0, n - 1, x1, x2 - 1).suffix_mx + 
							   	   query(1, 0, n - 1, x2, y2).prefix_mx,
								   query(1, 0, n - 1, x1, y1).suffix_mx + 
								   query(1, 0, n - 1, y1 + 1, y2).prefix_mx)));
			}
		}
	}
	return 0;
}