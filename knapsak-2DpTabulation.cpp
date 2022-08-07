#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=101;
int n;int W;
int dp[N][100001],mW[N][100001];

int main()
{
    
    cin>> n;
    cin>>W;

    int value[n],weight[n];
    for (int i=0;i<n;i++){
        cin>>weight[i];
    	cin>>value[i];
    	
    }

    //Tabulation DP
     for(int i=0;i<=n;i++){
        for(int j=0;j<=100001;j++){
            mW[i][j]=INT_MAX;
        }
    }
    dp[0][0]=1;
    mW[0][0]=0;
  
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100001;j++){
            //not including
            if(dp[i-1][j]){
            dp[i][j]=dp[i-1][j];
            mW[i][j]=min(mW[i][j],mW[i-1][j]);
        }
        // including
            if(j-value[i]>=0 && dp[i-1][j-value[i]] && mW[i-1][j-value[i]]+weight[i]<=W ){
            dp[i][j]=dp[i-1][j-value[i]];
            mW[i][j]=min(mW[i][j],mW[i-1][j-value[i]]+weight[i]);
        }
        }
    }

    int ans=0;
    
    for(int j=0;j<100001;j++){
            if(dp[n][j]){ans=j;};
        }
    cout<<"Answer "<<ans<<endl;
    cout<<"Prefix DP Printing"<<endl;
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=ans;j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<"Prefix mW Printing"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=ans;j++){
            if(mW[i][j]==INT_MAX){
                cout<<"-"<<" ";
            }else{
              cout<<mW[i][j]<<" ";  
            }
            
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}


// constraint
// 1≤N.≤100
// 1≤W.≤10^9
// 1≤w(i)≤W.
// 1≤v(i)≤10^3

// Input: 
// N. W.
// w1 v1
// w2 v2
// .  .
// .  .
// wN vN

// input:
// 3 4
// 3 30
// 2 15
// 2 18

// output:
// Answer 33
// Prefix DP Printing
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 
// Prefix mW Printing
// 0 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 0 - - - - - - - - - - - - - - 2 - - - - - - - - - - - - - - - - - - 
// 0 - - - - - - - - - - - - - - 2 - - 2 - - - - - - - - - - - - - - 4 
// 0 - - - - - - - - - - - - - - 2 - - 2 - - - - - - - - - - - - - - 4 



