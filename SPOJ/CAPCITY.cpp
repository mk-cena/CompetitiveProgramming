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

int n,m,a,b, scc[100005], out_degree[100005], scc_idx, candidate, found;
vector<int> graph[100005], graph_t[100005];
bool visited[100005], visited_t[100005];
stack<int> s;

void DFS(int node)
{
	if(!visited[node])
	{
		visited[node] = true;
		rep(i, graph[node].size()) DFS(graph[node][i]);
		s.push(node);
	}
}

void DFS_t(int node, int scc_idx)
{
	if(!visited_t[node])
	{
		visited_t[node] = true;
		rep(i, graph_t[node].size()) DFS_t(graph_t[node][i], scc_idx);
		scc[node] = scc_idx;
	}
}


int main()
{
	found = 0;
	scc_idx = 1;
	scanf("%d %d", &n, &m);
	rep(i, m)
	{
		scanf("%d %d", &a, &b), a--, b--;
		graph[a].push_back(b);
		graph_t[b].push_back(a);
	}
	rep(i, n) DFS(i);
	while(!s.empty())
	{
		int node = s.top();	s.pop();
		if(!visited_t[node])
		{
			DFS_t(node, scc_idx++);
		}
	}

	rep(i, n)
	{
		rep(j, graph[i].size())
		{
			if(scc[i] != scc[graph[i][j]])
				out_degree[scc[i]]++;
		}
	}

	for(int i = 1;i<scc_idx;i++)
	{
		if(!out_degree[i])
		{
			candidate = i;
			found++;
		}
	}

	if(found != 1)
	{
		printf("0\n");
	}
	else
	{
		int count = 0;
		rep(i,n)
			if(candidate == scc[i])
				count++;
		printf("%d\n", count);
		rep(i,n)
			if(candidate == scc[i])
				printf("%d ", i + 1);
	}
	return 0;
}