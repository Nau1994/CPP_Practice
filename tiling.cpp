#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int tiling(int x,int n){
	if(n==4){return 2;}
	else if(n<4){return 1;}
	return(tiling(x,n-1)+tiling(x,n-4));
}

int main()
{
    
    int n;
    cin>>n;
    cout<<tiling(4,n);
    cout<<endl;
}