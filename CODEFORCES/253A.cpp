#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n,m;
char c,d;
fstream file;

void alternate()
{
	int mx = max(m,n);
	int mn = min(m,n);

	if(m <= n) {c = 'B';d = 'G';}
	else {c = 'G';d = 'B';}

	for(int i=0;i<mn;i++) cout << c << d;
	for(int i=0;i<mx-mn;i++) cout << c;

	cout << endl;	
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n >> m;
	alternate();
}