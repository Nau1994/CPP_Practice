#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>


#define int long long int

using namespace std;

int32_t main()
{
    
    int h,w,mode=1e9+7;
    cin>>h>>w;
    string s[h];
    int dp[h][w];
    
    for (int i = 0; i < h; i++)
    {
    	cin>>s[i];
    }

    for (int i = 0; i < h; i++)
    {
    	for (int j = 0; j < w; j++)
    {	
    	if(i==0 && j==0) dp[i][j]=1;
    	else if(i==0) dp[i][j]=dp[i][j-1];
    	else if(j==0) dp[i][j]=dp[i-1][j];
    	
    	else dp[i][j]=dp[i-1][j]+dp[i][j-1];
    	
    	if(s[i][j]=='#') dp[i][j]=0;
    	dp[i][j] = dp[i][j]%mode;
    }
    }

    cout<<dp[h-1][w-1];
    cout<<endl;
    return 0;
}

// input:
// 5 2
// ..
// #.
// ..
// .#
// ..
// output:0

// input:
// 5 5
// ..#..
// .....
// #...#
// .....
// ..#..
// output:24
