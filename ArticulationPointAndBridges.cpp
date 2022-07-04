#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5+1, M=14;
vector<int> adjecency[N];
int vis[N], disc[N], low[N], tme = 1;

vector<pair<int, int>> bridges;
set<int> arti_points;

void dfs(int cur, int par) {
	vis[cur] = 1;
	disc[cur] = low[cur] = tme++;
	int child = 0;
	for (auto x : adjecency[cur]) {
		if (!vis[x]) {
			dfs(x, cur);
			child++;
			// we know low and disc of x
			low[cur] = min(low[cur], low[x]);

			// bridges
			if (low[x] > disc[cur]) {
				bridges.push_back({cur, x});
			}

			// articulation points
			if (par != 0 && low[x] >= disc[cur]) {
				arti_points.insert(cur);
			}

		}
		else if (x != par && vis[x]==1) {
			// backedge
			low[cur] = min(low[cur], disc[x]);
		}
	}

	// root is an arti or not
	if (par == 0 && child > 1) {
		arti_points.insert(cur);
	}

	vis[cur]=2;

	return;
}


int main()
{
    int n;
    cin>>n;int x,y;
    while(cin>>x>>y){
    	//undirected
    	adjecency[x].push_back(y);
    	adjecency[y].push_back(x);
    }

    memset(vis,0,sizeof(vis));
    dfs(1,0);

    cout<<"Articulation points: ";
	for (auto x : arti_points) cout << x << " ";

	cout<<endl<<"Bridges: "<<endl;
	for (auto x : bridges) {
		cout << x.first << "-" << x.second << '\n';
	}
    
    return 0;
}

// input:
// 12
// 7 12
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
// Articulation points: 1 2 3 4 5 7 8 
// Bridges: 
// 4-10
// 2-4
// 8-9
// 8-11
// 5-8
// 2-5
// 2-6
// 1-2
// 7-12
// 3-7
// 1-3
