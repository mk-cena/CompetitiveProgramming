#include <stdio.h>

using namespace std;

int main()
{
	int n,count = 0;
	scanf("%d",&n);

	for(int i=0,a,b,c;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a+b+c > 1)
			count++;
	}
	printf("%d",count);
}