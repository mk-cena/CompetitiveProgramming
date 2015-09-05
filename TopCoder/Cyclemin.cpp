// Paste me into the FileEdit configuration dialog

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cyclemin {
public:

   string bestmod( string s, int k ) 
   {
	   	string mn = s,tmp;
   		for(int i=0;i<s.length();i++)
   		{
   			tmp = s;
   			for(int j=0,l = 0;j<s.length() && l<k;j++)
   				if(tmp[j] != 'a')
   					tmp[j] = 'a',l++;
   			mn = min(mn,tmp);
	   		s = s[s.length() - 1] + s.substr(0, s.length() - 1);
   		}
   		return mn;
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
		return 0;
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string s                  = "aba";
			int k                     = 1;
			string expected__         = "aaa";

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "aba";
			int k                     = 0;
			string expected__         = "aab";

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "bbb";
			int k                     = 2;
			string expected__         = "aab";

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "sgsgaw";
			int k                     = 1;
			string expected__         = "aasgsg";

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "abacaba";
			int k                     = 1;
			string expected__         = "aaaabac";

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "isgbiao";
			int k                     = 2;
			string expected__         = "aaaisgb";

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string s                  = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string s                  = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Cyclemin().bestmod(s, k);
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
