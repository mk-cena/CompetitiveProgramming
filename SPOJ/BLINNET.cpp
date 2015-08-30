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

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}
class node
{
	public:
		ll p,d,id;
		node(){d = numeric_limits<ll>::max();}
		node(ll id, ll p, ll d):id(id),p(p),d(d){}
};
class Compare
{
	public:
		bool operator()(node a, node b)
		{
			return a.d > b.d;
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
char str[100000];
ll n,t,neighbours,cost;
vector <edge> graph[10001];
priority_queue<node, vector<node>, Compare>pq;
bool mst[10001];
int main()
{
	scanf("%lld\n",&t);
	while(t--)
	{
		cost = 0;
		memclr(mst);
		pq = priority_queue<node, vector<node>, Compare>();
		scanf("%lld",&n);
		rep(i, n)
		{
			edge e;
			graph[i] = vector<edge>();
			scanf("%s",str);
			scanf("%lld",&neighbours);
			rep(j, neighbours) scanf("%lld %lld",&e.v.id, &e.w),e.v.id--,graph[i].push_back(e);
		}
		pq.push(node(0,-1,0));
		while(!pq.empty())
		{
			node u = pq.top();pq.pop();
			if(mst[u.id]) continue;
			cost += u.d;
			mst[u.id] = true;
			rep(j, graph[u.id].size()) 
				if(!mst[graph[u.id][j].v.id] && graph[u.id][j].v.d >= graph[u.id][j].w)
				{
					pq.push(node(graph[u.id][j].v.id,-1, graph[u.id][j].w)); 
				}
		}
		printf("%lld\n",cost);
	}
	return 0;
}