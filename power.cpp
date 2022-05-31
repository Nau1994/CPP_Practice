#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

int pow1(int x,int n){
if(n==0){ return 1;}
return (x*pow(x,n-1));
}

int fast_pow(int x,int n){
if(n==0){ return 1;}
if(n&1){
	return (x*fast_pow(x,n/2)*fast_pow(x,n/2));
}
else{
	return (fast_pow(x,n/2)*fast_pow(x,n/2));}

}


int main()
{
    
    int n,x;
    cin>>x>>n;
    cout<<fast_pow(x,n);
    cout<<endl;
}