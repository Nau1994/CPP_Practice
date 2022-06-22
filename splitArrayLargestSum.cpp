#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<vector<int>> dp;

int splitArrayLargestSum(vector<int> arr,int partition,int index){
	//base
	if(index==arr.size()){
		if(partition==0) return 0;
		else return 1e9;
	}

	if(partition<=0) return 1e9;

	if(dp[index][partition]!=-1) return dp[index][partition];

	//rec
	int ans=1e9;
	int sum=0;
	for(int i=index;i<arr.size();i++){
		sum+=arr[i];
		ans=min(ans,max(sum,splitArrayLargestSum(arr,partition-1,i+1)));
	}

	return dp[index][partition]=ans;

}

int main()
{
    
    int partition,ar;
    cin>>partition;

    vector<int> arr;
    while(cin>>ar){
    	arr.push_back(ar);
    }

    dp.resize(arr.size()+1,vector<int>(partition+1,-1));
    cout<<splitArrayLargestSum(arr,partition,0)<<endl;

    

    cout<<endl;
    return 0;
}


// input:
// 2
// 7 2 5 10 8
// output:
// 18

// input:
// 2
// 3 2 3 4 5
// output:
// 9

// input:
// 3
// 1 4 4
// output:
// 4