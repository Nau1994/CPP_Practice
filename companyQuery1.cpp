#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1, M=14;
vector<int> adjecency[N];
int par[N][M],Q[N];

void dfs(int current,int parent){

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

int parentQuery(int node,int parPosition){
	//base
	if(parPosition==0) { if(node) return node;
	else return -1; } 

	if(node==0 or parPosition<0) return -1;

	//rec
	int ans=0;
	ans=parentQuery(par[node][(int)floor(log2(parPosition))],parPosition-pow(2,((int)floor(log2(parPosition)))));

	return ans;

}

int parentQuery2(int node,int parPosition){
	
	int new_node=node;
	
	//LSB to MSB
	// for(int i=0;i<M;i++){
	// 	if((parPosition>>i) & 1){
	// 		new_node=par[new_node][i];
	// 	}
		
	// }

	//MSB to LSB
	for(int i=0;i<M;i++){
		if((parPosition>>M-i-1) & 1){
			new_node=par[new_node][M-i-1];
		}
		
	}

	if (new_node) return new_node;
	else return -1;

}


int main()
{
    int n,q;
    cin>>n>>q;
    
    for(int i=2;i<=n;i++){
    	int x;
    	cin>>x;
    	adjecency[x].push_back(i);
    	adjecency[i].push_back(x);
    }

	memset(par,0,sizeof(par));
	memset(Q,0,sizeof(Q));
	

	dfs(1,0);
	
	while(q--){
		int node,parPosition;
		cin>>node>>parPosition;
		cout<<parentQuery2(node,parPosition)<<endl;
	}

	// cout<<parentQuery(4,1)<<endl;

    cout<<endl;
    return 0;
}


//input:
// 5 3
// 1 1 3 3
// 4 1
// 4 2
// 4 3
// output:
// 3
// 1
// -1







