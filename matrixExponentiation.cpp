#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int sz=2;
const int mod=1e9+7;
struct Mat
{
	int m[sz][sz];
	Mat(){
		memset(m,0,sizeof(m));
	}
	void indentity(){
		for (int i = 0; i < sz; i++)
		{
			m[i][i]=1;
		}
	}
	Mat operator*(Mat a){
		Mat res;
		for (int row = 0; row < sz; row++)
		{
			for (int col = 0; col < sz; col++)
		{
			for (int k = 0; k < sz; k++)
		{
			res.m[row][col]+=m[row][k]*a.m[k][col];
			res.m[row][col]%=mod;
		}
		}
		}

		return res;
	}
	Mat operator^(int b){
		Mat res,m;
		res.indentity();
	while(b){
		if(b&1){
			res=res*(*this);
		}
		(*this)=(*this)*(*this); 
		b>>=1;
	}
	return res;
	}
	
};

Mat power(Mat a,int b){
	Mat res;
	res.indentity();
	while(b){
		if(b&1){
			res=res*a;
		}
		a=a*a; 
		b>>=1;
	}

	return res;
}

int main()
{
    
    
    // cin>>sz;
    Mat a,b,res;
    for (int row = 0; row < sz; row++)
		{
			for (int col = 0; col < sz; col++)
		{
			cin>>a.m[row][col];
		}
		}
    
	for (int row = 0; row < sz; row++)
		{
			for (int col = 0; col < sz; col++)
		{
			cin>>b.m[row][col];
		}
		}
    
    res=b^2;

	for (int row = 0; row < sz; row++)
		{
			for (int col = 0; col < sz; col++)
		{
			cout<<res.m[row][col]<<" ";
		}cout<<endl;
		}
    cout<<endl;
}