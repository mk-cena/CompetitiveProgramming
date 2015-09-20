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
#include <sstream>

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

vector<int> pos[10];

class BoxUnion {
public:
	int area( vector <string> rectangles ) 
	{
		stringstream ss;
		int n = rectangles.size(), area, ans = 0, a, b, c, d, tmp;
		rep(i, n)
		{
			ss.clear(), ss.str(rectangles[i]);
			rep(j, 4) ss >> tmp, pos[i].push_back(tmp);
		}
		rep(i, n)
		{
			area = (pos[i][2] - pos[i][0]) * (pos[i][3] - pos[i][1]); 
			for(int j= i - 1;j>=0;j--)
			{
				a = max(pos[i][0], pos[j][0]), b = min(pos[i][2], pos[j][2]);
				c = max(pos[i][1], pos[j][1]), d = min(pos[i][3], pos[j][3]);
				if(a > b|| c > d) continue;
				area -=  (b - a) * (d - c);
			}
			ans += area;
		}
		a = c = -1, b = d = 10000000;
		rep(i, n) a = max(a, pos[i][0]), b = min(b, pos[i][2]), c = max(c, pos[i][1]), d = min(d, pos[i][3]);
		area = (b - a) * (d - c);
		if(n == 3 && a <= b && c <= d) ans += area;
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
			string rectangles[]       = { "200 300 203 304" };
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string rectangles[]       = { "0 0 10 10",
  "20 20 30 30" };
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string rectangles[]       = { "0 500 20000 501",
  "500 0 501 20000" };
			int expected__            = 39999;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string rectangles[]       = { "4 6 18 24",
  "7 2 12 19",
  "0 0 100 100" };
			int expected__            = 10000;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string rectangles[]       = { "1 3 5 6",
  "3 1 7 5",
  "4 4 9 7" };
			int expected__            = 35;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string rectangles[]       = { "0 0 20000 20000",
  "0 0 20000 20000",
  "0 0 20000 20000" };
			int expected__            = 400000000;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string rectangles[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string rectangles[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string rectangles[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
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
