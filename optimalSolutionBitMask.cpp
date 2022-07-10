#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;


int main()
{
    
    int prod,day;
    cin>>prod>>day;
    vector<vector<int>> dp((1<<prod), vector<int>(day, 1e8));
    // dp2.resize(n+1,vector<int>(p+1,-1));

    int price[prod][day];
	
	for(int p=0;p<prod;p++){
		for (int d = 0; d < day; d++)
		{
			cin>>price[p][d];
		}
	}
    //base
    // dp[0][0]=0;
    for(int d=0;d<day;d++){
    	dp[0][d]=0;
    }

    for(int p=0;p<prod;p++){
    	dp[(1<<p)][0]=price[p][0];
    }

    for(int mask=0;mask < (1<<prod);mask++){
    	for (int d = 1; d < day; d++)
		{
			//exclude dth 
			dp[mask][d]=dp[mask][d-1];

			//include dth
			for (int x = 0; x < prod; x++)
			{	
				//checking xth bit is set
				if((mask>>x)&1){
					dp[mask][d]=min(dp[mask][d],(dp[mask^(1<<x)][d-1]+price[x][d]));
				}
			}
		}
    }
	
	
    cout<<"Optimal Minimal Total Price: "<<dp[(1<<prod)-1][day-1]<<endl;

 
    return 0;
}


// input:
// 3 8
// 6 9 5 2 8 9 1 6
// 8 2 6 2 7 5 7 2
// 5 3 9 7 3 5 1 4
// output:
// Optimal Minimal Total Price: 5

