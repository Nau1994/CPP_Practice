#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=3000;
string n,m;
int dp[N][N];

int32_t give_lcs_prefix(int i,int j){
	//base
	if(i==n.size() or j==m.size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=0;
	//rec
	if (n[i]==m[j])
		ans=1+give_lcs_prefix(i+1,j+1);
	else
		ans=max({give_lcs_prefix(i,j+1),give_lcs_prefix(i+1,j)});
	
	return dp[i][j]=ans;
}

void trace_back_prefix(int i,int j){
	if(i==n.size() or j==m.size()) return;
	//rec
	if (n[i]==m[j])
		{
		cout<<n[i];
		trace_back_prefix(i+1,j+1);
		
		}
	else
		if(give_lcs_prefix(i,j)==give_lcs_prefix(i+1,j)){
			trace_back_prefix(i+1,j);
		}
		else {
			trace_back_prefix(i,j+1);
		}
		
	}

int32_t give_lcs(int i,int j){
	//base
	if(i<0 or j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=0;
	//rec
	if (n[i]==m[j])
		ans=1+give_lcs(i-1,j-1);
	else
		ans=max(give_lcs(i,j-1),give_lcs(i-1,j));
	
	return dp[i][j]=ans;
}

void trace_back(int i,int j){
	if(i<0 or j<0) return;
	
	
	//rec
	if (n[i]==m[j])
		{
		trace_back(i-1,j-1);
		cout<<n[i];
		}
	else
		if(give_lcs(i,j)==give_lcs(i-1,j)){
			trace_back(i-1,j);
		}
		else {
			trace_back(i,j-1);
		}
		
	}

int main()
{
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    // cout<<give_lcs(n.size()-1,m.size()-1)<<endl;
    // trace_back(n.size()-1,m.size()-1);
    cout<<give_lcs_prefix(0,0)<<endl;
    trace_back_prefix(0,0);
    cout<<endl;
}

// input:
// axyb
// abyxb

// output:
// 3
// ayb