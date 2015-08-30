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

int t,n,tmp,c,out_degree[1001],scc[1001],winners,found,scc_idx;
vector<int> graph[1001], graph_t[1001];
bool visited[1001], visited_t[1001];
stack<int> s;

void dfs(int node)
{
	if(!visited[node])
	{
		visited[node] = true;
		rep(i, graph[node].size()) dfs(graph[node][i]);
		s.push(node);
	}
}

void dfs_t(int node, int scc_idx)
{
	if(!visited_t[node])
	{
		visited_t[node] = true;
		rep(i, graph_t[node].size()) dfs_t(graph_t[node][i], scc_idx);
		scc[node] = scc_idx;
	}
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		found = 0;
		scc_idx = 1;
		s = stack<int>();
		scanf("%d", &n);
		rep(i, n) visited[i] = visited_t[i] = scc[i] = out_degree[i] = 0, graph[i] = vector<int>(), graph_t[i] = vector<int>();
		rep(i, n)
		{
			scanf("%d", &c);
			rep(j, c)
			{
				scanf("%d", &tmp), tmp--;
				graph[i].push_back(tmp);
				graph_t[tmp].push_back(i);
			}
		}
		rep(i,n) dfs(i);
		while(!s.empty())
		{
			int node = s.top();s.pop();
			if(!visited_t[node])
			{
				dfs_t(node, scc_idx++);
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
		for(int i = 1; i < scc_idx; ++i)
		{
			if(!out_degree[i])
			{
				winners = i;
				found++;
			}
		}
		int count = 0;
		if(found != 1) printf("0\n");
		else
		{
			rep(i, n)
			{
				if(winners == scc[i])
				{
					count++;
				}
			}
			printf("%d\n",count);
		}
	}
	return 0;
}