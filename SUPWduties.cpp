#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> dp;

int SUPWduties(int duties[],int i,int n){
   //base
	dp[n]=0;
	dp[n-1]=0;
	dp[n-2]=0;

	if(n-3<i) {return 0;}
	
   if(dp[i] != -1){ return dp[i];}
   

   //rec
   int minimum=min(duties[i]+SUPWduties(duties,i+1,n),min(duties[i+1]+SUPWduties(duties,i+2,n),duties[i+2]+SUPWduties(duties,i+3,n)));
  
   
   if (dp[i]>minimum or dp[i]==-1) dp[i]=minimum;

   return dp[i];
}

int SUPWdutiesTabular(int duties[],int n){
   //base
	dp[n]=0;
	dp[n-1]=0;
	dp[n-2]=0;
   

   //rec
   for(int i=n-3;i>=0;i--){
   	dp[i]=min(duties[i]+dp[i+1],min(duties[i+1]+dp[i+2],duties[i+2]+dp[i+3]));
   }

   return dp[0];
}

int main()
{
    
    int n;
    cin>>n;
    int duties[n];
    dp.resize(n+1,-1);
    for (int i=0;i<n;i++){
    	cin>>duties[i];
    }

    //memoisation
    cout<<SUPWduties(duties,0,n)<<endl;

    //tabular
    // cout<<SUPWdutiesTabular(duties,n)<<endl;

    //dp printing
    for(auto i: dp){
    	cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}



// input:
// 10
// 3 2 1 1 2 3 1 3 2 1
// output:4

// input:
// 5
// 2 2 3 2 2
// output:3

// input:
// 8
// 3 2 3 2 3 5 1 3
// output:5