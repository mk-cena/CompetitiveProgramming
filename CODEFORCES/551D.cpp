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

ll mod(ll a, ll b)
{
	return (((a % b) + b ) % b);
}

ll m;

void MUL(ll matA[2][2], ll matB[2][2])
{
	ll matC [2][2] = {{0,0},{0,0}};
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				matC[i][j] = (matC[i][j] + matA[i][k] * matB[k][j]) % m;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			matA[i][j] = matC[i][j];
}

void POW(ll mat[2][2], ll n)
{
	if(n == 1)
		return;
	if(n % 2 == 0)
		POW(mat, n/2), MUL(mat,mat);
	else
	{
		ll f1[2][2] = {{0,1},{1,1}};
		POW(mat, n - 1);
		MUL(mat, f1);
	}
}

ll fib(ll num)
{
	if(num == 1) return 2;
	ll F[2][2] = {{0,1},{1,1}};
	POW(F, num - 1);
	return 2 * F[0][0] + 3 * F[0][1];
}

ll pow_2(ll e)
{
	if(e == 0) return 1;
	if((e % 2) == 1) return (2 * (pow_2(e - 1) )) % m;
	ll x = (pow_2(e/2)) % m;
	return (x * x) % m;
}

int main()
{
	ll n,k,result = 1;
	ll l,f,pow2;
	scanf("%I64d %I64d %I64d %I64d", &n, &k, &l, &m);
	pow2 = pow_2(n);
	f = fib(n);
	if(m == 1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<l;i++)
	{
		int bit = k & 1;
		k >>= 1;
		if(bit)
			result = result * (pow2 % m - f) % m;
		else
			result = result * f % m;
		if(result < 0) result += m;
	}
	if(k != 0)
	{
		printf("0\n");
		return 0;
	}
	printf("%I64d\n",result);
	return 0;
}