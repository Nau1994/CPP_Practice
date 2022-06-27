#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;


int main()
{
    
    int n;
    cin>>n;

    int sequnes[n];
    map<int,int[2]> dp;

    for(int i=0;i<n;i++){
    	cin>>sequnes[i];
    	dp[sequnes[i]][0]=dp[sequnes[i]-1][0]+1;
    	if(dp[sequnes[i]-1][1]==0) dp[sequnes[i]][1]=i;
    	else dp[sequnes[i]][1]=dp[sequnes[i]-1][1];
    }

    int start_index,max_seq=0;
    for(auto x:dp){
    	if(max(max_seq,x.second[0])==x.second[0]){
    		max_seq=max(max_seq,x.second[0]);
    		start_index=x.second[1];
    	}
    }

   
    
    cout<<"Sequnce length : "<<max_seq<<endl;
    cout<<"Sequnce Indexes : "<<start_index;
    for(int i=start_index+1;i<n;i++){

    	if (sequnes[start_index]+1==sequnes[i]){
    		cout<<" "<<i;
    		start_index=i;
    	}
    }


    cout<<endl;
    return 0;
}


// input:
// 7
// 3 3 4 7 5 6 8
// output:
// Sequnce length : 4
// Sequnce Indexes : 1 2 4 5