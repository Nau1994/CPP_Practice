#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
#include <unordered_set>

using namespace std;
#define int long long int


int countMinSwap(vector<int> a){
    int n=a.size();
    pair<int,int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first=a[i];
        ap[i].second=i;
    }
    sort(ap,ap+n);
    
    vector<int> visited(n,false);
    int ans=0;
    for (int i = 0; i < n; i++)
    {   
        int cycle=0;
        //if element is visited or inorder
        if(visited[i] or ap[i].second==i) continue;

        //if element not visited
       
            int node=i;
            while(!visited[node]){
                visited[node]=true;
                cout<<ap[node].first<<"-"<<ap[ap[node].second].first<<",";
                node=ap[node].second;
                cycle+=1;
              }  
         
        cout<<endl;
        ans+=(cycle-1);
        
    }
    return ans;
}

int32_t main()
{
    
    
    vector<int> a;
    
    int x;
    while(cin>>x)
    {   
    	a.push_back(x);
    }

    int ans =countMinSwap(a);
    cout<<"No of swap:"<<ans;
       
    cout<<endl;
}


//N 

// input:
// 3 5 1 7 2 9 6
// output:
// 1-3,3-1,
// 2-6,6-9,9-7,7-5,5-2,
// No of swap:5