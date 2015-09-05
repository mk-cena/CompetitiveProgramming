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

int wiresToAdd;
bool visited1[500], visited2[500], gridConnection[500], network[500];
vector <string> wires;
priority_queue<pair<int, int> > pq;
vector<int> gridConnections;

class AddElectricalWires {
public:
	
	int dfs1(int node)
	{
		int count = 0;
		if(!visited1[node])
		{
			visited1[node] = true;
			rep(i, wires[node].size())
				if(wires[node][i] == '1')
					count += dfs1(i);
			count ++;
		}
		return count;
	}

	bool dfs2(int root, int node)
	{
		bool flag = true;

		if(!visited2[node])
		{
			visited2[node] = true;
			rep(i, wires[node].size())
			{
				if(wires[node][i] == '0') continue;
				if(gridConnection[i] && i != root) return false;
				else flag &= dfs2(root, i);
			}

		}
		return flag;
	}

   int maxNewWires(vector <string> _wires, vector <int> _gridConnections) 
   {
   		wires = _wires, wiresToAdd = 0, gridConnections = _gridConnections, memclr(gridConnection);

	   	rep(i, gridConnections.size())
	   	{
	   		memclr(visited1);
	   		gridConnection[gridConnections[i]] = true;
	   		int count = dfs1(gridConnections[i]);	
	   		pq.push(pair<int, int> (count, gridConnections[i]));
	   	}
	   	while(!pq.empty())
	   	{
	   		int root = pq.top().second; pq.pop();
	   		memclr(network), network[root] = true;
	   		rep(i, wires.size())
	   		{
	   			if(gridConnection[i]) continue;
	   			memclr(visited2);
				if(dfs2(root, i)) network[i] = true;
	   		}
   			rep(i, wires.size())
			{
				if(!network[i]) continue;
				rep(l, wires[i].size())
					if(network[l] && wires[i][l] == '0' && i != l) wiresToAdd++, wires[l][i] = wires[i][l] = '1';
			}   		
   		}
   		return wiresToAdd;
   }
};


// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
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
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string wires[]            = {"01100000", "10100000", "11000000", "00001000", "00010000", "00000010", "00000100", "00000000"};
			int gridConnections[]     = {0,3};
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string wires[]            = {"000","000","000"};
			int gridConnections[]     = {0,1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string wires[]            = {"01","10"};
			int gridConnections[]     = {0};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string wires[]            = {"00000","00000","00000","00000","00000"};
			int gridConnections[]     = {0,1,2,3,4};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string wires[]            = {"01000","10100","01010","00100","00000"};
			int gridConnections[]     = {2,4};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string wires[]            = ;
			int gridConnections[]     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string wires[]            = ;
			int gridConnections[]     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string wires[]            = ;
			int gridConnections[]     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AddElectricalWires().maxNewWires(vector <string>(wires, wires + (sizeof wires / sizeof wires[0])), vector <int>(gridConnections, gridConnections + (sizeof gridConnections / sizeof gridConnections[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
