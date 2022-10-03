#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
#define int long long int

const int N=1e5+1,mod=1e9+7;
vector<int> gr[N];
int dp[N][2];

int colour(int curr,int white,int par){
	int &ans=dp[curr][white];
	if(ans!=-1) return ans;

	ans=1;
	for (auto child:gr[curr])
	{
		if(child!=par){
			if(white){
				ans *=colour(child,1,curr)+colour(child,0,curr);
			}else{
				ans *=colour(child,1,curr);
			}

			ans%=mod;
		}
	}
	return ans;
}

int32_t main()
{	int n;
    cin>>n;
    
    int x,y;
    while(cin>>x>>y){
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }

    memset(dp,-1,sizeof(dp));
    cout<<(colour(1,0,0)+colour(1,1,0))%mod;
    cout<<endl;
}

// input:
// 10
// 8 5
// 10 8
// 6 5
// 1 5
// 4 8
// 2 10
// 3 6
// 9 2
// 1 7
// output:
// 157