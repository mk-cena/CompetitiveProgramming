#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b;
long long d;
pair <long long, int> clients[1000005];


void Greedy()
{
	int pleased = 0;
	sort(clients, clients + n);

	for(;d >= 0 && pleased < n;pleased++)
		d -= clients[pleased].first;

	if(d < 0) pleased--;
	printf("%d\n", pleased);
	for(int i=0;i < pleased;i++)
		printf("%d ", clients[i].second);

}

int main()
{
	int x,y;

	scanf("%d %I64d", &n, &d);
	scanf("%d %d", &a, &b);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &x, &y);
		clients[i].first = x * a + y * b;
		clients[i].second = i + 1;
	}

	Greedy();
}