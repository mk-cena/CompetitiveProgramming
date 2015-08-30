#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

char str [100001];

int main()
{
	scanf("%s",str);
	int len=strlen(str);
	bool flag = false;
	for(int i=0;i<len;i++)
	{
		if(i == len-1 && !flag) continue;
		if(str[i] == '0' && !flag) {flag = true; continue;}
		printf("%c",str[i]);
	}
}