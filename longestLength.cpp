#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

const int N=1e5+1;
vector<int> gr[N];

int lognestLength(int node){
	int ans=0;
	for (auto child:gr[node])
	{
		ans=max(ans,lognestLength(child)+1);
	}
	return ans;
}

int main()
{
    
    int n,e,ans=0;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
    	int x,y;
    	cin>>x>>y;
    	gr[x].push_back(y);
    }

    for (int i = 0; i < n; i++)
    {
    	ans=max(ans,lognestLength(i));
    }
    cout<<ans;
    cout<<endl;
}