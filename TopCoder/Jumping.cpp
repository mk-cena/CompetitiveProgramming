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

#define Y "Able"
#define N "Not able"

class Jumping {
public:
	string ableToGet( int x, int y, vector <int> jumpLengths )
	{
		string ans = N;
		int n = jumpLengths.size(), a = 0, b = 0, r;
		rep(i, n)
		{
			r = jumpLengths[i];
			if(r <= a) a -= r;
			else if(r <= b) a = 0;
			else a = r - b;
			b += r;
		}
		double d = sqrt(x * x + y * y);
		if(d >= a && d <=b) ans = Y;
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
			int x                     = 5;
			int y                     = 4;
			int jumpLengths[]         = {2, 5};
			string expected__         = "Able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 3;
			int y                     = 4;
			int jumpLengths[]         = {4};
			string expected__         = "Not able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 3;
			int y                     = 4;
			int jumpLengths[]         = {6};
			string expected__         = "Not able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 0;
			int y                     = 1;
			int jumpLengths[]         = {100, 100};
			string expected__         = "Able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 300;
			int y                     = 400;
			int jumpLengths[]         = {500};
			string expected__         = "Able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 11;
			int y                     = 12;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,10};
			string expected__         = "Able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 11;
			int y                     = 12;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,100};
			string expected__         = "Not able";

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
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
