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

using namespace std;

#define ll long long
#define ull unsigned long long
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
	return ((a % b) + b) % b;
}

int charHash(char c)
{
	return c - 'a' + 1;
}

#define P 27
#define MAXN 30009


int main()
{
	int k;
	char str[MAXN];
	ll fhash[MAXN], bhash[MAXN], POW[MAXN], cnt = 0;
	scanf("%d\n%s",&k,str);
	int N = strlen(str);
	bhash[N-k]=fhash[0]=0;
	POW[0] = 1;

	for(int i=1;i<=k;i++)
	{
		POW[i] = POW[i-1] * P;
		POW[i] = mod(POW[i],MAXPRIME);
	}

	for(int i=0;i<k;i++)
	{
		fhash[0] += (charHash(str[i]) * POW[k - i - 1]);
		fhash[0] = mod(fhash[0],MAXPRIME);
	}
	
	for(int i=0;i<k;i++)
	{
		bhash[N-k] += (charHash(str[N-i-1]) * POW[k - i - 1]);
		bhash[N-k] = mod(bhash[N-k], MAXPRIME);
	}

	for(int i=1;i<=N-k;i++)
	{
		fhash[i] = mod(fhash[i-1] - POW[k-1] * charHash(str[i-1]), MAXPRIME);
		fhash[i] = fhash[i] * P + charHash(str[i+k-1]);
		fhash[i] = mod(fhash[i], MAXPRIME);
	}

	for(int i=N-k-1;i>=0;i--)
	{
		bhash[i] = mod(bhash[i+1] - POW[k-1] * charHash(str[i+k]), MAXPRIME);
		bhash[i] = bhash[i] * P + charHash(str[i]);
		bhash[i] = mod(bhash[i], MAXPRIME);
	}

	for(int i=0;i<=N-k;i++)
	{
		if(fhash[i] == bhash[i]) cnt++;
	}

	printf("%lld\n",cnt);
	
	return 0;
}