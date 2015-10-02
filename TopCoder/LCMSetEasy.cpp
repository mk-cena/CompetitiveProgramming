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

#define Y "Possible"
#define N "Impossible"

int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return  a * (b / gcd(a, b));
}


class LCMSetEasy {
public:
	string include( vector <int> S, int x ) 
	{
		int n = S.size(), ans = 1;
		rep(i, n)
		{
			if(x % S[i]) continue;
			ans = lcm(ans, S[i]);
			printf("%d %d\n", ans, S[i]);
		}
		return ans == x?Y:N;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int S[]                   = {2,3,4,5};
			int x                     = 20;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {2,3,4};
			int x                     = 611;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {2,3,4};
			int x                     = 12;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {1,2,3,4,5,6,7,8,9,10};
			int x                     = 24;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int S[]                   = {100,200,300,400,500,600};
			int x                     = 2000;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int S[]                   = {100,200,300,400,500,600};
			int x                     = 8000;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int S[]                   = {1000000000,999999999,999999998};
			int x                     = 999999999;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int S[]                   = ;
			int x                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int S[]                   = ;
			int x                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int S[]                   = ;
			int x                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
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
