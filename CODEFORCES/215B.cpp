#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int n,m,k;
	double r1 = 0,r2,A,B,p1 = 0,p2 = 5005,tmp;

	scanf("%d", &n);
	for(int i = 0;i<n;i++)
	{
		scanf("%lf",&tmp);
		r1 = max(r1, tmp);
	}

	scanf("%d", &m);
	for(int i = 0;i<m;i++)
	{
		scanf("%lf",&tmp);
		p1 = max(p1, tmp);
	}

	scanf("%d", &k);
	for(int i = 0;i<k;i++)
	{
		scanf("%lf",&tmp);
		p2 = min(p2, tmp);
	}

	scanf("%lf %lf", &A, &B);

	r2 = sqrt((r1 * r1) / (1.0 + ((p2 * A)/(p1 * B))));

	printf("%.12lf", r2);
}