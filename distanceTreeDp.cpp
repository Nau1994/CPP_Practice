#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1;
vector<int> adjecency[N];
int dis[N],sub_tree_len[N];

void dfs(int current,int parent){

	
	for(int x:adjecency[current])
	{
	if(x!=parent)
	{
		dfs(x,current);

		sub_tree_len[current]=max(sub_tree_len[x]+1,sub_tree_len[current]);


	}
	}

}

void distance(int current,int parent,int parents_distance){

	int max1=0;
	int max2=0;
	

	for(int x:adjecency[current])
	{
	if(x!=parent)
	{	
		if (sub_tree_len[x]>max2){
			max1=max2;
			max2=sub_tree_len[x];
		}
		
		
	}}

	for(int x:adjecency[current])
	{
		int new_parents_distance=parents_distance;
	if(x!=parent)
	{	
		if (sub_tree_len[x]==max2){
			new_parents_distance=max(new_parents_distance,max1);
		}
		else{
			new_parents_distance=max(new_parents_distance,max2);
		}

		distance(x,current,new_parents_distance+1);

		//for using subtree length 
		dis[current]=max(sub_tree_len[x]+1,dis[current]);


	}
	}

	//for using super tree distance
	dis[current]=max(dis[current],parents_distance+1);
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
	memset(sub_tree_len,0,sizeof(sub_tree_len));

	dfs(1,0);
	distance(1,0,-1);

	cout<<"Distance:";
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
//Distance:5 6 4 6 7 4 7 4 5 5 6 6 7 7 

// input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5
// output:
// Distance:2 3 2 3 3 


