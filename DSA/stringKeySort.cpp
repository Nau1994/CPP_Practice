#include<bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <cstring>

using namespace std;
#define int long long int

string extractStringAtKey(string x,int key){
	char *s=strtok((char *)x.c_str()," ");
	while (key>1){
		s=strtok(NULL," ");
		key--;
	}

	return (string)s;
}

bool numericComparator(pair<string,string> element1,pair<string,string> element2){
	return (stoi(element1.first)>stoi(element2.first));
}

bool lexicoComparator(pair<string,string> element1,pair<string,string> element2){
	string s1= element1.first;
	string s2= element2.first;
	int len=min(s1.length(),s2.length());
	int i=0;
	do{
		if (int32_t(s1[i])>int32_t(s2[i])){
			return true;
		}
		else if (int32_t(s1[i])<int32_t(s2[i])){
			return false;
		}

		// cout<<typeid(int32_t(s1[len])).name()<<"-"<<s2[len]<<"stoi(s1[len])>stoi(s2[len])"<<endl;
	}while(i++<len);

	return (s1.length()>s2.length());
}

int32_t main()
{
    
    int n;
    cin>>n;
    cin.get(); //to consume the space after 'n'
    vector<string> input;
    for (int i = 0; i < n; i++)
    {	
    	string x;
    	getline(cin,x);
    	input.push_back(x);
    }
    int key; 
    string reversal,ordering;
    cin>>key>>reversal>>ordering;

    //tokenizer based on key
    vector<pair<string,string>> keyValue;
    for(auto x:input){
    	keyValue.push_back({extractStringAtKey(x,key),x});
    }

    
    //sorting
    if(ordering=="numeric"){
    	
    	sort(keyValue.begin(),keyValue.end(),numericComparator);
    }else{
    	sort(keyValue.begin(),keyValue.end(),lexicoComparator);
    }

    //reversal
    if(reversal=="true"){
    	reverse(keyValue.begin(),keyValue.end());
    }
    for(auto x:keyValue){
    	cout<<x.second<<endl;
    }

    cout<<endl;
}

// input:
// 3
// 92 122
// 77 13
// 82 12
// 2 true lexico
// output:
// 82 12
// 92 122
// 77 13

// input:
// 3
// 92 122
// 77 13
// 82 12
// 2 true numeric
// output:
// 82 12
// 77 13
// 92 122