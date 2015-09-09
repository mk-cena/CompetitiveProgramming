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

#define rep(i,N) for(int i=0;i<N;i++)

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
int predicted;
priority_queue<int, vector<int>, Compare> pq;
class Badgers {
public:
	int feedMost( vector <int> hunger, vector <int> greed, int totalFood ) 
	{
		int ub = hunger.size(), lb = 0, mid, predicted;
		rep(i, 50)
		{
			mid = lb + (ub - lb) / 2 + (ub - lb == 1);
			predicted = 0, pq = priority_queue<int, vector<int>, Compare>();
			rep(j, hunger.size()) pq.push(hunger[j] + greed[j] * (mid - 1));
			rep(j, mid) predicted += pq.top(), pq.pop();
			if(totalFood < predicted) ub = mid - (ub - lb == 1);
			else lb = mid;
		}
		return mid;
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
			int hunger[]              = {1,2,3};
			int greed[]               = {2,2,1};
			int totalFood             = 7;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int hunger[]              = {5,2,1,5};
			int greed[]               = {0,2,4,1};
			int totalFood             = 19;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int hunger[]              = {1,1,1,1,1};
			int greed[]               = {1000,1000,1000,1000,1000};
			int totalFood             = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int hunger[]              = {1,2,3,4,5,6,7,8,9,10};
			int greed[]               = {10,9,8,7,6,5,4,3,2,1};
			int totalFood             = 100;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int hunger[]              = ;
			int greed[]               = ;
			int totalFood             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int hunger[]              = ;
			int greed[]               = ;
			int totalFood             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hunger[]              = ;
			int greed[]               = ;
			int totalFood             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Badgers().feedMost(vector <int>(hunger, hunger + (sizeof hunger / sizeof hunger[0])), vector <int>(greed, greed + (sizeof greed / sizeof greed[0])), totalFood);
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
