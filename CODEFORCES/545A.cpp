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

using namespace std;

#define ll long long

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

int main()
{
	vector<int> vec;
	int n, mat[200][200];
	bool flag = false;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j] == 3 || mat[i][j] == 1) flag = true;
		}
		if(!flag) vec.push_back(i + 1);
		flag = false;
	}
	printf("%d\n",(int)vec.size());
	for(int i=0;i<vec.size();i++)
		printf("%d ",vec[i]);
	return 0;
}