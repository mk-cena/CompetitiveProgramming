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

class node
{
	public:
		ll d, id, p;
		node(){d = numeric_limits<ll>::max();}
		node(ll id):id(id){d = numeric_limits<ll>::max();}
		node(ll id,ll d):id(id),d(d){}
		bool operator<(node n)const
		{
			return d > n.d;
		}
};


class Compare
{
	public:
		bool operator()(node a, node b)
		{
			return a.d < b.d;
		}
};

class edge
{
	public:
		node v;
		ll w;
		edge(){}
		edge(node v, ll w):v(v), w(w){}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}
ll t,p,n,m,a,b,c,cost;
vector<edge> graph[1001];
bool mst[1001];
priority_queue<node, vector<node> > pq;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		cost = 0;
		memclr(mst);
		pq = priority_queue<node, vector<node> >();
		scanf("%lld", &p);
		scanf("%lld %lld", &n, &m);
		rep(i, n) graph[i] = vector<edge>();
		rep(i, m)
		{
			scanf("%lld %lld %lld", &a, &b, &c), a--, b--;
			graph[a].push_back(edge(node(b), c));
			graph[b].push_back(edge(node(a), c));
		}
		pq.push(node(0,0));
		while(!pq.empty())
		{
			node _node = pq.top();pq.pop();
			if(mst[_node.id]) continue;
			mst[_node.id] = true;
			cost += _node.d;
			rep(j, graph[_node.id].size())
			{
				if(!mst[graph[_node.id][j].v.id] && graph[_node.id][j].v.d >= graph[_node.id][j].w)
				{
					pq.push(node(graph[_node.id][j].v.id, graph[_node.id][j].w));
				}
			}
		}
		printf("%lld\n", cost * p);
	}
	return 0;
}