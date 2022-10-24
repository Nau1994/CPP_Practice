#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
#define int long long int
const int Mod=1e9+1;

int fastExponent(int m,int n){
int ans=1,pow=m;

while(n){
	
	if(n&1){
		ans *= pow;
		ans %=Mod;
	}
	pow *=pow;
	pow %=Mod;
	n=n>>1;
}

return ans;
}

int32_t main()
{
    
    int m,n;
    cin>>m>>n;
    
    cout<<fastExponent(m,n)<<endl;
    int res=pow(m,n);
    cout<<res%Mod;
}