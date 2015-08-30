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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

int cases,a,b,n,e,p[3000],d[3000];
vector<int> graph[3000];
bool v[3000],flag;
queue<int>q;

bool BFS(int node)
{
	q.push(node);
	while(!q.empty())
	{
		node = q.front();q.pop();
		if(!v[node])
		{
			v[node] = true;
			for(int i=0;i<graph[node].size();i++)
			{
				int child = graph[node][i];
				if(p[child] != -1 && !v[child] && d[child] != d[node] + 1)
					return false;
				q.push(child);
				p[child] = node;
				d[child] = d[node] + 1;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d",&cases);
	for(int t=1;t<=cases;t++)
	{
		scanf("%d %d",&n,&e);
		for(int i=1;i<=n;i++)
		{
			graph[i] = vector<int>();
			v[i] = false;
			p[i] = -1;
			d[i] = 0;
		}

		for(int i=0;i<e;i++)
		{
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		flag = true;
		for(int i=1;i<=n;i++)
			flag &= BFS(i);
	
		if(!flag)
			printf("Scenario #%d:\nSuspicious bugs found!\n",t);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n",t);
	}
	return 0;
}