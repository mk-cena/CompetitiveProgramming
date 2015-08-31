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
class node
{
	public:
		ll p, id;
		node(ll id):id(id){p = numeric_limits<ll>::max();}
		node(ll id, ll p):p(p),id(id){}
		bool operator<(node n)const
		{
			return p > n.p;
		}

};
class edge
{
	public:
		node v;
		ll w;
		edge(node v, ll w):v(v),w(w){}
};
ll t1, t2, t3, n, m, cost;
bool mst[10001];
priority_queue<node>pq;
vector<edge> graph[10001];
int main()
{
	cost = 0;
	scanf("%lld %lld", &n, &m);
	rep(i, m)
	{
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		t1--, t2--;
		graph[t1].push_back(edge(node(t2),t3));
		graph[t2].push_back(edge(node(t1),t3));
	}
	pq.push(node(0,0));
	while(!pq.empty())
	{
		node _node = pq.top();pq.pop();
		if(mst[_node.id]) continue;
		mst[_node.id] = true;
		cost += _node.p;
		rep(i, graph[_node.id].size())
			if(!mst[graph[_node.id][i].v.id] && graph[_node.id][i].v.p > graph[_node.id][i].w)
				pq.push(node(graph[_node.id][i].v.id, graph[_node.id][i].w));
	}
	printf("%lld\n", cost);
	return 0;
}