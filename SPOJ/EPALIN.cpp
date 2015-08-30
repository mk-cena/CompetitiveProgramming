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
#define P 53

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

char s[200015];
ull fhash, bhash[200015], N, POW[200015], found;

int charHash(char c)
{
	return 1 + (c >= 'a'? c - 'A' - 6:c -'A');
}

void preprocess()
{
	POW[0] = 1;
	bhash[N] = fhash = 0;
	for(ull i = 0, j = N - 1; i<N;i++,j--)
	{
		fhash = (fhash) * P  + charHash(s[i]);
		bhash[j] = (bhash[j + 1]) * P + charHash(s[j]);
		POW[i + 1] = (POW[i])* P;
	}
}

int main()
{
	while(scanf("%s",s) != EOF)
	{
		N = strlen(s);
		found = N - 1;
		preprocess();
		for(ull i = 0;i<N;i++)
		{
			if(fhash == bhash[i])
			{
				found = i;
				break;
			}
			else
				fhash -= ((POW[N-i-1]) * charHash(s[i]));
		}

		for(ull i=0;i<N;i++)
			printf("%c",s[i]);
		for(ll i=found - 1;i>=0;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}