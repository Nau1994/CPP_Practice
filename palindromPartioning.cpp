#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

string s;
map<int,vector<vector<string>>> dp;

bool isPalindrom(int i,int j){
while(i<=j){
	if (s[i]!=s[j]) return false;
	i++;
	j--;
}
return true;
}

vector<vector<string>> palindromPartitioning(int i){
//base
	if(i==s.size()) return vector<vector<string>>();

	if (dp.count(i)) return dp[i];

	vector<vector<string>> ans;
	for(int j=i;j<s.size();j++){
		if(isPalindrom(i,j)){
		vector<vector<string>> res=palindromPartitioning(j+1);
		
			string str=s.substr(i,j-i+1);

			

			if(res.empty()) {res.push_back({str});}
			else{
				for(auto &r:res){
				r.insert(r.begin(),str);
				
			}
			}

			

			for(auto r:res){
				ans.push_back(r);
			}
		
		}
		
			
	}

	return dp[i]=ans;
}

int main()
{
    cin>>s;
    vector<vector<string>> results;
    results=palindromPartitioning(0);

    //result printing
    for(auto res: results){
    	for(auto r:res){
    		cout<<r<<" ";
    	}
    	cout<<endl;
    }
    cout<<endl;
    return 0;
}



// input:aab
// output:
// a a b 
// aa b 

// input:aaaa
// output:
// a a a a 
// a a aa 
// a aa a 
// a aaa 
// aa a a 
// aa aa 
// aaa a 
// aaaa 

