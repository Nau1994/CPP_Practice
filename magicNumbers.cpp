#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>
#define int long long int

using namespace std;
string s1,s2;
int dp[2000][2][2][2000];
int d_magic,multiply,mod=1e9+7;


int sumOfDigitDp(int sum,bool first,bool last,int index){
	//base
	if(index==s2.size()) {
		if(sum==0) return 1;
		
	}

	//dp
	if(dp[sum][first][last][index]!=-1) return dp[sum][first][last][index];

	//from
	int from=first?(s1[index]-'0'):0;
	//till
	int till=last?(s2[index]-'0'):9;
	
	//rec
	int ans=0;
	
	for(int i=from;i<=till;i++){
		if(index%2==0 and i!=d_magic){
		ans +=sumOfDigitDp((sum*10+i)%multiply,first && (i==from),last && (i==till),index+1);
		
		}
		else if(index%2!=0 and i==d_magic){
		ans +=sumOfDigitDp((sum*10+i)%multiply,first && (i==from),last && (i==till),index+1);
		
		}
		
	}
	ans %=mod;
	return dp[sum][first][last][index]=ans;
}

int32_t main()
{
    
    
    cin>>multiply>>d_magic;
    cin>>s1>>s2;

    int dif=s2.size()-s1.size();

    //make number of digit same
    for(int i=0;i<dif;i++){
    	s1='0'+s1;
    }

    memset(dp,-1,sizeof(dp));
    cout<<sumOfDigitDp(0,true,true,0);
    // cout<<divisibleCount;
    
    cout<<endl;
    return 0;
}

// input:
// 1 1000 4
// output:
// 64