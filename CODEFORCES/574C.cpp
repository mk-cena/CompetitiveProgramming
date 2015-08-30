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

int get_rem_2_3(int num)
{
	while(!(num % 2)) num /= 2;
	while(!(num % 3)) num /= 3;
	return num;
}

int num, n, rem;
int main()
{
	scanf("%d",&n);
	rep(i, n) 
	{
		scanf("%d", &num);
		if(i != 0)
		{
			if(get_rem_2_3(num) != rem)
			{
				printf("No\n");
				return 0;
			}
		}
		else rem = get_rem_2_3(num);
	}
	printf("Yes\n");
	return 0;
}