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

vector<int> graph[100009];
stack<int> free1, free2;
int n1,n2,d,x,y,dependancies[100009],sdependancies[100009];

void rm_node(int *tdependancies, int node,
			stack <int> &sfree1, stack<int> &sfree2)
{
	for(int i=0;i<graph[node].size();i++)
		if(tdependancies[graph[node][i]] > 0)
		{
			tdependancies[graph[node][i]]--;
			if(tdependancies[graph[node][i]] == 0)
			{
				if(graph[node][i] <= n1)
					sfree1.push(graph[node][i]);
				else
					sfree2.push(graph[node][i]);
			}
		}
}

void insert_disc(int *tdependancies, stack<int> &sfree, stack<int>&sfree1, stack<int>&sfree2)
{
	while(!sfree.empty())
	{
		int node = sfree.top();sfree.pop();
		rm_node(tdependancies, node, sfree1, sfree2);
	}
}

int simulate(int *tdependancies, 
			 stack<int> &sfree1, stack<int> &sfree2, 
			 stack<int> &xfree1, stack<int> &xfree2)
{
	int changes = 2;

	while(!sfree1.empty() || !sfree2.empty())
	{
		insert_disc(tdependancies,sfree1, xfree1, xfree2);
		if(!sfree2.empty()) changes++;
		insert_disc(tdependancies,sfree2, xfree1, xfree2);
		if(!sfree1.empty()) changes++;
	}

	return changes;
}

void copy()
{
	for(int i=1;i<=n1+n2;i++)
	{
		sdependancies[i] = dependancies[i];
		if(dependancies[i] == 0)
		{
			if(i<=n1)
				free1.push(i);
			else
				free2.push(i);
		}
	}
}

int main()
{
	while(true)
	{

		scanf("%d %d %d", &n1, &n2, &d);
		if(n1 == 0 && n2 == 0 && d == 0)
			break;

		free1 = stack<int>(), free2 = stack<int>();
		for(int i=1;i<=n1+n2;i++)
			graph[i] = vector<int>(),dependancies[i]=0;

		for(int i=0;i<d;i++)
		{
			scanf("%d %d",&x,&y);
			graph[y].push_back(x);
			dependancies[x]++;
		}

		copy();
		int changes1 = simulate(sdependancies,free1,free2,free1,free2);
		copy();
		int changes2 = simulate(sdependancies,free2,free1,free1,free2);

		printf("%d\n",min(changes1, changes2));
		
	}
	return 0;
}