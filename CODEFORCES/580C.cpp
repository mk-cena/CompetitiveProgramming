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
#include <bitset>

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

int n, m, t1, t2, ans = 0, cat[100009], v[100009];
vector<int> graph[100009];

void BFS(int root)
{
	queue<pair<int, int> > q; 
	q.push(pair<int, int>(root, cat[root]));
	while(!q.empty())
	{
		pair<int, int> node = q.front(); q.pop();
		if(v[node.first] || node.second > m) continue;
		if(node.second <= m && graph[node.first].size() <= 1 && node.first) ans++;
		v[node.first] = true;
		rep(i, graph[node.first].size())
		{
			int child = graph[node.first][i], cons = cat[child]?node.second + 1:0;
			q.push(pair<int, int>(child, cons));
		}
	}
}

int main()
{
	memclr(v);
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &cat[i]);
	rep(i, n - 1) scanf("%d %d", &t1, &t2), t1--, t2--, graph[t1].push_back(t2), graph[t2].push_back(t1);
	BFS(0);
	printf("%d\n",ans);
	return 0;
}