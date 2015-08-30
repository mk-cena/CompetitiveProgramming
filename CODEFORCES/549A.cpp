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
#include <set>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAXPRIME 1000000007

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

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}

char image[100][100];
bool face(int i, int j)
{
	bool f = false,a = false,c = false,e = false;

	if(image[i][j] == 'f' ||
	   image[i][j+1] == 'f'||
	   image[i + 1][j] == 'f'||
	   image[i + 1][j+1] == 'f')
		f = true;
	if(image[i][j] == 'a' ||
	   image[i][j+1] == 'a'||
	   image[i + 1][j] == 'a'||
	   image[i + 1][j+1] == 'a')
		a = true;
	if(image[i][j] == 'c' ||
	   image[i][j+1] == 'c'||
	   image[i + 1][j] == 'c'||
	   image[i + 1][j+1] == 'c')
		c = true;
	if(image[i][j] == 'e' ||
	   image[i][j+1] == 'e'||
	   image[i + 1][j] == 'e'||
	   image[i + 1][j+1] == 'e')
		e = true;

	return f && a && c && e;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i =0;i<n;i++)
		scanf("%s",image[i]);
	int cnt=0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m-1;j++)
			if(face(i,j))
				cnt++;
	printf("%d\n",cnt);
	return 0;
}