#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

#define int long long int
const int N=400;
int n,a[N],pref[N],dp[N][N];

int sum(int l,int r){

	return pref[r]-((l==0)?0:pref[l-1]);
}

int slime(int l,int r)
{
	if (l==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	int ans=1e18;
	for (int i = l; i < r; i++)
	{
		ans=min(ans,slime(l,i)+slime(i+1,r)+sum(l,r));
	}
	// ans+=sum(l,r);
	return dp[l][r]=ans;
}

int32_t main()
{
    
    cin>>n;
    for (int i = 0; i < n; i++)
    {
    	cin>>a[i];
    	pref[i]=a[i];
    	if(i) pref[i]+=pref[i-1];
    }

    memset(dp,-1,sizeof(dp));
    // for (int i = 0; i < n; i++)
    // {
    // 	cout<<pref[i]<<" ";
    // }

    cout<<slime(0,n-1);
   
    
}