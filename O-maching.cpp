#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

#define int long long int
const int N=21;
int n,a[N][N],dp[N][(1<<N)],mod=1000000007;

int matching(int m,int w){

	if(m==n) return 1;
	if(dp[m][w]!=-1) return dp[m][w];
	int ans=0;
	for (int x = 0; x < n; x++)
	{
		if((w>>x)&1 and a[m][x]==1){
			ans+=matching(m+1,w^(1<<x));
			ans%=mod;
		}
	}

	return dp[m][w]=ans;
}

int32_t main()
{
    cin>>n;
 	for (int i = 0; i < n; i++)
 	   {
 	   	for (int j = 0; j < n; j++)
 	   {
 	   	cin>>a[i][j];
 	   }  
 	   } 

 	memset(dp,-1,sizeof(dp));
 	cout<<matching(0,(1<<n)-1);
    cout<<endl;
}

// input:
// 3
// 0 1 1
// 1 0 1
// 1 1 1
// output:
// 3

// input:
// 21
// 0 0 0 0 0 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1
// 1 1 1 0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 0
// 0 0 1 1 1 1 0 1 1 0 0 1 0 0 1 1 0 0 0 1 1
// 0 1 1 0 1 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 0
// 1 1 0 0 1 0 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
// 0 1 1 0 1 1 1 0 1 1 1 0 0 0 1 1 1 1 0 0 1
// 0 1 0 0 0 1 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0
// 0 0 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 1 1 1 1
// 0 0 1 0 0 1 0 0 1 0 1 1 0 0 1 0 1 0 1 1 1
// 0 0 0 0 1 1 0 0 1 1 1 0 0 0 0 1 1 0 0 0 1
// 0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 1 1 0 1 1 0
// 0 0 1 0 0 1 1 1 1 0 1 1 0 1 1 1 0 0 0 0 1
// 0 1 1 0 0 1 1 1 1 0 0 0 1 0 1 1 0 1 0 1 1
// 1 1 1 1 1 0 0 0 0 1 0 0 1 1 0 1 1 1 0 0 1
// 0 0 0 1 1 0 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1
// 1 0 1 1 0 1 0 1 0 0 1 0 0 1 1 0 1 0 1 1 0
// 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 1 0 0 1
// 0 0 0 1 0 0 1 1 0 1 0 1 0 1 1 0 0 1 1 0 1
// 0 0 0 0 1 1 1 0 1 0 1 1 1 0 1 1 0 0 1 1 0
// 1 1 0 1 1 0 0 1 1 0 1 1 0 1 1 1 1 1 0 1 0
// 1 0 0 1 1 0 1 1 1 1 1 0 1 0 1 1 0 0 0 0 0
// output:
// 102515160