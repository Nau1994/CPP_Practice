#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
string s1,s2;
int dp[90][2][2][10];


int sumOfDigitDp(int sum,bool first,bool last,int index){
	//base
	if(index==s2.size()) return sum;

	//dp
	if(dp[sum][first][last][index]!=-1) return dp[sum][first][last][index];

	//from
	int from=first?s1[index]-'0':0;
	//till
	int till=last?s2[index]-'0':9;

	//rec
	int ans=0;
	for(int i=from;i<=till;i++){
		ans += sumOfDigitDp(sum+i,first &&(i==from),last && (i==till),index+1);
	}

	return dp[sum][first][last][index]=ans;
}

int main()
{
    
    
    cin>>s1>>s2;

    for(int i=0;i<s2.size()-s1.size();i++){
    	s1='0'+s1;
    }

    memset(dp,-1,sizeof(dp));
    cout<<sumOfDigitDp(0,true,true,0);

    
    cout<<endl;
    return 0;
}