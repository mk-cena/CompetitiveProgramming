#include <stdio.h>
#include <vector>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	int a, b, sa = 0, sb = 0;
	vector <char> eggs;
	scanf("%I64d",&n);
	for(long long i =0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(abs(sa + a - sb) < abs(sa - sb - b)) eggs.push_back('A'), sa += a;
		else eggs.push_back('G'), sb += b;
	}

	if(abs(sa - sb) <= 500)
		for(long long i=0;i<eggs.size();i++)
			printf("%c",eggs[i]);
	else
		printf("-1");
}