#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
#include <unordered_set>

using namespace std;
#define int long long int


pair<int,int> subArray(vector<int> a){
    
    pair<int,int> result={-1,-1};
    int n=a.size();
    int smallest=*max_element(a.begin(), a.end());
    int largest=*min_element(a.begin(), a.end());

    //get largest and smallest element that not in order
    for (int i = 0; i < n; i++)
    {
        if(i<n-1 && a[i]>a[i+1]){
            largest=max(largest,a[i]);
            
        }
        if(i>0 && a[i]<a[i-1]){
            smallest=min(smallest,a[i]);
            
        }
    }
    
    //position of smallest
    for (int i = 0; i < n; i++)
    {
        if(smallest<a[i]) {result.first=i; break;}
    }
    //position of largest
    for (int i = 0; i < n; i++)
    {
        if(largest>a[n-i-1]) {result.second=n-i-1; break;}
    }

    //check if array is reverse
    if(a[0]==*max_element(a.begin(), a.end()) && a[n-1]==*min_element(a.begin(), a.end())){
        cout<<a[0]<<a[n-1]<<endl;
        reverse(a.begin(), a.end());
        return subArray(a);
    }else{
       return result; 
    }


    
}

int32_t main()
{
    
    
    vector<int> a;
    
    int x;
    while(cin>>x)
    {   
    	a.push_back(x);
    }

    auto subarray1=subArray(a);
    cout<<subarray1.first<<" "<<subarray1.second;
    // reverse(a.begin(), a.end());
    // auto subarray2=subArray(a);
    // if(subarray1.second-subarray1.first < subarray2.second-subarray2.first)
    // {
    //     cout<<subarray1.first<<" "<<subarray1.second;
    // }else{
    //    if(subarray2.first!=-1 && subarray2.second!=-1)
    //    {cout<<a.size()-1-subarray2.second<<" "<<a.size()-subarray2.first-1; 
    //    }else{
    //     cout<<subarray2.first<<" "<<subarray2.second;
    //    }
    // }
    
    cout<<endl;
}


//N 

// input:
// 1 9 3 0 18 5 2 4 10 7 12 6
// output:
// 0 11

//if sorting required
// 1 2 0 4 3
// 1 3


//if sorting not required
//1 4 3 2 5
//-1 -1

//if sorting not required
//1 2 3 4
//-1 -1

//if sorting not required
//4 3 2 1
//-1 -1