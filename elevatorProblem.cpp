#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int x,n;
vector<int> weight;

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

 //    vector<vector<int>> dp2(n + 1, vector<int>(p + 1, 0));
 //    // dp2.resize(n+1,vector<int>(p+1,-1));

 //    int dp3[n][p];
	// memset(dp3,0,sizeof(dp3));

	// map<int,map<int,vector<vector<int>>>> dp4;
	// //empty vector<vector<int>>()
	// // if(dp4.count(index) and dp4[index].count(sum)){} 


     cout<<"Minimum Ride: "<<elevatorProbBrutforce(0,{});

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