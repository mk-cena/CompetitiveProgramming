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
			return a < b;
		}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}

vector<int> s;
int dp[25][2000009], n;

void DP(int i, int sum)
{
	if(i == n) dp[i][sum] = 0;
	else
	{
		if(dp[i][sum] != -2) return;
		DP(i + 1, sum), DP(i + 1, sum + s[i]);
		dp[i][sum] = 0;
	}
}

class NumbersChallenge {
public:
	int MinNumber( vector <int> S )
	{
		int sum = 0; n = S.size(), s = S;
		rep(i, n) sum += s[i];
		rep(i, n + 1) rep(j, 2000009) dp[i][j] = -2; 
		DP(0, 0);
		rep(i, sum) if(dp[n][i] == -2) return i;
		return sum + 1;
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
			int S[]                   = {5, 1, 2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {2, 1, 4};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {2, 1, 2, 7};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
			int expected__            = 1092;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int S[]                   = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
			int expected__            = 56523;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int S[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int S[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int S[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
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
