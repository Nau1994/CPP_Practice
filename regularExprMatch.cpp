#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string s, p;
	vector<vector<int>> memo;
	bool regularExprMatch(int i, int j) {

		if ( j == p.size()) return i == s.size() ;

		if (i == s.size()) 
		{
			if((p.size()-j <= 2) and (p[p.size()-1]=='*')) return true;
			else return false;
		}


		if (memo[i][j] != -1) return memo[i][j];

		bool ans = false;

		if (s[i] == p[j]) {
			ans |= regularExprMatch(i + 1, j + 1);
		}

		else if (p[j] == '.') {
				ans |= regularExprMatch(i + 1, j + 1);
		}
		else if (p[j] == '*') {	
			if(j==0) {
				ans |= regularExprMatch(i, j + 1);
			}
			else {

				 if(p[j-1]==s[i] or p[j-1]=='.'){ ans |= regularExprMatch(i, j + 1) | regularExprMatch(i + 1, j); }
				else if(p[j-1]!=s[i]) { ans |= regularExprMatch(i, j + 1); }
			}
		}
		else if (s[i] != p[j] and p[j+1]=='*'){
			ans |= regularExprMatch(i, j + 1);
		}
		
		// cout<<i<<":"<<s[i]<<" "<<j<<":"<<p[j]<<" "<<ans<<endl;
		return memo[i][j] = ans;
	}
	bool isMatch(string ss, string pp) {
		this->s = ss;
		this->p = pp;
		memo.resize(ss.size() + 1, vector<int> (pp.size() + 1, -1));
		// 2d array structure filled with -1s
		return regularExprMatch(0, 0);
	}
};

int main()
{
	

	string s, p;
	cin >> s >> p;

	// cout<<s.size()<<p.size();

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
// aaa
// aba*c*a
// output:
// 0

// input:
// aaa
// ab*a*c*a
// output:
// 1

// input:
// abc
// .*
// output:
// 1

// input:
// aaa
// *
// output:
// 0