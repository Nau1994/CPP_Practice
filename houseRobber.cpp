#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> dp;
//vector<int> dp2[2];
vector<vector<int>> dp2;


int houseRobber(vector<int> houseMoney,int n){
if(n>=houseMoney.size()) return 0;
if(dp[n]!=-1) return dp[n];

int i=n;
dp[n]=max({houseMoney[i]+houseRobber(houseMoney,i+2),houseRobber(houseMoney,i+1)});


return dp[n];
}

int houseRobberDP2(vector<int> houseMoney,int robbed,int house){
if(house>=houseMoney.size()) return 0;
if(dp2[robbed][house]!=-1) return dp2[robbed][house];

if (robbed==1){
	dp2[robbed][house]=houseMoney[house]+houseRobberDP2(houseMoney,0,house+1);
}
else{
	dp2[robbed][house]=max({houseRobberDP2(houseMoney,0,house+1),houseRobberDP2(houseMoney,1,house+1)});
}

return dp2[robbed][house];
}

int main()
{
    
    vector<int> houseMoney;
    int money;

    while(cin>> money){
    	houseMoney.push_back(money);
    }
    dp.resize(houseMoney.size()+1,-1);

    //solve 1-D dp
    cout<<houseRobber(houseMoney,0)<<endl;
	//dp printing
	cout<<"1-DP :"<<endl;
    for(auto i: dp){
    	cout<<i<<" ";
    }
    cout<<endl;

    //solve 2-D dp
    dp2.resize(2, vector<int>(houseMoney.size()+1,-1));

    cout<<max(houseRobberDP2(houseMoney,0,0),houseRobberDP2(houseMoney,1,0))<<endl;
    cout<<"2-DP :"<<endl;
    for(int i=0;i<2;i++){
    	for(auto j: dp2[i]){
    	cout<<j<<" ";
    	}
    cout<<endl;
    }
    return 0;
}

// input:1 2 1 3
// output:5

// input:1 2 3 1
// output:4

// input:2 7 9 3 1
// output:12