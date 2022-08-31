#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

int main()
{
    
    int n,k;
    cin>>n>>k;
    int a[n];
    bool dp[k+1];
    for (int i = 0; i < n; i++)
    {
    	cin>>a[i];
    }
    
    dp[0]=0;

    for (int s = 1; s <= k; s++)
    {	dp[s]=0;
    	for (int i = 0; i < n; i++)
    {
    	if(s-a[i]>=0 && dp[s-a[i]]==0){
    		dp[s]=1;
    		break;
    	}
    }
    }

    cout<<(dp[k]?"First":"Second");
    cout<<endl;
}


// input:
// 1 100000
// 1
// output:
// Second

// input:
// 3 21
// 1 2 3
// output:
// First

// input:
// 3 20
// 1 2 3
// output:
// Second

