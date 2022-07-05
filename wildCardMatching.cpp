#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string s, p;
	vector<vector<int>> memo;
	bool wildCardMatch(int i, int j) {
		if ( j == p.size()) return i == s.size() ;
		if (i == s.size()) 
		{
			if(p[j] == '?') return false;
			else if(p[j] == '*' ) return wildCardMatch(i , j+1);
			else return false;
		}
		if (memo[i][j] != -1) return memo[i][j];

		bool ans = false;

		if (s[i] == p[j]) {
			ans |= wildCardMatch(i + 1, j + 1);
		}
		else if (p[j] == '?') {
				ans |= wildCardMatch(i + 1, j + 1);
		}
		else if (p[j] == '*') {	
			ans |= wildCardMatch(i, j + 1) | wildCardMatch(i + 1, j);
		}
		return memo[i][j] = ans;
	}
	bool isMatch(string ss, string pp) {
		this->s = ss;
		this->p = pp;
		memo.resize(ss.size() + 1, vector<int> (pp.size() + 1, -1));
		// 2d array structure filled with -1s
		return wildCardMatch(0, 0);
	}
};

int main()
{
	

	string s, p;
	cin >> s >> p;

	Solution H;
	cout << H.isMatch(s, p);

	return 0;
}


// input:
// abc
// *c
// output:
// 1

// input:
// abc
// *d
// output:
// 0

// input:
// abc
// ?c
// output:
// 0

// input:
// abc
// ?*
// output:
// 1