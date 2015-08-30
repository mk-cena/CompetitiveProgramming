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
			return a < b;
		}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}
int n,b,array[500000];
int main()
{
	while(true)
	{
		scanf("%d %d",&n,&b);
		if(n == -1 && b == -1) break;
		rep(i,n) scanf("%d",&array[i]);
		int ub = 5000000, lb = 0, mid, count;
		rep(i,25)
		{
			mid = (ub - lb) / 2 + ((ub - lb) & 1)  + lb;
			count = 0;
			rep(j,n) count += array[j]/mid + (array[j] % mid != 0);
			if(count <= b) ub = mid;
			else lb = mid;
		}
		printf("%d\n", mid);
	}
	return 0;
}