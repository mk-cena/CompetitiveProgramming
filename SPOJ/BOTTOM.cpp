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

bool v[5009],vT[5009];
int n,a,b,e;
vector<int> graph[5009], graphT[5009], sccs[5009], bottom;
stack<int> s;

int DFS(int node)
{
	int cnt = 0;
	if(!v[node])
	{
		cnt++;
		v[node] = true;
		for(int i=0;i<graph[node].size();i++)
			cnt += DFS(graph[node][i]);
		s.push(node);
	}
	return cnt;
}

void DFST(int node, int k)
{
	if(!vT[node])
	{
		vT[node] = true;
		sccs[k].push_back(node);
		for(int i=0;i<graphT[node].size();i++)
			DFST(graphT[node][i],k);
	}
}

int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(n == 0) break;
		scanf("%d",&e);

		bottom = vector<int>();
		for(int i=1;i<=n;i++)
			graph[i] = vector<int>(), graphT[i] = vector<int>(), sccs[i] = vector<int>(), v[i] = vT[i] = false;

		for(int i=0;i<e;i++)
		{
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graphT[b].push_back(a);
		}

		for(int i=1;i<=n;i++)
			DFS(i);

		while(!s.empty())
		{
			int tmp = s.top();s.pop();
			DFST(tmp,tmp);
		}

		for(int i=1;i<=n;i++)
		{
			if(sccs[i].size() == 0) continue;
			for(int j=1;j<=n;j++) v[j] = false;
			if(DFS(sccs[i][0]) <= sccs[i].size())
				for(int j=0;j<sccs[i].size();j++) 
					bottom.push_back(sccs[i][j]);
		}

		sort(bottom.begin(), bottom.end());

		for(int i=0;i<bottom.size();i++)
			printf("%d ",bottom[i]);
		printf("\n");
	}
	return 0;
}