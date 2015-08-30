#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define decreasing 0
#define increasing 1
#define undef 2


void Greedy()
{
	long long mx = -1, count = 0, num, last;
	int dir = undef,n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> num;

		if(mx <= num)
		{
			mx = num;
			dir = undef;
		}
		else
		{
			if(dir == undef)
			{
				if(last == mx)
					count += mx - num;
				else
				{
					if(last > num)
						dir = decreasing;
					else
						if(num > last)
							dir = increasing;
						else
							dir = undef;
				}
			}

			if(dir == decreasing)
			{
				if(num <= last)
					count += last - num;
				else
					dir = increasing;
			}
			if(dir == increasing)
				if(num < last)
				{
					count += last - num;
					dir = decreasing;
				}

		}
		last = num;
	}

	cout << count;
}

int main()
{
	Greedy();
	return 0;
}