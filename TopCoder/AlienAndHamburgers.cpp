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

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
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

bool visited_type[100];
class AlienAndHamburgers {
public:
	int getNumber( vector <int> type, vector <int> taste )
	{
		vector<pair<int, int> > neg;
		int A = 0, Y = 0, n =  taste.size();
		rep(i, 100) visited_type[i] = false;
		rep(i, n)
		{
			if(taste[i] >= 0)
			{
				A += taste[i];
				if(!visited_type[type[i]]) Y ++, visited_type[type[i]] = true;
			}
			else neg.push_back(pair<int, int>(taste[i], type[i]));
		}
		int joy = Y * A;
		sort(neg.begin(), neg.end(), compare);
		rep(i, neg.size())
			if(!visited_type[neg[i].second])
				Y++, A += neg[i].first, visited_type[neg[i].second] = true, joy = max(joy, Y * A);

		return joy;
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
			int type[]                = {1, 2};
			int taste[]               = {4, 7};
			int expected__            = 22;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int type[]                = {1, 1};
			int taste[]               = {-1, -1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int type[]                = {1, 2, 3};
			int taste[]               = {7, 4, -1};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int type[]                = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
			int taste[]               = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
			int expected__            = 54;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int type[]                = {30, 20, 10};
			int taste[]               = {100000, -100000, 100000};
			int expected__            = 400000;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int type[]                = ;
			int taste[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int type[]                = ;
			int taste[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int type[]                = ;
			int taste[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(taste, taste + (sizeof taste / sizeof taste[0])));
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
