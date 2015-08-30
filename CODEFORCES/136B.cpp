#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> a, c;
vector <int> torInv(vector<int> mn, vector<int> mx)
{
	int x,y,i;
	vector <int> ret;
	for(i = 0;i<mn.size();i++)
	{
		if(a[i] > c[i]) c[i] += 3; 
		ret.push_back(c[i] - a[i]);
	}
	for(int j = i;j < mx.size();j++)
		ret.push_back(mx[i]);
	return ret;
}

void base10(vector <int> vec)
{
	long long ret = 0;
	for(int i = 0;i<vec.size();i++)
	{
		ret += vec[i] * pow(3.0, (double)i);
	}
	printf("%lld", ret);
}

vector <int> base3(long long &n)
{
	vector <int> ret;
	while(n != 0)
	{
		ret.push_back(n % 3);
		n /= 3;
	}
	return ret;
}

void pad()
{
	if(a.size() < c.size())
		for(int i = a.size();i<c.size();i++)
			a.push_back(0);
	else
		for(int i = c.size();i<a.size();i++)
			c.push_back(0);

}

int main()
{
	long long tmp1,tmp2;
	scanf("%I64d %I64d",&tmp1,&tmp2);
	a = base3(tmp1);
	c = base3(tmp2);
	pad();
	base10(torInv(a,c));
}