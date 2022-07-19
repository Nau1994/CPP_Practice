#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

#define int long long int
const int mod=1e9+7;
int multiply(int a,int b){
	int res=0;
	while(b){
		if(b&1){
			res+=a; res%=mod;
		}
		a +=a; a%=mod;
		b>>=1;
	}

	return res;
}

int power(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res*=a; res%=mod;
		}
		a *=a; a%=mod;
		b>>=1;
	}

	return res;
}

int po(int a,int b){
	int res=1;
	while(b--){
		
		res*=a; 
	}

	return res;
}

int binaryExponentiation(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res*=a;
		}
		a *=a;
		b>>=1;
	}

	return res;
}

int32_t main()
{
    
    int a,b;
    cin>>a>>b;
    
    cout<<binaryExponentiation(a,b);
    cout<<endl;
    cout<<power(a,b);
    cout<<endl;
    cout<<multiply(a,b);
    cout<<endl;
}