#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
#define int long long int
const int N=3001;
int a[N],sum;

int gameSol1(int i,int j,bool turn){
	// if(i>j) return 0;
	if(i==j){
		if(turn) {return a[i];}
		else return 0;
	}
	int ans=0;
	if(turn){
		ans=max(gameSol1(i+1,j,!turn)+a[i] ,gameSol1(i,j-1,!turn)+a[j]);
	}
	else{
		ans=min(gameSol1(i+1,j,!turn) ,gameSol1(i,j-1,!turn));
	}
	return ans;
}

int gameSol2(int i,int j){
	if(i>j) return 0;
	int ans=0;
	ans=max(a[i]-gameSol2(i+1,j) ,a[j]-gameSol2(i,j-1));
	return ans;
}

int32_t main()
{
    
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
    	cin>>a[i];
    	sum+=a[i];
    }

    int max_x=gameSol1(0,n-1,true);
    int min_y=sum-max_x;
    cout<<"Solution1:"<<max_x-min_y<<endl;
    cout<<"Solution2:"<<gameSol2(0,n-1);

    cout<<endl;
}

// intput:
// 4
// 10 80 90 30
// output:
// Solution1:10
// Solution2:10

// intput:
// 3
// 10 100 10
// output:
// Solution1:-80
// Solution2:-80

// input:
// 10
// 1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
// output:
// Solution1:4999999995
// Solution2:4999999995
