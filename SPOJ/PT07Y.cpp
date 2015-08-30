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

queue<int> q;
bool v[10009],flag;
int a,b,e,n,p[10009];
vector<int> graph[10009];

bool BFS(int node)
{
	q.push(node);
	while(!q.empty())
	{
		int parent = q.front(); q.pop();
		if(!v[parent])
		{
			v[parent] = true;
			for(int i=0;i<graph[parent].size();i++)
			{
				int child = graph[parent][i];
				if(!v[child] && p[child] != -1)
					return false;
				q.push(child);
				p[child] = parent;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&n,&e);
	for(int i=1;i<=n;i++)
		v[i] = false, p[i] = -1;
	for(int i=0;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	flag = true;
	for(int i=1;i<=n;i++)
		flag &= BFS(i);

	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}