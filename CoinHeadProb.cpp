#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

#define int long long int
#define ld long double

using namespace std;
const int N=3000;
ld p[N];
int n;
ld dp[N][N];

ld coinProb(int i,int h){
	int t=n-h-i;
	if(i==n) return 1.00;

	ld &ans=dp[i][h];
	if(ans) return ans;

	ans=0.00;
	if(h){
		ans+=coinProb(i+1,h-1)*p[i];
	}
	if(t){
		ans+=coinProb(i+1,h)*(1-p[i]);
	}

	return ans;

}

int32_t main()
{
    cin>>n;

    for (int i = 0; i < n; i++)
    {
    	cin>>p[i];
    }

    ld ans=0;
    
    for (int h = (n/2+1); h <= n; h++)
    {
    	ans+=coinProb(0,h);
    }

    
    cout<<setprecision(10)<<fixed;
    cout<<ans;
    cout<<endl;
}

// input:
// 5
// 0.42 0.01 0.42 0.99 0.42
// output:
// 0.3821815872

// input:
// 1
// 0.50
// output:
// 0.5000000000

