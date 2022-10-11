#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
#include <unordered_set>

using namespace std;
#define int long long int

int mountainPeak(int *a,int n){
	int largest=0;
    for (int i = 1; i <= n-2;)
    {
        
        //check peak
        if(a[i]>a[i-1] and a[i]>a[i+1]){
            int cnt=1;
            int j=i;
            //backword
            while(j>=1 and a[j]>a[j-1]){
                j--;
                cnt++;
            }
            //forword
            while(i<=n-2 and a[i]>a[i+1]){
                i++;
                cnt++;
            }
            largest=max(largest,cnt);
        }
        else{
            i++;
        }
    }
	return largest;
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

    cout<<mountainPeak(a,n);
    cout<<endl;
}


//N 

// input:
// 17
// 5 6 1 2 3 4 5 4 3 2 0 1 2 3 -2 4
// output:
// 9