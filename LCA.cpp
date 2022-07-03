#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1, M=14;
vector<int> adjecency[N];
int par[N][M],Q[N],deep[N];

void dfs(int current,int parent){
	deep[current]=deep[parent]+1;
	par[current][0]=parent;
	for(int i=1;i<M;i++){
		par[current][i]=par[par[current][i-1]][i-1];
	}
	
	for(int x:adjecency[current])
	{
	if(x!=parent)
		{
			dfs(x,current);

		}
	}
	

}



int LCA(int u,int v){
	
	int new_node;
	if(v==u) return v;
	if(deep[v]<deep[u]) swap(u,v);
	int diff=deep[v]-deep[u];

	//MSB to LSB
	//to make v and u on same level
	for(int i=0;i<M;i++){
		if((diff>>M-i-1) & 1){
			v=par[v][M-i-1];
		}
		
	}



	for(int i=M-1;i>=0;i--){

		if(par[u][i]!=par[v][i]){
			v=par[v][i];
			u=par[u][i];
		}
		
	}

	return par[v][0];
	
	

}


int main()
{
    int n;
    cin>>n;
    int u,v;
    cin>>u>>v;
    int x,y;
    while(cin>>x>>y){
    	//undirected
    	adjecency[x].push_back(y);
    	adjecency[y].push_back(x);
    }

	memset(par,0,sizeof(par));
	memset(deep,0,sizeof(deep));

	dfs(1,0);
	cout<<"Least common Ancestor: "<<LCA(u,v)<<endl;
	
    return 0;
}


//input:
// 12 
// 9 10
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 4 10
// 5 8
// 8 9
// 8 11
// 3 7
// 7 12

// output:
//Least common Ancestor: 2








