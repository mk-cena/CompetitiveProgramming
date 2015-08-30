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


int main()
{
	char str[100009];
	scanf("%s",str);
	int n = strlen(str);
	vector<int> ab, ba;
	int i = 0;
	while(i < n - 1)
	{
		if(str[i] == 'A' && str[i + 1] == 'B')
		{
			ab.push_back(i);
		}		
		if(str[i] == 'B' && str[i + 1] == 'A')
		{
			ba.push_back(i);
		}
		i++;
	}
	bool flag = false;
	for(int i =0;i<ab.size();i++)
		for(int j=0;j<ba.size();j++)
		{
			if(abs(ab[i] - ba[j]) > 1)
			{
				flag =  true;
				break;
			}
		}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}