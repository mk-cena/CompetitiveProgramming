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

class trio
{
	public:
		int w, a, b;
		trio(int w, int a, int b):w(w),a(a),b(b){}
		bool operator<(trio t) const
		{
			return w < t.w;
		}
};

int n,tmp, pairs[1000];
bool visited[1000];
priority_queue<trio> pq;
int main()
{
	memclr(visited), memclr(pairs);
	scanf("%d", &n);
	for(int i = 2;i <= 2 * n; i++) for(int j = 1; j < i; j++) scanf("%d", &tmp), pq.push(trio(tmp,i,j));
	while(!pq.empty())
	{
		trio t = pq.top(); pq.pop();
		if(visited[t.a] || visited[t.b]) continue;
		visited[t.a] = visited[t.b] = true;
		pairs[t.a] = t.b, pairs[t.b] = t.a;
	}
	for(int i = 1; i <= 2 * n; i++) printf("%d ", pairs[i]);
	printf("\n");
	return 0;
}