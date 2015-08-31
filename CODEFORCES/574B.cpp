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
int n,m,tmp1,tmp2;
bool graph1[5000][5000];
vector<int> graph2[5000];
set<int> all_recognition;
int main()
{
	scanf("%d %d", &n, &m);
	rep(i,m)
	{
		scanf("%d %d", &tmp1, &tmp2);
		tmp1--, tmp2--;
		graph2[tmp1].push_back(tmp2);
		graph2[tmp2].push_back(tmp1);
		graph1[tmp1][tmp2] = graph1[tmp2][tmp1] = true;
	}
	
	rep(i, n)
		rep(j, graph2[i].size())
			rep(k, graph2[graph2[i][j]].size()) 
				if(graph1[i][graph2[graph2[i][j]][k]])
					all_recognition.insert(graph2[i].size() + graph2[graph2[i][j]].size() + graph2[graph2[graph2[i][j]][k]].size() - 6);

	if(all_recognition.empty()) printf("-1\n");
	else printf("%d\n",*(all_recognition.begin()));
	return 0;
}