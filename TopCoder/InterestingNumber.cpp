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

#define Y "Interesting"
#define N "Not interesting"

class InterestingNumber {
public:
	string isInteresting( string x ) 
	{
		int n = x.size();
		rep(i, 10)
		{
			int cnt = 0, cnt2 = 0;
			rep(j, n)
			{
				if(x[j] == i + '0')
				{
					if(cnt2 == 1) {if(cnt != i) return N;}
					cnt = 0, cnt2 ++;
				}
				else cnt++;
			}
			if(cnt2 != 0 && cnt2 != 2) return N;
		}
		return Y;
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
			string x                  = "2002";
			string expected__         = "Interesting";

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string x                  = "1001";
			string expected__         = "Not interesting";

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string x                  = "41312432";
			string expected__         = "Interesting";

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string x                  = "611";
			string expected__         = "Not interesting";

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string x                  = "64200246";
			string expected__         = "Interesting";

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string x                  = "631413164";
			string expected__         = "Not interesting";

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string x                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string x                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string x                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = InterestingNumber().isInteresting(x);
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
