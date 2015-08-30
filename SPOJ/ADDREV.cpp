#include <stdio.h>
#include <cmath>

using namespace std;
int a,b;

int rev(int n)
{
	int i,r = 0,tmp = n;
	for(i=0;tmp > 0;i++,tmp/=10);
	for(int j=i - 1,tmp=n;j>=0;j--,tmp/=10)
		r += (tmp%10) * ((int)pow(10.0,(double)j));
	return r;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		a = rev(a);
		b = rev(b);
		printf("%d\n", rev(a + b));
	}
}