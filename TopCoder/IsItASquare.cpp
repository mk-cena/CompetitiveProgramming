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


#define SQ "It's a square"
#define NSQ "Not a square"

class IsItASquare {
public:
	string isSquare( vector <int> x, vector <int> y ) 
	{
		string ret = NSQ;
		rep(i, 4)
		{
			rep(j, 4)
			{
				if(i == j) continue;
				rep(k, 4)
				{
					if(j == k || i == k || i == j) continue;
					rep(l, 4)
					{
						if(j == k || i == k || i == j || i == l || j == l || k == l) continue;
						double dx = x[j] - x[i], dy = y[j] - y[i];
						double l1 = sqrt(dx * dx + dy * dy);
						dx = x[k] - x[j], dy = y[k] - y[j];
						double l2 = sqrt(dx * dx + dy * dy);
						dx = x[l] - x[k], dy = y[l] - y[k];
						double l3 = sqrt(dx * dx + dy * dy);
						dx = x[i] - x[l], dy = y[i] - y[l];
						double l4 = sqrt(dx * dx + dy * dy);
						dx = x[k] - x[i], dy = y[k] - y[i];
						double l5 = sqrt(dx * dx + dy * dy);
						dx = x[l] - x[j], dy = y[l] - y[j];
						double l6 = sqrt(dx * dx + dy * dy);
						if(l1 == 0 || l2 == 0 || l3 == 0 || l4 == 0 || l5 == 0 || l6 == 0) continue;
						if(l1 == l2 && l2 == l3 && l3 == l4 && l5 == l6)
						{
							ret = SQ;
							return ret;
						}

					}
				}
			}
		}
		return ret;
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
			int x[]                   = {0, 0, 2, 2};
			int y[]                   = {0, 2, 0, 2};
			string expected__         = "It's a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0, 1, 5, 6};
			int y[]                   = {1, 6, 0, 5};
			string expected__         = "It's a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0, 0, 7, 7};
			int y[]                   = {0, 3, 0, 3};
			string expected__         = "Not a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, 5000, 5000, 10000};
			int y[]                   = {5000, 0, 10000, 5000};
			string expected__         = "It's a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4};
			int y[]                   = {4, 3, 2, 1};
			string expected__         = "Not a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {0, 5, 3, 8};
			int y[]                   = {0, 0, 4, 4};
			string expected__         = "Not a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
