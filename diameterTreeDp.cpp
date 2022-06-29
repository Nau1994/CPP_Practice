#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1;
vector<int> adjecency[N];
int dia[N][2],len[N];

void dfs(int current,int parent){

	dia[current][0]=0;
	dia[current][1]=1;
	int max1=0,max2=0;

	for(int x:adjecency[current])
	{
	if(x!=parent)
	{
		dfs(x,current);

		len[current]=max(len[x]+1,len[current]);

		if(max1<=len[x]+1){
		max2=max1;
		max1=max(max1,len[x]+1);
		}

		dia[current][0]=max(dia[current][0],dia[x][1]);
		dia[current][1]=max1+max2;

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

	memset(dia,0,sizeof(dia));
	memset(len,0,sizeof(len));

	dfs(1,0);

	cout<<"diameter: "<<max(dia[1][0],dia[1][1]);

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
//diameter: 8


