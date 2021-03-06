#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> arr;
vector<vector<int>> results;
vector<int> res;
vector<vector<int>> dp;

//give subset possible or not and when element can repeat
bool subSetSumResultWithRepeatElement(int index,int sum){
	
//base
	if (index==-1){  if (sum==0){
		results.push_back(res);
		
		return true;
	}
	else return false; }

	if(dp[index][sum]!=-1){
		
		return dp[index][sum];
	} 

bool ans=false;
//include repeat index

if (sum>=arr[index]){
	res.push_back(arr[index]);
ans |= subSetSumResultWithRepeatElement(index,sum-arr[index]);
res.pop_back();
}
//include index

// if (sum>=arr[index]){
// 	res.push_back(arr[index]);
// ans |= subSetSumResultWithRepeatElement(index-1,sum-arr[index]);
// res.pop_back();
// }

//exclude index

ans |= subSetSumResultWithRepeatElement(index-1,sum);

return dp[index][sum]=ans;
}

//give subset possible or not and subset value(results vector) as well
bool subSetSumResult(int index,int sum){
//base
	if (index==-1){  if (sum==0){
		results.push_back(res);
		return true;
	}
	else return false; }

	if(dp[index][sum]!=-1) return dp[index][sum];

bool ans=false;
//include index
if (sum>=arr[index]){
	res.push_back(arr[index]);
ans |= subSetSumResult(index-1,sum-arr[index]);
res.pop_back();
}
//exclude index
ans |= subSetSumResult(index-1,sum);

return dp[index][sum]=ans;
}


//give subset possible or not
bool subSetSum(int index,int sum){
//base
	if (index==-1){ return sum==0 ;}

bool ans=false;

//include index
if (sum>=arr[index]){
ans |= subSetSum(index-1,sum-arr[index]);
}
//exclude index
ans |= subSetSum(index-1,sum);

return ans;
}

int main()
{
    
    int sum;
    cin>>sum;
    int elemnt;
    while(cin>>elemnt){
    	arr.push_back(elemnt);
    }
    
    //dp initialize
    dp.resize(arr.size(),vector<int>(sum+1,-1));
    
    // cout<<subSetSum(arr.size()-1,sum);


    // cout<<subSetSumResult(arr.size()-1,sum);
    // cout<<endl;
    // //results print
    // for(auto res:results){
    // 	for(auto r:res){
    // 		cout<<r<<" ";
    // 	}
    // 	cout<<endl;
    // }

    cout<<subSetSumResultWithRepeatElement(arr.size()-1,sum);
    cout<<endl;
    //results print
    for(auto res:results){
    	for(auto r:res){
    		cout<<r<<" ";
    	}
    	cout<<endl;
    }


   
    cout<<endl;
    return 0;
}


// input:
// 9
// 2 7 4 5 19
// output:
// 1
// 5 4 
// 7 2 