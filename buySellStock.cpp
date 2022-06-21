#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int dp[10001][2][1001];

int maxProfit(vector<int> price,bool buy,int k,int day){

	if(day==price.size() or k<=0) return 0;
	if(dp[day][buy][k]!=-1) return dp[day][buy][k];
	
	//max next
	int ans=maxProfit(price,buy,k,day+1);

	//buy current
	if(buy){
		ans=max(ans,-price[day]+maxProfit(price,false,k,day+1));
	}
	else //sell current
	{
		ans=max(ans,price[day]+maxProfit(price,true,k-1,day+1));
	}

	

	return dp[day][buy][k]=ans;

}

int main()
{
    
    int k,p;
    cin>>k;

    vector<int> price;

    while(cin>>p){
    	price.push_back(p);
    }

    memset(dp,-1,sizeof(dp));

    cout<<maxProfit(price,true,k,0);

    
    
    //solve();

    cout<<endl;
    return 0;
}


// input:
// 2
// 2 4 1
// output:
// 2

// input:
// 2
// 3 2 6 5 0 3
// output:
// 7