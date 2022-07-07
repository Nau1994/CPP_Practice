#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string s;
	vector<vector<int>> memo;
	vector<int> memo1;
	vector<vector<int>> memo3;

	// memoising?
	// O(n*n)
	bool is_palindrome(int i, int j) {
		if (i >= j) return true;
		// if (i == j - 1) return (s[i] == s[j]);
		if (memo[i][j] != -1) return memo[i][j];
		return memo[i][j] = is_palindrome(i + 1, j - 1) && (s[i] == s[j]);
	}

	void prints(int i,int j){
		for(int k=i;k<=j;k++){
			cout<<s[k];
		}


	}

	// states O(n)
	int dp(int i) {
		
		if (i == s.size()) return 0;
		 // if(i==j) return 1;

		// if (memo3[i][j] != -1) return memo3[i][j];

		int ans = 0;
		// int ans = is_palindrome(i, j);
		
		
		// O(n)
		for (int k = i; k <= s.size()-1; k++) {
			
			// ans += dp(i, k)+dp(k + 1,j);

			ans += is_palindrome(i, k);

			
		}
		ans+=dp(i + 1);
		
		// return  memo3[i][j]=ans;
		return  ans;
	}

	// states O(n)
	int dp2(int index) {
		
		int ans = 0;
		
		// O(n)
		for (int i = index; i < s.size(); i++) {
			for(int j=i;j<s.size();j++){
				ans += is_palindrome(i, j);
			}
		}
		
		return  ans;
	}

	int substring(string s) {
		this->s = s;
		memo.resize(s.size(), vector<int>(s.size(), -1));
		memo1.resize(s.size(), -1);
		memo3.resize(s.size(), vector<int>(s.size(), -1));
		// cout<<dp2(0)<<endl;
		return dp(0) ;
	}
};

int main()
{
	

	string s;
	cin >> s;

	Solution H;
	cout << H.substring(s);



	return 0;
}

// input:aab
// output:1