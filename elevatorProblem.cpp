#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int x,n;
vector<int> weight;

int elevatorProbBitMak(pair<int,int> dp[]){
	dp[0]={1,0}; //first=ride,second=weight
	for(int mask=1;mask<(1<<n);mask++){
		dp[mask]={n,0};
		for(int y=0;y<n;y++){
			if((mask>>y)&1){
				int new_mask=mask^(1<<y);
				pair<int,int> temp;
				if(dp[new_mask].second+weight[y]<=x){
					temp.first=dp[new_mask].first;
					temp.second=dp[new_mask].second+weight[y];
				}
				else{
					temp.first=dp[new_mask].first+1;
					temp.second=weight[y];
				}
				dp[mask]=min(dp[mask],temp);
				//min will compare first then second
			}
			
		}
	}
	return dp[(1<<n)-1].first;
}

int givePartition(vector<int> st)
{
	int sum=0,ride=1;
	for(auto i:st){
		if(weight[i]+sum <= x){
			sum+=weight[i];
		}
		else{
			ride++;
			sum=weight[i];
		}
	}
	return ride;
}

int elevatorProbBrutforce(int element,vector<int> st){
	//base
	if(element==n){
		return givePartition(st);
	}
	//rec
	int ans=n;
	for(int i=0;i<n;i++){
		if(!(count(st.begin(), st.end(), i))){
			
			st.push_back(i);
			ans=min(ans,elevatorProbBrutforce(element+1,st));
			st.pop_back();
		}
	}
	return ans;
}

int main()
{
	
    cin>>x>>n;
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	weight.push_back(x);
    }


     // cout<<"Minimum Ride: "<<elevatorProbBrutforce(0,{});


    pair<int,int> dp[1<<n];
    cout<<"Minimum Ride: "<<elevatorProbBitMak(dp);


    //dp printing
    // for(auto i: weight){
    // 	cout<<i<<" ";
    // }
    cout<<endl;
    return 0;
}

// intput:
// 10 5
// 2
// 3
// 3
// 5
// 6
// output:
//Minimum Ride: 2