#include<bits/stdc++.h>
// #include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
#define int long long int

vector<vector<int>> tripletSum(int *a,int n,int sum){
	vector<vector<int>> result;
    sort(a,a+n);
	for (int i = 0; i <= n-3; i++)
    {   
        int s=i+1;
        int e=n-1;
    	while(s<e){
            int pairsum=a[s]+a[e];

            if(pairsum==sum-a[i]){
                result.push_back({a[i],a[s],a[e]});
                e--;
                s++;
            }

            if(pairsum>sum-a[i]){
                e--;
            }

            if(pairsum<sum-a[i]){
                s++;
            }

            
        }
    }

	return result;
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

    for(auto pair:tripletSum(a,n,s)){
        for (auto x:pair)
        {
            cout<<x<<" ";
        }
    	cout<<endl;
    }
    cout<<endl;
}

//first sort --O(Nlog(N))
//pick one from array --O(N)
//perfor two pointer pairSum for finding rest two element --N(O)
//O(Nlog(N))+O(N*N) => O(N*N)


// input:
// 10 12
// 15 3 2 4 5 6 7 8 9 1
// output:
// 1 2 9 
// 1 3 8 
// 1 4 7 
// 1 5 6 
// 2 3 7 
// 2 4 6 
// 3 4 5 


