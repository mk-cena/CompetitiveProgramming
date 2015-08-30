#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long m, n, tmp;
vector <long long> numbers;

bool larger(long long a, long long b)
{
	return a > b;
}
long long Log(long long e)
{
	long long c = -1, x = e;
	while(x) c++,x/=4;
	return c;
}
void brute()
{
	long long ret = 0;
	for(long long i=0;i<=n;i++)
		for(long long  j = 0;j<pow(4.0,(double)i);j++)
			ret += numbers[j];
	cout << ret << endl;
}

int main()
{
	scanf("%I64d", &m);
	n = Log(m);
	for(long long i = 0;i<m;i++)
	{
		scanf("%I64d", &tmp);
		numbers.push_back(tmp);
	}
	sort(numbers.begin(), numbers.end(), larger);
	brute();
}