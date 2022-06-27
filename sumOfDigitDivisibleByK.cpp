#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
string s1,s2;
int dp[90][90][2][2][10];
int k;


int sumOfDigitDp(int sum_digit,int sum,bool first,bool last,int index){
	//base
	if(index==s2.size()) {
		if(sum==0 and sum_digit==0) return 1;
		else return 0;
	}

	//dp
	if(dp[sum_digit][sum][first][last][index]!=-1) return dp[sum_digit][sum][first][last][index];

	//from
	int from=first?(s1[index]-'0'):0;
	//till
	int till=last?(s2[index]-'0'):9;
	
	//rec
	int ans=0;
	
	for(int i=from;i<=till;i++){
		ans +=sumOfDigitDp((sum_digit+i)%k,(sum*10+i)%k,first && (i==from),last && (i==till),index+1);
		
		
	}

	return dp[sum_digit][sum][first][last][index]=ans;
}

int main()
{
    
    
    cin>>s1>>s2>>k;

    int dif=s2.size()-s1.size();

    //make number of digit same
    for(int i=0;i<dif;i++){
    	s1='0'+s1;
    }

    memset(dp,-1,sizeof(dp));
    cout<<sumOfDigitDp(0,0,true,true,0);
    // cout<<divisibleCount;
    
    cout<<endl;
    return 0;
}

// input:
// 1 1000 4
// output:
// 64