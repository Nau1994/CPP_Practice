#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

#define int long long int

const int N=100;
const int K=100001;
const int mod=1000000007;
int n,k,a[N];
int mem[N][K];

int noOfWay(int i,int k){
	//base
	
	if(i==0) if(a[i]>=k) return 1;
		else return 0;
	
	
	if(mem[i][k]!=-1) return mem[i][k];
	//rec
	int ans=0;
	for (int j = 0; j <= a[i]; j++)
	{	
		if(j<=k){
			ans+=noOfWay(i-1,k-j);
		}
		
	}
	return mem[i][k]=(ans%mod);
}

int noOfWayTabular(int n,int k){
	
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i <= n; i++)
	{
		
		for (int j = 0; j <= k; j++)
		{	
			for (int m = 0; m <= j; m++)
			{
			if(m<=a[i] ){
			dp[i][j]+=dp[i-1][j-m];
			}	
			}
		
		
		}
	}

	for (int i = 0; i <= n; i++)
	{
		
		for (int j = 0; j <= k; j++)
		{	
			
			cout<<dp[i][j]<<" ";
			
		}cout<<endl;
	}

	return dp[n][k];
}


int noOfWayTabular2(int n,int k){
	
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i <= n; i++)
	{
		int ans=0;
		for (int j = 0; j <= k; j++)
		{	
			
			
			if(j<=a[i]){
				
				dp[i][j]=ans+dp[i-1][j];
				ans=dp[i][j];
			}else{
				dp[i][j]=ans+dp[i-1][j]-dp[i-1][j-a[i]-1];
				ans=dp[i][j];
			}
			
			dp[i][j] =((dp[i][j]%mod)+mod)%mod;
			}
			
		}
	

	for (int i = 0; i <= n; i++)
	{
		
		for (int j = 0; j <= k; j++)
		{	
			
			cout<<dp[i][j]<<" ";
			
		}cout<<endl;
	}

	return dp[n][k]%mod;
}


int noOfWayTabular3(int n,int k){
	
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{	
			dp[i-1][j]+=dp[i-1][j-1];
		}
		for (int j = 0; j <= k; j++)
		{	
			
			dp[i][j]=dp[i-1][j];
			if(j>a[i]){
			dp[i][j]-=dp[i-1][j-a[i]-1];
			}
			dp[i][j] =((dp[i][j]%mod)+mod)%mod;	
		}
		
		}
	

	for (int i = 0; i <= n; i++)
	{
		
		for (int j = 0; j <= k; j++)
		{	
			
			cout<<dp[i][j]<<" ";
			
		}cout<<endl;
	}

	return dp[n][k];
}

int32_t main()
{
    
    
    cin>>n>>k;

    for (int i = 1; i <= n; i++)
    {
    	cin>>a[i];
    }

    cout<<"Recursive solution->>";
    memset(mem,-1,sizeof(mem));
    cout<<noOfWay(n,k);
    cout<<endl;

    cout<<"Tabular solution->>";
    cout<<noOfWayTabular(n,k);
    cout<<endl;

    cout<<"Tabular+PrefixSum solution->>";
    cout<<noOfWayTabular2(n,k);
    cout<<endl;

    cout<<"Tabular+PrefixSum solution->>";
    cout<<noOfWayTabular3(n,k);
    cout<<endl;
}

// input:
// 3 4
// 1 2 3
// output:
// Recursive solution->>5
// Tabular solution->>
// 1 0 0 0 0 
// 1 1 0 0 0 
// 1 2 2 1 0 
// 1 3 5 6 5 
// 5
// Tabular+PrefixSum solution->>
// 1 0 0 0 0 
// 1 1 0 0 0 
// 1 2 2 1 0 
// 1 3 5 6 5 
// 5
// Tabular+PrefixSum solution->>
// 1 1 1 1 1 
// 1 2 2 2 2 
// 1 3 5 6 6 
// 1 3 5 6 5 
// 5
