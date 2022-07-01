#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1;
vector<int> adjecency[N];
int dis[N],g[N],h[N];

void dfs(int current,int parent){

	
	for(int x:adjecency[current])
	{
	if(x!=parent)
	{
		dfs(x,current);
		h[current]+=h[x];
		g[current]+=g[x]+h[x];


	}
	}
	h[current]+=1;

}

void sumOfDistance(int current,int parent,int parents_sum){

	

	

	for(int x:adjecency[current])
	{
		int new_parents_sum=parents_sum;
	if(x!=parent)
	{	
		
		new_parents_sum+=g[current]-(g[x]+h[x])+(h[1]-h[x]);
		

		sumOfDistance(x,current,new_parents_sum);

	}
	}

	//for using subtree length 
	dis[current]+=g[current];

	//for using super tree distance
	dis[current]+=parents_sum;
}

int main()
{
    int n;
    cin>>n;
    int x,y;
    while(cin>>x>>y){
    	//undirected
    	adjecency[x].push_back(y);
    	adjecency[y].push_back(x);
    }

	memset(dis,0,sizeof(dis));
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));

	dfs(1,0);
	sumOfDistance(1,0,0);

	cout<<"Sum Of Distance:";
	for(auto i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}

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
// 6 9
// 9 11
// 11 13
// 3 8
// 8 10
// 10 12
// 12 14
// output:
//Sum Of Distance:35 45 31 45 57 37 57 37 45 45 55 55 67 67 

// input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5
// output:
// Sum Of Distance:6 9 5 8 8 



