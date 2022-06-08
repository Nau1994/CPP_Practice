#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	int sum, n;
	cin >> sum >> n;

	int a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// O(sum)
	bool dp[sum + 1];

	// one row dp[j]

	dp[0] = true;

	for (int j = 1; j <= sum; j++) {
		dp[j] = false;
	}

	// O(n*sum)
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= 0; j--) {

			if (j - a[i] >= 0) {
				dp[j] |= dp[j - a[i]];
			}

		}

	}

	cout << dp[sum]<<endl;
for (int j = 0; j <= sum; j++) {
			cout << dp[j] << " ";
		}

	return 0;
}