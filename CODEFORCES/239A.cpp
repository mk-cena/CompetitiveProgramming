#include <stdio.h>

using namespace std;

int main()
{
	bool flag = false;
	long long y,k,n;
	scanf("%I64d %I64d %I64d",&y,&k,&n);
	for(long long i=k;i<=n;i+=k)
		if(i-y > 0)
			printf("%I64d ",i - y),flag=true;
	if(!flag) printf("-1");
}