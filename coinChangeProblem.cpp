#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
vector<int> arr;


vector<vector<int>> dp;
map<int,map<int,vector<vector<int>>>> dp2;
// map<vector<int>,vector<vector<int>>> dp2;

//give subset possible or not and when element can uniq
vector<vector<int>> coinChangeProblem(int index,int sum){
    
//base
    if (index==-1){  return vector<vector<int>>(); }

    if(dp2.count(index) and dp2[index].count(sum)){
        
        return dp2[index][sum];
    } 

vector<vector<int>> res;
//include repeat index

if (sum>=arr[index]){
    
res = coinChangeProblem(index-1,sum-arr[index]);


if (res.empty()){
    if(sum==arr[index]){
        dp2[index][sum].push_back({arr[index]});
        }
    }
else{
    for (auto r:res)
    {
    r.insert(r.begin(),arr[index]);
    dp2[index][sum].push_back(r);

    }
    }
//dp2[index][sum].insert(dp2[index][sum].end(),res.begin(),res.end());
}



//exclude index

res = coinChangeProblem(index-1,sum);


if (res.empty()){
    if(sum==arr[index-1]){
        dp2[index][sum].push_back({arr[index]});
        }
    }
else {
    for (auto r:res)
    {
        if (sum>accumulate(r.begin(), r.end(), 0)){
    r.insert(r.begin(),arr[index]);}
    dp2[index][sum].push_back(r);

    }
    }

return dp2[index][sum];
}

//give all subset possible  when element can repeat
vector<vector<int>> coinChangeProblemRepeat(int index,int sum){
	
//base
	if (index==-1){  return vector<vector<int>>(); }

	if(dp2.count(index) and dp2[index].count(sum)){
		
		return dp2[index][sum];
	} 

vector<vector<int>> res;
//include repeat index

if (sum>=arr[index]){
	
res = coinChangeProblemRepeat(index,sum-arr[index]);


if (res.empty()){
    if(sum==arr[index]){
        dp2[index][sum].push_back({arr[index]});
        }
    }
else{
    for (auto r:res)
    {
    r.insert(r.begin(),arr[index]);
    dp2[index][sum].push_back(r);

    }
    }
//dp2[index][sum].insert(dp2[index][sum].end(),res.begin(),res.end());
}



//exclude index

res = coinChangeProblemRepeat(index-1,sum);


if (res.empty()){
    if(sum==arr[index-1]){
        dp2[index][sum].push_back({arr[index]});
        }
    }
else {
    for (auto r:res)
    {
        if (sum>accumulate(r.begin(), r.end(), 0)){
    r.insert(r.begin(),arr[index]);}
    dp2[index][sum].push_back(r);

    }
    }

return dp2[index][sum];
}


int main()
{
    
    int sum;
    cin>>sum;
    int elemnt;
    vector<vector<int>> results;

    while(cin>>elemnt){
    	arr.push_back(elemnt);
    }
    
    //dp initialize
    dp.resize(arr.size(),vector<int>(sum+1,-1));
    
    

    results=coinChangeProblemRepeat(arr.size()-1,sum);

    // results=coinChangeProblem(arr.size()-1,sum);
    
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


// with repeat:
// input:
// 12
// 2 7 4 5 19
// output:
// 5 5 2 
// 5 7 
// 4 4 4 
// 4 4 2 2 
// 4 2 2 2 2 
// 2 2 2 2 2 2 

// without repeat:
// input:
// 12
// 2 7 4 5 19
// output:
// 5 7 