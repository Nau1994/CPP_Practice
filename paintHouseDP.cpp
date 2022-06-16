#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	int noHouse,noColour;
	cin >> noHouse >> noColour;
	int cost[noColour][noHouse];

	for (int i = 0; i < noColour; i++) {
		for (int j = 0; j < noHouse; j++) {
		cin >> cost[i][j];
		}
	}
	
	
	int dp[noHouse][2];
	int houseColour;
	memset(dp,0,sizeof(dp));
	dp[0][0]=cost[0][0];
	dp[0][1]=0;

	
	


	for (int colour = 0; colour < noColour; colour++) {
			if(min(dp[0][0],cost[colour][0])==cost[colour][0]){
				dp[0][0]=cost[colour][0];
				dp[0][1]=colour;
			}
		}

	for (int house = 1; house < noHouse; house++) {
		dp[house][0]=INT_MAX; //initialize

		for (int colour = 0; colour < noColour; colour++) {
			if((dp[house-1][1] != colour) and (min(dp[house-1][0]+cost[colour][house],dp[house][0])==dp[house-1][0]+cost[colour][house])){
				dp[house][0]=dp[house-1][0]+cost[colour][house];
				dp[house][1]=colour;
			}
		}
		
		}



	cout<<"DP printing : "<<endl;
		for (int i = 0; i < noHouse; i++) {
		for (int j = 0; j < 2; j++) {
		cout << dp[i][j]<<" ";
		}
		cout<<endl;
	}

		cout<<"Answer:"<<dp[noHouse-1][0];


	return 0;
}

// input:
// 3 3
// 14 11 14
// 2 14 3
// 11 5 10
// output:
// DP printing : 
// 2 1 
// 7 2 
// 10 1 
// Answer:10


// input:
// 3 3
// 14 11 14
// 2 5 3
// 11 14 10
// output:
// DP printing : 
// 2 1 
// 13 0 
// 16 1 
// Answer:16