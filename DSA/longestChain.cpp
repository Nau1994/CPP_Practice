#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
#include <unordered_set>

using namespace std;
#define int long long int


int longestChain(int *a,int n){
    unordered_set<int> st;
    int longest=0;

    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if(st.find(a[i]-1)==st.end()){
            int cnt=0;
            int j=a[i];
            while(st.find(j)!=st.end()){
                cnt++;
                j++;
            }
            longest=max(cnt,longest);
        }

    }


    return longest;
}

int32_t main()
{
    
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
    	cin>>a[i];
    }

    cout<<longestChain(a,n);
    cout<<endl;
}


//N 

// input:
// 17
// 5 6 1 2 3 4 5 4 3 2 0 1 2 3 -2 4
// output:
// 7

// input:
// 11
// 1 9 3 0 18 2 4 10 7 12 6
// output:
// 5