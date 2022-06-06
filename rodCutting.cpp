#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> dp;

int rodCuttingDP1(int rodPrice[],int n,int index){

//base
	if(n==0 or index==n) return 0;
	if(dp[n]!=-1) return dp[n];


	//rec
	return dp[n]=max({rodPrice[index]+rodCuttingDP1(rodPrice,n-(index+1),index),rodCuttingDP1(rodPrice,n,index+1) });
}

int rodCuttingDP2(int rodPrice[],int n){

//base
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];


	//rec
	//dp[n]=0;
	for (int i=0;i<n;i++ ){
	 dp[n]=max({dp[n],rodPrice[i]+rodCuttingDP2(rodPrice,n-i-1)});
	}

	return dp[n];
}


int main()
{
    
    int n;
    cin>>n;
    int rodPrice[n];
    dp.resize(n+1,-1);
    for (int i=0;i<n;i++){cin>>rodPrice[i];}
    
    //mu solution
    // cout<<rodCuttingDP1(rodPrice,n,0)<<endl;

    //instructor solution
    cout<<rodCuttingDP2(rodPrice,n)<<endl;

    //dp printing
    for(auto i: dp){
    	cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}


// input:
// 8
// 1 3 4 5 7 9 10 11
// output:
// 12

// input:
// 4
// 1 1 1 6
// output:
// 6