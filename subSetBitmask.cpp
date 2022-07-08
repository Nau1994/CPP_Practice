#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

void substring(string s,int n){
	for (int i = 1; i < (1<<n);i++)
    {	
    	int flag=((i>>0) & 1);

    	for (int j = 1; j < n; j++)
    	{	
    			flag+=(!((i>>j-1) & 1)&((i>>j) & 1));
    			if (flag>1) break;
    		
    	}

    	if(flag>1) continue;

    	for (int j = 0; j < n; j++)
    	{
    		if((i>>j) & 1){
    			cout<<s[j];
    		}
    	}cout<<endl;
    }
}

void subset(string s,int n){
	for (int i = 0; i < (1<<n);i++)
    {	
    	
    	for (int j = 0; j < n; j++)
    	{
    		if((i>>j) & 1){
    			cout<<s[j];
    		}
    	}cout<<endl;
    }
}

int main()
{
    
    string s;
    cin>>s;
    int n=s.size();
    
    cout<<"SubString:  "<<endl;
    substring(s,n);
    cout<<"------------"<<endl;
    cout<<"Sub Set:    "<<endl;
    subset(s,n);

    return 0;
}

// input:abcd
// output:
// SubString:  
// a
// b
// ab
// c
// bc
// abc
// d
// cd
// bcd
// abcd
// ------------
// Sub Set:    

// a
// b
// ab
// c
// ac
// bc
// abc
// d
// ad
// bd
// abd
// cd
// acd
// bcd
// abcd
