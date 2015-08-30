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

#define MAX 400005

class segnode
{
	public:
		int zeroes, ones, twos;
		segnode()
		{
			zeroes = ones = twos = 0;
		}
		inline void acc (segnode *node1, segnode *node2)
		{
			zeroes = node1->zeroes + node2->zeroes;
			ones = node1->ones + node2->ones;
			twos = node1->twos + node2->twos;
		}
		inline void shift(int num)
		{
			int temp;
			if(num == 1)
			{
				temp = zeroes, zeroes = twos, twos = ones, ones = temp;
			}
			else if(num == 2)
			{
				shift(1);
				shift(1);
			}
		}
};

int n,q,a,b,t,lazy[MAX];
segnode tree[MAX];

inline void build(int node, int b, int e)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;

	if(b == e)
	{
		tree[node].zeroes = 1;
		return;
	}
	
	build(left, b, mid);
	build(right, mid + 1, e);
	
	tree[node].acc(&tree[left], &tree[right]);
}

inline int query(int node, int b, int e, int i, int j)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;

	if(lazy[node])
	{
		tree[node].shift(lazy[node]);
		if(b != e)
		{
			lazy[left]+=lazy[node], lazy[right]+=lazy[node];
			lazy[left] %= 3, lazy[right] %= 3;
		}
		lazy[node] = 0;
	}

	if(b > j || e < i) return 0;

	if(b >= i && e <= j) return tree[node].zeroes;

	int l = query(left, b, mid, i, j);
	int r = query(right, mid + 1, e, i, j);

	return l + r;
}

inline void update(int node, int b, int e, int i, int j)
{
	int mid = (b + e) / 2, left = 2 * node, right = left + 1;

	if(lazy[node])
	{
		tree[node].shift(lazy[node]);
		if(b != e)
		{
			lazy[left]+=lazy[node], lazy[right]+=lazy[node];
			lazy[left] %= 3, lazy[right] %= 3;
		}
		lazy[node] = 0;
	}

	if(b > j || e < i) return;

	if(b >=i && e <= j)
	{
		tree[node].shift(1);
		if(b != e)
		{
			lazy[left]++, lazy[right]++;
			lazy[left] %= 3, lazy[right] %= 3;
		}
		return;
	}

	update(left, b, mid, i, j);
	update(right, mid + 1, e, i, j);
	tree[node].acc(&tree[left], &tree[right]);
}

inline int next_int() {
	int n = 0;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int main()
{
	n = next_int(), q = next_int();
	build(1, 0, n - 1);
	rep(i, q)
	{
		t = next_int(), a = next_int(), b = next_int();
		if(t) printf("%d\n", query(1, 0, n - 1, a, b));
		else update(1, 0, n - 1, a, b);
	}
	return 0;
}