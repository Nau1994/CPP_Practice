#include<bits/stdc++.h>
#define int long long int

using namespace std;

int memo[1000];

// O(n*n)
int countWaysOrdered(int n) {
	if (n == 0) return 1;
	if (memo[n] != -1) return memo[n];
	int ans = 0;

	// for (i....n)
	for (int i = 1; i <= n; i++) {
		ans += countWaysOrdered(n - i);
	}

	return memo[n] = ans;
}

int32_t main() {

	int n;
	cin >> n;

	// top down approach
	memset(memo, -1, sizeof(memo));

	cout <<"O(n*n)-Approach: "<< countWaysOrdered(n) << '\n';

	// bottom up approach
	// O(n)
	int sum = 0;
	int dp[n + 1];

	for (int i = 1; i <= n; i++) {
		dp[i] = sum + 1;
		sum += dp[i];
	}

	cout <<"O(n)-Approach: "<< dp[n] << '\n';

	// 2^(n-1)
	// O(1)
	cout <<"O(1)-Approach: "<<pow(2, n - 1) << '\n';



}

// input:5
// output:
// O(n*n)-Approach: 16
// O(n)-Approach: 16
// O(1)-Approach: 16