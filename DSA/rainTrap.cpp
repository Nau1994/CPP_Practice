#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
#include <unordered_set>

using namespace std;
#define int long long int


int rainTrap(vector<int> a){
    
    int result=0,n=a.size();
    int left[a.size()];
    int right[a.size()];

    //Left Max Right Max
    left[0]=a[0];
    right[n-1]=a[n-1];
    for (int i = 1; i < n; i++)
    {
        // longest=max(a[i],longest);
        left[i]=max(a[i],left[i-1]);
        right[n-1-i]=max(a[n-1-i],right[n-1-i+1]);
    }

    // longest=0;
    // for (int i = a.size()-1; i >= 0 ; i--)
    // {
    //     // longest=max(a[i],longest);
    //     right[i]=longest=max(a[i],longest);
    // }

    //calculat Trap
    for (int i = 0; i < a.size(); i++)
    {
        
        result+=min(left[i],right[i])-a[i];
    }
    

    return result;
}

int32_t main()
{
    
    
    vector<int> a;
    
    int x;
    while(cin>>x)
    {   
    	a.push_back(x);
    }

    cout<<rainTrap(a);
    cout<<endl;
}


//N 

// input:
// 0 1 0 2 1 0 1 3 2 1 2 1
// output:
// 6
