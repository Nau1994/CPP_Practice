#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

int nodes,edge;
const int N=10;
vector<int> adjecencyList[N];




bool hamiltonionPathWithBitMaskMemoTablulation()
{	int dp[nodes][1 << nodes];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < nodes; i++) {
		dp[i][1 << i] = 1;
	}
	for (int mask = 0; mask < (1 << nodes); mask++) {
		for (int cur = 0; cur < nodes; cur++) {
			if (dp[cur][mask]) {
				for (auto x : adjecencyList[cur]) {
					if (!((mask >> x) & 1)) {
						dp[x][mask | (1 << x)] = true;
					}
				}
			}
		}
	}
	bool ans = 0;
	for (int i = 0; i < nodes; i++) {
		ans |= dp[i][(1 << nodes) - 1];
	}
	return ans;
}

int memo[N][1 << N];
bool hamiltonionPathWithBitMaskMemo(int cur, int mask) {
	if (mask == (1 << nodes) - 1) {
		return true;
	}
	if (memo[cur][mask] != -1) {
		return memo[cur][mask];
	}
	bool ans = false;
	for (auto x : adjecencyList[cur]) {
		// xth bit of mask is set or not
		if (!((mask >> x) & 1)) {
			ans |= hamiltonionPathWithBitMaskMemo(x, mask | (1 << x));
		}
	}
	return memo[cur][mask] = ans;
}

map<pair<int, set<int>>, bool> mp;
bool hamiltonionPathWithMemo(int cur, set<int> St) {
	if (St.size() == nodes) {
		return true;
	}
	if (mp.count({cur, St})) {
		return mp[ {cur, St}];
	}

	bool ans = false;
	for (auto x : adjecencyList[cur]) {
		if (St.find(x) == St.end()) {
			set<int> temp = St;
			temp.insert(x);
			ans |= hamiltonionPathWithMemo(x, temp);
		}
	}
	return mp[ {cur, St}] = ans;
}

int visited[N];
bool hamiltonionPath(int node,int nodeCount){
	if(nodeCount==nodes){
		//cout<<visited;
		return true;
	}
	visited[node]=1;

	for(auto next:adjecencyList[node]){
		if(!visited[next]){
			return hamiltonionPath(next,nodeCount+1);
		}
	}

	visited[node]=0;
	return false;
}


int AllHamiltonionPath(int node,int nodeCount,string path){
	if(nodeCount==nodes){
		cout<<path;
		cout<<endl;

		return 1;
	}
	
	int noOfPath=0;
	
	visited[node]=1;

	for(auto next:adjecencyList[node]){
		if(!visited[next]){
			
			noOfPath += AllHamiltonionPath(next,nodeCount+1,path+to_string(next));
			
		}

	}

	visited[node]=0;
	return noOfPath;
}


int main()
{
    
    
    cin>>nodes>>edge;
    for (int i=0;i<edge;i++){
    	int x,y;
    	cin>>x>>y;
    	adjecencyList[x].push_back(y);
    	adjecencyList[y].push_back(x);
    }

    //to see Hamiltonion Path does exists?

 //    for(int i=0;i<nodes;i++){
 //    	if(hamiltonionPath(i,1)){
 //    		cout<<1;
 //    		return 0;
 //    	}
	// }


	//to see ALL Hamiltonion Paths 

	// int noOfPath=0;
	// for(int i=0;i<nodes;i++){
	// 	noOfPath+=AllHamiltonionPath(i,1,to_string(i));	
	// }
	// cout<<"Total no of Path :"<<noOfPath<<endl;


	// Hamiltonion Paths with recursive and memoization

	// bool Path=false;
	// for(int i=0;i<nodes;i++){
	// 	set<int> st={};
	// 	Path=hamiltonionPathWithMemo(i,st);	
	// }
	// cout<<Path;

	// Hamiltonion Paths with recursive and BitMask memoization

	// bool Path=false;
	//  memset(memo, -1, sizeof(memo));
	// for(int i=0;i<nodes;i++){
	// 	Path=hamiltonionPathWithBitMaskMemo(i,(1<<i));	
	// }
	// cout<<Path;

	// Hamiltonion Paths with tabulation and BitMask memoization

	bool Path=false;
	Path=hamiltonionPathWithBitMaskMemoTablulation();
	cout<<Path;
	return 0;
}



//input:
// 4 4
// 0 1
// 1 2
// 2 3
// 1 3

// output:
// 0123
// 0132
// 2310
// 3210
// Total no of Path :4