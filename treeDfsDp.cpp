#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1;
vector<int> adjecency[N];
int dp[N][2];

void dfs(int current,int parent){

	dp[current][0]=0;
	dp[current][1]=1;

	for(int x:adjecency[current])
	{
	if(x!=parent)
	{
		dfs(x,current);
		dp[current][0]+=dp[x][1];
		dp[current][1]+=min(dp[x][0],dp[x][1]);

	}
	}

}

int main()
{
    // int n;
    // cin>>n;
    int x,y;
    while(cin>>x>>y){
    	//undirected
    	adjecency[x].push_back(y);
    	adjecency[y].push_back(x);
    }

	memset(dp,0,sizeof(dp));

	dfs(1,0);

	cout<<"number of vertex in vertex cover set: "<<min(dp[1][0],dp[1][1]);

    cout<<endl;
    return 0;
}

// input:
// 1 2
// 1 3
// 1 4
// 2 5
// 3 6
// 4 7
// output:
// number of vertex in vertex cover set: 3

