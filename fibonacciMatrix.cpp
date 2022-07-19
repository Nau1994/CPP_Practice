#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int sz=2,mod=1e9+7;
struct Mat{
 int m[sz][sz];
 Mat(){ memset(m,0,sizeof(m));}
 void identity(){ for (int i = 0; i < sz; i++){m[i][i]=1;}}
 Mat operator*(Mat a){
 	Mat res;
 	for (int row = 0; row < sz; row++)
 	{for (int col = 0; col < sz; col++)
 	{for (int k = 0; k < sz; k++)
 	{
 		res.m[row][col]+=m[row][k]*a.m[k][col];
 		res.m[row][col]%=mod;
 	}}} return res;
 }
 Mat operator^(int b){
 	Mat res;
 	res.identity();
 	while(b){
 		if(b&1){ res=res*(*this); }
 		(*this)=(*this)*(*this);
 		b>>=1;
 	} return res;
 } 
};

//O(2*2*2*log(N))
void fibonacciMatrix(int n){
	if(n<=2){cout<<1; return;}
	Mat T;
	T.m[0][0]=T.m[0][1]=T.m[1][0]=1;
	T=T^(n-2);
	cout<<(T.m[0][0]+T.m[0][1])%mod<<endl;

}

int main()
{
    
    int n;
    cin>>n;
    fibonacciMatrix(n);
    cout<<endl;
}