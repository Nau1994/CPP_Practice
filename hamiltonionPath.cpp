#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

const int N=1e5;
vector<int> adjecencyList[N];
int nodes,edge;
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

	int noOfPath=0;
	for(int i=0;i<nodes;i++){
		noOfPath+=AllHamiltonionPath(i,1,to_string(i));	
	}
	cout<<"Total no of Path :"<<noOfPath<<endl;
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