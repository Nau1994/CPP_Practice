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
        int dp[n+1][s+1];

        memset(dp,0,sizeof(dp));
    

    

    //prefix subset further can NOT be optimized to 2-DP or 1-DP
    for(int i=0;i<=s;i++){
    dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if (j-value[i-1] >= 0){
            dp[i][j]=max(dp[i][j-value[i-1]]+weight[i-1],dp[i-1][j]);
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
// Prefix :Answer 36
// Prefix DP Printing
// 0 0 0 0 0 
// 0 0 0 30 30 
// 0 0 15 30 30 
// 0 0 18 30 36 



// input:
// 4 3
// 3 30
// 2 15
// 2 18
// output:
// Prefix :Answer 32
// Prefix DP Printing
// 0 0 0 0 0 
// 0 8 16 24 32 
// 0 8 16 24 32 
// 0 8 16 24 32 
// 0 8 16 24 32 
// 0 8 16 24 32 

