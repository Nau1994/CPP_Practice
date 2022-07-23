#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int t;
int s[4][2]={{-2,1},
{-2,-1},
{1,-2},
{-1,-2}};
map<pair<int,int>, int> dp;

bool giveNext(int x,int y){
	//base
	if(x>15 or y>15 or x<1 or y<1) return true;
	if(dp.count({x,y})) return dp[{x,y}];

	bool ans=true;
	for(auto i:s){
		ans &= giveNext(x+i[0],y+i[1]);
	}

 return (dp[{x,y}]=!ans);
}

int main()
{
    
    
    cin>>t;
    while(t--){
    	int x,y;
    	cin>>x>>y;
    	if(giveNext(x,y)){
    		cout<<"First"<<endl;
    	}else{
    		cout<<"Second"<<endl;
    	}
    }
    
    cout<<endl;
}

// input:
// 3
// 5 2
// 5 3
// 8 8
// output:
// Second
// First
// First
