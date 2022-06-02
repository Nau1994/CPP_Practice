#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

vector<int> dp; 

int countOfSetBit(int n){
 if(dp[n]!=-1){return dp[n];}
 return dp[n]= countOfSetBit(n/2)+countOfSetBit(n%2);
}

int main()
{
    
    int n,count=0;
    cin>>n;
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for (auto i=0;i<n;i++ ){
    	count+=countOfSetBit(n);
    }
    cout<<count;
    cout<<endl;
    return 0;
}