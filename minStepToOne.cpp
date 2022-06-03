#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> dp;

int main()
{
    
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    
    dp[1]=0;
 
    for (int i=2;i<=n;i++){
        
        if ((i%2==0 and dp[i/2]!=-1) and (i%3==0 and dp[i/3]!=-1)){
            dp[i]=min({dp[i/2],dp[i/3],dp[i-1]})+1;
        }
        else if (i%3==0 and dp[i/3]!=-1) {
        dp[i]=min({dp[i/3],dp[i-1]})+1;
        }
        else if (i%2==0 and dp[i/2]!=-1) {
           dp[i]=min({dp[i/2],dp[i-1]})+1; 
        }
        else{
            dp[i]=dp[i-1]+1;
        }

    }

    cout<<dp[n]<<endl;;
    //dp printing
    for(auto i: dp){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}


// input:10
// output:3