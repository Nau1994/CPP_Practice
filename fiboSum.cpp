#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int sz=3,mod=1e9+7;
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
int fiboSum(int n){
	if(n==1){return 1;}
	if(n==0 or n==-1){return 0;}
	Mat T;
	T.m[0][0]=T.m[0][1]=T.m[0][2]=1;
	T.m[1][1]=T.m[1][2]=1;
	T.m[2][1]=1;
	T=T^(n-1);
	return (T.m[0][0]+T.m[0][1])%mod ;

}

int main()
{
    
    int n,m;
    cin>>n>>m;
    if(m<n) swap(n,m);
    cout<<(fiboSum(m)-fiboSum(n-1)+mod)%mod;
    cout<<endl;
}

// input:0 3
// output:4

// input:3 5
// output:10

// input:10 19
// output:10857

// input:4 4
// output:3