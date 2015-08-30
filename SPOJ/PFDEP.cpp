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

int n,m,dependents[200],v,tmp;
bool graph[200][200], visited[200];
priority_queue <int, vector <int>, Compare> pq;

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<200;i++)
	{
		visited[i] = false;
		dependents[i] = 0;
		for(int j=0;j<200;j++)
			graph[i][j]=false;
	}

	for(int i=0;i<m;i++)
	{
		scanf("%d",&v);
		scanf("%d", &dependents[v]);
		for(int j=0;j<dependents[v];j++)
		{
			scanf("%d",&tmp);
			graph[v][tmp] = true;
		}
	}

	for(int i=1;i<=n;i++)
		if(dependents[i] == 0)
			pq.push(i);

	while(!pq.empty())
	{
		int node = pq.top();
		pq.pop();
		printf("%d ",node);
		for(int i=1;i<=n;i++)
			if(graph[i][node])
			{
				graph[i][node] = false;
				dependents[i]--;
				if(dependents[i] == 0)
					pq.push(i);
			}
	}

	printf("\n");

	return 0;
}