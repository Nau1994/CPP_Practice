#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;


int main()
{
    
    int s;
    cin>>s;
    int n;
    cin>> n;
    int value[n],weight[n];
    for (int i=0;i<n;i++){
    	cin>>value[i];
    	cin>>weight[i];
    }

//recursive
    // cout<<knapsacRec(value,weight,s,n)<<endl;
    


    //Tabulation DP
        int dp[n+1][s+1]={0};
    for(int i=0;i<=s;i++){
    dp[0][i]=0;
    }

    //suffix subset further can be optimized to 2-DP or 1-DP
    for(int i=1;i<=n;i++){
    	for(int j=s;j>=1;j--){
    		if (j-value[i-1] >= 0){
    		dp[i][j]=max(dp[i-1][j-value[i-1]]+weight[i-1],dp[i-1][j]);
    	}
        else{
            dp[i][j]=dp[i-1][j];
        }
    	}
    }
    cout<<"Suffix :Answer "<<dp[n][s]<<endl;
    cout<<"Suffix DP Printing"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    //prefix subset further can NOT be optimized to 2-DP or 1-DP
    for(int i=0;i<=s;i++){
    dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if (j-value[i-1] >= 0){
            dp[i][j]=max(dp[i-1][j-value[i-1]]+weight[i-1],dp[i-1][j]);
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
        }
    }

    cout<<"Prefix :Answer "<<dp[n][s]<<endl;
    cout<<"Prefix DP Printing"<<endl;
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=s;j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }

    cout<<endl;
    return 0;
}


// input:
// 4 5
// 1 8
// 2 4
// 3 0
// 2 5
// 2 3
// output:
// Suffix :Answer 13
// Suffix DP Printing
// 0 0 0 0 0 
// 0 8 8 8 8 
// 0 8 8 12 12 
// 0 8 8 12 12 
// 0 8 8 13 13 
// 0 8 8 13 13 
// Prefix :Answer 13
// Prefix DP Printing
// 0 0 0 0 0 
// 0 8 8 8 8 
// 0 8 8 12 12 
// 0 8 8 12 12 
// 0 8 8 13 13 
// 0 8 8 13 13 



// input:
// 4 3
// 3 30
// 2 15
// 2 18
// output:
// Suffix :Answer 33
// Suffix DP Printing
// 0 0 0 0 0 
// 0 0 0 30 30 
// 0 0 15 30 30 
// 0 0 18 30 33 
// Prefix :Answer 33
// Prefix DP Printing
// 0 0 0 0 0 
// 0 0 0 30 30 
// 0 0 15 30 30 
// 0 0 18 30 33 

