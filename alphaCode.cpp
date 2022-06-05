#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> dp;

int alphaCode(string code){

if ((code.at(0)-'0')==0){return 0;}
    else dp[0]=1;

    if(stoi(code.substr(0,2))>26 or stoi(code.substr(0,2))<10){
    	dp[1]=1;
    }else{
    	dp[1]=2;
    }
    //solve();

    for (int i=2;i<code.length();i++){
    	if(stoi(code.substr(i-1,2))>26 or stoi(code.substr(i-1,2))<10)
    	{
    	dp[i]=dp[i-1];
    	}else{
    	dp[i]=dp[i-1]+dp[i-2];
    	}
    	
    }

    return dp[code.length()-1];
}

int main()
{
    int testCase;
    cin>>testCase;
    for (int test=0;test<testCase;test++){
    	string code;
    	int result=0;
    	cin>>code;
    	dp.resize(code.length(),0);
    	result=alphaCode(code);
    	if (result) cout<<result<<endl;

    	//dp printing
    	// cout<<"DP :";
    	// for(auto i: dp){
    	// cout<<i<<" ";
    	// }
    	// cout<<endl;
    }
    
    
    
    return 0;
}



// input:
// 5
// 25114
// 1111111111
// 33333333
// 01111
// 0

// output:
// 6
// 89
// 1
