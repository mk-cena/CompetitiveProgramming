#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

char str[200];

void Greedy()
{
	char c = 'a';
	string s;

	for(int i =0;i<strlen(str);i++)
		if(c < str[i]) c = str[i],s = c;
		else if(c == str[i]) s += c;

	printf("%s",s.c_str());
}

int main()
{
	scanf("%s",str);
	Greedy();
}