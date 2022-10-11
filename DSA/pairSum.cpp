#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
#include <unordered_set>

using namespace std;
#define int long long int

vector<int> pairSum(int *a,int n,int sum){
	unordered_set<int> st;
	for (int i = 0; i < n; i++)
    {
    	if(st.find(sum-a[i])!=st.end()){
    		return {a[i],sum-a[i]};
    	}
    	st.insert(a[i]);
    }

	return {};
}

int32_t main()
{
    
    int n,s;
    cin>>n>>s;
    int a[n];
    for (int i = 0; i < n; i++)
    {
    	cin>>a[i];
    }

    for(auto x:pairSum(a,n,s)){
    	cout<<x<<",";
    }
    cout<<endl;
}

//N*N --brutforce
//Nlog(N) --fisrt sort then searching
//N --using unordered_set