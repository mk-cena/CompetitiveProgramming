// Paste me into the FileEdit configuration dialog

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
#include <limits>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,N) for(int i=0;i<N;i++)
#define memclr(ARRAY) memset(ARRAY,0,sizeof(ARRAY))
#define MAXPRIME 1000000007
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745

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

#define MX 1000009

int ans = 0;
vector<int> factors;
bool prime[MX];

void build()
{
	rep(i, MX) prime[i] = true;
	prime[0] = prime[1] = false;
	rep(i, 1010) if(prime[i]) for(int j = i * i; j < MX; j += i) prime[j] = false;
}


class BigFatInteger {
public:
	int minOperations( int A, int B ) 
	{
		build();
		
		int tmp = A, k = 2, q = 0;
		while(true)
		{
			if(tmp != 1 && prime[k] && !(tmp % k)) q++, tmp /= k;
			else
			{
				if(q) factors.push_back(q * B - 1), ans++;
				if(tmp == 1) break;
				k++, q = 0;
			}
		}

		int fact = 1;
		while(true)
		{
			bool flag = false;
			rep(j, factors.size()) flag |= factors[j] > 0, factors[j]-=fact;
			if(flag) ans++;
			else break;
			fact *= 2;
		}
		
		return ans;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int A                     = 6;
			int B                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 162;
			int B                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 999983;
			int B                     = 9;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 360;
			int B                     = 8;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
