#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
#define int long long int
int n,m;
vector<int> s;
map<int, bool> dp;
bool giveNext(int n){
	if(dp.count(n)) return dp[n];
	for(int i:s){
		if((n%i==0) && (i%2==0)) return dp[n]=true;
		if((n%i==0) && (giveNext(n/i)==false)) return dp[n]=true;
	}

	return dp[n]=false;
}

int32_t main()
{
    

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
    	int x;
    	cin>>x;
    	s.push_back(x);
    }
    if(giveNext(n)){
    		cout<<"First"<<endl;
    	}else{
    		cout<<"Second"<<endl;
    	}
    
}