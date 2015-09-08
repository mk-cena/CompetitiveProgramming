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

#define INF 9223372036854775807LL

ll ans;
int len, a[20];

class LuckySum {
public:
	ll reverse(ll num)
	{
		ll tmp = 0, tmp2 = num;
		while(tmp2 > 0) tmp *= 10, tmp += tmp2 % 10, tmp2 /= 10;
		return tmp;
	}

	void dfs(int i, int terminate, int carry, ll sum)
	{
		if(i == -1 && carry == 0)
		{
			ans = min(ans, reverse(sum));
			return;
		}

		if(a[i] == 4 || a[i] == -1)
		{
			if(carry == 0)
			{
				if(len - i - 1 > 0) dfs(i - 1, 1, 0, sum * 10 + 4);
				if(!terminate) dfs(i - 1, 0, 1, sum * 10 + 4);
			}
		}

		if(a[i] == 7 || a[i] == -1)
		{
			if(carry == 0 && len - i - 1 > 0) dfs(i - 1, 1, 0, sum * 10 + 7);
		}

		if(a[i] == 5 || a[i] == -1)
		{
			if(carry == 1)
			{
				if(len - i - 1 > 0) dfs(i - 1, 1, 0, sum * 10 + 5);
				if(!terminate) dfs(i - 1, 0, 1, sum * 10 + 5);
			}
		}

		if(a[i] == 2 || a[i] == -1)
		{
			if(carry == 1 && !terminate) dfs(i - 1, 0, 1, sum * 10 + 2);
		}

		if(a[i] == 8 || a[i] == -1)
		{
			if(carry == 0 && !terminate) dfs(i - 1, 0, 0, sum * 10 + 8);
			else if(carry == 1 && len - i - 1 > 0) dfs(i - 1, 1, 0, sum * 10 + 8);
		}

		if(a[i] == 9 || a[i] == -1)
		{
			if(carry == 1 && !terminate) dfs(i - 1, 0, 0, sum * 10 + 9);
		}

		if(a[i] == 1 || a[i] == -1)
		{
			if(carry == 0 && !terminate) dfs(i - 1, 0, 1, sum * 10 + 1);
			else if(carry == 1 && i == 0) dfs(i - 1, 1, 0, sum * 10 + 1);
		}
	}
	
	long long construct(string note) 
   	{
	 	len = note.length();
	 	ans = INF;
	 	rep(i, len) a[i] = note[i] == '?'? -1:note[i] - '0';
		dfs(len - 1, 0, 0, 0);
		if(ans == INF) return -1;
		else return ans;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string note               = "?";
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string note               = "?1";
			long long expected__      = 11;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string note               = "4?8";
			long long expected__      = 448;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string note               = "2??";
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string note               = "??????????????";
			long long expected__      = 11888888888888LL;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string note               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string note               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string note               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LuckySum().construct(note);
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
